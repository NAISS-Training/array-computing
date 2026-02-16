# Array Computing with Eigen

This is a course on array computing with the C++ library Eigen.

Course web page is [here](https://naiss-training.github.io/array-computing).

## Requirements

To build the course materials, you need to have CMake and a C++ compiler installed on your system. You also need to have the Eigen library installed. The CMake configuration uses vcpkg to manage dependencies, so you need to have vcpkg installed and set up on your system.

## Installing vcpkg

You can install vcpkg by following the instructions on the [vcpkg GitHub repository](https://learn.microsoft.com/sv-se/vcpkg/get_started/get-started). When this has been installed the CMakeLists.txt file will automatically use vcpkg to install the Eigen library.

## Building the course materials

The course materials are built using CMake. You can build the materials using the following commands:

```bash
git clone
cd array-computing
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

Building optimised version

```bash
cmake -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```
