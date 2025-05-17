#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "show_year.hpp"

using json = nlohmann::json;

void showYear(const std::string& filename) {
    int year;
    std::cout << "Enter year (1390 to 1400): ";
    std::cin >> year;

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
    }

    bool found = false;

    // Search for all matching entries
    for (const auto& entry : data) {
        if (entry["year"] == year) {
            std::cout << "Rainfall in " << year
                      << ", Month: " << entry["month"]
                      << ": " << entry["rainfall"] << " mm\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No data found for " << year << ".\n";
    }
}