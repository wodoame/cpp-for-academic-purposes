// In C++, strings are typically handled using the `std::string` class, which provides a wide range of methods to manipulate and operate on strings. 
// Here are some commonly used methods of `std::string` in C++:

// 1. `length()` or `size()`: Returns the length of the string.
// ```cpp
std::string str = "Hello, World!";
int length = str.length();  // or str.size();
```

// 2. `empty()`: Checks if the string is empty.
// ```cpp
std::string str = "Hello";
if (str.empty()) {
    // String is empty
}
```

// 3. `clear()`: Clears the contents of the string.
// ```cpp
std::string str = "Hello";
str.clear();  // str is now an empty string
```

// 4. `append()`: Appends another string or a part of it to the current string.
// ```cpp
std::string str = "Hello";
str.append(" World!");  // str is now "Hello World!"
```

// 5. `substr()`: Extracts a substring from the current string.
// ```cpp
std::string str = "Hello, World!";
std::string substr = str.substr(7, 5);  // substr is "World"
```

// 6. `find()`: Searches for a substring within the current string.
// ```cpp
std::string str = "Hello, World!";
size_t found = str.find("World");  // found is 7
```

// 7. `replace()`: Replaces a portion of the string with another string.
// ```cpp
std::string str = "Hello, World!";
str.replace(7, 5, "People");  // str is now "Hello, People!"
```

// 8. `compare()`: Compares two strings.
// ```cpp
std::string str1 = "Hello";
std::string str2 = "World";
int result = str1.compare(str2);  // result is a negative value since "Hello" comes before "World"
```

// 9. `c_str()`: Returns a C-style string (null-terminated character array) representing the contents of the string.
// ```cpp
std::string str = "Hello";
const char* cstr = str.c_str();
```

These are just a few examples of the many methods available for `std::string` in C++. For more details and additional functionality, you can refer to the C++ documentation or relevant C++ programming resources.
  
