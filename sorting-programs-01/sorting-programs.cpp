#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for system("clear") or system("cls")

// ANSI escape codes for colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

// Selection Sort
void selectionSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Quicksort
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void displayMenu() {
    std::cout << YELLOW << "Choose a sorting algorithm:\n" << RESET;
    std::cout << GREEN << "1. Bubble Sort\n" << RESET;
    std::cout << GREEN << "2. Insertion Sort\n" << RESET;
    std::cout << GREEN << "3. Selection Sort\n" << RESET;
    std::cout << GREEN << "4. Quicksort\n" << RESET;
    std::cout << CYAN << "Enter your choice (1-4): " << RESET;
}

void displayArray(const std::vector<int>& arr) {
    std::cout << BLUE << "Sorted Array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << RESET << "\n";
}

int main() {
    system("clear"); // Use system("cls") for Windows
    int choice;
    displayMenu();
    std::cin >> choice;

    std::cout << CYAN << "Enter the number of elements: " << RESET;
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << CYAN << "Enter the elements:\n" << RESET;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    switch (choice) {
    case 1:
        bubbleSort(arr);
        break;
    case 2:
        insertionSort(arr);
        break;
    case 3:
        selectionSort(arr);
        break;
    case 4:
        quicksort(arr, 0, n - 1);
        break;
    default:
        std::cout << RED << "Invalid choice! Exiting...\n" << RESET;
        return 1;
    }

    displayArray(arr);
    return 0;
}
