
# Stack Library (C++)

A modern, header-based **generic Stack implementation** written in C++.
Designed with clean architecture, iterators, and unit tests.

## ✨ Features
- Template-based (generic)
- Dynamic array implementation
- Iterator support (LIFO order)
- Range-based for loop compatible
- Exception-safe
- Unit tested
- CMake build system
- CI with GitHub Actions

## 📦 Project Structure

```
stack/
├── stack.h        # Public interface
├── stack.tpp      # Template implementation
├── tests.cpp      # Unit tests
└── CMakeLists.txt

````

## 🚀 Usage

```cpp
#include "stack.h"

Stack<int> s;
s.push(10);
s.push(20);
s.push(30);

for (int x : s) {
    std::cout << x << " ";
}
// Output: 30 20 10
````

## 🧪 Running Tests

```bash
cmake -B build
cmake --build build
./build/stack_tests
```

## ⚙️ Requirements

* C++17 or newer
* CMake ≥ 3.20

## 📜 License

This project is licensed under the MIT License.

