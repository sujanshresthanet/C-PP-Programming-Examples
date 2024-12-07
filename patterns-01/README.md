  README - Pattern Generator

Pattern Generator in C++
========================

This program allows users to generate 20 different patterns using C++. The patterns range from basic shapes like squares and triangles to advanced ones like Pascal's triangle and hollow patterns.

Features
--------

*   20 pre-defined patterns to choose from.
*   Color-coded menu options and input/output for better user experience.
*   Dynamic user input for pattern size.
*   Graceful handling of invalid inputs.
*   Easy-to-read code structure with separate functions for each pattern.

Available Patterns
------------------

1.  Square of \*
2.  Right Triangle
3.  Inverted Right Triangle
4.  Pyramid
5.  Inverted Pyramid
6.  Diamond
7.  Numbers Right Triangle
8.  Pascal's Triangle
9.  Floyd's Triangle
10.  Checkerboard Pattern
11.  Zig-Zag Pattern
12.  Reverse Numbers Triangle
13.  Hollow Square
14.  Alphabet Triangle
15.  Hollow Triangle
16.  Alternating Numbers Triangle
17.  Right Triangle with Spaces
18.  Number Pyramid
19.  Hollow Pyramid
20.  Spiral Pattern

How to Run the Code
-------------------

1.  Make sure you have a C++ compiler installed, such as `g++`.
2.  Download or copy the source code into a file named `patterns.cpp`.
3.  Open a terminal or command prompt and navigate to the directory where the file is located.
4.  Compile the code using the following command:
    
        g++ patterns.cpp -o patterns
    
5.  Run the executable using:
    
        ./patterns
    

Usage
-----

1.  On running the program, you will see a menu of 20 patterns to choose from.
2.  Enter the number corresponding to the pattern you want to display.
3.  Provide the size of the pattern (e.g., 5 for a 5x5 grid).
4.  The selected pattern will be displayed on the console.
5.  You can choose another pattern or exit by entering `0`.

Example Output
--------------

For a pattern size of 5, choosing **Right Triangle** (option 2):

    * 
    * * 
    * * * 
    * * * * 
    * * * * * 
    

Requirements
------------

*   C++17 or later (for modern C++ features).
*   A terminal or console that supports ANSI escape codes for colors.

Customization
-------------

You can add more patterns by creating new functions following the existing structure. Update the `patterns` vector and `displayPatterns` menu to include your custom patterns.

License
-------

This project is open-source and available for educational purposes.