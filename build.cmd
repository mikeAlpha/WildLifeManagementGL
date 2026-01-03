@echo off
setlocal

rem --- paths ---
set "MINGW_PATH=C:\mingw64\bin"
set "GCC_PATH=C:\msys64\ucrt64\bin"

rem --- stop on first error ---
rem (batch does not have `set -e`, so use conditional exits)
rmdir /S /Q build 2>nul || exit /b 1
mkdir build || exit /b 1
cd build || exit /b 1

rem --- configure ---
cmake -G "MinGW Makefiles" ^
  -DCMAKE_C_COMPILER="%MINGW_PATH%\gcc.exe" ^
  -DCMAKE_CXX_COMPILER="%MINGW_PATH%\g++.exe" ^
  -DCMAKE_MAKE_PROGRAM="%MINGW_PATH%\mingw32-make.exe" ^
  -DCMAKE_BUILD_TYPE=Debug ^
  .. || exit /b 1

rem --- build ---
"%MINGW_PATH%\mingw32-make.exe" -j%NUMBER_OF_PROCESSORS% || exit /b 1

endlocal
