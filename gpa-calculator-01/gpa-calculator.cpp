#include <iostream>
#include <iomanip>  // For setting precision
#include <string>
#include <limits>
#include <cctype>   // For toupper() function

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
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
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
