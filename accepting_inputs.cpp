#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    // Accepting an integer input
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Accepting a string input
    std::cout << "Enter your name: ";
    std::cin.ignore(); // Ignore any remaining newline character from previous input
    std::getline(std::cin, name);

    // Displaying the inputs
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    return 0;
}

// In the code above, we declare two variables: age of type int to store the age, and name of type std::string to store the name.

// To accept an integer input, we use std::cin along with the extraction operator (>>).
// The user is prompted to enter their age, and the input is stored in the age variable.

// To accept a string input, we use std::getline(std::cin, name). Before using std::getline, we include std::cin.ignore() to discard any remaining newline character in the input stream. 
// The user is prompted to enter their name, and the input is stored in the name variable.

// Finally, we display the inputs back to the user using std::cout.
