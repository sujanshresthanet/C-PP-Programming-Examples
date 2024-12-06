#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

// ANSI Color Codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

// Function Prototypes
void addTwoIntegers();
void gcdOfTwoNumbers();
void lcmOfTwoNumbers();
void checkPrimeNumber();
void countDigits();
void powerOfNumber();
void printPrimes();
void armstrongNumbers();
void checkDivisibleBy3And5();
void numbersDivisibleBy3And5();
void checkAbundantNumber();
void sumOfDigits();
void displayFactors();
void swapFirstLastDigits();
void cubeOfNumbers();

// Main Function
int main() {
    while (true) {
        cout << YELLOW << "\nChoose an option from the following menu:" << RESET << endl;
        cout << CYAN << "1. Add two integers\n"
             << "2. Find GCD of two numbers\n"
             << "3. Find LCM of two numbers\n"
             << "4. Check whether number is prime or not\n"
             << "5. Count number of digits in an integer\n"
             << "6. Calculate the power of a number\n"
             << "7. Print prime numbers from 1 to 100 (1 to N)\n"
             << "8. Display Armstrong numbers between two intervals\n"
             << "9. Check if a number is divisible by 3 and 5\n"
             << "10. Print numbers divisible by 3 and 5 from 1 to 100\n"
             << "11. Check abundant number\n"
             << "12. Find sum of digits of a number\n"
             << "13. Display factors of a number\n"
             << "14. Swap first and last digits of a number\n"
             << "15. Print cube of a number up to an integer\n"
             << "16. Exit\n"
             << RESET;

        cout << BLUE << "Enter your choice: " << RESET;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: addTwoIntegers(); break;
            case 2: gcdOfTwoNumbers(); break;
            case 3: lcmOfTwoNumbers(); break;
            case 4: checkPrimeNumber(); break;
            case 5: countDigits(); break;
            case 6: powerOfNumber(); break;
            case 7: printPrimes(); break;
            case 8: armstrongNumbers(); break;
            case 9: checkDivisibleBy3And5(); break;
            case 10: numbersDivisibleBy3And5(); break;
            case 11: checkAbundantNumber(); break;
            case 12: sumOfDigits(); break;
            case 13: displayFactors(); break;
            case 14: swapFirstLastDigits(); break;
            case 15: cubeOfNumbers(); break;
            case 16: cout << GREEN << "Exiting the program. Goodbye!" << RESET << endl; return 0;
            default: cout << RED << "Invalid choice! Please try again." << RESET << endl;
        }
    }
    return 0;
}

// Function Implementations
void addTwoIntegers() {
    int a, b;
    cout << GREEN << "Enter two integers: " << RESET;
    cin >> a >> b;
    cout << MAGENTA << "Sum: " << (a + b) << RESET << endl;
}

void gcdOfTwoNumbers() {
    int a, b;
    cout << GREEN << "Enter two integers: " << RESET;
    cin >> a >> b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout << MAGENTA << "GCD: " << a << RESET << endl;
}

void lcmOfTwoNumbers() {
    int a, b;
    cout << GREEN << "Enter two integers: " << RESET;
    cin >> a >> b;
    int gcd = a;
    int tempB = b;
    while (tempB != 0) {
        int temp = tempB;
        tempB = gcd % tempB;
        gcd = temp;
    }
    cout << MAGENTA << "LCM: " << (a * b) / gcd << RESET << endl;
}

void checkPrimeNumber() {
    int n;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    bool isPrime = n > 1;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    cout << MAGENTA << n << (isPrime ? " is " : " is not ") << "a prime number." << RESET << endl;
}

void countDigits() {
    int n, count = 0;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    n = abs(n);
    do {
        n /= 10;
        ++count;
    } while (n != 0);
    cout << MAGENTA << "Number of digits: " << count << RESET << endl;
}

void powerOfNumber() {
    double base, exponent;
    cout << GREEN << "Enter base and exponent: " << RESET;
    cin >> base >> exponent;
    cout << MAGENTA << "Result: " << pow(base, exponent) << RESET << endl;
}

void printPrimes() {
    int n;
    cout << GREEN << "Enter the limit N: " << RESET;
    cin >> n;
    cout << MAGENTA << "Prime numbers: ";
    for (int i = 2; i <= n; ++i) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) cout << i << " ";
    }
    cout << RESET << endl;
}

void armstrongNumbers() {
    int low, high;
    cout << GREEN << "Enter the lower and upper intervals: " << RESET;
    cin >> low >> high;
    cout << MAGENTA << "Armstrong numbers: ";
    for (int num = low; num <= high; ++num) {
        int sum = 0, temp = num, digits = 0;
        while (temp) {
            ++digits;
            temp /= 10;
        }
        temp = num;
        while (temp) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }
        if (sum == num) cout << num << " ";
    }
    cout << RESET << endl;
}

void checkDivisibleBy3And5() {
    int n;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    cout << MAGENTA << n << (n % 3 == 0 && n % 5 == 0 ? " is " : " is not ") << "divisible by 3 and 5." << RESET << endl;
}

void numbersDivisibleBy3And5() {
    cout << MAGENTA << "Numbers divisible by 3 and 5: ";
    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0 && i % 5 == 0) cout << i << " ";
    }
    cout << RESET << endl;
}

void checkAbundantNumber() {
    int n, sum = 0;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) sum += i;
    }
    cout << MAGENTA << n << (sum > n ? " is " : " is not ") << "an abundant number." << RESET << endl;
}

void sumOfDigits() {
    int n, sum = 0;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    n = abs(n);
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    cout << MAGENTA << "Sum of digits: " << sum << RESET << endl;
}

void displayFactors() {
    int n;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    cout << MAGENTA << "Factors: ";
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) cout << i << " ";
    }
    cout << RESET << endl;
}

void swapFirstLastDigits() {
    int n;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    string s = to_string(abs(n));
    swap(s[0], s[s.length() - 1]);
    cout << MAGENTA << "Number after swapping: " << (n < 0 ? "-" : "") << s << RESET << endl;
}

void cubeOfNumbers() {
    int n;
    cout << GREEN << "Enter an integer: " << RESET;
    cin >> n;
    cout << MAGENTA << "Cubes up to " << n << ": ";
    for (int i = 1; i <= n; ++i) {
        cout << i * i * i << " ";
    }
    cout << RESET << endl;
}
