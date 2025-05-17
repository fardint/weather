#include <iostream>
#include <fstream>
#include <numeric>
#include "../include/json.hpp"
#include "show_year_average.hpp"

using json = nlohmann::json;

void showYearAverage(const std::string& filename) {
    int year;
    std::cout << "Enter year (1390 to 1400): ";
    std::cin >> year;

    // if (year < 1390 || year > 1400) {
    //     std::cerr << "Year out of range. Please enter a year between 1390 and 1400.\n";
    //     return;
    // }

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
        std::cerr << "Could not open file: " << filename << "\n";
        return;
    }

    bool found = false;
    double totalRainfall = 0.0;
    int monthCount = 0;

    // Search for all matching entries and calculate average
    for (const auto& entry : data) {
        if (entry["year"] == year) {
            totalRainfall += double(entry["rainfall"]);
            monthCount++;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No data found for the year " << year << ".\n";
    } else {
        double averageRainfall = totalRainfall / monthCount;
        std::cout << "Average rainfall for the year " << year << " is "
                  << averageRainfall << " mm.\n";
    }
}