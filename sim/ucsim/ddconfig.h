/* ddconfig_in.h.  Generated from configure.ac by autoheader.  */

#ifndef DDCONFIG_HEADER
#define DDCONFIG_HEADER

/* Define to be the type of length parameter of accept (without the \*'). */
//#undef ACCEPT_SOCKLEN_T

/* Define if building universal (internal helper macro) */
#undef AC_APPLE_UNIVERSAL_BUILD

/* XXX */
//#undef FD_HEADER_OK

/* XXX */
#undef FD_NEED_SELECT_H

/* XXX */
#undef FD_NEED_TIME_H

/* XXX */
#define FD_NEED_TYPES_H 1

/* XXX */
#define FD_NEED_WINSOCK2_H  1

/* XXX */
#undef FD_NEED_GNUTYPES_H

/* XXX */
//#undef GNU_GETCWD

/* XXX */
#undef HAVE_CURSES_H
#undef HAVE_NCURSESW_H
#undef HAVE_NCURSES_H
#undef HAVE_NCURSESW_CURSES_H
#undef HAVE_NCURSES_CURSES_H

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#undef HAVE_DIRENT_H

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Define to 1 if you have the <endian.h> header file. */
#undef HAVE_ENDIAN_H

/* XXX */
#define HAVE_FLEX 1

/* Define to 1 if you have the <getopt.h> header file. */
#undef HAVE_GETOPT_H

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the <sys/wait.h> header file. */
#undef HAVE_SYS_WAIT_H

/* Define to 1 if you have the `nsl' library (-lnsl). */
#undef HAVE_LIBNSL

/* Define to 1 if you have the `rt' library (-lrt). */
#undef HAVE_LIBRT

/* Define to 1 if you have the `socket' library (-lsocket). */
#undef HAVE_LIBSOCKET

/* Define to 1 if you have the <machine/endian.h> header file. */
#undef HAVE_MACHINE_ENDIAN_H

/* Define to 1 if you have the <memory.h> header file. */
#undef HAVE_MEMORY_H

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
#undef HAVE_NDIR_H

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H  1

/* Define to 1 if you have the <cstdint.h> header file. */
#undef HAVE_CSTDINT_H

#undef HAVE_MKFIFO         // mkfifo()

#undef HAVE_SIGACTION      // sigaction / sigemptyset / ...

#define HAVE_IO_H  1       // #include <io.h>

#undef HAVE_NETINET_IN_H   // #include <netinet/in.h>

#undef HAVE_ARPA_INET_H    // #include <arpa/inet.h>

#undef HAVE_SYS_TIME_H

#undef HAVE_TERMIOS_H      // #include <termios.h>

#undef HAVE_PTHREAD_H      // #include <pthread.h>

#define HAVE_WINDOWS_H  1  // #include <windows.h>

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H  1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP  1

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
#undef HAVE_SYS_DIR_H

/* Define to 1 if you have the <sys/endian.h> header file. */
#undef HAVE_SYS_ENDIAN_H

/* Define to 1 if you have the <sys/isa_defs.h> header file. */
#undef HAVE_SYS_ISA_DEFS_H

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
#undef HAVE_SYS_NDIR_H

/* XXX */
#undef HAVE_SYS_SOCKET_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H  1

/* Define to 1 if you have the <termios.h> header file. */
#undef HAVE_TERMIOS_H

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the <wincon.h> header file. */
#define HAVE_WINCON_H  1

/* Define to 1 if you have a working `fork' function. */
#undef HAVE_WORKING_FORK

/* Define to 1 if you have the `_exit' function. */
#undef HAVE__EXIT

/* Define to 1 if you have the `dup2' function. */
#undef HAVE_DUP2

/* Define to 1 if you have the `dup3' function. */
#undef HAVE_DUP3

/* Define to 1 if you have the `pipe' function. */
#undef HAVE_PIPE

/* Define to 1 if you have the `pipe2' function. */
#undef HAVE_PIPE2

/* Define to 1 if you have the `waitpid' function. */
#undef HAVE_WAITPID

/* Define to 1 if you have the `vasprintf' function. */
#undef HAVE_VASPRINTF

#undef HAVE_STRCASECMP

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF  1

/* XXX */
#define HAVE_WINSOCK2_H 1

/* Define to 1 if you have the `yylex' function. */
#undef HAVE_YYLEX

/* which header file defines FD_ macros */
#define HEADER_FD         <winsock2.h>

/* XXX */
#undef HEADER_SOCKET

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#undef LT_OBJDIR

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#define PACKAGE_NAME "ucsim"

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Define as the return type of signal handlers (`int' or `void'). */
#undef RETSIGTYPE

/* XXX */
//#undef SCANF_A

/* The size of `char', as computed by sizeof. */
#define SIZEOF_CHAR 1

/* The size of `int', as computed by sizeof. */
#undef SIZEOF_INT

/* The size of `long', as computed by sizeof. */
#undef SIZEOF_LONG

/* The size of `long long', as computed by sizeof. */
#undef SIZEOF_LONG_LONG

/* The size of `short', as computed by sizeof. */
#undef SIZEOF_SHORT

/* XXX */
#undef SOCKET_AVAIL

/* XXX */
#undef SOCKLEN_T

/* XXX */
#undef SPEC_BYTE

/* XXX */
#undef SPEC_DWORD

/* XXX */
#undef SPEC_QWORD

/* XXX */
#undef SPEC_WORD

/* XXX */
#undef STATISTIC

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS   1

/* XXX */
#define TYPE_BYTE   char

/* XXX */
#define TYPE_DWORD  int 

/* XXX */
#define TYPE_QWORD  long long

/* XXX */
#define TYPE_WORD  short 

/* XXX */
#define UCSOCKET_T  int

/* XXX */
#undef VERSIONHI

/* XXX */
#undef VERSIONLO

/* XXX */
#undef VERSIONP

/* XXX */
#define VERSIONSTR  "0.1"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
#  undef WORDS_BIGENDIAN
# endif
#endif

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#undef YYTEXT_POINTER

/* XXX */
#undef _A_

/* XXX */
#undef _M_

#endif /* DDCONFIG_HEADER */
