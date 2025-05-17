#include <iostream>
#include <fstream>
#include <limits>
#include "../include/json.hpp"
#include "show_year_lowest.hpp"

using json = nlohmann::json;

// Assuming you are using nlohmann::json
void showYearLowest(const std::string& filename) {
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

    // Find the year with the lowest total rainfall
    int yearWithLowestRainfall = -1; 
    double minRainfall = std::numeric_limits<double>::max();

    // Replace structured bindings with traditional iteration
    for (std::map<int, double>::const_iterator it = yearlyRainfall.begin(); it != yearlyRainfall.end(); ++it) {
        if (it->second < minRainfall) {
            minRainfall = it->second;
            yearWithLowestRainfall = it->first;
        }
    }

    if (yearWithLowestRainfall == -1) {
        std::cout << "No data found.\n";
    } else {
        std::cout << "Year with the lowest rainfall is " 
                  << yearWithLowestRainfall 
                  << " with " << minRainfall << " mm of total rain.\n";
    }
}