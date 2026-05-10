# C++ Practice Problems

## About This Repository & Development Environment

This repository demonstrates the capabilities of the **Nemotron 3 Super 120B** model when running locally with **opencode** on an **NVIDIA RTX Pro 6000 96GB (Founder Edition)**.

Each of the six C++ practice programs in this repository was created with AI-assisted development using:
- **Model**: Nemotron 3 Super 120B (NVIDIA's advanced language model)
- **Development Tool**: opencode (local AI-powered coding assistant)
- **Hardware**: NVIDIA RTX Pro 6000 96GB Founder Edition GPU
  - Memory: 96 GB GDDR6
  - Architecture: Ada Lovelace
  - CUDA Cores: 18176 (verify with `nvidia-smi`)
  - Tensor Cores: 568 (4th generation)
  - Memory Bandwidth: 864 GB/s
  - Display Outputs: 4x DisplayPort 1.4a

This setup showcases how powerful local AI development can be for:
- Learning and practicing programming concepts
- Generating functional code across multiple domains
- Rapid prototyping of educational examples
- Creating well-documented, tested codebases

This repository contains six beginner-to-intermediate level C++ programs designed to practice various programming concepts.

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

### 3. Word Frequency Analyzer (`word-freq/`)
A program that:
- Asks the user for a filename (defaults to sample.txt if not found)
- Reads text and counts word frequencies (case-insensitive, ignoring punctuation)
- Displays words and their frequencies sorted by frequency (highest first)
- Uses unordered_map for counting and vector for sorting
- Includes error handling for file operations

**Example usage:**
```
Enter filename: sample.txt
Top 10 most frequent words:
the (23)
and (19)
to (15)
of (14)
a (12)
```

### 4. Loan Amortization Calculator (`loan-calculator/`)
A program that:
- Asks for loan amount, annual interest rate (percentage), and loan term in years
- Calculates monthly payment using the standard amortization formula
- Displays a detailed amortization schedule showing payment number, beginning balance, payment amount, principal portion, interest portion, and ending balance
- Shows total interest paid over the life of the loan
- Formats currency to 2 decimal places
- Handles edge case of zero interest rate

**Example usage:**
```
Enter loan amount: 200000
Enter annual interest rate (%): 5
Enter loan term (years): 30
Monthly payment: $1073.64
[Amortization schedule displayed...]
Total interest paid: $186511.57
```

### 5. Minesweeper Clone (`minesweeper/`)
A text-based implementation of the classic Minesweeper game that:
- Asks for grid dimensions (rows, columns) and number of mines
- Creates and initializes a game board with mines randomly placed
- Allows the user to make moves by entering coordinates (row, column)
- Reveals selected cells showing numbers (0-8) indicating adjacent mines
- Ends game when a mine is revealed or all non-mine cells are revealed
- Displays board with '.' for unrevealed cells, numbers for revealed cells, and '*' for mines (game over only)
- Includes input validation for all user entries

**Example usage:**
```
Enter rows: 8
Enter columns: 8
Enter number of mines: 10
[Board displayed...]
Enter row and column to reveal: 3 4
[Updated board displayed...]
```

### 6. ASCII Art Generator (`ascii-art/`)
A creative program that generates ASCII art from shapes and text featuring:
- Menu-driven interface with options to draw:
  * Rectangles (specify width, height, character)
  * Triangles (specify size, character)
  * Diamonds (specify size, character)
  * Text-to-ASCII conversion using a simple block font
  * Quit
- All shape options allow custom drawing characters (default '*')
- Text conversion renders input as blocky ASCII art
- Loops until user chooses to quit

**Example usage:**
```
Select option: 1
Enter width: 5
Enter height: 3
Enter character (default *): #
#####
#####
#####
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

### Word Frequency Analyzer
```bash
cd word-freq
g++ main.cpp -o wordfreq
./wordfreq
```

### Loan Amortization Calculator
```bash
cd loan-calculator
g++ main.cpp -o loancalc
./loancalc
```

### Minesweeper Clone
```bash
cd minesweeper
g++ main.cpp -o minesweeper
./minesweeper
```

### ASCII Art Generator
```bash
cd ascii-art
g++ main.cpp -o asciiart
./asciiart
```

## Requirements
- A C++ compiler (e.g., g++ with C++11 support)
- Standard C++ libraries

## Notes
- The days since calculator uses noon time for both dates to avoid daylight saving time issues.
- Input validation ensures that only positive integers are accepted where appropriate.
- The executables are not included in the Git repository (only source code is tracked).
- Each program has been tested and verified to work correctly.