# Rainfall Management System

## Overview

The **Rainfall Management System** is a C++ application designed to help manage and analyze rainfall data for the years 1390 to 1400. This program allows users to add rainfall entries, retrieve specific rainfall data, and provides a foundation for further analysis of rainfall trends over a ten-year period. The data is stored in JSON format for better organization and easy access.

---

## Features

1. **Add Rainfall Entry**:
    - Add or update monthly rainfall data for a specific year (1390 to 1400).
    - Data is stored in a JSON file for persistence.

2. **View Rainfall Entry**:
    - Retrieve the rainfall data for a given year and month.

3. **Extensible Design**:
    - The structure allows for the addition of advanced features, such as:
        - Showing cumulative data (total rainfall, averages, etc.)
        - Yearly and monthly rainfall comparisons
        - Identifying trends like wettest or driest months and years.

---

## How to Use

1. **Run the Program**:
    - Use a C++ compiler to build and run the application.
    - Ensure the JSON library (`nlohmann::json`) is included in the project.

2. **Main Menu**:
   Upon startup, the program displays the following menu options:
   ```
   ______________ (RAINFALL MANAGEMENT) By FARDIN TURKMEN _____________

   1. Add Entry
   2. Show Entry
   99. Exit
   Choose an option:
   ```

3. **Add an Entry**:
    - Select option `1` and input the following details when prompted:
        - `Year (1390 to 1400)`
        - `Month (1 to 12)`
        - `Rainfall (mm)`
    - The program will add or update the entry in the `rainfall_data.json` file.

4. **Show an Entry**:
    - Select option `2` and input the following details when prompted:
        - `Year (1390 to 1400)`
        - `Month (1 to 12)`
    - The program will fetch and display the corresponding rainfall record from the JSON file. If no record exists, it will notify the user.

5. **Exit**:
    - Select `99` to terminate the program.

---

## Project Structure

The application consists of several components:

1. **Main Application (`weather.cpp`)**:
    - Handles the user interface and menu options.

2. **Add Entry (`add_entry.cpp`)**:
    - Handles inserting and updating rainfall data into the JSON file.

3. **Show Entry (`show_entry.cpp`)**:
    - Manages retrieval and display of specific rainfall data.

4. **Data Storage**:
    - Rainfall data is persisted in a file named `rainfall_data.json`.

---

## Dependencies

### Third-Party Library
- **nlohmann/json**: A modern JSON library for C++ used to manage and parse JSON data. For installation:
    - Include the header file `json.hpp` in the `include` directory of the project.

### File Handling
- The program reads and writes rainfall data to the `rainfall_data.json` file in the project directory. Ensure you have appropriate permissions to create and modify this file.

---

## Future Enhancements

The following functionalities can be added to extend the project:
1. Displaying all data in tabular format.
2. Showing rainfall trends for a given year.
3. Annual and monthly average rainfall calculations.
4. Identifying the wettest and driest months and years.
5. Comparing rainfall for a specific month across all years.
6. Visualizing the data with graphs for better understanding and analysis.

---

## Compilation Instructions

1. Ensure you have a C++ compiler installed (e.g., GCC or MSVC).
2. Include the required JSON library (`nlohmann/json`).
3. Compile the project files:
    - `weather.cpp`, `add_entry.cpp`, `show_entry.cpp`
4. Run the executable.

Example (using GCC):