#include <iostream>
#include <iomanip>
#include <cctype> // for isalpha()
using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";

void checkOddEven() {
    cout << CYAN << "Enter a number: " << RESET;
    int num;
    cin >> num;
    if (num % 2 == 0)
        cout << GREEN << num << " is Even." << RESET << endl;
    else
        cout << RED << num << " is Odd." << RESET << endl;
}

void checkVowelConsonant() {
    cout << CYAN << "Enter an alphabet: " << RESET;
    char ch;
    cin >> ch;
    ch = tolower(ch);
    if (isalpha(ch)) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cout << GREEN << ch << " is a Vowel." << RESET << endl;
        else
            cout << RED << ch << " is a Consonant." << RESET << endl;
    } else {
        cout << RED << "Invalid input! Please enter an alphabet." << RESET << endl;
    }
}

void checkLeapYear() {
    cout << CYAN << "Enter a year: " << RESET;
    int year;
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        cout << GREEN << year << " is a Leap Year." << RESET << endl;
    else
        cout << RED << year << " is not a Leap Year." << RESET << endl;
}

void generateMultiplicationTable() {
    cout << CYAN << "Enter a number for the multiplication table: " << RESET;
    int num;
    cin >> num;
    cout << GREEN << "Multiplication Table for " << num << ":" << RESET << endl;
    for (int i = 1; i <= 10; ++i) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}

void displayAlphabet() {
    cout << GREEN << "Characters from 'A' to 'Z':" << RESET << endl;
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        cout << ch << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        cout << YELLOW << "\nSelect an option:" << RESET << endl;
        cout << BLUE << "1. Check if a number is Odd or Even" << RESET << endl;
        cout << BLUE << "2. Check if an alphabet is Vowel or Consonant" << RESET << endl;
        cout << BLUE << "3. Check if a year is a Leap Year" << RESET << endl;
        cout << BLUE << "4. Generate Multiplication Table" << RESET << endl;
        cout << BLUE << "5. Display characters from 'A' to 'Z'" << RESET << endl;
        cout << BLUE << "6. Exit" << RESET << endl;

        cout << CYAN << "Enter your choice: " << RESET;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                checkOddEven();
                break;
            case 2:
                checkVowelConsonant();
                break;
            case 3:
                checkLeapYear();
                break;
            case 4:
                generateMultiplicationTable();
                break;
            case 5:
                displayAlphabet();
                break;
            case 6:
                cout << GREEN << "Exiting... Goodbye!" << RESET << endl;
                return 0;
            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
        }
    }
}
