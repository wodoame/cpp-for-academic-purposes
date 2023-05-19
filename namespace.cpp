// In C++, a namespace is a feature that allows you to group related declarations (such as variables, functions, and classes) together under a common name.
// It provides a way to avoid naming conflicts and organizes code into logical units.

// Namespaces are used to create separate scopes or contexts within a program. The main purpose is to prevent naming collisions between different entities
// with the same name. By placing related declarations inside a namespace, you can ensure that they are unique and easily identifiable.

// Here's an example of how namespaces can be used in C++:
#include <iostream>

// Declaration of a namespace
namespace MyNamespace {
    int x = 5;
    
    void display() {
        std::cout << "Value of x: " << x << std::endl;
    }
}

int main() {
    // Accessing the variable and function from the namespace
    MyNamespace::display();
    std::cout << "Value of x from the namespace: " << MyNamespace::x << std::endl;
    
    // Using the 'using' directive to avoid repetitive namespace qualification
    using namespace MyNamespace;
    display();
    std::cout << "Value of x from the namespace using 'using' directive: " << x << std::endl;
    
    return 0;
}
// In the above example, MyNamespace is a namespace that contains the variable x and the function display(). 
// By using the scope resolution operator ::, we can access these entities from within the namespace. Alternatively, we can use the using directive
// to avoid repetitive qualification and directly access the entities.

// Namespaces are particularly useful when working with large codebases, libraries, or when integrating different third-party libraries, as they help avoid
// conflicts between identifiers and improve code organization.
