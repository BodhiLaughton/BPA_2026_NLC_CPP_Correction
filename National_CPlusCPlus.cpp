// Contestant ID: #000000
// Event: (335) C++ Programming

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
                std::vector<Customer> customers;
                customers.emplace_back("John", "Doe", "john.doe@example.com", "555-0101", 100);
                customers.emplace_back("Jane", "Smith", "jane.smith@example.com", "555-0102", 150);
                customers.emplace_back("Alice", "Johnson", "alice.johnson@example.com", "555-0103", 200);
                customers.emplace_back("Bob", "Brown", "bob.brown@example.com", "555-0104", 250);
                customers.emplace_back("Charlie", "Davis", "charlie.davis@example.com", "555-0105", 300);
            }
        
            static void createAndDisplayEmployees() { 
                std::vector<Employee> employees;
                employees.emplace_back("Michael", "Scott", "michael.scott@dundermifflin.com", "555-1234", 1);
                employees.emplace_back("Dwight", "Schrute", "dwight.schrute@dundermifflin.com", "555-5678", 2);
                employees.emplace_back("Jim", "Halpert", "jim.halpert@dundermifflin.com", "555-9012", 3);
                employees.emplace_back("Pam", "Beesly", "pam.beesly@dundermifflin.com", "555-3456", 3);
                employees.emplace_back("Kevin", "Malone", "kevin.malone@dundermifflin.com", "555-7890", 4);
            }
        
            static void buildAndTraverseBinaryTree() { 
            
            }

            static void postorderTraversal(const TreeNode* node) {
            
            }

            static void displayCurrentDateTime() { 
                
            }

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
                
            }

            static void countDigits() { 
                
            }

            static void analyzeString() { 
            
            }

            static void convertTemperature() { 
                
            }

            static void importAndSortProducts() {
                
            }
    };

} // namespace NationalCPlusPlus

int main() {
    NationalCPlusPlus::Menu menu;
    int menuVal;
    while (true) {
        for (const auto& menuItem : menu.menuItems) {
            std::cout << menuItem.prompt << '\n';
        }
        std::cout << "Option 0: Exit\n" << std::endl;

        if (std::cin >> menuVal && menuVal >= 0 && menuVal <= menu.menuItems.size()) {
            if (menuVal == 0) {
                break;
            }

            menu.menuItems[menuVal].menuFunction();
            continue;
        }

        system("CLS");
        std::cout << "Entered value must be an integer 0-10\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout << "Goodbye!";

    return 0;
}