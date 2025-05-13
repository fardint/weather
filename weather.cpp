#include <iostream>
#include "functions/add_entry.hpp"
#include "functions/show_entry.hpp"

const std::string DATA_FILE = "./data/rainfall_data.json";

void showMenu() {
    std::cout << "\nRainfall Manager:\n";
    std::cout << "1. Add Entry\n";
    std::cout << "2. Show Entry\n";
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
        }else if (choice == 99) {
            break;
        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
