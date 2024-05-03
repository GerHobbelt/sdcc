#ifndef FUIOCL_HEADER
#define FUIOCL_HEADER

#include "ddconfig.h"

#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "fiocl.h"

class cl_io: public cl_f
{
 public:
  cl_io();
  cl_io(chars fn, chars mode);
  cl_io(int the_server_port);
  virtual ~cl_io(void);
 protected:
#ifdef HAVE_TERMIOS_H
  struct termios saved_attributes;
#endif
 public:
  virtual enum file_type determine_type(void);
  virtual int close(void);
  virtual void changed(void);
  virtual int check_dev(void);
  virtual bool writable(void);

  virtual void prepare_terminal();
  virtual void save_attributes();
  virtual void restore_attributes();
};


#endif

/* End of fuiocl.h */
