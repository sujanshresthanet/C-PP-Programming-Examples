#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm> // Include for sort and max_element
using namespace std;

// Color codes for terminal
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

// Function declarations
void sortArray();
void findLargestElement();
void sumArrayElements();
void countArrayElements();
void calculateAverage();
void ticTacToeGame();
void swapFirstLast();

int main() {
    int choice;
    do {
        // Menu display
        cout << BLUE << "\nChoose an option:" << RESET << endl;
        cout << YELLOW << "1. Sort array in ascending order" << RESET << endl;
        cout << GREEN << "2. Find largest element of given array" << RESET << endl;
        cout << CYAN << "3. Find sum of array elements" << RESET << endl;
        cout << RED << "4. Find number of elements in an array" << RESET << endl;
        cout << YELLOW << "5. Calculate average using array" << RESET << endl;
        cout << GREEN << "6. Play Tic Tac Toe (2D Array)" << RESET << endl;
        cout << CYAN << "7. Swap first and last elements of an array" << RESET << endl;
        cout << RED << "0. Exit" << RESET << endl;

        cout << BLUE << "Enter your choice: " << RESET;
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << RED << "Invalid input! Please enter a valid choice." << RESET << endl;
            continue;
        }

        switch (choice) {
            case 1: sortArray(); break;
            case 2: findLargestElement(); break;
            case 3: sumArrayElements(); break;
            case 4: countArrayElements(); break;
            case 5: calculateAverage(); break;
            case 6: ticTacToeGame(); break;
            case 7: swapFirstLast(); break;
            case 0: cout << GREEN << "Exiting the program. Goodbye!" << RESET << endl; break;
            default: cout << RED << "Invalid choice! Please try again." << RESET << endl; break;
        }
    } while (choice != 0);

    return 0;
}

// Function definitions
void sortArray() {
    int n;
    cout << CYAN << "Enter the number of elements in the array: " << RESET;
    cin >> n;
    vector<int> arr(n);
    cout << CYAN << "Enter the elements: " << RESET;
    for (int &x : arr) cin >> x;

    sort(arr.begin(), arr.end());
    cout << GREEN << "Sorted array in ascending order: " << RESET;
    for (int x : arr) cout << x << " ";
    cout << endl;
}

void findLargestElement() {
    int n;
    cout << CYAN << "Enter the number of elements in the array: " << RESET;
    cin >> n;
    vector<int> arr(n);
    cout << CYAN << "Enter the elements: " << RESET;
    for (int &x : arr) cin >> x;

    int largest = *max_element(arr.begin(), arr.end());
    cout << GREEN << "Largest element: " << RESET << largest << endl;
}

void sumArrayElements() {
    int n, sum = 0;
    cout << CYAN << "Enter the number of elements in the array: " << RESET;
    cin >> n;
    vector<int> arr(n);
    cout << CYAN << "Enter the elements: " << RESET;
    for (int &x : arr) {
        cin >> x;
        sum += x;
    }
    cout << GREEN << "Sum of array elements: " << RESET << sum << endl;
}

void countArrayElements() {
    int n;
    cout << CYAN << "Enter the number of elements in the array: " << RESET;
    cin >> n;
    cout << GREEN << "Number of elements in the array: " << RESET << n << endl;
}

void calculateAverage() {
    int n;
    double sum = 0;
    cout << CYAN << "Enter the number of elements in the array: " << RESET;
    cin >> n;
    vector<int> arr(n);
    cout << CYAN << "Enter the elements: " << RESET;
    for (int &x : arr) {
        cin >> x;
        sum += x;
    }
    cout << GREEN << "Average of array elements: " << RESET << fixed << setprecision(2) << (sum / n) << endl;
}

void ticTacToeGame() {
    cout << YELLOW << "Tic Tac Toe is not implemented yet. Please choose another option!" << RESET << endl;
}

void swapFirstLast() {
    int n;
    cout << CYAN << "Enter the number of elements in the array: " << RESET;
    cin >> n;
    if (n < 2) {
        cout << RED << "Array should have at least 2 elements to swap!" << RESET << endl;
        return;
    }

    vector<int> arr(n);
    cout << CYAN << "Enter the elements: " << RESET;
    for (int &x : arr) cin >> x;

    swap(arr[0], arr[n - 1]);
    cout << GREEN << "Array after swapping first and last elements: " << RESET;
    for (int x : arr) cout << x << " ";
    cout << endl;
}
