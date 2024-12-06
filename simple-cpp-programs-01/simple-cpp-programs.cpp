#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm> // For std::max
using namespace std;

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

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string BLUE = "\033[34m";

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

// Function implementations
void helloWorld() {
    cout << GREEN << "Hello, World!" << RESET << endl;
}

void checkPositiveNegative() {
    int num;
    cout << YELLOW << "Enter a number: " << RESET;
    cin >> num;
    cout << CYAN << (num >= 0 ? "Positive" : "Negative") << RESET << endl;
}

void reverseNumber() {
    int num;
    cout << YELLOW << "Enter a number to reverse: " << RESET;
    cin >> num;
    cout << CYAN << "Reversed number: " << reverseRecursively(num) << RESET << endl;
}

int reverseRecursively(int num, int rev) {
    if (num == 0) return rev;
    return reverseRecursively(num / 10, rev * 10 + num % 10);
}

void greatestOfThree() {
    int a, b, c;
    cout << YELLOW << "Enter three numbers: " << RESET;
    cin >> a >> b >> c;
    int greatest = max(a, max(b, c)); // Nested max calls
    cout << CYAN << "Greatest number: " << greatest << RESET << endl;
}

void fibonacciSeries() {
    int n1 = 0, n2 = 1, next, range;
    cout << YELLOW << "Enter the range for Fibonacci series: " << RESET;
    cin >> range;
    cout << CYAN << "Fibonacci series: " << RESET;
    for (int i = 1; i <= range; ++i) {
        cout << n1 << " ";
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
    cout << endl;
}

void factorial() {
    int num;
    cout << YELLOW << "Enter a number: " << RESET;
    cin >> num;
    unsigned long long fact = 1;
    for (int i = 1; i <= num; ++i) fact *= i;
    cout << CYAN << "Factorial: " << fact << RESET << endl;
}

void primeNumbers() {
    int start, end;
    cout << YELLOW << "Enter the range (start and end): " << RESET;
    cin >> start >> end;
    cout << CYAN << "Prime numbers: " << RESET;
    for (int num = start; num <= end; ++num) {
        bool isPrime = true;
        if (num < 2) continue;
        for (int i = 2; i <= sqrt(num); ++i)
            if (num % i == 0) { isPrime = false; break; }
        if (isPrime) cout << num << " ";
    }
    cout << endl;
}

void checkArmstrong() {
    int num, sum = 0, temp, digit;
    cout << YELLOW << "Enter a number: " << RESET;
    cin >> num;
    temp = num;
    while (temp > 0) {
        digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }
    cout << CYAN << (sum == num ? "Armstrong number" : "Not an Armstrong number") << RESET << endl;
}

void checkPalindrome() {
    int num;
    cout << YELLOW << "Enter a number: " << RESET;
    cin >> num;
    cout << CYAN << (num == reverseRecursively(num) ? "Palindrome" : "Not a palindrome") << RESET << endl;
}

void displayPalindromes() {
    int start, end;
    cout << YELLOW << "Enter the range (start and end): " << RESET;
    cin >> start >> end;
    cout << CYAN << "Palindrome numbers: " << RESET;
    for (int num = start; num <= end; ++num)
        if (num == reverseRecursively(num)) cout << num << " ";
    cout << endl;
}

void asciiValue() {
    char ch;
    cout << YELLOW << "Enter a character: " << RESET;
    cin >> ch;
    cout << CYAN << "ASCII value: " << static_cast<int>(ch) << RESET << endl;
}

void findSizes() {
    cout << CYAN << "Size of int: " << sizeof(int) << " bytes\n"
         << "Size of float: " << sizeof(float) << " bytes\n"
         << "Size of double: " << sizeof(double) << " bytes\n"
         << "Size of char: " << sizeof(char) << " bytes" << RESET << endl;
}

void sumNaturalNumbers() {
    int n;
    cout << YELLOW << "Enter n: " << RESET;
    cin >> n;
    cout << CYAN << "Sum: " << n * (n + 1) / 2 << RESET << endl;
}

void printInteger() {
    int num;
    cout << YELLOW << "Enter an integer: " << RESET;
    cin >> num;
    cout << CYAN << "You entered: " << num << RESET << endl;
}
