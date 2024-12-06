#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert string from uppercase to lowercase
void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "\033[1;32m" << "Converted String (Lowercase): " << str << "\033[0m" << endl;
}

// Function to convert string from lowercase to uppercase
void toUpperCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "\033[1;34m" << "Converted String (Uppercase): " << str << "\033[0m" << endl;
}

// Function to sort strings in ascending alphabetical order
void sortStrings(string &str) {
    sort(str.begin(), str.end());
    cout << "\033[1;33m" << "Sorted String: " << str << "\033[0m" << endl;
}

// Function to find the length of a string without using strlen
void stringLength(string &str) {
    int length = 0;
    for (char c : str) {
        length++;
    }
    cout << "\033[1;36m" << "Length of String: " << length << "\033[0m" << endl;
}

// Function for string concatenation without using strcat
void stringConcatenation(string &str1, string &str2) {
    string result = str1 + str2;
    cout << "\033[1;35m" << "Concatenated String: " << result << "\033[0m" << endl;
}

// Function to reverse a string using recursion
void reverseString(string &str, int start, int end) {
    if (start >= end) return;
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

// Function to find the frequency of characters in a string
void frequencyOfChars(string &str) {
    int freq[256] = {0};
    for (char c : str) {
        freq[c]++;
    }
    cout << "\033[1;31m" << "Character Frequencies: " << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": " << freq[i] << endl;
        }
    }
}

// Function to search for a substring in a given string
void searchSubstring(string &str, string &sub) {
    size_t found = str.find(sub);
    if (found != string::npos) {
        cout << "\033[1;37m" << "Substring found at position: " << found << "\033[0m" << endl;
    } else {
        cout << "\033[1;37m" << "Substring not found." << "\033[0m" << endl;
    }
}

// Function to replace the first occurrence of a vowel with '-' in a string
void replaceVowel(string &str) {
    string vowels = "aeiouAEIOU";
    for (size_t i = 0; i < str.length(); i++) {
        if (vowels.find(str[i]) != string::npos) {
            str[i] = '-';
            break;
        }
    }
    cout << "\033[1;38m" << "String after vowel replacement: " << str << "\033[0m" << endl;
}

int main() {
    string str1, str2, sub;
    int choice;

    while (true) {
        // Show the menu
        cout << "\033[1;32m" << "\nChoose a String Operation:" << endl;
        cout << "1. Convert string from upper case to lower case" << endl;
        cout << "2. Convert string from lower case to upper case" << endl;
        cout << "3. Sort a set of strings in ascending alphabetical order" << endl;
        cout << "4. Find length of a string without using strlen()" << endl;
        cout << "5. String concatenation without using strcat" << endl;
        cout << "6. Reverse a String using recursion" << endl;
        cout << "7. Find frequency of characters in a string" << endl;
        cout << "8. Search substring in a given string" << endl;
        cout << "9. Replace first occurrence of vowel with '-' in a string" << endl;
        cout << "10. Exit" << endl;
        cout << "\033[0m";
        cout << "\033[1;36m" << "Enter your choice (1-10): ";
        cin >> choice;
        cout << "\033[0m";

        cin.ignore(); // Clear the input buffer before getting string inputs

        if (choice == 10) {
            cout << "\033[1;31m" << "Exiting program. Goodbye!" << "\033[0m" << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "\033[1;36m" << "Enter the string (Uppercase): ";
                getline(cin, str1); // Using getline for multi-word input
                toLowerCase(str1);
                break;
            case 2:
                cout << "\033[1;36m" << "Enter the string (Lowercase): ";
                getline(cin, str1); // Using getline for multi-word input
                toUpperCase(str1);
                break;
            case 3:
                cout << "\033[1;36m" << "Enter the string to sort: ";
                getline(cin, str1); // Using getline for multi-word input
                sortStrings(str1);
                break;
            case 4:
                cout << "\033[1;36m" << "Enter the string to find its length: ";
                getline(cin, str1); // Using getline for multi-word input
                stringLength(str1);
                break;
            case 5:
                cout << "\033[1;36m" << "Enter first string: ";
                getline(cin, str1); // Using getline for multi-word input
                cout << "Enter second string: ";
                getline(cin, str2); // Using getline for multi-word input
                stringConcatenation(str1, str2);
                break;
            case 6:
                cout << "\033[1;36m" << "Enter the string to reverse: ";
                getline(cin, str1); // Using getline for multi-word input
                reverseString(str1, 0, str1.length() - 1);
                cout << "\033[1;37m" << "Reversed String: " << str1 << "\033[0m" << endl;
                break;
            case 7:
                cout << "\033[1;36m" << "Enter the string to find character frequencies: ";
                getline(cin, str1); // Using getline for multi-word input
                frequencyOfChars(str1);
                break;
            case 8:
                cout << "\033[1;36m" << "Enter the main string: ";
                getline(cin, str1); // Using getline for multi-word input
                cout << "Enter the substring to search: ";
                getline(cin, sub); // Using getline for multi-word input
                searchSubstring(str1, sub);
                break;
            case 9:
                cout << "\033[1;36m" << "Enter the string to replace vowel with '-': ";
                getline(cin, str1); // Using getline for multi-word input
                replaceVowel(str1);
                break;
            default:
                cout << "\033[1;31m" << "Invalid choice, please try again!" << "\033[0m" << endl;
        }
    }

    return 0;
}
