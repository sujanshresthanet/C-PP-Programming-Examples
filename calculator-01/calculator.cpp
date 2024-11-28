#include <iostream>
#include <iomanip>

using namespace std;

// Function declarations
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2, result;
    int choice;

    do {
        // Display the menu to the user
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    result = subtract(num1, num2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    result = multiply(num1, num2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    if (num2 != 0) {
                        result = divide(num1, num2);
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    } else {
                        cout << "Error: Division by zero is not allowed." << endl;
                    }
                    break;
                default:
                    break;
            }
        } else if (choice == 5) {
            cout << "Exiting the calculator. Thank you!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "===========================" << endl;
    cout << "       Simple Calculator   " << endl;
    cout << "===========================" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exit" << endl;
    cout << "===========================" << endl;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}
