#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

// Function prototypes
void drawRectangle(int width, int height, char ch = '*');
void drawTriangle(int size, char ch = '*');
void drawDiamond(int size, char ch = '*');
std::string textToASCII(const std::string& text);
void showMenu();
char getChoice();
int getDimension(const std::string& prompt);
char getCharacter();

int main() {
    bool quit = false;
    
    while (!quit) {
        showMenu();
        char choice = getChoice();
        
        switch (choice) {
            case '1': { // Rectangle
                int width = getDimension("Enter width: ");
                int height = getDimension("Enter height: ");
                char ch = getCharacter();
                drawRectangle(width, height, ch);
                break;
            }
            case '2': { // Triangle
                int size = getDimension("Enter size: ");
                char ch = getCharacter();
                drawTriangle(size, ch);
                break;
            }
            case '3': { // Diamond
                int size = getDimension("Enter size: ");
                char ch = getCharacter();
                drawDiamond(size, ch);
                break;
            }
            case '4': { // Text to ASCII
                std::cout << "Enter text (short word/phrase): ";
                std::string text;
                std::getline(std::cin >> std::ws, text);
                std::cout << textToASCII(text) << std::endl;
                break;
            }
            case '5': // Quit
                quit = true;
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
        if (!quit) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}

// Draw a rectangle of specified size
void drawRectangle(int width, int height, char ch) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

// Draw a right triangle of specified size
void drawTriangle(int size, char ch) {
    for (int i = 1; i <= size; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

// Draw a diamond of specified size
void drawDiamond(int size, char ch) {
    // Top half
    for (int i = 1; i <= size; ++i) {
        // Spaces
        for (int j = 0; j < size - i; ++j) {
            std::cout << " ";
        }
        // Characters
        for (int j = 0; j < 2 * i - 1; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    
    // Bottom half
    for (int i = size - 1; i >= 1; --i) {
        // Spaces
        for (int j = 0; j < size - i; ++j) {
            std::cout << " ";
        }
        // Characters
        for (int j = 0; j < 2 * i - 1; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

// Simple block font mapping for A-Z, 0-9
std::map<char, std::vector<std::string>> initBlockFont() {
    std::map<char, std::vector<std::string>> font;
    
    // Each letter is represented as 3 lines of 3 characters each
    // Using block characters: space, # for filled
    
    // A
    font['A'] = {
        " # ",
        "# #",
        "###"
    };
    
    // B
    font['B'] = {
        "## ",
        "# #",
        "## "
    };
    
    // C
    font['C'] = {
        " ##",
        "#  ",
        " ##"
    };
    
    // D
    font['D'] = {
        "## ",
        "# #",
        "## "
    };
    
    // E
    font['E'] = {
        "###",
        "#  ",
        "###"
    };
    
    // F
    font['F'] = {
        "###",
        "#  ",
        "#  "
    };
    
    // G
    font['G'] = {
        " ##",
        "#  ",
        "# ##"
    };
    
    // H
    font['H'] = {
        "# #",
        "###",
        "# #"
    };
    
    // I
    font['I'] = {
        "###",
        " # ",
        "###"
    };
    
    // J
    font['J'] = {
        "###",
        "  #",
        "## "
    };
    
    // K
    font['K'] = {
        "# #",
        "## ",
        "# #"
    };
    
    // L
    font['L'] = {
        "#  ",
        "#  ",
        "###"
    };
    
    // M
    font['M'] = {
        "# #",
        "###",
        "# #"
    };
    
    // N
    font['N'] = {
        "# #",
        "## ",
        "# #"
    };
    
    // O
    font['O'] = {
        " # ",
        "# #",
        " # "
    };
    
    // P
    font['P'] = {
        "## ",
        "# #",
        "## "
    };
    
    // Q
    font['Q'] = {
        " # ",
        "# #",
        " # #"
    };
    
    // R
    font['R'] = {
        "## ",
        "# #",
        "## "
    };
    
    // S
    font['S'] = {
        " ##",
        "#  ",
        " ##"
    };
    
    // T
    font['T'] = {
        "###",
        " # ",
        " # "
    };
    
    // U
    font['U'] = {
        "# #",
        "# #",
        " ###"
    };
    
    // V
    font['V'] = {
        "# #",
        "# #",
        " # "
    };
    
    // W
    font['W'] = {
        "# #",
        "# #",
        "# #"
    };
    
    // X
    font['X'] = {
        "# #",
        " # ",
        "# #"
    };
    
    // Y
    font['Y'] = {
        "# #",
        " # ",
        " # "
    };
    
    // Z
    font['Z'] = {
        "###",
        "  #",
        "###"
    };
    
    // Space
    font[' '] = {
        "   ",
        "   ",
        "   "
    };
    
    return font;
}

std::string textToASCII(const std::string& text) {
    static const std::map<char, std::vector<std::string>> font = initBlockFont();
    std::string result;
    
    // Convert to uppercase for simplicity
    std::string upperText;
    for (char c : text) {
        upperText += std::toupper(c);
    }
    
    // Each character is 3 lines high
    for (int line = 0; line < 3; ++line) {
        for (char c : upperText) {
            auto it = font.find(c);
            if (it != font.end()) {
                result += it->second[line];
                result += " "; // Space between characters
            } else {
                // Default to space for unknown characters
                result += "   ";
                result += " ";
            }
        }
        if (line < 2) { // Don't add newline after last line
            result += "\n";
        }
    }
    
    return result;
}

void showMenu() {
    std::cout << "=== ASCII Art Generator ===\n";
    std::cout << "1. Draw a rectangle\n";
    std::cout << "2. Draw a triangle\n";
    std::cout << "3. Draw a diamond\n";
    std::cout << "4. Convert text to ASCII art\n";
    std::cout << "5. Quit\n";
    std::cout << "Enter your choice: ";
}

char getChoice() {
    char choice;
    std::cin >> choice;
    return choice;
}

int getDimension(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a positive integer.\n";
        } else {
            std::cin.ignore(10000, '\n'); // Clear newline
            break;
        }
    }
    return value;
}

char getCharacter() {
    std::cout << "Enter character to use (default '*'): ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        return '*';
    }
    return input[0];
}