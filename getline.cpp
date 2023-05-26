#include <iostream>
#include <string>

int main() {
    std::string input;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);
  
    // suppose you have already read an integer or some number then you must use the getline() function in this way to avoid problems
    std::getline(std::cin >> ws, input); 
    
    // this simply handles all whitespaces or \n characters left in the buffer after reading the integer

    std::cout << "You entered: " << input << std::endl;

    return 0;
}

// The getline function is used to read a line of input from the standard input (in this case, the keyboard) and store it in a std::string variable.
// It allows you to read an entire line, including any spaces or special characters, until a newline character is encountered.

// In the example above, the program prompts the user to enter a sentence, and the getline function reads the input until the user presses the Enter key. 
// The entered sentence is then displayed back to the user.

// Remember to include the <iostream> and <string> headers to use the getline function and the std::string class respectively.
