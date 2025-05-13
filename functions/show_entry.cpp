#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "show_entry.hpp"

using json = nlohmann::json;

void showEntry(const std::string& filename) {
    int year, month;
    std::cout << "Enter year (1390 to 1400): ";
    std::cin >> year;

    std::cout << "Enter month (1 to 12): ";
    std::cin >> month;

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

    // Search for entry
    for (const auto& entry : data) {
        if (entry["year"] == year && entry["month"] == month) {
            std::cout << "Rainfall in " << year << "/" << month
                      << ": " << entry["rainfall"] << " mm\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "No data found for " << year << "/" << month << ".\n";
    }
}
