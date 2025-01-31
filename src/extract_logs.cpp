// #include <iostream>
// #include <fstream>
// #include <string>
// #include <chrono>

// using namespace std;

// // Function to extract logs for the specified date
// void extract_logs(const string& date) {
//     string input_file_path = "test_logs.log";
//     string output_file_path = "output/output_" + date + ".txt";

//     // Open the input file for reading
//     ifstream input_file(input_file_path);
//     if (!input_file.is_open()) {
//         cerr << "Error: Could not open input file " << input_file_path << endl;
//         return;
//     }

//     // Open the output file for writing
//     ofstream output_file(output_file_path);
//     if (!output_file.is_open()) {
//         cerr << "Error: Could not open output file " << output_file_path << endl;
//         input_file.close();
//         return;
//     }

//     string line;
//     bool found_logs = false;

//     // Start time tracking
//     auto start = chrono::high_resolution_clock::now();

//     // Read the input file line by line
//     while (getline(input_file, line)) {
//         // Check if the first 10 characters (the date part) match the specified date
//         if (line.substr(0, 10) == date) {
//             output_file << line << endl;  // Write the matching line to the output file
//             found_logs = true;
//         }
//     }

//     // End time tracking
//     auto end = chrono::high_resolution_clock::now();
//     chrono::duration<double> elapsed = end - start;
    
//     // Print performance information
//     if (found_logs) {
//         cout << "Logs for " << date << " have been successfully extracted to " << output_file_path << endl;
//     } else {
//         cout << "No logs found for the date: " << date << endl;
//     }

//     // Print the elapsed time for performance tracking
//     cout << "Elapsed time: " << elapsed.count() << " seconds." << endl;

//     // Close the input and output files
//     input_file.close();
//     output_file.close();
// }

// int main(int argc, char* argv[]) {
//     // Check if the correct number of arguments is passed
//     if (argc != 2) {
//         cerr << "Usage: ./extract_logs <YYYY-MM-DD>" << endl;
//         return 1;
//     }

//     string date = argv[1];

//     // Validate the date format
//     if (date.length() != 10 || date[4] != '-' || date[7] != '-' ||
//         !isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) ||
//         !isdigit(date[5]) || !isdigit(date[6]) ||
//         !isdigit(date[8]) || !isdigit(date[9])) {
//         cerr << "Invalid date format. Please use YYYY-MM-DD." << endl;
//         return 1;
//     }

//     // Extract logs for the given date
//     extract_logs(date);

//     return 0;
// }



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

// Function to process log file and extract logs for a specific date
void extractLogs(const string& inputDate, const string& inputFilePath, const string& outputFilePath) {
    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);
    
    // Check if files are open
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file." << endl;
        return;
    }
    
    string line;
    string datePrefix = inputDate + " ";  // Target date prefix (YYYY-MM-DD )
    
    while (getline(inputFile, line)) {
        // Check if the line starts with the target date
        if (line.rfind(datePrefix, 0) == 0) {
            // Write the log entry to the output file
            outputFile << line << endl;
        }
    }
    
    cout << "Logs for " << inputDate << " have been successfully extracted to " << outputFilePath << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <date (YYYY-MM-DD)> <input file path>" << endl;
        return 1;
    }
    
    string inputDate = argv[1]; // Date from command line
    string inputFilePath = argv[2]; // Path to the log file
    string outputFilePath = "output/output_" + inputDate + ".txt"; // Output file path
    
    // Extract logs for the given date
    extractLogs(inputDate, inputFilePath, outputFilePath);

    return 0;
}

