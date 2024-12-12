C++ Temperature Converter
=========================

This C++ program converts temperatures between Celsius, Fahrenheit, and Kelvin. It provides a user-friendly interface, handles invalid inputs, and allows the user to continue converting multiple temperatures.

Features
--------

*   Converts temperatures between Celsius, Fahrenheit, and Kelvin.
*   Handles invalid input for both temperature values and units.
*   Prompts the user to continue or exit after each conversion.
*   Displays clear output showing both the original and converted values with units.

Prerequisites
-------------

To run this program, you need a C++ compiler such as **GCC** or an integrated development environment (IDE) like **Code::Blocks**, **Visual Studio**, or **Clion**.

How to Run the Program
----------------------

### Step 1: Write the Code

Copy the C++ code from the repository or use the following code to create a new file named **temperature-converter.cpp**:

    #include #include // for std::numeric\_limits
    #include // for std::tolower
    
    using namespace std;
    
    // Function to convert from Celsius to Fahrenheit, Kelvin
    double celsiusToFahrenheit(double celsius) {
        return (celsius \* 9/5) + 32;
    }
    
    double celsiusToKelvin(double celsius) {
        return celsius + 273.15;
    }
    
    // Function to convert from Fahrenheit to Celsius, Kelvin
    double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) \* 5/9;
    }
    
    double fahrenheitToKelvin(double fahrenheit) {
        return (fahrenheit - 32) \* 5/9 + 273.15;
    }
    
    // Function to convert from Kelvin to Celsius, Fahrenheit
    double kelvinToCelsius(double kelvin) {
        return kelvin - 273.15;
    }
    
    double kelvinToFahrenheit(double kelvin) {
        return (kelvin - 273.15) \* 9/5 + 32;
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
            cin.ignore(numeric\_limits::max(), '\\n'); // Ignore the invalid input
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
    

### Step 2: Compile the Code

To compile the program, open your terminal or command prompt, navigate to the directory where the **temperature-converter.cpp** file is located, and run the following command:

g++ -o temperature-converter temperature-converter.cpp
    

This will create an executable file named **temperature-converter** in the same directory.

### Step 3: Run the Program

After compiling the code, you can run the program by executing the following command in the terminal or command prompt:

./temperature-converter
    

On Windows, you can run the program by typing:

temperature-converter.exe
    

### Step 4: Interact with the Program

Once the program is running, follow the on-screen instructions to input a temperature value and select the units for conversion. After conversion, the program will display the result and ask if you would like to convert another temperature.

Example Usage
-------------

Here's an example of how the program works:

Enter temperature value: 100
Enter the unit of the input temperature (C for Celsius, F for Fahrenheit, K for Kelvin): C
Enter the unit you want to convert to (C for Celsius, F for Fahrenheit, K for Kelvin): F
Converting 100 C to F gives: 212 F
Do you want to convert another temperature? (y/n): y
Enter temperature value: 0
Enter the unit of the input temperature (C for Celsius, F for Fahrenheit, K for Kelvin): F
Enter the unit you want to convert to (C for Celsius, F for Fahrenheit, K for Kelvin): C
Converting 0 F to C gives: -17.7778 C
Do you want to convert another temperature? (y/n): n
Goodbye!
    

Contributing
------------

If you would like to contribute to this project, feel free to fork the repository, make your changes, and create a pull request. Suggestions and improvements are always welcome!

License
-------

This project is open-source and available under the MIT License. 