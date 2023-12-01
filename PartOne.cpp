#include "utility.h"

//--------------------------------------PartOne----------------------------------------------------------------------------------//

/**
 * Function to process the given text file and output the frequency of each character.
 * 
 * @param inputFilePath The path to the input text file.
 * @param outputFilePath The path to the output file where character frequencies will be written.
 */
void processFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    // Open the input file for reading
    std::ifstream inFile(inputFilePath);
    // Open the output file for writing
    std::ofstream outFile(outputFilePath);

    // Check if the input file was successfully opened
    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << inputFilePath << std::endl;
        return;
    }

    // Vector to store the frequency of each ASCII character
    std::vector<int> freq(128, 0);
    char ch; // Variable to store each character read from the file

    // Read the file character by character
    while (inFile.get(ch)) {
        // Increment the frequency of the read character
        freq[static_cast<int>(ch)]++;
    }

    // Close the input file
    inFile.close();

    // Write the frequencies to the output file
    for (int i = 0; i < 128; ++i) {
        if (freq[i] > 0) { // Check if the character occurred in the text
            if (i == 10) { // Special handling for line feed character
                outFile << "LF " << freq[i] << std::endl;
            } else {
                // Write the character and its frequency
                outFile << static_cast<char>(i) << " " << freq[i] << std::endl;
            }
        }
    }

    // Close the output file
    outFile.close();
}

/**
 * Main function of the program.
 */
int main() {
    // Specify the paths for the input and output files
    const std::string inputFilePath = "clear.txt";
    const std::string outputFilePath = "freq.txt";

    // Call the function to process the file
    processFile(inputFilePath, outputFilePath);

    return 0;
}

//---------------------------------------Team 5 Gunturu, Khan, Manchikatla, Muddana, Richert---------------------------------------//