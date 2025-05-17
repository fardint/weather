#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "show_month_average.hpp"

using json = nlohmann::json;

void showMonthAverage(const std::string& filename) {
    int month;
    std::cout << "Enter month (1 to 12): ";
    std::cin >> month;

    // Validate month input
    if (month < 1 || month > 12) {
        std::cerr << "Invalid month. Please enter a value between 1 and 12.\n";
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

    double totalRainfall = 0.0;  // Sum of rainfall for the specified month
    int yearCount = 0;          // Number of years with data for the specified month

    // Iterate over all entries in the dataset
    for (const auto& entry : data) {
        // Check if the month matches
        if (entry["month"] == month) {
            totalRainfall += double(entry["rainfall"]);
            yearCount++;
        }
    }

    // Calculate and display the average rainfall
    if (yearCount == 0) {
        std::cout << "No data found for month " << month << " in any year.\n";
    } else {
        double monthAverageRainfall = totalRainfall / yearCount;
        std::cout << "Average rainfall for month " << month 
                  << " across all recorded years is " 
                  << monthAverageRainfall << " mm.\n";
    }
}