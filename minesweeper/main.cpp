#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

struct Cell {
    bool isMine;
    bool revealed;
    int adjacentMines;
};

void initializeBoard(std::vector<std::vector<Cell>>& board, int rows, int cols, int mineCount) {
    board.resize(rows, std::vector<Cell>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = {false, false, 0};
        }
    }

    // Place mines randomly
    srand(static_cast<unsigned>(time(0)));
    int placed = 0;
    while (placed < mineCount) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (!board[r][c].isMine) {
            board[r][c].isMine = true;
            ++placed;
        }
    }

    // Compute adjacent mine counts
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j].isMine) continue;
            int count = 0;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = i + dr;
                    int nc = j + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc].isMine) {
                        ++count;
                    }
                }
            }
            board[i][j].adjacentMines = count;
        }
    }
}

void displayBoard(const std::vector<std::vector<Cell>>& board, bool showMines) {
    int rows = board.size();
    int cols = board[0].size();
    std::cout << "  ";
    for (int c = 0; c < cols; ++c) {
        std::cout << c + 1 << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < rows; ++i) {
        std::cout << i + 1 << ' ';
        for (int j = 0; j < cols; ++j) {
            const Cell& cell = board[i][j];
            if (cell.revealed) {
                if (cell.isMine) {
                    std::cout << "* ";
                } else {
                    std::cout << cell.adjacentMines << ' ';
                }
            } else {
                if (showMines && cell.isMine) {
                    std::cout << "* ";
                } else {
                    std::cout << ". ";
                }
            }
        }
        std::cout << '\n';
    }
}

bool isWin(const std::vector<std::vector<Cell>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    int revealedNonMine = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!board[i][j].isMine && board[i][j].revealed) {
                ++revealedNonMine;
            }
        }
    }
    int totalNonMine = rows * cols;
    int mineCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j].isMine) ++mineCount;
        }
    }
    return revealedNonMine == (totalNonMine - mineCount);
}

int main() {
    int rows, cols, mineCount;
    std::cout << "Enter number of rows: ";
    while (!(std::cin >> rows) || rows <= 0) {
        std::cout << "Please enter a positive integer for rows: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Enter number of columns: ";
    while (!(std::cin >> cols) || cols <= 0) {
        std::cout << "Please enter a positive integer for columns: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Enter number of mines: ";
    while (!(std::cin >> mineCount) || mineCount <= 0 || mineCount >= rows * cols) {
        std::cout << "Please enter a positive integer less than total cells (" << rows * cols << "): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<std::vector<Cell>> board;
    initializeBoard(board, rows, cols, mineCount);

    bool gameOver = false;
    while (!gameOver) {
        displayBoard(board, false);
        std::cout << "Enter row and column (1-indexed) to reveal: ";
        int r, c;
        if (!(std::cin >> r >> c)) {
            std::cout << "Invalid input. Please enter two integers.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        --r; --c; // convert to 0-indexed
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            std::cout << "Coordinates out of bounds. Try again.\n";
            continue;
        }
        if (board[r][c].revealed) {
            std::cout << "Cell already revealed. Try another.\n";
            continue;
        }

        // Reveal the cell
        board[r][c].revealed = true;
        if (board[r][c].isMine) {
            gameOver = true;
            std::cout << "Game Over! You hit a mine.\n";
            displayBoard(board, true); // show all mines
        } else {
            // Check win condition
            if (isWin(board)) {
                gameOver = true;
                std::cout << "Congratulations! You've cleared all non-mine cells.\n";
                displayBoard(board, false); // mines still hidden
            }
        }
    }

    return 0;
}