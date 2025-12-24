set -e

MINGW_PATH="/c/mingw/bin"

rm -rf build
mkdir build
cd build

cmake -G "MinGW Makefiles" \
  -DCMAKE_C_COMPILER="${MINGW_PATH}/gcc.exe" \
  -DCMAKE_CXX_COMPILER="${MINGW_PATH}/g++.exe" \
  -DCMAKE_MAKE_PROGRAM="${MINGW_PATH}/mingw32-make.exe" \
  -DCMAKE_BUILD_TYPE=Release \
  ..
  
"${MINGW_PATH}/mingw32-make.exe" -j$(nproc)
