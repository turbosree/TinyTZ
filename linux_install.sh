#!/bin/sh
# Author: Sreejith.Naarakathil@gmail.com

tar -xvzf tzdata2013d.tar.gz
cp -f Makefile.NEW Makefile
make TOPDIR=./build cc=gcc clean
make TOPDIR=./build cc=gcc production
make TOPDIR=./build cc=gcc tzlib_clean
make TOPDIR=./build cc=gcc tzlib

