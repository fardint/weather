#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "show_all.hpp"

using json = nlohmann::json;

void showAll(const std::string& filename) {
    // Load data
    std::ifstream inFile(filename);
    json data = json::array();
    
    if (inFile.is_open()) {
        try {
            inFile >> data;
        } catch (...) {
            std::cerr << "Error reading file or invalid JSON.\n";
            return;
        }
    } else {
        std::cerr << "Unable to open file.\n";
        return;
    }

    if (data.empty()) {
        std::cout << "No data available.\n";
        return;
    }

    // Display all entries
    std::cout << "All Rainfall Data:\n";
    for (const auto& entry : data) {
        std::cout << "Year: " << entry["year"]
                  << ", Month: " << entry["month"]
                  << ", Rainfall: " << entry["rainfall"] << " mm\n";
    }
}