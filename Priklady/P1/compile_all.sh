#!/bin/bash

touch CMakeLists.txt
exec 3<> CMakeLists.txt
echo "cmake_minimum_required(VERSION 3.14)" >&3
echo "project(${PWD##*/})" >&3

for f in *.c;
do
    base=$(basename $f .c)
    if [ -e $base ]
    then
        rm $base
    fi
    gcc $f -o $base
    echo "add_executable($base $f)" >&3

done
exec 3>&-
