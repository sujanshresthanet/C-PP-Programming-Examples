Phonebook Application
=====================

This is a simple **Phonebook** application written in C++ that allows users to **add**, **edit**, **delete**, and **list contacts** (name and phone number). The contacts are stored in a file in plain text format, and the program provides a colorful text-based menu system for interacting with the phonebook.

Features
--------

*   **List Contacts**: Displays all contacts in a table format.
*   **Add New Contact**: Add a new contact with name and phone number.
*   **Edit Existing Contact**: Edit the phone number of an existing contact.
*   **Delete Contact**: Remove a contact from the phonebook by name.
*   **Colorful UI**: The menu and output messages are color-coded using ANSI escape sequences for a better user experience.
*   **Input Validation**: Ensures that the user enters valid data, such as contact name and phone number.

File Format
-----------

The phonebook contacts are stored in a text file (`phonebook.txt`) in a simple CSV-like format, where each contact is saved on a new line in the form:

    
    Name,PhoneNumber
        

Example:

    
    John Doe,123-456-7890
    Jane Smith,987-654-3210
        

Requirements
------------

*   **C++ compiler** (GCC, Clang, or similar)
*   **Basic C++ knowledge** for understanding and modifying the code

Functionality
-------------

### Menu Options:

1.  **List Contacts**: Displays all contacts in a nicely formatted table with columns for the name and phone number.
2.  **Add a New Contact**: Prompts the user to enter a name and phone number and adds it to the phonebook.
3.  **Edit an Existing Contact**: Allows the user to edit the phone number of an existing contact by entering their name.
4.  **Delete a Contact**: Deletes a contact from the phonebook by entering their name.
5.  **Exit**: Exits the application.

How to Run the Application
--------------------------

Follow these steps to run the Phonebook application:

1.  Save the code to a file, e.g., `phonebook.cpp`.
2.  Open a terminal and navigate to the directory where the file is saved.
3.  Compile the code using a C++ compiler:
    
        g++ phonebook.cpp -o phonebook
    
4.  Run the compiled executable:
    
        ./phonebook
    

How the Program Works
---------------------

The program uses the following classes and methods:

*   **Contact Class**: Represents a contact with a name and phone number. Includes methods for displaying and saving contacts in a formatted string.
*   **Phonebook Class**: Handles the main functionality, such as loading and saving contacts from a file, and providing options to list, add, edit, and delete contacts.
*   **Input Validation**: Ensures that the user inputs valid data such as names and phone numbers.

Important Notes
---------------

*   The phonebook is stored in a text file called ``phonebook.txt in the same directory as the program. Each contact is saved on a new line in the format `Name,PhoneNumber`.`
`*   The program supports a colorful menu and output using ANSI escape codes, making it more visually appealing in the terminal.`

  **Enjoy managing your contacts with this simple phonebook app!**   