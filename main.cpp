#include "Matrix.hpp" // Include Matrix header
#include <iostream>   // For input/output streams (cout)
#include <fstream>    // For file streams (ifstream)
#include <string>     // For string manipulation
#include <cctype>     // For character handling (isspace)

using namespace std; // Use standard namespace

int main(int argc, char* argv[]) {
    // Check for correct number of command-line arguments
    if (argc != 2) {
        cout << "Usage: ./program <input_file>" << endl;
        return 1; // Indicate error
    }
    string filename = argv[1]; // Get filename from arguments
    ifstream infile(filename.c_str()); // Open the input file
    // Check if file opened successfully
    if (!infile) {
        cout << "Cannot open file: " << filename << endl;
        return 1; // Indicate error
    }
    string line; // Variable to hold each line read from file
    string addend = "-123.456"; // Define the number to add (as string)
    string multiplier = "2.0"; // Define the number to multiply by (as string)

    // Read file line by line
    while (getline(infile, line)) {
        // Trim leading whitespace
        while (!line.empty() && std::isspace(line[0]))
            line.erase(line.begin());
        // Trim trailing whitespace
        while (!line.empty() && std::isspace(line[line.size()-1]))
            line.erase(line.end()-1);
        // Skip empty lines after trimming
        if (line == "")
            continue;

        // Check if the line represents a valid double (using function from Matrix.hpp?)
        if (isValidDouble(line)) {
            // Add using string representation
            string added = addDoubleStrings(line, addend);
            // Multiply using string representation
            string multiplied = multiplyDoubleStrings(line, multiplier);
            // Print results for valid numbers
            cout << "Valid number: " << line << endl;
            cout << "After adding " << addend << ", result: " << added << endl;
            cout << "After multiplying by " << multiplier << ", result: " << multiplied << endl;
        } else {
            // Print message for invalid numbers
            cout << "Invalid number: " << line << endl;
        }
    }
    infile.close(); // Close the input file
    return 0; // Indicate successful execution
}
