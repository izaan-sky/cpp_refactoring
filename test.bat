@echo off
REM set "PATH=C:\msys64\mingw64\bin;%PATH%"
cmake -S . -B build -G "MinGW Makefiles" && cmake --build build && ctest --test-dir build --output-on-failure
