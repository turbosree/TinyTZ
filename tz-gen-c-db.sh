#!/bin/sh
# // -----------------------------------------------------------------------------
# /// \file                  tz-strip-new.sh
# /// \brief                 Shell script to strip down the standard tzdata
# ///                        tzdata: http://www.iana.org/time-zones
# /// \author                Sreejith.Naarakathil@gmail.com
# // -----------------------------------------------------------------------------

cat tzdata2013d_template.h >> tzdata2013d.c

cat tz_included.txt | \
	 sed '/^\;\;#/d' | \
	 sed '/^\;\;/d' | \
	 sed '/^$/d' | \
	 while read tz; 
do 
	 tz1=$(echo $tz | sed 's/\//_/g')
	 echo "void tz_set_${tz1}(void);"
done; 

echo "void (*tz_set_fp[])(void) = {"
cat tz_included.txt | \
	 sed '/^\;\;#/d' | \
	 sed '/^\;\;/d' | \
	 sed '/^$/d' | \
	 while read tz; 
do 
	 tz1=$(echo $tz | sed 's/\//_/g')
	 echo "tz_set_${tz1},"
done; 
echo "};" 

echo "char *locale_tz_names[] = {"
cat tz_included.txt | \
	 sed '/^\;\;#/d' | \
	 sed '/^\;\;/d' | \
	 sed '/^$/d' | \
	 while read tz; 
do 
	 echo "\"${tz}\","
done; 
echo "};" 

echo ""
cat tz_included.txt | \
	 sed '/^\;\;#/d' | \
	 sed '/^\;\;/d' | \
	 sed '/^$/d' | \
	 while read tz; 
do 
	 tz1=$(echo $tz | sed 's/\//_/g')
	 echo "void tz_set_${tz1}(void)
{
   locale_localtime = ${tz1};
   locale_localtime_len = ${tz1}_len;
}"
	 echo ""
done; 

cat tzdata2013d_template.c >> tzdata2013d.c
cp -f tzdata2013d.c tzdata2013d.c.backup

# debug_print(\"\ntz_set_${tz1}: %d\n\", ${tz1}_len);
