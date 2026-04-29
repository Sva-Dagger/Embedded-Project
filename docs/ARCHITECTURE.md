# Architecture Overview

## 🏗️ System Architecture

The Embedded-Project follows a layered architecture design pattern, ensuring clear separation of concerns and maintainability.

```
┌─────────────────────────────────────┐
│       Application Layer             │
│    (User Application Code)          │
└────────────────┬────────────────────┘
                 │
┌────────────────▼────────────────────┐
│         Core Modules                │
│   (Business Logic, Algorithms)      │
└────────────────┬────────────────────┘
                 │
┌────────────────▼────────────────────┐
│       Device Drivers                │
│  (Peripheral Interfaces)            │
└────────────────┬────────────────────┘
                 │
┌────────────────▼────────────────────┐
│   Hardware Abstraction Layer        │
│      (HAL - Low-level I/O)          │
└────────────────┬────────────────────┘
                 │
┌────────────────▼────────────────────┐
│        Hardware/Firmware            │
└─────────────────────────────────────┘
```

## 📁 Directory Organization

```
Embedded-Project/
├── include/                    # Public headers
│   ├── core/                   # Core module interfaces
│   ├── drivers/                # Driver interfaces
│   ├── hal/                    # HAL interfaces
│   └── utils/                  # Utility interfaces
├── src/                        # Implementation
│   ├── core/                   # Core implementations (C++)
│   ├── drivers/                # Driver implementations (C++/C)
│   ├── hal/                    # HAL implementations (C)
│   ├── utils/                  # Utility implementations (C++/C)
│   └── main.cpp                # Entry point
├── test/                       # Test suite
│   ├── unit/                   # Unit tests
│   └── integration/            # Integration tests
├── docs/                       # Documentation
│   ├── API.md                  # API reference
│   ├── ARCHITECTURE.md         # This file
│   └── SETUP.md                # Setup guide
└── tools/                      # Build tools & scripts
```

## 🔄 Layer Descriptions

### Application Layer (C++)
- **Purpose**: High-level application logic
- **Language**: C++ (Object-Oriented)
- **Responsibilities**:
  - Main application flow
  - User interactions
  - Business logic
- **Example**:
  ```cpp
  class Application {
  public:
      void run();
      void handleEvent(const Event& event);
  };
  ```

### Core Modules (C++)
- **Purpose**: Core functionality and algorithms
- **Language**: Primarily C++
- **Responsibilities**:
  - State machines
  - Event handling
  - Complex algorithms
  - Data structures
- **Naming**: Use camelCase
- **Example**:
  ```cpp
  class StateManager {
  public:
      void update();
      void setState(State newState);
  };
  ```

### Device Drivers (C++/C)
- **Purpose**: Control and manage hardware peripherals
- **Language**: Mixed C++ and C
- **Responsibilities**:
  - UART, SPI, I2C communication
  - GPIO control
  - Timer management
  - Interrupt handling
- **Example**:
  ```cpp
  class UARTDriver {
  public:
      bool initialize(uint32_t baudRate);
      void transmit(const uint8_t* data, size_t length);
  };
  ```

### Hardware Abstraction Layer (C)
- **Purpose**: Isolate hardware-specific details
- **Language**: C (C99 standard)
- **Responsibilities**:
  - Register manipulation
  - Direct hardware access
  - Microcontroller-specific operations
  - Low-level I/O
- **Naming**: Use snake_case
- **Example**:
  ```c
  typedef struct {
      uint32_t base_address;
      uint32_t clock_enable_mask;
  } hal_uart_config_t;

  hal_status_t hal_uart_init(const hal_uart_config_t* config);
  void hal_uart_send_byte(uint8_t byte);
  ```

## 🔌 Interface Design

### Driver Interface Pattern

```cpp
// include/drivers/uart_driver.h
class UARTDriver {
public:
    virtual ~UARTDriver() = default;
    virtual bool initialize(uint32_t baudRate) = 0;
    virtual void transmit(const uint8_t* data, size_t length) = 0;
    virtual size_t receive(uint8_t* data, size_t maxLength) = 0;
};

// src/drivers/uart_driver.cpp
class UARTDriverImpl : public UARTDriver {
public:
    bool initialize(uint32_t baudRate) override;
    void transmit(const uint8_t* data, size_t length) override;
    size_t receive(uint8_t* data, size_t maxLength) override;
};
```

### Module Interface Pattern

```cpp
// include/core/state_manager.h
class StateManager {
public:
    enum class State { IDLE, RUNNING, ERROR };
    
    void update();
    State getCurrentState() const;
    void setState(State newState);
    
private:
    void onEnterState(State state);
    void onExitState(State state);
};
```

## 🔗 Communication Flow

### Example: UART Data Reception

```
Hardware Interrupt
    ↓
hal_uart_interrupt_handler() [C]
    ↓
UARTDriver::onDataReceived() [C++]
    ↓
StateManager::handleData() [C++]
    ↓
Application::processData() [C++]
```

## 🧩 Design Patterns

### 1. Observer Pattern
For event handling between modules:
```cpp
class EventBus {
public:
    void subscribe(Observer* observer);
    void publish(const Event& event);
};
```

### 2. State Machine
For complex behavior management:
```cpp
class StateMachine {
    virtual void onEnter() {}
    virtual void onExit() {}
    virtual void update() {}
};
```

### 3. Singleton
For hardware resources (use cautiously):
```cpp
class HardwareManager {
public:
    static HardwareManager& getInstance();
private:
    HardwareManager() = default;
};
```

## 📋 Coding Conventions

### C++ (72.4% of project)
- **Naming**: `camelCase` for variables/functions, `PascalCase` for classes
- **Files**: `.cpp` for implementation, `.h`/`.hpp` for headers
- **Include Guards**: `#ifndef` pattern
- **Namespaces**: Organize related classes
  ```cpp
  namespace drivers {
      class UARTDriver { };
  }
  ```

### C (27.6% of project)
- **Naming**: `snake_case` for all identifiers
- **Files**: `.c` for implementation, `.h` for headers
- **Typedef Structs**: Use `_t` suffix
  ```c
  typedef struct {
      uint32_t field;
  } hal_config_t;
  ```
- **Type Prefixes**: Use for clarity
  ```c
  #define GPIO_PIN_0 0
  #define GPIO_PORT_A 0
  ```

## 🔒 Memory Management

### Guidelines
- Use stack allocation when possible
- For dynamic allocation: use RAII in C++
- In C: pair `malloc`/`free` carefully
- Embedded systems: pre-allocate buffers
- Document buffer sizes and ownership

### Example
```cpp
// Good: Stack allocated
std::array<uint8_t, 256> buffer;

// Acceptable: Dynamic with RAII
std::unique_ptr<uint8_t[]> buffer(new uint8_t[size]);

// Avoid in embedded: Unbounded allocation
uint8_t* buffer = new uint8_t[dynamicSize];
```

## 🧪 Testing Architecture

### Unit Tests
- Test individual functions/classes in isolation
- Use mocks for dependencies
- Located in `test/unit/`

### Integration Tests
- Test multiple modules together
- Verify interfaces between layers
- Located in `test/integration/`

## 📈 Future Enhancements

- [ ] Add power management module
- [ ] Implement wireless communication layer
- [ ] Add real-time OS support
- [ ] Extend HAL for additional microcontrollers
- [ ] Performance profiling tools

## 📚 References

- [Embedded C Best Practices](https://barrgroup.com/embedded-systems/books/embedded-c)
- [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines)
- [Design Patterns](https://en.wikipedia.org/wiki/Software_design_pattern)
- [Microcontroller Documentation](https://www.st.com/en/microcontrollers)

---

**Last Updated**: 2026-04-29
