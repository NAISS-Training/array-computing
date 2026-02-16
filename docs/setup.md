---
icon: lucide/hammer
---

# Setup

This document describes how to set up a development environment for the course. All the source code examples for the course are available from the [https://github.com/NAISS-Training/array-computing](https://github.com/NAISS-Training/array-computing)

## Building the course materials using CMake

This is the general build instruction that should work on all platforms. You can also find platform specific instructions in the following sections below.

### Requirements

To build the course materials, you need to have CMake and a C++ compiler installed on your system. You also need to have the Eigen library installed. The CMake configuration uses vcpkg to manage dependencies, so you need to have vcpkg installed and set up on your system.

### Installing vcpkg

You can install vcpkg by following the instructions on the [vcpkg GitHub repository](https://learn.microsoft.com/sv-se/vcpkg/get_started/get-started). When this has been installed the CMakeLists.txt file will automatically use vcpkg to install the Eigen library.

### Building the course materials

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

## Using COSMOS at LUNARC

If you have applied for an account at LUNARC you can login to the remote desktop environment or connect using a SSH terminal. More information can be found here:

- [Login into remote desktop environment](https://lunarc-documentation.readthedocs.io/en/latest/getting_started/using_hpc_desktop/)
- [Login using SSH](https://lunarc-documentation.readthedocs.io/en/latest/getting_started/login_howto/)

A suitable environment can be loaded using the following commands:

```bash
module load foss/2024a
module load Eigen
module load CMake
```

To validate the environment you can run the following commands:

```bash
g++ --version
cmake --version
```

This should give output similar to:

```bash
$ g++ --version
g++ (GCC) 13.3.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ cmake --version
cmake version 3.29.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

To validate that Eigen is working properly, create a file called `ex0.cpp` with the following content:

```cpp
#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Matrix3d m = Eigen::Matrix3d::Random();
    std::cout << "Here is the matrix m:" << std::endl;
    std::cout << m << std::endl;
    return 0;
}
```

Compile the file using the following command:

```bash
g++ ex0.cpp -o ex0
```

Run the compiled file using the following command:

```bash
./ex0
```

This should give output similar to:

```bash
Here is the matrix m:
0.680375   0.59688 -0.329554
-0.211234  0.823295  0.536459
0.566198 -0.604897 -0.444451
```

## Linux

The easiest way to set up a development environment on Linux is to use a package manager. The following commands can be used to install the necessary tools on Ubuntu:

```bash
sudo apt-get update
sudo apt-get install g++
sudo apt-get install cmake
sudo apt-get install libeigen3-dev
```

To validate the environment you can run the following commands:

```bash
g++ --version
cmake --version
```

This should give output similar to:

```bash
g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake version 3.28.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

To validate that Eigen is working properly, create a file called `ex0.cpp` with the following content:

```cpp
#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Matrix3d m = Eigen::Matrix3d::Random();
    std::cout << "Here is the matrix m:" << std::endl;
    std::cout << m << std::endl;
    return 0;
}
```

Compile the file using the following command:

```bash
g++ ex0.cpp -I/usr/include/eigen3 -o ex0
```

Run the compiled file using the following command:

```bash
./ex0
```

This should give output similar to:

```bash
Here is the matrix m:
0.680375   0.59688 -0.329554
-0.211234  0.823295  0.536459
0.566198 -0.604897 -0.444451
```

## macOS

The easiest way to set up a development environment on macOS is to use a package manager. The following commands can be used to install the necessary tools using Homebrew:

```bash
brew install gcc
brew install cmake
brew install eigen
```

To validate that Eigen is working properly, create a file called `ex0.cpp` with the following content:

```cpp
#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Matrix3d m = Eigen::Matrix3d::Random();
    std::cout << "Here is the matrix m:" << std::endl;
    std::cout << m << std::endl;
    return 0;
}
```

Compile the file using the following command:

```bash
g++ -std=c++11 -I/usr/local/include/eigen3 ex0.cpp -o ex0
```

Run the compiled file using the following command:

```bash
./ex0
```

This should give output similar to:

```bash
Here is the matrix m:
0.680375   0.59688 -0.329554
-0.211234  0.823295  0.536459
0.566198 -0.604897 -0.444451
```

## Windows

On Windows you have two options. The first one is to install the Microsoft Visual Studio IDE and use the Visual Studio Command Prompt. The second option is to use the Windows Subsystem for Linux (WSL). The easiest is probably to install WSL and use the Ubuntu distribution. Then the compilers and libraries are installed in the same way as described for Linux.
