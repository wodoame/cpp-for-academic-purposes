In C++, a **constructor** is a special member function of a class that initializes objects. It is automatically invoked when an object of the class is created. Here's an overview:

---

### **Key Features of Constructors**
1. **Name**: The name of the constructor is the same as the class name.
2. **No Return Type**: Constructors do not have a return type, not even `void`.
3. **Automatic Invocation**: Called automatically when an object is created.
4. **Overloading**: Constructors can be overloaded, meaning you can have multiple constructors with different parameter lists.

---

### **Types of Constructors**

1. **Default Constructor**:
   - Takes no arguments.
   - Provides default values to the object's attributes.

   ```cpp
   class MyClass {
   public:
       int x;

       // Default constructor
       MyClass() {
           x = 0;
           std::cout << "Default Constructor called. x = " << x << std::endl;
       }
   };

   int main() {
       MyClass obj; // Default constructor is called
       return 0;
   }
   ```

---

2. **Parameterized Constructor**:
   - Takes arguments to initialize the object with specific values.

   ```cpp
   class MyClass {
   public:
       int x;

       // Parameterized constructor
       MyClass(int value) {
           x = value;
           std::cout << "Parameterized Constructor called. x = " << x << std::endl;
       }
   };

   int main() {
       MyClass obj(42); // Parameterized constructor is called
       return 0;
   }
   ```

---

3. **Copy Constructor**:
   - Initializes an object by copying another object of the same class.

   ```cpp
   class MyClass {
   public:
       int x;

       // Parameterized constructor
       MyClass(int value) : x(value) {}

       // Copy constructor
       MyClass(const MyClass& other) {
           x = other.x;
           std::cout << "Copy Constructor called. x = " << x << std::endl;
       }
   };

   int main() {
       MyClass obj1(42);     // Parameterized constructor is called
       MyClass obj2 = obj1;  // Copy constructor is called
       return 0;
   }
   ```

---

4. **Defaulted and Deleted Constructors**:
   - A constructor can be explicitly declared as `default` or `delete`.

   ```cpp
   class MyClass {
   public:
       MyClass() = default;  // Compiler-generated default constructor
       MyClass(int) = delete; // Disables the constructor with an int parameter
   };

   int main() {
       MyClass obj1;    // Works fine
       // MyClass obj2(42); // Error: This constructor is deleted
       return 0;
   }
   ```

---

5. **Constructor Initialization List**:
   - Used to initialize members before the constructor body is executed.

   ```cpp
   class MyClass {
   public:
       int x;
       int y;

       // Constructor with initialization list
       MyClass(int a, int b) : x(a), y(b) {
           std::cout << "x = " << x << ", y = " << y << std::endl;
       }
   };

   int main() {
       MyClass obj(10, 20);
       return 0;
   }
   ```

---

### **Important Notes**
- Constructors cannot be virtual.
- If no constructor is provided, the compiler generates a default constructor.
- If any constructor is defined, the compiler does not generate a default constructor.
