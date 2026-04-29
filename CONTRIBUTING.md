# Contributing to Embedded-Project

Thank you for your interest in contributing to the Embedded-Project! This document provides guidelines and instructions for contributing.

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Process](#development-process)
- [Coding Standards](#coding-standards)
- [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)
- [Testing Requirements](#testing-requirements)
- [Documentation Requirements](#documentation-requirements)

---

## 🤝 Code of Conduct

We are committed to providing a welcoming and inclusive environment. All contributors are expected to:

- Be respectful and professional
- Welcome diverse perspectives
- Focus on constructive feedback
- Follow these contributing guidelines

---

## 🚀 Getting Started

### 1. Fork and Clone

```bash
# Fork the repository on GitHub
# Clone your fork
git clone https://github.com/YOUR_USERNAME/Embedded-Project.git
cd Embedded-Project

# Add upstream remote
git remote add upstream https://github.com/Sva-Dagger/Embedded-Project.git
```

### 2. Set Up Development Environment

```bash
# Follow setup guide
# See: docs/SETUP.md

# Create build directory
mkdir build && cd build

# Configure project
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build .
```

### 3. Verify Build

```bash
# Run tests
ctest --output-on-failure

# Expected: All tests pass
```

---

## 🔄 Development Process

### Step 1: Create Feature Branch

```bash
# Update main branch
git fetch upstream
git rebase upstream/main

# Create feature branch with descriptive name
git checkout -b feature/short-description
# or
git checkout -b fix/issue-number
# or
git checkout -b docs/documentation-update
```

### Branch Naming Convention

- `feature/feature-name` - New features
- `fix/issue-name` - Bug fixes
- `docs/doc-name` - Documentation
- `refactor/refactor-name` - Code refactoring
- `test/test-name` - Test additions
- `chore/task-name` - Build, CI/CD, dependencies

### Step 2: Make Changes

```bash
# Edit files
# Keep changes focused and atomic

# Build locally
cmake --build build

# Run tests
cd build && ctest --output-on-failure
```

### Step 3: Commit Changes

See [Commit Guidelines](#commit-guidelines)

### Step 4: Push to Fork

```bash
git push origin feature/your-feature-name
```

### Step 5: Create Pull Request

See [Pull Request Process](#pull-request-process)

---

## 📝 Coding Standards

### C++ Code Style

#### Naming Conventions

```cpp
// Classes: PascalCase
class UARTDriver {
};

// Functions/Methods: camelCase
void transmitData() {
}

// Variables: camelCase
int dataLength = 0;
uint8_t* dataBuffer = nullptr;

// Constants: UPPER_SNAKE_CASE
constexpr int MAX_BUFFER_SIZE = 256;
#define DEFAULT_BAUD_RATE 115200

// Private members: leading underscore
class MyClass {
private:
    int _internalValue;
};
```

#### Code Formatting

```cpp
// Indentation: 4 spaces (no tabs)
void function() {
    if (condition) {
        statement();
    }
}

// Line length: Max 100 characters
// Break long lines appropriately
auto result = someFunction(param1, param2,
                           param3, param4);

// Braces: Opening brace on same line
void function() {
    // code
}

// Spaces around operators
int result = a + b;
if (x > 0) {
}

// One space after keywords
if (condition) {
}
for (int i = 0; i < count; ++i) {
}
```

#### Comments

```cpp
// Single line comment for brief explanations
int value = 0;

// Multi-line comment for complex logic
/*
 * This function performs complex operation.
 * It handles multiple states and edge cases.
 */

// Doxygen-style documentation
/**
 * Initializes the UART driver.
 *
 * @param baudRate The baud rate in bits per second
 * @return true if initialization successful, false otherwise
 */
bool initialize(uint32_t baudRate);

// TODO comments for future work
// TODO: Implement timeout mechanism
```

#### Function/Class Organization

```cpp
class MyDriver {
public:
    // Constructors/Destructors
    MyDriver();
    ~MyDriver();
    
    // Public interface
    bool initialize();
    void process();
    
protected:
    // Protected members
    void internalFunction();
    
private:
    // Private implementation
    void privateMethod();
    int _privateData;
};
```

### C Code Style

#### Naming Conventions

```c
// Functions: snake_case with module prefix
hal_status_t hal_uart_init(const hal_uart_config_t* config);
void hal_uart_send_byte(uint8_t byte);

// Structures: snake_case with _t suffix
typedef struct {
    uint32_t base_address;
    uint32_t clock_mask;
} hal_uart_config_t;

// Enumerations
typedef enum {
    GPIO_PIN_0 = 0,
    GPIO_PIN_1 = 1,
} gpio_pin_t;

// Constants/Defines: UPPER_SNAKE_CASE
#define HAL_TIMEOUT_MS 1000
#define UART_BUFFER_SIZE 256
```

#### Formatting

```c
// Same indentation as C++ (4 spaces)
void function(int parameter) {
    if (parameter > 0) {
        // code
    }
}

// Pointer styling
uint8_t* buffer = malloc(256);
const char* message = "text";
```

### General Standards

#### Header Guard

```cpp
// include/drivers/uart_driver.h
#ifndef UART_DRIVER_H
#define UART_DRIVER_H

// Contents

#endif
```

#### Include Organization

```cpp
// 1. System headers
#include <iostream>
#include <vector>
#include <memory>

// 2. Project headers
#include "hal/hal.h"
#include "drivers/uart_driver.h"
#include "utils/logger.h"
```

#### Memory Management

```cpp
// Prefer stack allocation
std::array<uint8_t, 256> buffer;

// Use smart pointers in C++
std::unique_ptr<uint8_t[]> dynamicBuffer(new uint8_t[size]);
std::shared_ptr<Driver> driver = std::make_shared<DriverImpl>();

// In C: clear malloc/free pairs
uint8_t* buffer = (uint8_t*)malloc(size);
// ...
free(buffer);
buffer = NULL;
```

---

## 📌 Commit Guidelines

### Commit Message Format

```
<type>(<scope>): <subject>

<body>

<footer>
```

### Type

- `feat`: A new feature
- `fix`: A bug fix
- `docs`: Documentation only changes
- `style`: Changes that don't affect code meaning (formatting, etc.)
- `refactor`: Code change without feature or bug fix
- `test`: Adding or updating tests
- `chore`: Changes to build process, dependencies, etc.

### Subject

- Use imperative mood ("add" not "added")
- Don't capitalize first letter
- No period at end
- Limit to 50 characters

### Body

- Explain what and why, not how
- Wrap at 72 characters
- Separate from subject with blank line

### Examples

```
feat(uart): add timeout support for receive operations

Add configurable timeout for UART receive to prevent blocking.
Implements exponential backoff for retries.

Fixes #123
```

```
fix(gpio): correct pin mapping for GPIO port B

The previous implementation used incorrect register offsets
for GPIO port B, causing pin 16-31 to be unresponsive.

Tested on STM32F4 microcontroller.
```

```
docs(api): update UART driver documentation with examples
```

---

## 🔀 Pull Request Process

### Before Submitting

1. **Update main branch**
   ```bash
   git fetch upstream
   git rebase upstream/main
   ```

2. **Run tests**
   ```bash
   ctest --output-on-failure
   ```

3. **Check code style**
   ```bash
   clang-format -i src/**/*.cpp include/**/*.h
   clang-tidy src/main.cpp
   ```

4. **Build release**
   ```bash
   cmake .. -DCMAKE_BUILD_TYPE=Release
   cmake --build . --config Release
   ```

### PR Description Template

```markdown
## Description
Brief description of changes.

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Breaking change
- [ ] Documentation update

## Related Issues
Fixes #(issue number)

## Testing
Describe testing performed.

## Checklist
- [ ] Code follows style guidelines
- [ ] Self-review completed
- [ ] Comments added for complex logic
- [ ] Documentation updated
- [ ] Tests added/updated
- [ ] All tests pass
- [ ] No new warnings

## Screenshots (if applicable)
```

### Review Process

1. Wait for code review
2. Address feedback promptly
3. Push updates (don't rebase after review starts)
4. Request re-review after updates
5. Merge when approved

---

## 🧪 Testing Requirements

### Unit Tests

All new features must include unit tests:

```cpp
// test/unit/test_uart_driver.cpp
#include <gtest/gtest.h>
#include "drivers/uart_driver.h"

class UARTDriverTest : public ::testing::Test {
protected:
    UARTDriverImpl driver;
};

TEST_F(UARTDriverTest, InitializeSuccess) {
    EXPECT_TRUE(driver.initialize(115200));
}

TEST_F(UARTDriverTest, TransmitData) {
    uint8_t data[] = {0x01, 0x02, 0x03};
    EXPECT_NO_THROW(driver.transmit(data, 3));
}
```

### Test Coverage

- Minimum 80% code coverage for new code
- All error paths tested
- Edge cases covered

### Running Tests

```bash
# Run all tests
ctest --output-on-failure

# Run specific test
ctest -R test_name --output-on-failure

# With verbose output
ctest --output-on-failure -V

# Generate coverage report
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON
cmake --build .
ctest
```

---

## 📚 Documentation Requirements

### Code Documentation

Every public function must have Doxygen-style documentation:

```cpp
/**
 * Initializes the UART interface.
 *
 * Configures the hardware and sets up internal buffers.
 *
 * @param baudRate Baud rate (9600, 19200, or 115200)
 * @return true if successful, false on error
 *
 * @note Must be called before other UART operations
 * @see receive(), transmit()
 */
bool initialize(uint32_t baudRate);
```

### API Documentation

Update relevant API documentation in `docs/API.md`

### README Updates

If adding new features, update `README.md` with:
- Feature description
- Basic usage example
- Link to detailed documentation

### Changelog

Update `CHANGELOG.md` (if exists) with:
- Type of change
- Brief description
- Related issue numbers

---

## 🐛 Bug Reports

### Report Issues

When reporting bugs, include:

1. **Description**: Clear explanation of the bug
2. **Steps to Reproduce**: Detailed reproduction steps
3. **Expected Behavior**: What should happen
4. **Actual Behavior**: What actually happened
5. **Environment**:
   - OS and version
   - Compiler and version
   - Build type (Debug/Release)
6. **Logs/Output**: Error messages or stack traces
7. **Screenshots**: Visual evidence if applicable

### Example

```markdown
## Description
UART transmission fails when buffer contains null bytes

## Steps to Reproduce
1. Initialize UART at 115200 baud
2. Create buffer with null byte: [0x01, 0x00, 0x03]
3. Call transmit()

## Expected
All 3 bytes transmitted

## Actual
Only first byte transmitted, transmission stops at null

## Environment
- OS: Ubuntu 22.04
- Compiler: GCC 11.2
- Build: Debug
```

---

## ✅ Checklist for Contributors

Before submitting PR, verify:

- [ ] Branch created from `main`
- [ ] Descriptive branch name
- [ ] Code follows style guidelines
- [ ] No compiler warnings
- [ ] Tests written and passing
- [ ] Code coverage maintained
- [ ] Documentation updated
- [ ] Commit messages follow guidelines
- [ ] PR description is clear
- [ ] No merge conflicts

---

## 🔗 Additional Resources

- [CMake Documentation](https://cmake.org/documentation/)
- [C++17 Reference](https://en.cppreference.com/w/cpp/17)
- [C99 Standard](https://en.cppreference.com/w/c)
- [Doxygen Documentation](https://www.doxygen.nl/)
- [Git Workflow](https://git-scm.com/book/en/v2)

---

## 📞 Questions?

- Check existing issues: [Issues](https://github.com/Sva-Dagger/Embedded-Project/issues)
- Review documentation: [docs/](./docs/)
- Ask in discussions: [Discussions](https://github.com/Sva-Dagger/Embedded-Project/discussions)

---

**Thank you for contributing!** 🎉

**Last Updated**: 2026-04-29
