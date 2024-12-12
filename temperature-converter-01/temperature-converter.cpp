#include <iostream>
#include <limits> // for std::numeric_limits
#include <cctype> // for std::tolower

using namespace std;

// Function to convert from Celsius to Fahrenheit, Kelvin
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert from Fahrenheit to Celsius, Kelvin
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

// Function to convert from Kelvin to Celsius, Fahrenheit
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

bool isValidTemperatureUnit(char unit) {
    return (unit == 'C' || unit == 'F' || unit == 'K');
}

int main() {
    char cont = 'y';
    while (tolower(cont) == 'y') {
        double temp;
        char fromUnit, toUnit;

        // Input: get temperature and units from the user
        cout << "Enter temperature value: ";
        while (!(cin >> temp)) {
            cout << "Invalid input. Please enter a numeric value for temperature: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
        }

        cout << "Enter the unit of the input temperature (C for Celsius, F for Fahrenheit, K for Kelvin): ";
        cin >> fromUnit;
        fromUnit = toupper(fromUnit); // Convert to uppercase to standardize input

        // Validate input temperature unit
        while (!isValidTemperatureUnit(fromUnit)) {
            cout << "Invalid unit. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin: ";
            cin >> fromUnit;
            fromUnit = toupper(fromUnit); // Convert to uppercase
        }

        cout << "Enter the unit you want to convert to (C for Celsius, F for Fahrenheit, K for Kelvin): ";
        cin >> toUnit;
        toUnit = toupper(toUnit); // Convert to uppercase to standardize input

        // Validate output temperature unit
        while (!isValidTemperatureUnit(toUnit)) {
            cout << "Invalid unit. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin: ";
            cin >> toUnit;
            toUnit = toupper(toUnit); // Convert to uppercase
        }

        // Conversion based on user input
        double convertedTemp = 0.0;

        if (fromUnit == 'C') {
            if (toUnit == 'F') {
                convertedTemp = celsiusToFahrenheit(temp);
            } else if (toUnit == 'K') {
                convertedTemp = celsiusToKelvin(temp);
            } else {
                cout << "Invalid conversion." << endl;
                continue;
            }
        } else if (fromUnit == 'F') {
            if (toUnit == 'C') {
                convertedTemp = fahrenheitToCelsius(temp);
            } else if (toUnit == 'K') {
                convertedTemp = fahrenheitToKelvin(temp);
            } else {
                cout << "Invalid conversion." << endl;
                continue;
            }
        } else if (fromUnit == 'K') {
            if (toUnit == 'C') {
                convertedTemp = kelvinToCelsius(temp);
            } else if (toUnit == 'F') {
                convertedTemp = kelvinToFahrenheit(temp);
            } else {
                cout << "Invalid conversion." << endl;
                continue;
            }
        }

        // Output the result with a detailed message
        cout << "Converting " << temp << " " << fromUnit
             << " to " << toUnit << " gives: " << convertedTemp << " " << toUnit << endl;

        // Ask if the user wants to continue
        cout << "Do you want to convert another temperature? (y/n): ";
        cin >> cont;
        cont = tolower(cont); // Convert to lowercase for consistency
    }

    cout << "Goodbye!" << endl;
    return 0;
}
