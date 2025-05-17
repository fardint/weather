#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "show_month.hpp"

using json = nlohmann::json;

void showMonth(const std::string& filename) {
    int month;
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

    // Search for all matching entries
    for (const auto& entry : data) {
        if (entry["month"] == month) {
            std::cout << "Rainfall in " << entry["year"]
                      << ", Month: " << entry["month"]
                      << ": " << entry["rainfall"] << " mm\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No data found for " << month << ".\n";
    }
}