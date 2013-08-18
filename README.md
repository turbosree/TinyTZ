sreejith.naarakathil@gmail.com

TinyTZ
======

Using IANA time zone database in embedded systems with strict memory requirements and with/without filesystem support.

Default build of Time zone database gives a binary database stored in files (zoneinfo/). It is ~2MB in size for supporting 
~586 different time zone names. The reference code and the time zone data base are available in the below link,
http://www.iana.org/time-zones
Current version:
Time Zone Data v. 2013d (Released 2013-07-05)	tzdata2013d.tar.gz (213.8kb)
Time Zone Code v. 2013d (Released 2013-07-05)	tzcode2013d.tar.gz (135.0kb)

This implementation strips down the original time zone data to few kilo bytes (< 200KB) binary data and avoids
the filesystem dependency for use with embedded systems with strict memory constraints. The IANA reference source code is 
used “as is” from the IANA web site. There are minor Make file changes and a private header file added for removing 
filesystem dependency.

Building libtz
==============
$make distclean
$linux_install.sh
You may need to change the tool chain and target paths in linux_install.sh. 
On successful installation, libtz and the binary database can be found under the build directory.

The following files are additionally added to the original source, 
Makefile.NEW
intercept.h
locale_tz_map.h*
tzdata2013d.c*
tzdata2013d_template.c
tzdata2013d_template.h
linux_install.sh
tz-gen-c-db.sh
tz-strip-db.sh
Configuration file for tz-strip-db.sh: tzr.txt, zn.txt
Included and omitted tz names: tz_included.txt*, tz_omitted.txt*

* These files are generated during the build process.
