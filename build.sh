#!/bin/bash

# TODO: build for linux test windows(and then linux once i get it building)

set -e

mkdir -p build

cd build # why cd into build then exit its stupid

printf "Compiling for MacOS(OSX)...\n" #i like calling it osx its shorter than macos idc if you dont like it its here and its staying
clang++ -std=c++17 -O2 ../src/main.cpp -o assaultcube-cli
printf "Done!\n"
if (( $? == 0 )); then
    printf "Build successful!\n"
else
    printf "Build failed!\n"
fi

if (( 0 == 1 )); then # not building for windows yet
    printf "Compiling for Windows...\n"
    x86_64-w64-mingw32-g++ -std=c++17 -O2 ../src/main.cpp -o assaultcube-cli.exe
    printf "Done!\n"
else 
    printf "Skipping Windows build...\n"
fi