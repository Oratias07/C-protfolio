# C Programming Portfolio

A collection of C programs developed during **Introductory Systems Programming** coursework at Braude College of Engineering, demonstrating proficiency in data structures, memory management, and systems programming concepts.

## 📁 Repository Structure

```
programs/
├── JumpingGame/                # Interactive doubly-linked list traversal game
├── LinkedListsBasics/          # Linked list fundamentals
├── LinkedListsAdvanced/        # Advanced list operations and recursion
├── GenericProgramming/         # Generic programming with void pointers
└── StackImplementations/       # Stack ADT implementations
```

## 🎮 Programs Overview

### Jumping Game (`JumpingGame/`)
**Interactive Linked List Game**

A game built on a doubly-linked list where players navigate between nodes based on step values. Demonstrates:
- Dynamic memory allocation
- Doubly-linked list implementation
- Pointer manipulation
- Game state management

**Files:**
- `main.c` - Main game loop and initialization
- `game.c` - Core game logic functions
- `game.h` - Structure definitions and function declarations

---

### LinkedListsBasics

#### `linked_list.c` - Basic Linked List Implementation
Creates and manages a simple singly-linked list with:
- Dynamic node creation
- User input handling
- List traversal and display
- Proper memory deallocation

#### `student_manager.c` - Student Management System
File-based student record management with:
- Reading structured data from files (`List.txt`, `List1.txt`)
- Dynamic string allocation
- Average grade calculation
- Finding and removing records
- Linked list manipulation

**Concepts:** File I/O, string handling, struct manipulation

---

### LinkedListsAdvanced

#### `list_partitioning.c` - List Partitioning
Separates integers from a file into positive and negative sublists:
- Multiple list management
- Conditional node transfer
- Head/tail pointer tracking
- File parsing

**Input:** `ThreeLists.txt`

#### `recursive_list.c` - Recursive List Operations
Demonstrates recursive programming on linked lists:
- Recursive list traversal
- Recursive length calculation
- Recursive display
- Array-to-list conversion

**Concepts:** Recursion, function pointers, list construction

---

### GenericProgramming

#### `pair_sum.c`, `pair_sum_v2.c`, `pair_sum_v3.c` - Void Pointer Arithmetic
Implements type-agnostic pair-sum search using:
- `void*` pointers for generic data
- Function pointers for type-specific operations
- Type casting and dereferencing
- Bool enumeration

**Features:**
- Works with both `int` and `float` arrays
- Generic sum-finding algorithm
- Demonstrates C polymorphism patterns
- Multiple implementations showing evolution of approach

---

### StackImplementations

Multiple stack implementations showcasing different design approaches:

#### `LinkedListStack/` - Linked List-Based Stack
Standard stack operations using linked list nodes
- **Files:** `main.c`, `stack.c`, `stack.h`

#### `ArrayBasedStack/` - Array-Based Stack with Dynamic Resizing
Enhanced stack with:
- Dynamic resizing
- Overflow/underflow handling
- Size tracking
- **Files:** `main.c`, `stack.c`, `stack.h`

#### `StackVariant/` - Alternative Stack Implementation
Variant design with different implementation strategy
- **Files:** `main.c`, `stack.c`, `stack.h`

#### `StackADT/` - Full Abstract Data Type Implementation
Professional-grade ADT with complete encapsulation:
- Modular design (separate interface/implementation)
- Opaque pointers
- API-based access
- **Files:** `main.c`, `stack.c`, `stack.h`

**Concepts:** ADT design, separation of interface/implementation, modular programming, progressive complexity

---

## 🛠️ Technical Highlights

### Core Competencies Demonstrated
- **Data Structures:** Singly/doubly-linked lists, stacks (array-based)
- **Memory Management:** Dynamic allocation, proper deallocation, memory leak prevention
- **File I/O:** Reading structured data, parsing text files
- **Advanced C:** Function pointers, void pointers, generic programming
- **Recursion:** Recursive list operations, recursive algorithms
- **Modular Programming:** Header files, multi-file projects, ADT design

### Best Practices
- Consistent error handling
- Memory leak prevention
- Defensive programming
- Code documentation
- Modular architecture

---

## 🚀 Compilation & Execution

### General Compilation
```bash
gcc program.c -o program
./program
```

### Multi-file Projects (e.g., JumpingGame)
```bash
cd programs/JumpingGame
gcc main.c game.c -o jumping_game
./jumping_game
```

### Stack Implementations
```bash
cd programs/StackImplementations/ArrayBasedStack
gcc main.c stack.c -o stack
./stack
```

---

## 📝 Notes

- All programs use C89/C99 standards
- Input files (`.txt`) are expected in the same directory as executables
- Programs include input validation and error handling
- `_CRT_SECURE_NO_WARNINGS` used for MSVC compatibility

---

## 📚 Course Context

**Course:** Introductory Systems Programming  
**Institution:** Braude College of Engineering  
**Focus Areas:**
- Procedural programming in C
- Systems-level thinking
- Manual memory management
- Data structure implementation
- Algorithm design

---

## 🔄 Recent Restructuring

The repository has been professionally reorganized for clarity:
- ✅ `JampingGame/` → `JumpingGame/` (typo fix)
- ✅ `lab10/` → `LinkedListsBasics/`
- ✅ `lab11/` → `LinkedListsAdvanced/`
- ✅ `lab12/` → `GenericProgramming/`
- ✅ `lab13/` → `StackImplementations/`

**File naming standardized:**
- Generic names like `lab10_1.c` → Descriptive names like `linked_list.c`
- Stack implementations: `lab13_1/` → `LinkedListStack/` (with `main.c`, `stack.c`, `stack.h`)
- Game files: `JGmain.c`, `JGfunc.c`, `JGheader.h` → `main.c`, `game.c`, `game.h`

---

## 📄 License

Educational project - Braude College of Engineering

---

**Author:** Braude College Student  
**Year:** 2024-2025  
**Language:** C