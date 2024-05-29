**A simple Tetris game written using the SFML framework**

To install the SFML library I use vcpkg

In vcpkg directory:
```
vcpkg install sfml
vcpkg integrate
```

In Tetris repository:
```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=<vcpkg-root>/scripts/buildsystems/vcpkg.cmake
cmake --build .
```
