
# UMBC Puzzle Management System

## Overview
The UMBC Puzzle Management System is a C++ application designed to create, manipulate, and test puzzle grids. It supports operations such as appending grids, recreating grids, and filling grids with random characters. The project also includes a robust testing framework to ensure the correctness of implemented features.

## Features
- **Dynamic Grid Creation**: Create puzzle grids with a specified number of rows and columns.
- **Grid Manipulation**:
  - Append grids horizontally or vertically.
  - Recreate grids with new dimensions and random values.
- **Testing Framework**: A comprehensive tester class verifies the correctness of constructors, copy operations, append operations, and more.
- **Random Value Generation**: Grids are filled with random characters, ensuring variety and testing flexibility.

## Files
### Source Files
- **`puzzle.cpp` & `puzzle.h`**:
  - Implements the `Puzzle` class, which provides methods for creating, manipulating, and managing puzzle grids.
- **`mytest.cpp`**:
  - Contains the `Tester` class, which includes various test functions to validate the functionality of the `Puzzle` class.
- **`puzzle.h`**:
  - Includes definitions for the `Puzzle` and `Random` classes, as well as constants and helper functions.

## Installation
1. **Ensure all files are in the same directory**.
2. Compile the application using a C++ compiler:
   ```bash
   g++ -o puzzle_system puzzle.cpp mytest.cpp
   ```
3. Run the application:
   ```bash
   ./puzzle_system
   ```

## How to Use
### Grid Creation
- Create a puzzle grid by specifying the number of rows and columns. For example:
  ```cpp
  Puzzle grid(10, 12);
  ```
- Fill the grid with random values using a seed:
  ```cpp
  grid.fill(seed);
  ```

### Grid Manipulation
- **Append Right**:
  - Horizontally append one grid to another:
    ```cpp
    grid1.appendRight(grid2);
    ```
- **Append Bottom**:
  - Vertically append one grid to another:
    ```cpp
    grid1.appendBottom(grid2);
    ```
- **Recreate Grid**:
  - Recreate a grid with new dimensions and random values:
    ```cpp
    grid.reCreate(rows, cols, seed);
    ```

### Testing
- Run the test suite in `mytest.cpp` to validate grid operations:
  - Constructor tests.
  - Copy and assignment operator tests.
  - Append operations tests (normal and edge cases).
  - Recreate operation tests.

### Example Output
- Example grid dump after creation:
  ```
     01 02 03 04 05
  01 a  b  c  d  e
  02 f  g  h  i  j
  03 k  l  m  n  o
  ```
- Example test output:
  ```
  Testing Copy Constructor (normal case): Passed!
  Testing Append Right Normal Case: Passed!
  ```

## Dependencies
- Standard C++ libraries:
  - `<iostream>`
  - `<algorithm>`
  - `<random>`
  - `<ctime>`
  - `<cmath>`

## Classes and Functions
### `Puzzle`
- **Dynamic Grid Management**: Create and manipulate 2D character grids.
- **Key Methods**:
  - `reCreate(int rows, int cols, int seed)`: Recreate a grid with new dimensions and random values.
  - `appendRight(const Puzzle& rhs)`: Append another grid horizontally.
  - `appendBottom(const Puzzle& rhs)`: Append another grid vertically.
  - `fill(int seed)`: Fill the grid with random characters.
  - `dump()`: Print the grid to the console.

### `Tester`
- **Testing Framework**: Verifies the correctness of the `Puzzle` class.
- **Key Test Functions**:
  - `testCopyConstructorNormal(const Puzzle& puzzle)`: Tests deep copy functionality.
  - `testAppendRightNormalCase()`: Tests appending grids horizontally.
  - `testAppendBottomNormalCase()`: Tests appending grids vertically.
  - `testConstructorNormalCase()`: Tests normal constructor behavior.

### `Random`
- **Random Value Generator**: Generates random integers or real numbers for filling grids.
- **Key Methods**:
  - `getRandNum()`: Generate a random integer.
  - `getRealRandNum()`: Generate a random real number.

## Notes
- Minimum grid dimensions are 10x10. Attempting to create smaller grids will result in default sizes.
- Ensure proper memory management to avoid leaks when manipulating grids.

## Author
- **UMBC CMSC 341**: Ashraf Kawooya
- **Semester**: Spring 2024

## License
This project is for educational purposes and does not include any warranty or guarantee.
