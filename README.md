**A simple Tetris game written using the SFML framework**

I'm using vcpkg to install SFML lib

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
