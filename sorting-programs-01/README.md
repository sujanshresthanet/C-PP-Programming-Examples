Sorting Algorithm Selector
==========================

A C++ program that allows the user to choose from different sorting algorithms, input an array, and see the sorted output. The program features a colorful terminal interface for a better user experience.

Features
--------

*   Allows the user to choose from the following sorting algorithms:
    *   Bubble Sort
    *   Insertion Sort
    *   Selection Sort
    *   Quicksort
*   Supports colorful terminal output:
    *   Green: Menu options
    *   Cyan: User inputs
    *   Blue: Sorted array output
    *   Red: Error messages
*   Handles input validation for the menu choice.

Prerequisites
-------------

*   A C++ compiler (e.g., g++, clang++)
*   A terminal that supports ANSI escape codes for colorful output

How to Run
----------

1.  Clone or download this repository to your local machine.
2.  Navigate to the directory where the program file is located.
3.  Compile the program using a C++ compiler. For example:
    
        g++ -o sorting_program sorting_program.cpp
    
4.  Run the compiled program:
    
        ./sorting_program
    
5.  Follow the on-screen instructions:
    *   Choose a sorting algorithm by entering the corresponding number (1-4).
    *   Enter the number of elements you want to sort.
    *   Input the elements of the array.
6.  View the sorted array displayed in colorful output.

Example Usage
-------------

1.  Run the program:
    
        ./sorting_program
    
2.  Choose an algorithm:
    
        Choose a sorting algorithm:
        1. Bubble Sort
        2. Insertion Sort
        3. Selection Sort
        4. Quicksort
        Enter your choice (1-4): 2
    
3.  Input the array details:
    
        Enter the number of elements: 5
        Enter the elements:
        5 3 8 6 2
    
4.  View the sorted output:
    
        Sorted Array: 2 3 5 6 8
    

Dependencies
------------

No external libraries are required. The program uses standard C++ libraries for functionality.

Contributing
------------

If you'd like to contribute, feel free to fork this repository, make your changes, and submit a pull request. Suggestions for additional sorting algorithms or features are welcome!
