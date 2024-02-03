rmdir /S /q "build"
mkdir "build"
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG="/Zi" -DCMAKE_GENERATOR_PLATFORM=x64 ..
cmake --build . 