CGPA Calculator in C++
======================

Overview
--------

This is a **CGPA Calculator** program implemented in **C++**. The program allows users to enter the number of subjects, their respective credits, and grades for each subject. Based on the entered data, it calculates the **Cumulative Grade Point Average (CGPA)**.

The program supports both **upper and lower case** grade entries (e.g., `A`, `a`, `B`, `b`) and performs input validation to ensure the entered values for credits and grades are correct.

Key Features:
-------------

*   **User-friendly interaction**: Provides prompt messages with color-coded inputs and outputs.
*   **Handles invalid inputs**: Ensures the program does not crash on invalid inputs (e.g., non-numeric credits, invalid grades).
*   **Color-coded text**: Uses ANSI escape sequences for colored text to differentiate between instructions, user inputs, and errors.

Requirements
------------

*   C++ compiler (e.g., GCC, Clang)
*   C++11 or later (for handling standard libraries)

Code Explanation
----------------

### Functions:

*   **getGradePoint(char grade)**: This function converts the entered grade (e.g., `A`, `B`, `C`, `D`, `F`) to its corresponding grade point value. It returns `-1` for invalid grades.
*   **setColor(int color)**: This function sets the text color using ANSI escape sequences. Different colors are used for input prompts, errors, and output.
*   **resetColor()**: This function resets the color back to the default terminal color.

How to Run
----------

Follow these steps to compile and run the CGPA calculator program:

### Step 1: Save the Code

Save the C++ code in a file with the extension `.cpp` (e.g., `gpa-calculator.cpp`).

### Step 2: Compile the Code

Use a C++ compiler to compile the code. If you're using **GCC**, the command will be:

    g++ gpa-calculator.cpp -o gpa-calculator

### Step 3: Run the Program

Once compiled, run the program using the following command:

    ./gpa-calculator

### Sample Output:

    
    Welcome to the CGPA Calculator!
    Please enter the number of subjects: 3
    Enter the credits for subject 1: 3
    Enter the grade for subject 1 (A, B, C, D, F): B
    Enter the credits for subject 2: 4
    Enter the grade for subject 2 (A, B, C, D, F): A
    Enter the credits for subject 3: 2
    Enter the grade for subject 3 (A, B, C, D, F): D
    
    Your CGPA is: 3.03
        

Code Snippet
------------

The code implementation in C++ is as follows:

    
    #include 
    #include   // For setting precision
    #include 
    #include 
    #include    // For toupper() function
    
    using namespace std;
    
    // Function to get the grade points based on user input
    float getGradePoint(char grade) {
        grade = toupper(grade);  // Convert grade to uppercase
        switch(grade) {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            case 'F': return 0.0;
            default: return -1.0;  // Invalid grade
        }
    }
    
    // Function to set text color
    void setColor(int color) {
        // Colors for text
        cout << "\033[1;" << color << "m";
    }
    
    void resetColor() {
        cout << "\033[0m";  // Reset to default color
    }
    
    int main() {
        int numSubjects;
        
        // Set text color for instructions
        setColor(32);  // Green text for instructions
        cout << "Welcome to the CGPA Calculator!" << endl;
        resetColor();
    
        cout << "Please enter the number of subjects: ";
        cin >> numSubjects;
    
        // Handle invalid input for number of subjects
        if (cin.fail()) {
            setColor(31);  // Red for error
            cout << "Invalid input. Please enter a valid number." << endl;
            resetColor();
            return 1;
        }
    
        float totalCredits = 0, totalGradePoints = 0;
    
        for (int i = 1; i <= numSubjects; ++i) {
            int credits;
            char grade;
    
            // Get valid credit input
            while (true) {
                setColor(34);  // Blue text for user input
                cout << "Enter the credits for subject " << i << ": ";
                resetColor();
                cin >> credits;
    
                // Check for valid credit input
                if (cin.fail() || credits <= 0) {
                    cin.clear(); // Clear input buffer to avoid infinite loop
                    cin.ignore(numeric_limits::max(), '\n'); // Ignore bad input
                    setColor(31);  // Red for error
                    cout << "Invalid credit value. Please enter a positive integer." << endl;
                    resetColor();
                } else {
                    break; // Exit loop on valid input
                }
            }
    
            // Get valid grade input
            while (true) {
                setColor(34);  // Blue text for grade input
                cout << "Enter the grade for subject " << i << " (A, B, C, D, F): ";
                resetColor();
                cin >> grade;
    
                // Validate the grade
                float gradePoint = getGradePoint(grade);
                if (gradePoint != -1.0) {
                    totalCredits += credits;
                    totalGradePoints += (credits * gradePoint);
                    break;  // Exit loop on valid grade
                } else {
                    setColor(31);  // Red for error
                    cout << "Invalid grade entered. Please enter A, B, C, D, or F." << endl;
                    resetColor();
                }
            }
        }
    
        if (totalCredits == 0) {
            setColor(31);  // Red for error
            cout << "Total credits cannot be zero. Please check your input." << endl;
            resetColor();
            return 1;
        }
    
        float cgpa = totalGradePoints / totalCredits;
    
        // Set color for CGPA result
        setColor(36);  // Cyan for output
        cout << fixed << setprecision(2);  // Set precision for CGPA
        cout << "\nYour CGPA is: " << cgpa << endl;
        resetColor();
    
        return 0;
    }