#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iomanip>  // for table formatting

using namespace std;

struct Contact {
    string name;
    string phoneNumber;

    // Constructor to easily create Contact objects
    Contact(const string& name = "", const string& phoneNumber = "") : name(name), phoneNumber(phoneNumber) {}

    // Method to display a contact in a formatted manner (const method)
    void display() const {
        cout << "| " << setw(20) << left << name << " | " << setw(15) << left << phoneNumber << " |" << endl;
    }

    // Method to save contact to a string in a custom format (const method)
    string to_string_format() const {
        return name + "," + phoneNumber;
    }

    // Method to load contact from a string
    static Contact from_string_format(const string& contactString) {
        stringstream ss(contactString);
        string name, phoneNumber;
        getline(ss, name, ',');
        getline(ss, phoneNumber, ',');
        return Contact(name, phoneNumber);
    }
};

class Phonebook {
private:
    vector<Contact> contacts;
    const string filename = "phonebook.txt";

    // Method to load contacts from file
    void loadContacts() {
        ifstream file(filename);
        string line;
        contacts.clear();  // Clear any existing contacts before loading
        while (getline(file, line)) {
            if (!line.empty()) {
                contacts.push_back(Contact::from_string_format(line));
            }
        }
    }

    // Method to save contacts to file
    void saveContacts() {
        ofstream file(filename);
        for (const auto& contact : contacts) {
            file << contact.to_string_format() << endl;
        }
    }

public:
    Phonebook() {
        loadContacts();
    }

    // Method to display all contacts in table format
    void listContacts() {
        if (contacts.empty()) {
            cout << "\n\033[1;31mNo contacts available.\033[0m" << endl;
        } else {
            cout << "\n\033[1;34mContact List:\033[0m" << endl;
            cout << "\033[1;32m+----------------------+-----------------+\033[0m" << endl;
            cout << "\033[1;32m| Name                 | Phone Number    |\033[0m" << endl;
            cout << "\033[1;32m+----------------------+-----------------+\033[0m" << endl;
            for (const auto& contact : contacts) {
                contact.display();
            }
            cout << "\033[1;32m+----------------------+-----------------+\033[0m" << endl;
        }
    }

    // Method to add a new contact
    void addContact() {
        string name, phoneNumber;
        cout << "\n\033[1;33mEnter contact's name: \033[0m";
        cin.ignore();
        getline(cin, name);
        cout << "\033[1;33mEnter contact's phone number: \033[0m";
        getline(cin, phoneNumber);

        // Basic validation
        if (name.empty() || phoneNumber.empty()) {
            cout << "\n\033[1;31mError: Name and phone number cannot be empty.\033[0m" << endl;
            return;
        }

        contacts.push_back(Contact(name, phoneNumber));
        saveContacts();
        cout << "\n\033[1;32mContact added successfully!\033[0m" << endl;
    }

    // Method to edit an existing contact
    void editContact() {
        string name;
        cout << "\n\033[1;33mEnter the name of the contact to edit: \033[0m";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (auto& contact : contacts) {
            if (contact.name == name) {
                cout << "\n\033[1;34mEditing contact: " << contact.name << "\033[0m" << endl;
                cout << "\033[1;33mEnter new phone number: \033[0m";
                getline(cin, contact.phoneNumber);

                // Basic validation for phone number
                if (contact.phoneNumber.empty()) {
                    cout << "\n\033[1;31mError: Phone number cannot be empty.\033[0m" << endl;
                    return;
                }

                found = true;
                break;
            }
        }

        if (found) {
            saveContacts();
            cout << "\n\033[1;32mContact updated successfully!\033[0m" << endl;
        } else {
            cout << "\n\033[1;31mContact not found!\033[0m" << endl;
        }
    }

    // Method to delete a contact
    void deleteContact() {
        string name;
        cout << "\n\033[1;33mEnter the name of the contact to delete: \033[0m";
        cin.ignore();
        getline(cin, name);

        auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            saveContacts();
            cout << "\n\033[1;32mContact deleted successfully!\033[0m" << endl;
        } else {
            cout << "\n\033[1;31mContact not found!\033[0m" << endl;
        }
    }
};

int getMenuChoice() {
    int choice;
    while (true) {
        cout << "\n\033[1;36mPhonebook Menu\033[0m" << endl;
        cout << "\033[1;35m1.\033[0m \033[1;33mList contacts\033[0m" << endl;
        cout << "\033[1;35m2.\033[0m \033[1;33mAdd a new contact\033[0m" << endl;
        cout << "\033[1;35m3.\033[0m \033[1;33mEdit an existing contact\033[0m" << endl;
        cout << "\033[1;35m4.\033[0m \033[1;33mDelete a contact\033[0m" << endl;
        cout << "\033[1;35m5.\033[0m \033[1;33mExit\033[0m" << endl;
        cout << "\n\033[1;37mEnter your choice: \033[0m";

        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard invalid input
            cout << "\n\033[1;31mInvalid input! Please enter a number between 1 and 5.\033[0m" << endl;
        } else {
            return choice;
        }
    }
}

int main() {
    Phonebook phonebook;

    int choice;
    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                phonebook.listContacts();
                break;
            case 2:
                phonebook.addContact();
                break;
            case 3:
                phonebook.editContact();
                break;
            case 4:
                phonebook.deleteContact();
                break;
            case 5:
                cout << "\n\033[1;32mExiting program...\033[0m" << endl;
                break;
            default:
                cout << "\n\033[1;31mInvalid choice! Please try again.\033[0m" << endl;
        }
    } while (choice != 5);

    return 0;
}
