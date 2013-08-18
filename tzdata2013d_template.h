// -----------------------------------------------------------------------------
/// \file                  tzdata2013d_template.h
/// \brief                 File access interceptor code
///                        Implements the access to tzdata binary db
/// \author                Sreejith.Naarakathil@gmail.com
// -----------------------------------------------------------------------------
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

unsigned char* locale_localtime = 0;
unsigned int locale_localtime_len = 0;
unsigned int locale_tz_id = 0;

#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

