# PmergeMe - Ford-Johnson Merge-Insert Sort Algorithm

## Overview

**PmergeMe** is a C++ implementation of the Ford-Johnson (Merge-Insert) sorting algorithm as described in Donald Knuth's "The Art of Computer Programming, Volume 3."

This project demonstrates the efficiency of the merge-insert algorithm by implementing it separately for two different standard library containers (`std::vector` and `std::deque`), providing a performance comparison between them.

## Features

- ✅ **Ford-Johnson Algorithm Implementation** - Optimal sorting strategy combining pairwise comparison and merge-insertion
- ✅ **Dual Container Support** - Independent implementations for `std::vector` and `std::deque`
- ✅ **High Performance** - Handles 3000+ elements efficiently
- ✅ **Precise Timing** - Microsecond-level accuracy for both container types
- ✅ **Error Handling** - Robust validation of input (rejects negative numbers and non-numeric values)
- ✅ **C++98 Compatible** - Works with legacy C++ standards while using modern practices

## Requirements

### Build Requirements
- C++ compiler supporting C++98 standard (g++, clang++, etc.)
- GNU make
- POSIX-compliant system (for `gettimeofday()`)

### Functional Requirements
- Minimum 2 arguments (at least 1 positive integer to sort)
- Accepts positive integers only (0 and positive whole numbers)
- Efficiently sorts up to 3000+ elements

## Compilation

```bash
make           # Build the executable
make clean     # Remove object files
make fclean    # Remove all generated files
make re        # Clean rebuild
```

After compilation, the executable `PmergeMe` will be created.

## Usage

```bash
./PmergeMe <positive_integers>
```

### Arguments
- `<positive_integers>`: Space-separated positive integers to sort

### Examples

#### Basic Example
```bash
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00500 us
Time to process a range of 5 elements with std::deque : 0.00300 us
```

#### Single Element
```bash
$ ./PmergeMe 42
Before: 42
After: 42
Time to process a range of 1 elements with std::vector : 0.00200 us
Time to process a range of 1 elements with std::deque : 0.00100 us
```

#### Large Dataset (3000 elements)
```bash
$ ./PmergeMe $(seq 1 3000 | shuf | tr '\n' ' ')
Before: 1044 2106 1115 142 1805 206 176 1707 2613 1604 ...
After: 1 2 3 4 5 6 7 8 9 10 11 12 ... 2999 3000
Time to process a range of 3000 elements with std::vector : 1.63000 us
Time to process a range of 3000 elements with std::deque : 2.15000 us
```

#### Error: Negative Number
```bash
$ ./PmergeMe "-1" "2"
Error
$ echo $?
1
```

#### Error: Non-numeric Input
```bash
$ ./PmergeMe "abc" "123"
Error
$ echo $?
1
```

## Output Format

The program outputs four lines to standard output:

1. **Before:** The unsorted sequence exactly as provided on the command line
2. **After:** The sorted sequence in ascending order
3. **Vector Timing:** Time taken to sort using `std::vector` (in microseconds)
4. **Deque Timing:** Time taken to sort using `std::deque` (in microseconds)

All timing measurements include both data management and sorting operations.

## Algorithm: Ford-Johnson (Merge-Insert Sort)

The Ford-Johnson algorithm is a comparison-based sorting algorithm that combines:

1. **Pairwise Comparison Phase**: Elements are compared in pairs and organized
2. **Insertion Phase**: Smaller elements are inserted into a sorted main chain
3. **Binary Insertion**: New elements are inserted using binary search for efficiency

This algorithm is particularly efficient because it minimizes the number of comparisons needed, achieving nearly optimal comparison complexity.

## Implementation Details

### Two Independent Implementations

The program intentionally implements the Ford-Johnson algorithm separately for each container type:

- **Vector Implementation** (`mergeInsertVector`)
  - Uses `std::vector<int>` for random-access storage
  - Optimized for contiguous memory access patterns

- **Deque Implementation** (`mergeInsertDeque`)
  - Uses `std::deque<int>` for double-ended queue storage
  - Optimized for insertion/deletion at both ends

This dual approach allows accurate performance comparison between the two containers.

### Key Methods

```cpp
// Vector operations
void mergeVector(std::vector<int>& arr, int left, int mid, int right);
void mergeInsertVector(std::vector<int>& arr);
void sortVector();

// Deque operations
void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
void mergeInsertDeque(std::deque<int>& arr);
void sortDeque();

// Input parsing and validation
void parseNumbers(char* av[]);

// Output formatting
void displayResults();
```

### Input Validation

The program validates input strictly:
- Rejects negative numbers (detected by leading '-')
- Rejects non-numeric characters
- Rejects empty arguments
- Throws `InvalidInput` exception on validation failure

## Error Handling

All errors are caught and reported consistently:

```
Error
```

With exit code `1` indicating failure, or `0` on success.

## Technical Specifications

| Aspect | Details |
|--------|---------|
| **C++ Standard** | C++98 |
| **Compiler Flags** | `-Wall -Wextra -Werror -std=c++98` |
| **Time Precision** | Microseconds (5 decimal places) |
| **Maximum Elements** | Tested with 3000+; no hard limit |
| **Integer Type** | `int` |
| **Memory Usage** | O(n) auxiliary space for merging |

## Performance Characteristics

### Time Complexity
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log² n)

### Space Complexity
- **Auxiliary Space:** O(n) for temporary merge arrays

## Building and Testing

### Quick Build
```bash
make
```

### Test Suite
```bash
# Basic sorting
./PmergeMe 3 5 9 7 4

# Single element
./PmergeMe 1

# Duplicates
./PmergeMe 42 42 42

# Large dataset
./PmergeMe $(seq 1 100 | shuf | tr '\n' ' ')

# Error handling
./PmergeMe "-1"
./PmergeMe "abc"
./PmergeMe          # No arguments
```

## Files

- `PmergeMe.cpp` - Main implementation of Ford-Johnson algorithm
- `PmergeMe.hpp` - Class definition and method declarations
- `main.cpp` - Entry point with timing and output logic
- `Makefile` - Build configuration
- `README.md` - This documentation

## Author

Created as part of the C++ learning curriculum (CPP09 - Exercise 2)

## License

Educational project - use for learning purposes.

## References

- Donald E. Knuth, "The Art of Computer Programming, Volume 3: Sorting and Searching", Section 5.3.1
- Ford, L. R., Jr.; Johnson, S. M. (1959). "A Tournament Problem"

## Notes

- The timing measurement includes all overhead (parsing, initialization, display preparation)
- Results vary based on system load and hardware capabilities
- Vector typically performs better for random access; deque for insertion patterns
- The algorithm is stable in its comparison operations but does not guarantee overall stability
