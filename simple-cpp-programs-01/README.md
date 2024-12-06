Simple C++ Programs
===================

Interactive C++ programs with various functionalities.

Introduction
------------

This repository contains a C++ program that demonstrates several simple programming concepts such as:

*   Hello World Program
*   Number checks (Positive/Negative, Armstrong, Palindrome, etc.)
*   Recursion examples (Reverse a number)
*   Mathematical operations (Factorial, Fibonacci, Prime numbers, etc.)

Features
--------

The program allows users to choose from a list of different functionalities:

*   Hello World Program in C++
*   Check if a number is positive or negative
*   Reverse an input number using recursion
*   Find the greatest of three numbers
*   Print Fibonacci series in a range
*   Find factorial of a given number
*   Find prime numbers in a range
*   Check if a number is Armstrong
*   Check if a number is a palindrome
*   Display palindrome numbers in a range
*   Find ASCII value of a character
*   Find size of data types like int, float, double, char
*   Sum of first n natural numbers
*   Print the integer entered by the user
*   Exit the program

Code Explanation
----------------

The program is implemented using functions for each of the listed functionalities. The code uses simple user input and output mechanisms with some basic control flow like loops and conditionals. Here's a brief overview of the main components:

### Code Implementation

    
    #include 
    #include 
    #include 
    #include 
    #include  // For std::max
    using namespace std;
    
    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string CYAN = "\033[36m";
    const string BLUE = "\033[34m";
    
    // Function prototypes
    void helloWorld();
    void checkPositiveNegative();
    void reverseNumber();
    int reverseRecursively(int num, int rev = 0);
    void greatestOfThree();
    void fibonacciSeries();
    void factorial();
    void primeNumbers();
    void checkArmstrong();
    void checkPalindrome();
    void displayPalindromes();
    void asciiValue();
    void findSizes();
    void sumNaturalNumbers();
    void printInteger();
    
    int main() {
        while (true) {
            cout << GREEN << "Choose an option:" << RESET << endl;
            cout << CYAN << "1. Hello World Program in C++\n"
                 << "2. Check if a number is positive or negative\n"
                 << "3. Reverse an input number using recursion\n"
                 << "4. Find the greatest of three numbers\n"
                 << "5. Print Fibonacci series in a range\n"
                 << "6. Find factorial of a given number\n"
                 << "7. Find prime numbers in a range\n"
                 << "8. Check if a number is Armstrong\n"
                 << "9. Check if a number is palindrome\n"
                 << "10. Display palindrome numbers in a range\n"
                 << "11. Find ASCII value of a character\n"
                 << "12. Find size of int, float, double, and char\n"
                 << "13. Sum of first n natural numbers\n"
                 << "14. Print integer entered by user\n"
                 << "15. Exit" << RESET << endl;
    
            cout << YELLOW << "Enter your choice: " << RESET;
            int choice;
            cin >> choice;
    
            switch (choice) {
                case 1: helloWorld(); break;
                case 2: checkPositiveNegative(); break;
                case 3: reverseNumber(); break;
                case 4: greatestOfThree(); break;
                case 5: fibonacciSeries(); break;
                case 6: factorial(); break;
                case 7: primeNumbers(); break;
                case 8: checkArmstrong(); break;
                case 9: checkPalindrome(); break;
                case 10: displayPalindromes(); break;
                case 11: asciiValue(); break;
                case 12: findSizes(); break;
                case 13: sumNaturalNumbers(); break;
                case 14: printInteger(); break;
                case 15: cout << RED << "Exiting program. Goodbye!" << RESET << endl; return 0;
                default: cout << RED << "Invalid choice. Try again!" << RESET << endl;
            }
            cout << endl;
        }
    }
        

How to Run
----------

Follow these steps to compile and run the C++ program:

### Step 1: Clone the Repository

    git clone https://github.com/sujanshresthanet/C-PP-Programming-Examples.git

### Step 2: Compile the Program

Open a terminal and navigate to the directory where the code is located. Then, run the following command to compile the code:

    g++ -o simple-cpp-programs simple-cpp-programs.cpp

### Step 3: Run the Program

After successful compilation, run the program by executing:

    ./simple-cpp-programs

### Step 4: Follow the On-Screen Instructions

The program will prompt you to select an option by entering the corresponding number. After that, the program will execute the functionality and display the result.

Contributing
------------

Feel free to fork this repository, make changes, and submit pull requests. Contributions are welcome!

