#!/bin/sh
# // -----------------------------------------------------------------------------
# /// \file                  tz-strip-new.sh
# /// \brief                 Shell script to strip down the standard tzdata
# ///                        tzdata: http://www.iana.org/time-zones
# /// \author                Sreejith.Naarakathil@gmail.com
# // -----------------------------------------------------------------------------

# Remove old log files
rm -f tz_omitted.txt
rm -f tz_included.txt
# insert a blank line above every line which matches "Zone" or "Link" at the begining of line
cat tzr.txt |     sed '/^\;\;/d' | while read tzr;
do
    sed -i '/^Zone/{x;p;x;G;}' $tzr
    sed -i '/^Link/{x;p;x;G;}' $tzr
    sed -i '/^# Rule/{x;p;x;G;}' $tzr
done;

cat zn.txt | \
    sed '/^\;\;#/d' | \
    sed -n '/^\;\;/p' | \
    sed 's/;;//g' | \
    sed 's/^[ \t]*//' > tz_included.txt;

cat zn.txt | \
    sed '/^\;\;/d' | \
    sed '/^$/d' | \
    while read tz1;
do
    echo $tz1 >> tz_omitted.txt
    tz=$(echo $tz1 | sed 's/\//\\\//g');
    cat tzr.txt |     sed '/^\;\;/d' | while read tzr;
    do
        sed -i '/^Zone.*'"$tz"'/s/^/#/g' $tzr;
        sed -i '/^Link.*'"$tz"'/s/^/#/g' $tzr;
    done;
    sed -i '/'"$tz"'/s/^/#/g' backward;
done;
cat tzr.txt |     sed '/^\;\;/d' | while read tzr;
do
    sed -i '/^#Zone/,/^$/ {/^#Zone/n;/^$/ !{s/^/#/g}}' $tzr
done;

