Simple C++ Calculator
=====================

A command-line calculator program written in C++ that supports basic arithmetic operations: addition, subtraction, multiplication, and division.

Features
--------

*   Menu-based user interface
*   Supports the following operations:
    *   Addition (+)
    *   Subtraction (-)
    *   Multiplication (\*)
    *   Division (/)
*   Error handling for division by zero
*   Option to exit the program

Usage
-----

1.  Clone or download the source code to your local machine.
2.  Ensure you have a C++ compiler installed, such as `g++`.
3.  Save the code into a file named `calculator.cpp`.
4.  Open a terminal or command prompt and navigate to the directory containing the file.
5.  Compile the program using the following command:
    
        g++ calculator.cpp -o calculator
    
6.  Run the program using:
    
        ./calculator    # On Linux/Mac
        calculator.exe  # On Windows
    
7.  Follow the on-screen menu to perform calculations:
    *   Enter two numbers when prompted.
    *   Select an operation from the menu (1 for addition, 2 for subtraction, etc.).
    *   View the result or error message (e.g., division by zero).
    *   Repeat or enter `5` to exit the program.

Code Structure
--------------

*   **displayMenu()**: Displays the main menu with operation choices.
*   **add()**: Function for addition.
*   **subtract()**: Function for subtraction.
*   **multiply()**: Function for multiplication.
*   **divide()**: Function for division with error handling for division by zero.
*   All functionality is integrated into a loop for continuous usage until the user exits.

Example
-------

    
    ===========================
           Simple Calculator   
    ===========================
    1. Addition (+)
    2. Subtraction (-)
    3. Multiplication (*)
    4. Division (/)
    5. Exit
    ===========================
    Enter your choice (1-5): 1
    Enter first number: 10
    Enter second number: 20
    Result: 10 + 20 = 30
    

System Requirements
-------------------

*   C++ compiler (e.g., `g++`)
*   Operating System: Linux, macOS, or Windows
*   Terminal or command prompt

License
-------

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).