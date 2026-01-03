set -e

MINGW_PATH="/c/mingw64/bin"
GCC_PATH="/c/msys64/ucrt64/bin"

rm -rf build
mkdir build
cd build

cmake -G "MinGW Makefiles" \
  -DCMAKE_C_COMPILER="${MINGW_PATH}/gcc.exe" \
  -DCMAKE_CXX_COMPILER="${MINGW_PATH}/g++.exe" \
  -DCMAKE_MAKE_PROGRAM="${MINGW_PATH}/mingw32-make.exe" \
  -DCMAKE_BUILD_TYPE=Debug \
  ..
  
"${MINGW_PATH}/mingw32-make.exe" -j$(nproc)
