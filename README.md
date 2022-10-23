# SinLU-cpp

Libtorch implementation SinLU (Sinu-Sigmoidal Linear Unit)

## Prerequisite

- libtorch Release version (1.12.0)
- Visual Studio build tools 2019

## How to execute 
1. [Cmake 설치](https://cmake.org/download/)
1.1 VScode의 CMake, CMake Language Support, CMake Tools 설치
1.2 CMakeLists.txt를 저장 (Ctrl+S)

2. 아래 커맨드 입력 

```"C:\Program Files\CMake\bin\cmake.EXE" --build d:/Code/SinLU-cpp/build --config Release --target ALL_BUILD -j 14 --```

3. libtorch lib의 dll 파일을 Release 폴더로 이동

4. 파일 실행 ```build\Release\Main.exe```

## See together

[Tensorflow implementation (UnOfficial)](https://github.com/kaintels/SinLU-tf)

[PyTorch implementaiton (Official)](https://github.com/ashis0013/SinLU)