#include<iostream>
#include<cmath>
#include<limits>
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    double a, b;
    int choice;
    bool running = true;

    cout << "basic calculator(add, subtract, multiply, divide, square root, power, log)\n";
     while (running) {
        cout << "Select operation:\n";
        cout << "\nEnter first number (a): ";
        while (!(cin >> a)) {
            cout << "Invalid number. Try again: ";
            clearInput();
        }
        cout << "\nChoose operation:\n";
        cout << "1) Add (a + b)\n";
        cout << "2) Subtract (a - b)\n";
        cout << "3) Multiply (a * b)\n";
        cout << "4) Divide (a / b)\n";
        cout << "5) Square Root (√a)\n";
        cout << "6) Power (a^b)\n";
        cout << "7) Logarithm (log_a b)\n";
        cout << "8) log base 10 of a (log10(a) )\n";
        cout << "9) Exit\n";
        cout << "Enter choice (1-9): ";
        while (!(cin >> choice) || choice < 1 || choice > 9) {
            cout << "Invalid choice. Enter a number from 1 to 9: ";
            clearInput();
        }
        cout << fixed; // optional: show decimals

           // Prompt for second operand only when required by the chosen operation
           if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 6 || choice == 7) {
               cout << "\nEnter second number (b): ";
               while (!(cin >> b)) {
                   cout << "Invalid number. Try again: ";
                   clearInput();
               }
           }

           switch (choice) {
                case 1:
                    cout << "Result: " << a << " + " << b << " = " << (a + b) << "\n";
                    break;
                case 2:
                    cout << "Result: " << a << " - " << b << " = " << (a - b) << "\n";
                    break;
                case 3:
                    cout << "Result: " << a << " * " << b << " = " << (a * b) << "\n";
                    break;
                case 4:
                    if (b == 0.0) {
                        cout << "Error: Division by zero is undefined.\n";
                    } else {
                        cout << "Result: " << a << " / " << b << " = " << (a / b) << "\n";
                    }
                    break;
                case 5:
                    if (a < 0.0) {
                        cout << "Error: Cannot compute square root of a negative number.\n";
                    } else {
                        cout << "Result: √" << a << " = " << sqrt(a) << "\n";
                    }
                    break;
                case 6: {
                    // pow handles many cases, but negative bases with non-integer exponent may produce NaN
                    double result = pow(a, b);
                    if (std::isnan(result)) {
                        cout << "Error: Result is not a real number (NaN). This can happen when a < 0 and b is fraction.\n";
                    } else {
                        cout << "Result: " << a << "^" << b << " = " << result << "\n";
                    }
                    break;
                }
                case 7:
                    // log base a of b: log_a(b) = ln(b) / ln(a)
                    if (a <= 0.0 || a == 1.0) {
                        cout << "Error: log base a is defined for a > 0 and a != 1.\n";
                    } else if (b <= 0.0) {
                        cout << "Error: log_a(b) requires b > 0.\n";
                    } else {
                        cout << "Result: log_" << a << "(" << b << ") = " << (log(b) / log(a)) << "\n";
                    }
                    break;
                case 8:
                    if (a <= 0.0) {
                        cout << "Error: log10 defined for only a > 0.\n";
                    } else {
                        cout << "Result: log10(" << a << ") = " << log10(a) << "\n";
                    }
                    break;
                case 9:
                    running = false;
                    cout << "Goodbye!\n";
                    break;
                default:
                    cout << "Unknown choice.\n";
                    break;
            }
        }
        return 0;
    }