#include <iostream>
#include <string>
using namespace std;

int main() {
    string correctUsername = "admin";
    string correctPassword = "1234";

    string username, password;

    int attempts = 3;
    bool loginSuccess = false;

    while (attempts > 0) {

        cout << "\n===== LOGIN SYSTEM =====\n";

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // Password Strength Validation
        if (password.length() < 4) {
            cout << "Weak Password! Password must contain at least 4 characters.\n";
            continue;
        }

        // Check credentials
        if (username == correctUsername && password == correctPassword) {
            cout << "\nLogin Successful!\n";
            loginSuccess = true;
            break;
        }
        else {
            attempts--;

            cout << "\nWrong Credentials!\n";

            if (attempts > 0) {
                cout << "Remaining Attempts: " << attempts << endl;
            }
        }
    }

    // Lock system after 3 failures
    if (!loginSuccess) {
        cout << "\nSystem Locked! Too many failed attempts.\n";
    }

    return 0;
}
