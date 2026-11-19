#!/bin/bash

# TODO: build for linux test linx what the fuck why cant i spell 

set -e

mkdir -p build

printf "Compiling for macOS(OSX)...\n" #i like calling it osx its shorter than macos idc if you dont like it its here and its staying
clang++ -std=c++17 -O2 src/*.cpp -o build/assaultcube-cli
printf "Done!\n"
u="$(uname -s)"
if (($"u" != "Darwin")); then 
# i dont have zig and i dont wanna download it my terminal is also a crime scene i kept trying java/c++ syntax for the if
# i recommend being sleep deprived 
    printf "Compiling for Linx (Linux x86_64, static)...\n"
    zig c++ -target x86_64-linux-musl src/*.cpp -o build/assaultcube-cli-linux
    printf "Done!\n"
    else
    printf "Skipping lix(Linux i cant spell) uname: "; uname -s # i missed another
fi

if (( 0 == 1 )); then # not building for windows yet
    printf "Compiling for Windows...\n"
    x86_64-w64-mingw32-g++ -std=c++17 -O2 src/*.cpp -o build/assaultcube-cli.exe
    printf "Done!\n"
else 
    printf "Skipping Windows build...\n"
fi