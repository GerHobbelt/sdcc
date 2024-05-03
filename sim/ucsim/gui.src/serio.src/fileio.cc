/******************************************************************************
 * to emulate the serial input and output of an 8051 controller               *
 * fileio.cc - file input and output                                          *
 ******************************************************************************/
#include "ddconfig.h"

#include <sys/types.h>
#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_IO_H
#include <io.h>
#endif

 // These flags aren't defined on some platforms
#if defined (S_IRUSR) && defined (S_IWUSR) && defined (S_IRGRP) && defined (S_IWGRP) && defined (S_IROTH) && defined (S_IWOTH)
#define PUBLIC_MODE  \
    (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#else
#define PUBLIC_MODE 0644
#endif

#include "fileio.hh"

#ifdef HAVE_MKFIFO

FileIO::FileIO()
{

  // make the input fifo
  if(mkfifo(DEF_INFILE, PUBLIC_MODE) == -1) {
    if(errno != EEXIST) {
      std::cerr << "mkfifo(): Error number " << errno << " occourred: " << strerror(errno) << "\n";
      exit(-1);
    }
  }
  
  // the input fifo - non blocking
  if ((fdin = open(DEF_INFILE, O_RDONLY|O_NONBLOCK)) == -1) {
    std::cerr << "open(): Error number " << errno << " occourred: " << strerror(errno) << "\n";
    exit(-1);
  }
  
  // make the output fifo
  if(mkfifo(DEF_OUTFILE, PUBLIC_MODE) == -1) {
    if(errno != EEXIST) {
      std::cerr << "mkfifo(): Error number " << errno << " occourred: " << strerror(errno) << "\n";
      exit(-1);
    }
  }
  
  // the output fifo
  if ((fdout = open(DEF_OUTFILE, O_RDWR|O_NONBLOCK)) == -1) {
    std::cerr << "open(): Error number " << errno << " occourred: " << strerror(errno) << "\n";
    exit(-1);
  }
}

FileIO::FileIO(const char *infile, const char *outfile)
{
  // make the input fifo
  if(mkfifo(infile, PUBLIC_MODE) == -1) {
    if(errno != EEXIST) {
      std::cerr << "mkfifo(): Error number " << errno << " occourred: " << strerror(errno);
      exit(-1);
    }
  }
  
  // the input fifo - non blocking
  if ((fdin = open(infile, O_RDONLY|O_NONBLOCK)) == -1) {
    std::cerr << "open(): Error number " << errno << " occourred: " << strerror(errno);
    exit(-1);
  }
  
  // make the output fifo
  if(mkfifo(outfile, PUBLIC_MODE) == -1) {
    if(errno != EEXIST) {
      std::cerr << "mkfifo(): Error number " << errno << " occourred: " << strerror(errno);
      exit(-1);
    }
  }
  
  // the output fifo
  if ((fdout = open(outfile, O_RDWR|O_NONBLOCK)) == -1) {
    std::cerr << "open(): Error number " << errno << " occourred: " << strerror(errno);
    exit(-1);
  }
}


FileIO::~FileIO()
{
  close(fdin);
  close(fdout);
}

int FileIO::SendByte(char b)
{
  int ret;
  
  if((ret = write(fdout, &b, 1)) != 1)
    {
      std::cerr << "write(): Error number " << errno << " occourred: " << strerror(errno);
      exit(-1);
    }
  
  return(ret);
}


int FileIO::RecvByte(char *b)
{
  int ret;
  
  ret = read(fdin, b, 1);
  
  if((ret == -1) && (errno != EAGAIN))
    {
      std::cerr << "read(): Error number " << errno << " occourred: " << strerror(errno);
      exit(-1);
    }
  
  return(ret);
}

// send a string
int FileIO::SendStr(char *str)
{
  int ret;
  
  if((ret = write(fdout, str, strlen(str))) != (int)strlen(str))
    {
      std::cerr << "write(): Error number " << errno << " occourred: " << strerror(errno);
      exit(-1);
    }
  
  return(ret);
}


int FileIO::RecvStr(char *str)
{
  int ret;
  
  ret = read(fdin, str, MAX_SIZ-1);
  str[MAX_SIZ] = 0;
  
  if((ret == -1) && (errno != EAGAIN))
    {
      std::cerr << "read(): Error number " << errno << " occourred: " << strerror(errno);
      exit(-1);
    }
  
  return(ret);
}

#else

// TODO: MSVC/Win32/Win64:
// https://stackoverflow.com/questions/26561604/create-windows-named-pipe-in-c

#endif // HAVE_MKFIFO
