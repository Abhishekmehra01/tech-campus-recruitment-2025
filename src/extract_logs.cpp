#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void extractLogs(const std::string& filename, const std::string& date) {
    std::ifstream logFile(filename);
    if (!logFile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // Ensure output directory exists
    std::string outputDir = "output";
    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }

    std::string outputFilename = outputDir + "/output_" + date + ".txt";
    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Error: Could not create output file " << outputFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(logFile, line)) {
        if (line.rfind(date, 0) == 0) {  // Check if line starts with the date
            outputFile << line << '\n';
        }
    }

    logFile.close();
    outputFile.close();

    std::cout << "Logs for " << date << " extracted to " << outputFilename << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " YYYY-MM-DD" << std::endl;
        return 1;
    }

    std::string date = argv[1];
    std::string logFilename = "test_logs.log"; // Update this if needed

    extractLogs(logFilename, date);
    return 0;
}
