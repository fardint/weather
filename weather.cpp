#include<iostream>
#include <fstream>
/* https://github.com/nlohmann/json/releases/latest/download/json.hpp */
#include "include/json.hpp"
using namespace std;

using json = nlohmann::json;

json readJsonFile(const std::string& filename) {
    std::ifstream file(filename);

    // Check if file exists or can be opened
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open file: " << filename << "\n";
        return json::array(); // return empty array
    }

    json data;
    try {
        file >> data;  // parse JSON
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << "\n";
        return json::array();
    }

    return data;
}

int main() {
    json rainfallData = readJsonFile("./data/rainfall_data.json");

    std::cout << "Loaded " << rainfallData.size() << " entries.\n";

    for (const auto& record : rainfallData) {
        std::cout << "Year: " << record["year"]
                  << ", Month: " << record["month"]
                  << ", Rainfall: " << record["rainfall"] << " mm\n";
    }

    return 0;
}

