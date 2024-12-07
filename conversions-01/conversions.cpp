#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert temperature
double convertTemperature(double value, int fromUnit, int toUnit) {
    if (fromUnit == 1) { // Celsius
        if (toUnit == 1) return value;
        else if (toUnit == 2) return (value * 9.0 / 5.0) + 32; // Fahrenheit
        else if (toUnit == 3) return value + 273.15; // Kelvin
    } else if (fromUnit == 2) { // Fahrenheit
        if (toUnit == 1) return (value - 32) * 5.0 / 9.0; // Celsius
        else if (toUnit == 2) return value;
        else if (toUnit == 3) return (value - 32) * 5.0 / 9.0 + 273.15; // Kelvin
    } else if (fromUnit == 3) { // Kelvin
        if (toUnit == 1) return value - 273.15; // Celsius
        else if (toUnit == 2) return (value - 273.15) * 9.0 / 5.0 + 32; // Fahrenheit
        else if (toUnit == 3) return value;
    }
    return 0;
}

// Function to convert length
double convertLength(double value, int fromUnit, int toUnit) {
    double conversionFactor[5][5] = {
        {1, 0.001, 39.3701, 3.28084, 1000}, // meters to [m, km, inches, feet, mm]
        {1000, 1, 39370.1, 3280.84, 1000000}, // km to [m, km, inches, feet, mm]
        {0.0254, 0.0000254, 1, 0.0833333, 25.4}, // inches to [m, km, inches, feet, mm]
        {0.3048, 0.0003048, 12, 1, 304.8}, // feet to [m, km, inches, feet, mm]
        {0.001, 0.000001, 0.0393701, 0.00328084, 1} // mm to [m, km, inches, feet, mm]
    };
    return value * conversionFactor[fromUnit][toUnit];
}

// Function to convert area
double convertArea(double value, int fromUnit, int toUnit) {
    double conversionFactor[5][5] = {
        {1, 0.0001, 1550, 10.7639, 1000000}, // square meter to [m², km², ft², acres, mm²]
        {10000, 1, 15500000, 107639, 10000000000}, // square km to [m², km², ft², acres, mm²]
        {0.092903, 9.2903e-6, 1, 0.00002296, 929.03}, // square feet to [m², km², ft², acres, mm²]
        {4046.86, 0.00000404686, 43560, 1, 4046860000}, // acres to [m², km², ft², acres, mm²]
        {1e-6, 1e-12, 0.00107639, 2.47105e-10, 1} // square mm to [m², km², ft², acres, mm²]
    };
    return value * conversionFactor[fromUnit][toUnit];
}

// Function to convert weight
double convertWeight(double value, int fromUnit, int toUnit) {
    double conversionFactor[5][5] = {
        {1, 0.001, 35.274, 2.20462, 1000}, // gram to [g, kg, oz, lb, mg]
        {1000, 1, 35.274, 2.20462, 1000000}, // kg to [g, kg, oz, lb, mg]
        {28.3495, 0.0283495, 1, 0.0625, 28349.5}, // ounce to [g, kg, oz, lb, mg]
        {453.592, 0.453592, 16, 1, 453592}, // pound to [g, kg, oz, lb, mg]
        {0.001, 1e-6, 0.000035274, 0.00000220462, 1} // milligram to [g, kg, oz, lb, mg]
    };
    return value * conversionFactor[fromUnit][toUnit];
}

// Function to convert volume
double convertVolume(double value, int fromUnit, int toUnit) {
    double conversionFactor[5][5] = {
        {1, 0.001, 0.000264172, 0.0353147, 1000}, // liter to [L, m³, gallon, cubic feet, ml]
        {1000, 1, 264.172, 35.3147, 1000000}, // cubic meter to [L, m³, gallon, cubic feet, ml]
        {3.78541, 0.00378541, 1, 0.133681, 3785.41}, // gallon to [L, m³, gallon, cubic feet, ml]
        {28.3168, 0.0283168, 7.48052, 1, 28316.8}, // cubic feet to [L, m³, gallon, cubic feet, ml]
        {0.001, 1e-6, 0.000264172, 3.53147e-5, 1} // milliliter to [L, m³, gallon, cubic feet, ml]
    };
    return value * conversionFactor[fromUnit][toUnit];
}

// Function to show colorful menu options
void showMenu(const string& title, const string options[], int numOptions) {
    cout << "\033[1;36m" << title << "\033[0m" << endl;
    for (int i = 0; i < numOptions; ++i) {
        cout << "\033[1;32m" << i + 1 << ". " << options[i] << "\033[0m" << endl;
    }
}

int main() {
    int categoryChoice, fromUnit, toUnit;
    double value;
    char continueChoice;

    do {
        string categories[] = {"Length", "Temperature", "Area", "Volume", "Weight"};
        showMenu("Select Conversion Category", categories, 5);

        cout << "Enter your choice (1-5): ";
        cin >> categoryChoice;

        switch (categoryChoice) {
            case 1: {
                string lengthUnits[] = {"Meters", "Kilometers", "Inches", "Feet", "Millimeters"};
                showMenu("Select Length Units", lengthUnits, 5);

                cout << "Enter value to convert: ";
                cin >> value;

                cout << "Select From Unit: ";
                cin >> fromUnit;

                cout << "Select To Unit: ";
                cin >> toUnit;

                double result = convertLength(value, fromUnit - 1, toUnit - 1);
                cout << "\033[1;33mConverted Value: " << result << " " << lengthUnits[toUnit - 1] << "\033[0m" << endl;
                break;
            }
            case 2: {
                string temperatureUnits[] = {"Celsius", "Fahrenheit", "Kelvin"};
                showMenu("Select Temperature Units", temperatureUnits, 3);

                cout << "Enter value to convert: ";
                cin >> value;

                cout << "Select From Unit: ";
                cin >> fromUnit;

                cout << "Select To Unit: ";
                cin >> toUnit;

                double result = convertTemperature(value, fromUnit - 1, toUnit - 1);
                cout << "\033[1;33mConverted Value: " << result << " " << temperatureUnits[toUnit - 1] << "\033[0m" << endl;
                break;
            }
            case 3: {
                string areaUnits[] = {"Square Meters", "Square Kilometers", "Square Feet", "Acres", "Square Millimeters"};
                showMenu("Select Area Units", areaUnits, 5);

                cout << "Enter value to convert: ";
                cin >> value;

                cout << "Select From Unit: ";
                cin >> fromUnit;

                cout << "Select To Unit: ";
                cin >> toUnit;

                double result = convertArea(value, fromUnit - 1, toUnit - 1);
                cout << "\033[1;33mConverted Value: " << result << " " << areaUnits[toUnit - 1] << "\033[0m" << endl;
                break;
            }
            case 4: {
                string volumeUnits[] = {"Liters", "Cubic Meters", "Gallons", "Cubic Feet", "Milliliters"};
                showMenu("Select Volume Units", volumeUnits, 5);

                cout << "Enter value to convert: ";
                cin >> value;

                cout << "Select From Unit: ";
                cin >> fromUnit;

                cout << "Select To Unit: ";
                cin >> toUnit;

                double result = convertVolume(value, fromUnit - 1, toUnit - 1);
                cout << "\033[1;33mConverted Value: " << result << " " << volumeUnits[toUnit - 1] << "\033[0m" << endl;
                break;
            }
            case 5: {
                string weightUnits[] = {"Grams", "Kilograms", "Ounces", "Pounds", "Milligrams"};
                showMenu("Select Weight Units", weightUnits, 5);

                cout << "Enter value to convert: ";
                cin >> value;

                cout << "Select From Unit: ";
                cin >> fromUnit;

                cout << "Select To Unit: ";
                cin >> toUnit;

                double result = convertWeight(value, fromUnit - 1, toUnit - 1);
                cout << "\033[1;33mConverted Value: " << result << " " << weightUnits[toUnit - 1] << "\033[0m" << endl;
                break;
            }
            default:
                cout << "\033[1;31mInvalid Choice! Please try again.\033[0m" << endl;
        }

        cout << "Do you want to convert again? (Y/N): ";
        cin >> continueChoice;

    } while (continueChoice == 'Y' || continueChoice == 'y');

    return 0;
}
