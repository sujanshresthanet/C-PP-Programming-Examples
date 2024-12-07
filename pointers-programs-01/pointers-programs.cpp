#include <iostream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

// Function prototypes
void findLargestUsingPointers();
void countVowelsAndConsonants();
void printStringUsingPointer();
void swapUsingPointers();
void initializeAccessPointer();
void accessArrayElementsUsingPointer();
void clearInputStream();

int main() {
    int choice;
    do {
        cout << YELLOW "Choose a program to execute:" RESET << endl;
        cout << GREEN "1. Find the largest of three numbers using pointers" RESET << endl;
        cout << GREEN "2. Count vowels and consonants in a string using a pointer" RESET << endl;
        cout << GREEN "3. Print string using a pointer" RESET << endl;
        cout << GREEN "4. Swap two numbers using pointers" RESET << endl;
        cout << GREEN "5. Initialize and access a pointer variable" RESET << endl;
        cout << GREEN "6. Access array elements using a pointer" RESET << endl;
        cout << RED "0. Exit" RESET << endl;

        cout << CYAN "Enter your choice: " RESET;
        cin >> choice;

        if (cin.fail()) {
            cout << RED "Invalid input. Please enter a number." RESET << endl;
            clearInputStream();
            continue;
        }

        switch (choice) {
            case 1:
                findLargestUsingPointers();
                break;
            case 2:
                countVowelsAndConsonants();
                break;
            case 3:
                printStringUsingPointer();
                break;
            case 4:
                swapUsingPointers();
                break;
            case 5:
                initializeAccessPointer();
                break;
            case 6:
                accessArrayElementsUsingPointer();
                break;
            case 0:
                cout << RED "Exiting program. Goodbye!" RESET << endl;
                break;
            default:
                cout << RED "Invalid choice. Please select a valid option." RESET << endl;
        }
    } while (choice != 0);

    return 0;
}

void findLargestUsingPointers() {
    int a, b, c, *p1, *p2, *p3;
    cout << CYAN "Enter three numbers: " RESET;
    if (!(cin >> a >> b >> c)) {
        cout << RED "Invalid input. Please enter valid numbers." RESET << endl;
        clearInputStream();
        return;
    }

    p1 = &a; p2 = &b; p3 = &c;
    int largest = (*p1 > *p2) ? ((*p1 > *p3) ? *p1 : *p3) : ((*p2 > *p3) ? *p2 : *p3);
    cout << GREEN "The largest number is: " << largest << RESET << endl;
}

void countVowelsAndConsonants() {
    string str;
    cout << CYAN "Enter a string: " RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    getline(cin, str);

    const char *p = str.c_str();
    int vowels = 0, consonants = 0;

    while (*p) {
        if (isalpha(*p)) {
            char ch = tolower(*p);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        p++;
    }

    cout << GREEN "Vowels: " << vowels << ", Consonants: " << consonants << RESET << endl;
}

void printStringUsingPointer() {
    string str;
    cout << CYAN "Enter a string: " RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    getline(cin, str);

    const char *p = str.c_str();
    cout << GREEN "The string is: ";
    while (*p) {
        cout << *p;
        p++;
    }
    cout << RESET << endl;
}

void swapUsingPointers() {
    int x, y, *p1, *p2;
    cout << CYAN "Enter two numbers to swap: " RESET;
    if (!(cin >> x >> y)) {
        cout << RED "Invalid input. Please enter valid numbers." RESET << endl;
        clearInputStream();
        return;
    }

    p1 = &x;
    p2 = &y;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << GREEN "After swapping: x = " << x << ", y = " << y << RESET << endl;
}

void initializeAccessPointer() {
    int var = 42;
    int *p = &var;
    cout << GREEN "Value of variable: " << *p << RESET << endl;
    cout << GREEN "Address of variable: " << p << RESET << endl;
}

void accessArrayElementsUsingPointer() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    cout << GREEN "Array elements are: ";
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
    }
    cout << RESET << endl;
}

// Function to clear the input stream in case of invalid input
void clearInputStream() {
    cin.clear(); // Clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
}
