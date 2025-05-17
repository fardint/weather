#include <iostream>
#include "functions/add_entry.hpp"
#include "functions/show_entry.hpp"
#include "functions/show_all.hpp"
#include "functions/show_year.hpp"
#include "functions/show_month.hpp"
#include "functions/show_month_average.hpp"
#include "functions/show_month_highest.hpp"
#include "functions/show_month_lowest.hpp"
#include "functions/show_year_average.hpp"
#include "functions/show_year_lowest.hpp"
#include "functions/show_year_highest.hpp"

const std::string DATA_FILE = "./data/rainfall_data.json";

void showMenu() {
    std::cout << "(_____________ (RAINFALL MANAGEMENT) By FARDIN TURKMEN _____________)" << "\n";

    std::cout << "1. Add Entry\n";
    std::cout << "2. Show Entry\n";
    std::cout << "3. Show All Entries\n";
    std::cout << "4. Show Year\n";
    std::cout << "5. Show Month\n";
    std::cout << "6. Show Year Average\n";
    std::cout << "7. Show Month With Lowest Rain\n";
    std::cout << "8. Show Month With Highest Rain\n";
    std::cout << "9. Show Year With Lowest Rain\n";
    std::cout << "10. Show Year With Highest Rain\n";
    std::cout << "11. Show Month Average\n";
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
        } else if (choice == 5){
            showMonth(DATA_FILE);
        } else if (choice == 6){
            showYearAverage(DATA_FILE);
        } else if (choice == 7){
            showMonthLowest(DATA_FILE);
        } else if (choice == 8){
            showMonthHighest(DATA_FILE);
        } else if (choice == 9){
            showYearLowest(DATA_FILE);
        } else if (choice == 10){
            showYearHighest(DATA_FILE);
        } else if (choice == 11){
            showMonthAverage(DATA_FILE);
        } else if (choice == 99) {
            break;
        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
