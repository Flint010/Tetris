A simple Tetris game written using the SFML framework 

I'm using vcpkg to install SFML lib

In vcpkg directory:
```
vcpkg install sfml
vcpkg integrate
```

In Tetris repository:
```
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=<strong><vcpkg-root></strong>/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

<span style="color: red">Текст для изменения цвета</span>
<strong></strong>
