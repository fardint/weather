#include <iostream>
#include <fstream>
#include <limits>
#include <map>
#include "../include/json.hpp"
#include "show_year_highest.hpp"

using json = nlohmann::json;

void showYearHighest(const std::string& filename) {
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

    // Map to store total rainfall for each year
    std::map<int, double> yearlyRainfall;

    // Summing up rainfall for each year
    for (const auto& entry : data) {
        int year = entry["year"];
        double rainfall = entry["rainfall"];
        yearlyRainfall[year] += rainfall;
    }

    // Find the year with the highest total rainfall
    int yearWithHighestRainfall = -1; 
    double maxRainfall = std::numeric_limits<double>::lowest();

    // Replace structured bindings with traditional iteration
    for (std::map<int, double>::const_iterator it = yearlyRainfall.begin(); it != yearlyRainfall.end(); ++it) {
        if (it->second > maxRainfall) {  // Adjusted to find maximum
            maxRainfall = it->second;
            yearWithHighestRainfall = it->first;
        }
    }

    if (yearWithHighestRainfall == -1) {
        std::cout << "No data found.\n";
    } else {
        std::cout << "Year with the highest rainfall is " 
                  << yearWithHighestRainfall 
                  << " with " << maxRainfall << " mm of total rain.\n";
    }
}