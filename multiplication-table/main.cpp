#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int cols, rows;
    
    // Ask for column size
    cout << "Enter column size: \n";
    cin >> cols;
    
    // Ask for row size
    cout << "Enter row size: \n";
    cin >> rows;
    
    // Validate input
    if (cols <= 0 || rows <= 0) {
        cout << "Error: row and column sizes must be positive integers." << endl;
        return 1;
    }
    
    // Calculate maximum value to determine field width
    int max_value = rows * cols;
    int digit_width = 0;
    int temp = max_value;
    if (temp == 0) {
        digit_width = 1;
    } else {
        while (temp > 0) {
            digit_width++;
            temp /= 10;
        }
    }
    int field_width = digit_width + 1; // Add 1 for space between columns
    
    // Print multiplication table matrix
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << setw(field_width) << (i * j);
        }
        cout << endl;
    }
    
    return 0;
}