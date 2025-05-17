#include <iostream>
#include <fstream>
#include <limits>
#include "../include/json.hpp"
#include "show_month_highest.hpp"

using json = nlohmann::json;

void showMonthHighest(const std::string& filename) {
    int year;
    std::cout << "Enter year (1390 to 1400): ";
    std::cin >> year;

    if (year < 1390 || year > 1400) {
        std::cerr << "Year out of range. Please enter a year between 1390 and 1400.\n";
        return;
    }

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
    double maxRainfall = std::numeric_limits<double>::lowest();
    int monthWithHighestRainfall = -1;

    // Search for the month with the highest rainfall in the given year
    for (const auto& entry : data) {
        if (entry["year"] == year) {
            double rainfall = entry["rainfall"];
            if (rainfall > maxRainfall) {
                maxRainfall = rainfall;
                monthWithHighestRainfall = entry["month"];
            }
            found = true;
        }
    }

    if (!found) {
        std::cout << "No data found for the year " << year << ".\n";
    } else {
        std::cout << "Month with the highest rainfall in " << year
                  << " is Month " << monthWithHighestRainfall
                  << " with " << maxRainfall << " mm of rain.\n";
    }
}