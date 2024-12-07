#include <iostream>
#include <iomanip> // For std::setw
#include <string>
#include <vector>

using namespace std;

// ANSI Color Codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

// Pattern Functions
void pattern1(int n) { // Square of *
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << "* ";
        cout << endl;
    }
}

void pattern2(int n) { // Right Triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

void pattern3(int n) { // Inverted Right Triangle
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

void pattern4(int n) { // Pyramid
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ');
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

void pattern5(int n) { // Inverted Pyramid
    for (int i = n; i >= 1; i--) {
        cout << string(n - i, ' ');
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

void pattern6(int n) { // Diamond
    pattern4(n);
    for (int i = n - 1; i >= 1; i--) {
        cout << string(n - i, ' ');
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

void pattern7(int n) { // Numbers Right Triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
}

void pattern8(int n) { // Pascal's Triangle
    for (int i = 0; i < n; i++) {
        int val = 1;
        cout << string((n - i) * 2, ' ');
        for (int j = 0; j <= i; j++) {
            cout << val << "   ";
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

void pattern9(int n) { // Floyd's Triangle
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << num++ << " ";
        cout << endl;
    }
}

void pattern10(int n) { // Checkerboard Pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ((i + j) % 2 == 0 ? "* " : "  ");
        }
        cout << endl;
    }
}

void pattern11(int n) { // Zig-Zag Pattern
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern12(int n) { // Reverse Numbers Triangle
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) cout << j << " ";
        cout << endl;
    }
}

void pattern13(int n) { // Hollow Square
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
}

void pattern14(int n) { // Alphabet Triangle
    char ch = 'A';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << ch++ << " ";
        cout << endl;
    }
}

void pattern15(int n) { // Hollow Triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == n || j == 1 || j == i) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
}

void pattern16(int n) { // Alternating Numbers Triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << ((i + j) % 2 == 0 ? "1 " : "0 ");
        cout << endl;
    }
}

void pattern17(int n) { // Right Triangle with Spaces
    for (int i = 1; i <= n; i++) {
        cout << string((n - i) * 2, ' ');
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

void pattern18(int n) { // Number Pyramid
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ');
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
}

void pattern19(int n) { // Hollow Pyramid
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ');
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == n) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern20(int n) { // Spiral Pattern (simple version)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
}

// Menu and Driver
void displayPatterns() {
    cout << YELLOW << "Available Patterns:" << RESET << endl;
    vector<string> patternNames = {
        "Square of *",
        "Right Triangle",
        "Inverted Right Triangle",
        "Pyramid",
        "Inverted Pyramid",
        "Diamond",
        "Numbers Right Triangle",
        "Pascal's Triangle",
        "Floyd's Triangle",
        "Checkerboard Pattern",
        "Zig-Zag Pattern",
        "Reverse Numbers Triangle",
        "Hollow Square",
        "Alphabet Triangle",
        "Hollow Triangle",
        "Alternating Numbers Triangle",
        "Right Triangle with Spaces",
        "Number Pyramid",
        "Hollow Pyramid",
        "Spiral Pattern"
    };

    for (size_t i = 0; i < patternNames.size(); i++) {
        cout << GREEN << i + 1 << ". " << patternNames[i] << RESET << endl;
    }
}


int main() {
    vector<void (*)(int)> patterns = {pattern1, pattern2, pattern3, pattern4, pattern5, pattern6, pattern7, pattern8, pattern9, pattern10, pattern11, pattern12, pattern13, pattern14, pattern15, pattern16, pattern17, pattern18, pattern19, pattern20};

    int choice, n;

    while (true) {
        displayPatterns();
        cout << CYAN << "Enter your choice (1-20, or 0 to exit): " << RESET;
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > 20) {
            cout << RED << "Invalid choice! Please try again." << RESET << endl;
            continue;
        }

        cout << CYAN << "Enter the size of the pattern: " << RESET;
        cin >> n;

        cout << MAGENTA << "Displaying Pattern " << choice << ":\n" << RESET;
        patterns[choice - 1](n);
        cout << endl;
    }

    cout << GREEN << "Goodbye!" << RESET << endl;
    return 0;
}
