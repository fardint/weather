#include <iostream>
#include "functions/add_entry.hpp"
#include "functions/show_entry.hpp"
#include "functions/show_all.hpp"
#include "functions/show_year.hpp"

const std::string DATA_FILE = "./data/rainfall_data.json";

void showMenu() {
    std::cout << R"(
_____________ (RAINFALL MANAGEMENT) By FARDIN TURKMEN _____________
)" << "\n";

    std::cout << "1. Add Entry\n";
    std::cout << "2. Show Entry\n";
    std::cout << "3. Show All Entries\n";
    std::cout << "4. Show Year\n";
    std::cout << "99. Exit\n";
    std::cout << "Choose an option: ";
}


int main() {
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            addEntry(DATA_FILE);
        } else if (choice == 2) {
            showEntry(DATA_FILE); 
        } else if (choice == 3){
            showAll(DATA_FILE);
        } else if (choice == 4){
            showYear(DATA_FILE);
        } else if (choice == 99) {
            break;
        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
