#include<iostream>
#include<cmath>
#include<iomanip> 

using namespace std;

const double R = 0.08206; // Ideal gas constant in L*atm/(mol*K)

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

void solveIdealGasLaw() {
    int choice;
    cout << "\n--- Ideal Gas Law (PV = nRT) ---" << endl;
    cout << "Select variable to calculate:" << endl;
    cout << "1. Pressure (P)\n2. Volume (V)\n3. Number of Moles (n)\n4. Temperature (T)" << endl;
    cout << "Enter choice (1-4): ";
    cin >> choice;

    double P, V, n, T, tempC;

    switch (choice) {
        case 1: // Find P
            cout << "Enter Volume (L): "; cin >> V;
            cout << "Enter Moles (n): "; cin >> n;
            cout << "Enter Temperature (°C): "; cin >> tempC;
            T = celsiusToKelvin(tempC);
            P = (n * R * T) / V;
            cout << "Result: Pressure (P) = " << P << " atm" << endl;
            break;

        case 2: // Find V
            cout << "Enter Pressure (atm): "; cin >> P;
            cout << "Enter Moles (n): "; cin >> n;
            cout << "Enter Temperature (°C): "; cin >> tempC;
            T = celsiusToKelvin(tempC);
            V = (n * R * T) / P;
            cout << "Result: Volume (V) = " << V << " L" << endl;
            break;

        case 3: // Find n
            cout << "Enter Pressure (atm): "; cin >> P;
            cout << "Enter Volume (L): "; cin >> V;
            cout << "Enter Temperature (°C): "; cin >> tempC;
            T = celsiusToKelvin(tempC);
            n = (P * V) / (R * T);
            cout << "Result: Moles (n) = " << n << " mol" << endl;
            break;

        case 4: // Find T
            cout << "Enter Pressure (atm): "; cin >> P;
            cout << "Enter Volume (L): "; cin >> V;
            cout << "Enter Moles (n): "; cin >> n;
            T = (P * V) / (n * R);
            cout << "Result: Temperature (T) = " << T << " K (" << (T - 273.15) << " °C)" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
    }
}

void solveCombinedGasLaw() {
    int choice;
    cout << "\n--- Combined Gas Law (P1*V1/T1 = P2*V2/T2) ---" << endl;
    cout << "Select variable to solve for:" << endl;
    cout << "1. Final Pressure (P2)\n2. Final Volume (V2)\n3. Final Temperature (T2)" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    double P1, V1, T1_C, P2, V2, T2_C, T1, T2;

    cout << "Enter Initial Pressure (P1): "; cin >> P1;
    cout << "Enter Initial Volume (V1): "; cin >> V1;
    cout << "Enter Initial Temperature (T1 in °C): "; cin >> T1_C;
    T1 = celsiusToKelvin(T1_C);

    switch (choice) {
        case 1: // Find P2
            cout << "Enter Final Volume (V2): "; cin >> V2;
            cout << "Enter Final Temperature (T2 in °C): "; cin >> T2_C;
            T2 = celsiusToKelvin(T2_C);
            P2 = (P1 * V1 * T2) / (T1 * V2);
            cout << "Result: Final Pressure (P2) = " << P2 << endl;
            break;

        case 2: // Find V2
            cout << "Enter Final Pressure (P2): "; cin >> P2;
            cout << "Enter Final Temperature (T2 in °C): "; cin >> T2_C;
            T2 = celsiusToKelvin(T2_C);
            V2 = (P1 * V1 * T2) / (P2 * T1);
            cout << "Result: Final Volume (V2) = " << V2 << endl;
            break;

        case 3: // Find T2
            cout << "Enter Final Pressure (P2): "; cin >> P2;
            cout << "Enter Final Volume (V2): "; cin >> V2;
            T2 = (P2 * V2 * T1) / (P1 * V1);
            cout << "Result: Final Temperature (T2) = " << T2 << " K (" << (T2 - 273.15) << " °C)" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
    }
}

int main() {
    int option;
    do {
        cout << "\n===================================" << endl;
        cout << "      GAS LAW CALCULATOR MENU      " << endl;
        cout << "===================================" << endl;
        cout << "1. Ideal Gas Law (PV = nRT)" << endl;
        cout << "2. Combined Gas Law (P1V1/T1 = P2V2/T2)" << endl;
        cout << "3. Exit" << endl;
        cout << "Select an option (1-3): ";
        cin >> option;

        switch (option) {
            case 1:
                solveIdealGasLaw();
                break;
            case 2:
                solveCombinedGasLaw();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
        }
    } while (option != 3);

    return 0;
}
