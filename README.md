# C++ Practice Problems

This repository contains two beginner-level C++ programs designed to practice basic programming concepts.

## Programs

### 1. Multiplication Table (`multiplication-table/`)
A program that:
- Asks the user for the number of columns
- Asks the user for the number of rows
- Validates that both inputs are positive integers
- Prints a formatted multiplication table of the specified size
- Uses `std::setw` for proper column alignment

**Example usage:**
```
Enter column size: 
Enter row size: 
   1   2   3   4   5
   2   4   6   8  10
   3   6   9  12  15
   4   8  12  16  20
   5  10  15  20  25
```

### 2. Days Since Calculator (`days-since/`)
A program that:
- Asks the user for a target date (year, month, day)
- Retrieves the current date using the `<ctime>` library
- Calculates the number of days between today and the target date
- Displays today's date, the target date, and the days since (negative if the target date is in the future)

**Example usage:**
```
Enter year: 2026
Enter month: 5
Enter day: 1
Today's date: 2026-05-09
Target date: 2026-05-01
Days since target date: 8
```

## Building and Running

Each program can be compiled and run independently:

### Multiplication Table
```bash
cd multiplication-table
g++ main.cpp -o mult
./mult
```

### Days Since Calculator
```bash
cd days-since
g++ main.cpp -o days-since
./days-since
```

## Requirements
- A C++ compiler (e.g., g++)
- Standard C++ libraries

## Notes
- The days since calculator uses noon time for both dates to avoid daylight saving time issues.
- Input validation ensures that only positive integers are accepted for the multiplication table dimensions.
- The executables are not included in the Git repository (only source code is tracked).