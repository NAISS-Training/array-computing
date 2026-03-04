---
icon: lucide/hammer
---

# Setup

This document describes how to set up a development environment for the course.
All course source code is available at:

- [https://github.com/NAISS-Training/array-computing](https://github.com/NAISS-Training/array-computing)

## Quick start (recommended)

If you already have a C++ compiler and CMake installed, this is the fastest way to get started:

```bash
git clone https://github.com/NAISS-Training/array-computing.git
cd array-computing
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

## Minimum requirements

- C++ compiler with C++23 support
- CMake (recommended: 3.24 or newer)
- Eigen 3.4.x

Optional:

- `make` (only needed for the Makefile-based workflow)
- `vcpkg` (if your CMake setup uses it for dependency management)

## Building with CMake (cross-platform)

This is the default and recommended workflow for all platforms.

### 1. Clone the repository

```bash
git clone https://github.com/NAISS-Training/array-computing.git
cd array-computing
```

### 2. Configure and build (Debug)

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

### 3. Configure and build (Release)

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

## vcpkg notes

If your local `CMakeLists.txt` integrates with `vcpkg`, install and bootstrap `vcpkg` first:

- [Get started with vcpkg](https://learn.microsoft.com/vcpkg/get_started/get-started)

Typical configure command when a toolchain file is needed:

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake
```

If your repository already wires this automatically, you can use the standard configure command shown above.

## Building with Make (Linux/macOS)

If you prefer Make and have all prerequisites installed:

```bash
cd src
make
```

The `Makefile` builds all configured examples in `src`.

## Platform-specific setup

### Linux (Ubuntu)

Install tools:

```bash
sudo apt-get update
sudo apt-get install -y g++ cmake libeigen3-dev
```

Validate tools:

```bash
g++ --version
cmake --version
```

Validate Eigen installation with a minimal test:

Create `ex0.cpp`:

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

Compile and run:

```bash
g++ -std=c++23 ex0.cpp -I/usr/include/eigen3 -o ex0
./ex0
```

### macOS

Install tools using Homebrew:

```bash
brew install gcc cmake eigen
```

Create `ex0.cpp`:

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

Compile and run (Apple Silicon):

```bash
g++ -std=c++23 ex0.cpp -I/opt/homebrew/include/eigen3 -o ex0
./ex0
```

Compile and run (Intel):

```bash
g++ -std=c++23 ex0.cpp -I/usr/local/include/eigen3 -o ex0
./ex0
```

### Windows

Two supported workflows:

### Option A: WSL (recommended)

1. Install WSL and Ubuntu.
2. Open an Ubuntu terminal in WSL.
3. Follow the Linux setup instructions in this document.

### Option B: Visual Studio + CMake

1. Install Visual Studio with the **Desktop development with C++** workload.
2. Install CMake (if not already available from Visual Studio tools).
3. Install Eigen using `vcpkg` or another package manager.
4. Use the **x64 Native Tools Command Prompt for VS** and run:

```bat
git clone https://github.com/NAISS-Training/array-computing.git
cd array-computing
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

If your generator is multi-config (for example Visual Studio), use:

```bat
cmake --build build-release --config Release
```

## Using COSMOS at LUNARC

If you have an account at LUNARC, you can log in via remote desktop or SSH:

- [Login into remote desktop environment](https://lunarc-documentation.readthedocs.io/en/latest/getting_started/using_hpc_desktop/)
- [Login using SSH](https://lunarc-documentation.readthedocs.io/en/latest/getting_started/login_howto/)

Load a suitable environment:

```bash
module load foss/2025b
module load Eigen
module load CMake
```

Validate tools:

```bash
g++ --version
cmake --version
```

Validate Eigen with the same `ex0.cpp` test shown above. Compile and run:

```bash
g++ -std=c++23 ex0.cpp -o ex0
./ex0
```

## Template for course exercises

The `template` folder contains a simple Eigen project and a Makefile.
Add your C++ file there and build it with the provided Makefile.

## Troubleshooting

- **Eigen not found**: verify Eigen installation path and include directory (`-I.../eigen3`) or use `vcpkg` toolchain with CMake.
- **Compiler does not support C++23**: check `g++ --version` (or your compiler version) and install a newer toolchain.
- **CMake configure fails after dependency changes**: remove the build directory and configure again.
- **Wrong generator/toolchain on Windows**: run from the correct Visual Studio developer prompt or use WSL.

## Verification checklist

- `g++ --version` (or equivalent) works
- `cmake --version` works
- CMake configure step completes successfully
- Build step completes successfully
- At least one program runs without errors
