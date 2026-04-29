# Development Setup Guide

This guide provides detailed instructions for setting up your development environment for the Embedded-Project across different platforms.

## 📋 Table of Contents

- [Prerequisites](#prerequisites)
- [Windows Setup](#windows-setup)
- [Linux Setup](#linux-setup)
- [macOS Setup](#macos-setup)
- [Verification](#verification)
- [IDE Configuration](#ide-configuration)
- [Troubleshooting](#troubleshooting)

---

## 📦 Prerequisites

### Common Requirements
- Git
- CMake 3.15 or higher
- C++ compiler with C++17 support
- C compiler with C99 support

### Optional Tools
- Visual Studio Code or Visual Studio (IDE)
- Clang/LLVM tools
- ARM toolchain (for cross-compilation)
- Code formatter (clang-format)
- Static analyzer (clang-tidy)

---

## 🪟 Windows Setup

### Option 1: Visual Studio (Recommended for Windows)

#### Step 1: Install Required Software

1. **Visual Studio 2019 or 2022**
   - Download from: https://visualstudio.microsoft.com/
   - Install with "Desktop Development with C++" workload
   - Include CMake tools

2. **Git for Windows**
   - Download from: https://git-scm.com/download/win
   - Use default installation settings

3. **CMake** (if not installed with Visual Studio)
   - Download from: https://cmake.org/download/
   - Add to system PATH

#### Step 2: Clone Repository

```cmd
cd C:\Projects
git clone https://github.com/Sva-Dagger/Embedded-Project.git
cd Embedded-Project
```

#### Step 3: Configure in Visual Studio

1. Open Visual Studio
2. File → Open → CMake
3. Select `CMakeLists.txt` from the project folder
4. Visual Studio will automatically configure CMake

#### Step 4: Build

```cmd
cmake --build .\build --config Debug
```

### Option 2: Command Line with MSVC

```cmd
# Create build directory
mkdir build
cd build

# Configure
cmake .. -G "Visual Studio 16 2019"

# Build Debug
cmake --build . --config Debug

# Build Release
cmake --build . --config Release

# Run tests
ctest -C Debug --output-on-failure
```

### Option 3: MinGW/GCC

```cmd
# Install MinGW from: https://www.mingw-w64.org/

mkdir build
cd build

cmake .. -G "MinGW Makefiles"
cmake --build .

ctest --output-on-failure
```

---

## 🐧 Linux Setup

### Ubuntu/Debian

#### Step 1: Install Dependencies

```bash
sudo apt update
sudo apt install -y \
    build-essential \
    cmake \
    git \
    curl \
    wget \
    pkg-config \
    libssl-dev \
    clang-format \
    clang-tidy
```

#### Step 2: Install C++ Compiler

```bash
# GCC (default)
sudo apt install -y g++ gcc

# Or Clang
sudo apt install -y clang llvm
```

#### Step 3: Clone Repository

```bash
cd ~/Projects
git clone https://github.com/Sva-Dagger/Embedded-Project.git
cd Embedded-Project
```

#### Step 4: Build Project

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```

#### Step 5: Run Tests

```bash
ctest --output-on-failure
```

### Fedora/RHEL

```bash
sudo dnf install -y \
    gcc-c++ \
    cmake \
    git \
    make \
    clang-tools-extra

# Follow same build steps as Ubuntu
```

### Arch Linux

```bash
sudo pacman -S \
    base-devel \
    cmake \
    git \
    clang

# Follow same build steps as Ubuntu
```

---

## 🍎 macOS Setup

### Step 1: Install Xcode Command Line Tools

```bash
xcode-select --install
```

### Step 2: Install Homebrew (Optional but Recommended)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Step 3: Install Dependencies

```bash
# Using Homebrew
brew install cmake git clang-format

# Or using MacPorts
# sudo port install cmake git clang_select +version13
```

### Step 4: Clone Repository

```bash
cd ~/Projects
git clone https://github.com/Sva-Dagger/Embedded-Project.git
cd Embedded-Project
```

### Step 5: Build Project

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```

### Step 6: Run Tests

```bash
ctest --output-on-failure
```

---

## ✅ Verification

### Verify Installation

Run this to verify your setup:

```bash
# Check CMake version
cmake --version

# Check compiler
g++ --version  # or clang++ --version

# Check Git
git --version
```

### Build and Test

```bash
cd build

# Build all targets
cmake --build .

# Run all tests
ctest --output-on-failure

# View test details
ctest --output-on-failure -V
```

### Expected Output

```
Test project: /path/to/Embedded-Project/build
    Start  1: test_uart_driver
1/3 Test #1: test_uart_driver ................... Passed    0.05 sec
    Start  2: test_gpio_driver
2/3 Test #2: test_gpio_driver ................... Passed    0.03 sec
    Start  3: test_system_integration
3/3 Test #3: test_system_integration ........... Passed    0.07 sec

100% tests passed, 0 tests failed out of 3
```

---

## 🛠️ IDE Configuration

### Visual Studio Code

#### Step 1: Install Extensions

1. C/C++ Extension Pack (Microsoft)
2. CMake Tools (Microsoft)
3. Clang-Format (Xaver Hellauer)

#### Step 2: Configuration File

Create `.vscode/settings.json`:

```json
{
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "cmake.buildDirectory": "${workspaceFolder}/build",
    "cmake.generator": "Unix Makefiles",
    "editor.formatOnSave": true,
    "editor.defaultFormatter": "xaver.clang-format",
    "[cpp]": {
        "editor.defaultFormatter": "xaver.clang-format"
    },
    "C_Cpp.codeAnalysis.enabled": true,
    "C_Cpp.codeAnalysis.runAutomatically": true,
    "C_Cpp.clang_format_path": "/usr/bin/clang-format"
}
```

#### Step 3: Configure CMake

1. Press `Ctrl+Shift+P`
2. Type "CMake: Select a Kit"
3. Choose your compiler (GCC, Clang, or MSVC)
4. Press `Ctrl+Shift+P` and "CMake: Build"

### Visual Studio

#### Step 1: Open Project

1. File → Open → CMake
2. Select `CMakeLists.txt`

#### Step 2: Configure Build

1. CMake → Configure
2. Select toolset (Visual Studio 16 2019, etc.)
3. CMake → Build All

### CLion (JetBrains)

1. File → Open
2. Select project folder
3. CLion will automatically detect CMakeLists.txt
4. Configure CMake profile
5. Build → Build Project

---

## 🐛 Troubleshooting

### CMake Not Found

**Windows:**
```cmd
# Add CMake to PATH manually or reinstall with PATH option
"C:\Program Files\CMake\bin\cmake.exe" --version
```

**Linux/macOS:**
```bash
which cmake
sudo ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake
```

### Compiler Not Found

**Windows:**
```cmd
# Check if MSVC is installed
where cl.exe

# Or use MinGW
cmake .. -G "MinGW Makefiles"
```

**Linux:**
```bash
# Install GCC
sudo apt install build-essential

# Or Clang
sudo apt install clang
```

### Build Errors

#### Error: "CMake Error at CMakeLists.txt:X"

```bash
# Clean and reconfigure
rm -rf build
mkdir build
cd build
cmake ..
```

#### Error: "C++17 not supported"

**Windows:**
```cmd
cmake .. -G "Visual Studio 16 2019" -DCMAKE_CXX_STANDARD=17
```

**Linux/macOS:**
```bash
cmake .. -DCMAKE_CXX_COMPILER=g++-9  # Or newer version
```

#### Error: "Test executable not found"

```bash
# Rebuild
cmake --build . --target all

# Run specific test
ctest --output-on-failure -R test_name
```

### Permission Denied

**Linux/macOS:**
```bash
# If build fails with permission issues
chmod +x ./build/bin/*
```

### Out of Memory During Build

```bash
# Reduce parallel jobs
cmake --build . --parallel 2

# Or on Linux
make -j 2
```

---

## 📊 Development Workflow

### Daily Workflow

```bash
# 1. Pull latest changes
git pull origin main

# 2. Create feature branch
git checkout -b feature/my-feature

# 3. Make changes and build
cd build
cmake --build .

# 4. Run tests
ctest --output-on-failure

# 5. Commit changes
git add .
git commit -m "feat: add new feature"

# 6. Push to remote
git push origin feature/my-feature
```

### Building Different Configurations

```bash
# Debug build (with symbols, no optimization)
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug

# Release build (optimized, no debug info)
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release

# RelWithDebInfo (optimized with debug info)
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
```

---

## 🔄 Updating Development Tools

### Update CMake

**Windows:**
- Download latest from https://cmake.org/download/

**Linux:**
```bash
sudo apt upgrade cmake
```

**macOS:**
```bash
brew upgrade cmake
```

### Update Compiler

**Windows:**
- Use Visual Studio Installer to update MSVC

**Linux:**
```bash
sudo apt install --upgrade g++
```

**macOS:**
```bash
xcode-select --install  # Updates Xcode tools
```

---

## ✨ Tips and Best Practices

1. **Always create feature branches**
   ```bash
   git checkout -b feature/descriptive-name
   ```

2. **Build before committing**
   ```bash
   cmake --build . && ctest --output-on-failure
   ```

3. **Use incremental builds**
   - Only changed files are recompiled
   - Much faster than clean builds

4. **Format code before committing**
   ```bash
   clang-format -i src/**/*.cpp include/**/*.h
   ```

5. **Run static analysis**
   ```bash
   clang-tidy src/main.cpp -- -Iinclude
   ```

---

## 📚 Additional Resources

- [CMake Official Documentation](https://cmake.org/documentation/)
- [C++17 Standard Library](https://en.cppreference.com/w/cpp/17)
- [Embedded C Best Practices](https://barrgroup.com/embedded-systems/books/embedded-c)
- [LLVM Clang Tools](https://clang.llvm.org/)

---

**Last Updated**: 2026-04-29
