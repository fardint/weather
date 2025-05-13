// functions/add_entry.cpp

#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "add_entry.hpp"

using json = nlohmann::json;

void addEntry(const std::string& filename) {
    int year, month;
    double rainfall;

    std::cout << "Enter year (1390 to 1400): ";
    std::cin >> year;

    std::cout << "Enter month (1 to 12): ";
    std::cin >> month;

    std::cout << "Enter rainfall (mm): ";
    std::cin >> rainfall;

    // Load existing data
    std::ifstream inFile(filename);
    json data = json::array();
    if (inFile.is_open()) {
        try {
            inFile >> data;
        } catch (...) {
            std::cerr << "Failed to parse JSON, starting fresh.\n";
            data = json::array(); // reset if error
        }
    }

    bool updated = false;

    // Check if (year, month) already exists and update if so
    for (auto& entry : data) {
        if (entry["year"] == year && entry["month"] == month) {
            entry["rainfall"] = rainfall;
            updated = true;
            break;
        }
    }

    // If not found, add new entry
    if (!updated) {
        data.push_back({{"year", year}, {"month", month}, {"rainfall", rainfall}});
    }

    // Write updated data back to file
    std::ofstream outFile(filename);
    outFile << data.dump(4); // pretty print with 4 spaces

    if (updated) {
        std::cout << "Existing entry updated.\n";
    } else {
        std::cout << "New entry added.\n";
    }
}
