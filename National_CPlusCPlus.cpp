// Contestant ID: #000000
// Event: (335) C++ Programming

// import libraries
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

/*
*** IMPORTANT NOTE ***

This project was done based on a competition for BPA NLC 2026 C++ Programming Event.
The assignment prompt was not available so I could only complete the tasks that I remember myself from the event.
The functions that I do not remember what the task is I did not attempt.
A base-version of this C++ file was available but only included base-values and class declarations.
For the actual C++ everything is time based, so you want to go fast
I wanted to take the time and use good programming practices to progam these challenges
Even though I was incapable of doing the full prompt (unless I pay $40 to BPA for the prompt), I was still able to learn these things:
Structs in c++, Chrono library, lambda funcions in c++, namespaces, git and github
*/


// Namespace for better encapsulation
namespace NationalCPlusPlus {
    // Base class: Person
    class Person {
        public:
            std::string firstName;
            std::string lastName;
            std::string email;
            std::string phoneNumber;

            Person(std::string firstName, std::string lastName, std::string email, std::string phoneNumber) {
                this->firstName = firstName;
                this->lastName = lastName;
                this->email = email;
                this->phoneNumber = phoneNumber;
            }
    };

    // Derived class: Employee
    class Employee : public Person {
        public:
            int position;
            Employee(std::string firstName, std::string lastName, std::string email, std::string phoneNumber, int position)
                : Person(firstName, lastName, email, phoneNumber)
            {
                this->position = position;
            }

            // Helper function to get the position name as a string
            std::string getPositionName() const {
                switch(position) {
                    case 1:
                        return "Upper Management";
                    case 2:
                        return "Mid-Level Managment";
                    case 3:
                        return "Low-Level Managment";
                    case 4:
                        return "Hourly Employee";
                    default:
                        return "Unknown Position";
                }
            }
    };

    // Derived class: Customer
    class Customer : public Person {
        public:
            int loyaltyPoints;
            Customer(std::string firstName, std::string lastName, std::string email, std::string phoneNumber, int loyaltyPoints)
                : Person(firstName, lastName, email, phoneNumber) {
                this->loyaltyPoints = loyaltyPoints;
            }
    };
    

    // don't remember these from the event
    struct TreeNode {
       
    };
    
    struct ComputerPart { // Node structure for linked list
       
    };

    class ComputerPartsList {
    
    };
    
    struct ProductRecord { // Structure to represent a product record
        
    };

    // Structure to represent a single menu item
    struct MenuItem {
       std::string prompt;
       std::function<void()> menuFunction;

       MenuItem(const std::string& prompt, std::function<void()> menuFunction)
           : prompt(prompt), menuFunction(std::move(menuFunction)) {}
    };

    class Menu {
        public:
            // Populate the menu items with placeholders
            std::vector<MenuItem> menuItems;

            Menu() {
                // populate actual menu options to menuItems vector
                menuItems.emplace_back("Option 1: Create and display 5 customers", []() { createAndDisplayCustomers(); });
                menuItems.emplace_back("Option 2: Create and display 5 employees", []() { createAndDisplayEmployees(); });
                menuItems.emplace_back("Option 3: Build and traverse a binary tree", []() { buildAndTraverseBinaryTree(); });
                menuItems.emplace_back("Option 4: Display the current date and time", []() { displayCurrentDateTime(); });
                menuItems.emplace_back("Option 5: Manage and display computer parts list", []() { manageAndDisplayComputerParts(); });
                menuItems.emplace_back("Option 6: Import and display sorted product data", []() { importAndSortProducts(); });
                menuItems.emplace_back("Option 7: Count words in a user-entered string", []() { countWordsInString(); });
                menuItems.emplace_back("Option 8: Count digits in a number", []() { countDigits(); });
                menuItems.emplace_back("Option 9: Analyze a string (vowels, consonants, spaces, punctuation)", []() { analyzeString(); });
                menuItems.emplace_back("Option 10: Convert temperatures between Celsius and Fahrenheit", []() { convertTemperature(); });
            }
            
            static void createAndDisplayCustomers() {
                // create vector of customers and populate
                std::vector<Customer> customers;
                customers.emplace_back("John", "Doe", "john.doe@example.com", "555-0101", 100);
                customers.emplace_back("Jane", "Smith", "jane.smith@example.com", "555-0102", 150);
                customers.emplace_back("Alice", "Johnson", "alice.johnson@example.com", "555-0103", 200);
                customers.emplace_back("Bob", "Brown", "bob.brown@example.com", "555-0104", 250);
                customers.emplace_back("Charlie", "Davis", "charlie.davis@example.com", "555-0105", 300);

                std::cout << "--- Customer Details ---\n";

                // for each customer display information
                for (const auto& customer : customers) {
                    std::cout << "Name: " << customer.firstName << " " << customer.lastName << '\n';
                    std::cout << "Email: " << customer.email << '\n';
                    std::cout << "Phone Number: " << customer.phoneNumber << '\n';
                    std::cout << "Loyalty Points: " << customer.loyaltyPoints << "\n" << std::endl; 
                }
            }
        
            static void createAndDisplayEmployees() { 
                // create vector of customers and populate
                std::vector<Employee> employees;
                employees.emplace_back("Michael", "Scott", "michael.scott@dundermifflin.com", "555-1234", 1);
                employees.emplace_back("Dwight", "Schrute", "dwight.schrute@dundermifflin.com", "555-5678", 2);
                employees.emplace_back("Jim", "Halpert", "jim.halpert@dundermifflin.com", "555-9012", 3);
                employees.emplace_back("Pam", "Beesly", "pam.beesly@dundermifflin.com", "555-3456", 3);
                employees.emplace_back("Kevin", "Malone", "kevin.malone@dundermifflin.com", "555-7890", 4);

                std::cout << "--- Employee Details ---\n";

                // for each employee display information
                for (const auto& employee : employees) {
                    std::cout << "Name: " << employee.firstName << " " << employee.lastName << '\n';
                    std::cout << "Email: " << employee.email << '\n';
                    std::cout << "Phone Number: " << employee.phoneNumber << '\n';
                    std::cout << "Position: " << employee.getPositionName() << "\n" << std::endl; 
                }
            }
        
            // dont remember what these were meant to do
            static void buildAndTraverseBinaryTree() { 
            
            }

            static void postorderTraversal(const TreeNode* node) {
            
            }

            static void displayCurrentDateTime() { 
                auto now = std::chrono::system_clock::now();

                std::time_t time_now = std::chrono::system_clock::to_time_t(now);
                std::tm* local_time = std::localtime(&time_now);

                // display time
                std::cout << std::put_time(local_time, "%m-%d-%Y") << "\n" << std::endl;
            }

            // dont remember what this was supposed to do
            static void manageAndDisplayComputerParts() { 
                static ComputerPartsList partsList;

                // Adding some parts to the list
                /*
                "CPU"
                "GPU"
                "Motherboard"
                "RAM"
                "Power Supply"
                */
            }

            static void countWordsInString() { 
                std::string sentence;

                // repeat until valid response
                while (true) {
                    std::cout << "Enter a sentence: ";

                    if (std::getline(std::cin >> std::ws, sentence) && !sentence.empty()) {
                        break;
                    }

                    std::cout << "Sentence must contain something\n" << std::endl;
                }

                int count = 0;

                // letters and numbers can make a word
                bool hasFoundLetterOrNumber = false;

                for (int back = 0; back < sentence.size(); back++) {
                    // if character at back is a letter or number
                    if (std::isalnum(sentence.at(back))) {
                        hasFoundLetterOrNumber = true;
                    }

                    // if space at back
                    if (sentence.at(back) == ' ') {
                        // if at least one number or letter since last space
                        if (hasFoundLetterOrNumber) {
                            count++;
                        }

                        // reset flag
                        hasFoundLetterOrNumber = false;
                    }
                }

                if (hasFoundLetterOrNumber) count++;

                // display amount of words for user
                std::cout << "Amount of words: " << std::to_string(count) << "\n" << std::endl;
            }

            static void countDigits() { 
                int val;

                // repeat until valid response
                while (true) {
                    std::cout << "Enter an integer: ";

                    if (std::cin >> val && val > 0) {
                        break;
                    }

                    std::cout << "Input must be an integer and greater than 0\n" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                int numOfZeros = 0;
                int numOfEvens = 0;
                int numOfOdds = 0;
                int digit;

                // iterate through each digit
                while (val > 0) {
                    // find the digit in the 1s place
                    digit = val % 10;

                    // iterate counters
                    if (digit == 0) {
                        numOfZeros++;
                    } else if (digit % 2 == 0) {
                        numOfEvens++;
                    } else {
                        numOfOdds++;
                    }

                    // shift each digit to the right
                    val /= 10;   
                }

                std::cout << "\n--- Digit Analysis ---\n";
                std::cout << "Zero: " << std::to_string(numOfZeros) << '\n';
                std::cout << "Even digits (excluding zero): " << std::to_string(numOfEvens) << '\n';
                std::cout << "Odd digits: " << std::to_string(numOfOdds) << "\n" << std::endl;
            }

            static void analyzeString() {
                
            }

            
            static void convertTemperature() {
                std::string inputUnit;

                // repeat until valid response
                while (true) {
                    std::cout << "Enter the input unit (F/C): ";

                    if (std::getline(std::cin >> std::ws, inputUnit) && !inputUnit.empty() && (inputUnit == "F" || inputUnit == "C")) {
                        break;
                    }

                    std::cout << "Unit must be in proper format (F/C)\n" << std::endl;
                }

                // repeat until valid response
                double val;
                while (true) {
                    std::cout << "Enter the value: ";

                    if (std::cin >> val) {
                        break;
                    }

                    std::cout << "Input must be be a number\n" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                // display correct conversion based on the input unit
                if (inputUnit == "F") {
                    std::cout << "Output: " << (val - 32.0) * (5.0 / 9.0) << " degrees Celsius\n" << std::endl;
                } else {
                    std::cout << "Output: " << val * (9.0 / 5.0) + 32.0 << " degrees Fahrenheit" << std::endl;
                }
            }

            static void importAndSortProducts() {
                
            }
    };

} // namespace NationalCPlusPlus

int main() {
    system("CLS"); // clears screen (only works on WindowsOS)
    NationalCPlusPlus::Menu menu;

    int menuVal;
    
    // repeat until valid response
    while (true) {
        // iterate through each item and print
        for (const auto& menuItem : menu.menuItems) {
            std::cout << menuItem.prompt << '\n';
        }

        // print exit option
        std::cout << "Option 0: Exit" << std::endl;

        if (std::cin >> menuVal && menuVal >= 0 && menuVal <= menu.menuItems.size()) {
            if (menuVal == 0) {
                break;
            }

            // run lambda function
            menu.menuItems[menuVal - 1].menuFunction();

            system("PAUSE"); // wait for user to click enter (only works in WinowsOS)
            system("CLS"); // clears screen (only works on WindowsOS)
            continue;
        }

        system("CLS"); // clears screen (only works on WindowsOS)
        std::cout << "Entered value must be an integer 0-10\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    // say goodbye to user
    std::cout << "Goodbye!" << std::endl;

    return 0;
}