# Embedded-Project

A professional embedded systems project written in C++ and C.

## 📋 Table of Contents

- [Project Overview](#project-overview)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Build Instructions](#build-instructions)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Project Overview

This embedded systems project combines C++ and C code for embedded applications. The project is organized with separation of concerns to maintain clean architecture and ease of maintenance.

**Language Composition:**
- C++: 72.4%
- C: 27.6%

## 📁 Project Structure

```
Embedded-Project/
├── src/                          # Source code
│   ├── core/                     # Core functionality
│   ├── drivers/                  # Hardware drivers
│   ├── hal/                      # Hardware Abstraction Layer
│   ├── utils/                    # Utility functions
│   └── main.cpp                  # Application entry point
├── include/                      # Header files
│   ├── core/
│   ├── drivers/
│   ├── hal/
│   └── utils/
├── test/                         # Unit tests
│   ├── unit/
│   └── integration/
├── docs/                         # Documentation
│   ├── API.md
│   ├── ARCHITECTURE.md
│   └── SETUP.md
├── tools/                        # Build tools and scripts
├── CMakeLists.txt                # Build configuration
├── .gitignore                    # Git ignore rules
└── README.md                     # This file
```

## 🚀 Getting Started

### Prerequisites

- CMake 3.15 or higher
- C++ compiler (C++17 or later)
- C compiler (C99 or later)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/Sva-Dagger/Embedded-Project.git
cd Embedded-Project
```

2. Create a build directory:
```bash
mkdir build && cd build
```

3. Configure and build:
```bash
cmake ..
cmake --build .
```

## 🔨 Build Instructions

### Debug Build
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

### Release Build
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Run Tests
```bash
cd build
ctest
```

## 📝 Contributing

1. Create a feature branch (`git checkout -b feature/AmazingFeature`)
2. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
3. Push to the branch (`git push origin feature/AmazingFeature`)
4. Open a Pull Request

### Code Style Guidelines

- Follow embedded systems best practices
- Document all public APIs
- Include unit tests for new functionality
- Keep functions focused and modular

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

**Last Updated:** 2026-04-29
