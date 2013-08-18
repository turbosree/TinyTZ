// -----------------------------------------------------------------------------
/// \file                  intercept.h
/// \brief                 File access and time.h interceptor macros
/// \author                Sreejith.Naarakathil@gmail.com
// -----------------------------------------------------------------------------

#ifdef INTERCEPT
/* time.h */
static time_t sys_time(time_t *x) { return time(x); }

# undef  ctime
# define ctime tz_ctime
# undef  ctime_r
# define ctime_r tz_ctime_r
# undef  difftime
# define difftime tz_difftime
# undef  gmtime
# define gmtime tz_gmtime
# undef  gmtime_r
# define gmtime_r tz_gmtime_r
# undef  localtime
# define localtime tz_localtime
# undef  localtime_r
# define localtime_r tz_localtime_r
# undef  mktime
# define mktime tz_mktime
# undef  time
# define time tz_time
# undef  asctime
# define asctime tz_asctime
# undef  asctime_r
# define asctime_r tz_asctime_r
/* # undef  time_t */
/* # define time_t tz_time_t */

/* typedef time_tz time_t; */

char *ctime(time_t const *);
char *ctime_r(time_t const *, char *);
double difftime(time_t, time_t);
struct tm *gmtime(time_t const *);
struct tm *gmtime_r(time_t const *restrict, struct tm *restrict);
struct tm *localtime(time_t const *);
struct tm *localtime_r(time_t const *restrict, struct tm *restrict);
time_t mktime(struct tm *);
char *asctime(register const struct tm *timeptr);
char *asctime_r(register const struct tm *timeptr, char *buf);

static time_t
time(time_t *p)
{
    time_t r = sys_time(0);
    if (p)
        *p = r;
    return r;
}

/* File system access */
# undef  access
# define access tz_access
# undef  open
# define open tz_open
# undef  read
# define read tz_read
# undef  close
# define close tz_close
# undef  getenv
# define getenv tz_getenv
# undef  FILENAME_MAX
# define FILENAME_MAX 256       /* This lib will never open a file so this is safe */
# undef  TZNAME_MAX
# define TZNAME_MAX 255       /* This lib will never open a file so this is safe */
extern int access(const char *path, int amode);
extern int open(const char *path, int oflag, ... );
extern ssize_t read(int fildes, void *buf, size_t nbyte);
extern int close(int fildes);
extern char *getenv(const char *name);
#endif

