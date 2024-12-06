C++ String Operations Program
=============================

Description
-----------

This C++ program allows users to perform a variety of string manipulation operations. The available operations include converting strings between uppercase and lowercase, sorting strings, finding the length of a string, concatenating two strings, reversing a string using recursion, finding the frequency of characters in a string, searching for a substring, and replacing the first vowel in a string with a hyphen ("-"). The program continuously prompts the user to select an option until the user chooses to exit.

Features
--------

*   Convert string from uppercase to lowercase.
*   Convert string from lowercase to uppercase.
*   Sort a set of strings in ascending alphabetical order.
*   Find the length of a string without using `strlen()`.
*   Concatenate two strings without using `strcat()`.
*   Reverse a string using recursion.
*   Find frequency of characters in a string.
*   Search for a substring in a given string.
*   Replace the first vowel in a string with a hyphen ("-").
*   Colorful output for user interaction and results.
*   Clear user inputs between operations to ensure accurate handling.

How to Run the Program
----------------------

### Prerequisites

*   C++ compiler such as `g++` or any IDE that supports C++ programming (e.g., Visual Studio, Code::Blocks, or CLion).
*   Basic knowledge of C++ programming and the C++ Standard Library.

### Steps to Compile and Run

1.  Copy the code into a text file and save it as `string-programs.cpp`.
2.  Open a terminal or command prompt.
3.  Navigate to the directory where the file is saved.
4.  Compile the program using the following command:
    
    g++ -o string-programs string-programs.cpp
    
5.  Run the compiled program:
    
    ./string-programs
    
6.  Follow the on-screen prompts to select the desired string operation.
7.  The program will output the results with colorful formatting and allow you to continue performing operations until you choose to exit.

Code Explanation
----------------

The program begins by displaying a menu with different string manipulation options. The user selects an operation, and the program performs the corresponding string operation. The program uses C++ standard libraries like `iostream`, `string`, and `algorithm` to manipulate strings. Operations include converting case, reversing a string, sorting characters, and more. Each option is handled by a dedicated function that performs the specific task, ensuring modularity and ease of understanding.

Colorful Output
---------------

The program uses ANSI escape codes to add color to the output. These escape codes are supported by many terminals and console applications. Each operation's output is colored differently to improve the user experience:

*   Green for converted strings (e.g., lowercase).
*   Blue for other types of output (e.g., uppercase conversion).
*   Yellow for sorted strings.
*   Cyan for string length and other results.
*   Red for errors and invalid input.
*   Magenta for concatenation and vowel replacement results.

Sample Output
-------------

    Choose a String Operation:
    1. Convert string from upper case to lower case
    2. Convert string from lower case to upper case
    3. Sort a set of strings in ascending alphabetical order
    4. Find length of a string without using strlen()
    5. String concatenation without using strcat
    6. Reverse a String using recursion
    7. Find frequency of characters in a string
    8. Search substring in a given string
    9. Replace first occurrence of vowel with '-' in a string
    10. Exit
    Enter your choice (1-10): 1
    Enter the string (Uppercase): HELLO WORLD
    Converted String (Lowercase): hello world

    Choose a String Operation:
    1. Convert string from upper case to lower case
    2. Convert string from lower case to upper case
    3. Sort a set of strings in ascending alphabetical order
    4. Find length of a string without using strlen()
    5. String concatenation without using strcat
    6. Reverse a String using recursion
    7. Find frequency of characters in a string
    8. Search substring in a given string
    9. Replace first occurrence of vowel with '-' in a string
    10. Exit
    Enter your choice (1-10): 2
    Enter the string (Lowercase): hello world
    Converted String (Uppercase): HELLO WORLD
    

Exiting the Program
-------------------

To exit the program, select option **10** and press Enter. The program will display a goodbye message and terminate.

Conclusion
----------

This C++ program is an excellent way to practice and understand various string manipulation techniques in C++. The use of colorful output enhances the user interface, and the continuous prompting for new operations makes it a handy tool for string-related tasks.