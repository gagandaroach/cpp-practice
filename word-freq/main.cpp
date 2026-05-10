#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

// Function to remove punctuation and convert to lowercase
std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char ch : word) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            cleaned += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    return cleaned;
}

int main() {
    std::string filename;
    std::cout << "Enter filename (default: sample.txt): ";
    std::getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "sample.txt";
    }
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'\n";
        // Try to create a default sample if not found
        if (filename == "sample.txt") {
            std::cerr << "Creating a default sample.txt...\n";
            std::ofstream sampleFile("sample.txt");
            if (sampleFile.is_open()) {
                sampleFile << "Hello world! This is a sample text. Hello again, world.\n";
                sampleFile << "The quick brown fox jumps over the lazy dog. The dog was not amused.\n";
                sampleFile.close();
                std::cout << "Created sample.txt with default text.\n";
                // Reopen the file
                file.open("sample.txt");
                if (!file.is_open()) {
                    std::cerr << "Failed to open newly created sample.txt\n";
                    return 1;
                }
            } else {
                std::cerr << "Failed to create sample.txt\n";
                return 1;
            }
        } else {
            return 1;
        }
    }
    
    std::unordered_map<std::string, int> freqMap;
    std::string word;
    while (file >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            freqMap[cleaned]++;
        }
    }
    file.close();
    
    // Convert to vector for sorting
    std::vector<std::pair<std::string, int>> freqVec(freqMap.begin(), freqMap.end());
    
    // Sort by frequency descending, then by word ascending for tie-break
    std::sort(freqVec.begin(), freqVec.end(),
              [](const auto& a, const auto& b) {
                  if (a.second != b.second) {
                      return a.second > b.second;
                  }
                  return a.first < b.first;
              });
    
    // Output results
    std::cout << "\nWord frequencies (sorted by frequency):\n";
    for (const auto& pair : freqVec) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    
    return 0;
}