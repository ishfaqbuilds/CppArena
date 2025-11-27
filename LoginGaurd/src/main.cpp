#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <limits>

using namespace std;

class Registration
{
    string Username, Email, Password;
    string Entered_Username, Entered_Email, Entered_Password;
    fstream file;

    // Centralized File Paths
    const string LOGIN_FILE = "../data/Login.txt";
    const string TEMP_FILE = "../data/temp.txt";

    // Helper Functions
    bool isValidEmail(const string &email);
    bool isValidPassword(const string &password);

public:
    void Login();
    void Signup();
    void ForgotPassword();
};

int main()
{
    Registration obj;
    char option;
    bool exitProgram = false;

    while (!exitProgram)
    {
        system("clear"); // Use "cls" on Windows

        cout << "══════════════════════════════════════════\n";
        cout << "║║                                      ║║\n";
        cout << "║║           1. Login                   ║║\n";
        cout << "║║           2. Sign Up                 ║║\n";
        cout << "║║           3. Forgot Password         ║║\n";
        cout << "║║           4. Exit                    ║║\n";
        cout << "║║                                      ║║\n";
        cout << "══════════════════════════════════════════\n\n";

        cout << "Enter Your Option: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case '1':
            obj.Login();
            break;
        case '2':
            obj.Signup();
            break;
        case '3':
            obj.ForgotPassword();
            break;
        case '4':
            cout << "\n----------- GOODBYE! -----------\n\n";
            exitProgram = true;
            break;
        default:
            cout << "Invalid Option!\n";
        }

        if (!exitProgram)
        {
            cout << "Press Enter To Return To Main Menu.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}

// ------------------ Helper Functions ------------------

bool Registration::isValidEmail(const string &email)
{
    // Basic Regex For Email Validation
    const regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return regex_match(email, pattern);
}

bool Registration::isValidPassword(const string &password)
{
    if (password.length() < 8)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    for (char ch : password)
    {
        if (isupper(ch))
            hasUpper = true;
        else if (islower(ch))
            hasLower = true;
        else if (isdigit(ch))
            hasDigit = true;
        else
            hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// ------------------ Signup ------------------

void Registration::Signup()
{
    cout << "\nEnter Your Username: ";
    getline(cin, Username);

    cout << "Enter Your Email: ";
    getline(cin, Email);
    if (!isValidEmail(Email))
    {
        cout << "Error: Invalid email format! Please try again.\n";
        return;
    }

    cout << "Enter Your Password: ";
    getline(cin, Password);
    if (!isValidPassword(Password))
    {
        cout << "\nError: Password must be at least 8 characters long, contain uppercase, lowercase, digit, and special character.\n"
             << endl;
        return;
    }

    file.open(LOGIN_FILE, ios::out | ios::app);
    if (!file)
    {
        cerr << "Error: Unable to open file!\n";
        return;
    }
    file << Username << "*" << Email << "*" << Password << "\n";
    file.close();

    cout << "\nSignup Successful!\n";
}

// ------------------ Login ------------------

void Registration::Login()
{
    cout << "\nEnter Your Username: ";
    getline(cin, Entered_Username);
    cout << "Enter Your Password: ";
    getline(cin, Entered_Password);

    file.open(LOGIN_FILE, ios::in);
    if (!file)
    {
        cerr << "Error: Cannot open file or file does not exist!\n";
        return;
    }

    bool found = false;
    while (getline(file, Username, '*'))
    {
        getline(file, Email, '*');
        getline(file, Password, '\n');

        if (Username == Entered_Username)
        {
            found = true;
            if (Password == Entered_Password)
            {
                cout << "\nAccount Login Successful!\n";
                cout << "Username: " << Username << "\nEmail: " << Email << "\n\n";
            }
            else
            {
                cout << "\nPassword is Incorrect!\n\n";
            }
            break;
        }
    }

    if (!found)
    {
        cout << "\nUsername Doesn't Exist!\n\n";
    }

    file.close();
}

// ------------------ Forgot Password ------------------

void Registration::ForgotPassword()
{
    cout << "\nEnter Your Username: ";
    getline(cin, Entered_Username);
    cout << "Enter Your Email: ";
    getline(cin, Entered_Email);

    file.open(LOGIN_FILE, ios::in);
    if (!file)
    {
        cerr << "Error: Cannot open file or file does not exist!\n";
        return;
    }

    fstream tempFile(TEMP_FILE, ios::out);
    bool found = false;

    while (getline(file, Username, '*'))
    {
        getline(file, Email, '*');
        getline(file, Password, '\n');

        if (Username == Entered_Username && Email == Entered_Email)
        {
            found = true;
            cout << "\nAccount Found!\n";
            cout << "Current Password: " << Password << "\n";

            string choice;
            cout << "Do You Want To Change Your Password? (Yes/No): ";
            getline(cin, choice);

            if (choice == "yes" || choice == "Yes" || choice == "YES")
            {
                string NewPassword;
                cout << "Enter New Password: ";
                getline(cin, NewPassword);

                if (!isValidPassword(NewPassword))
                {
                    cout << "Error: Password must be at least 8 characters long, "
                         << "contain uppercase, lowercase, digit, and special character.\n";
                    tempFile << Username << "*" << Email << "*" << Password << "\n"; // keep old password
                }
                else
                {
                    tempFile << Username << "*" << Email << "*" << NewPassword << "\n";
                    cout << "\nPassword Changed Successfully!\n";
                }
            }
            else
            {
                tempFile << Username << "*" << Email << "*" << Password << "\n";
                cout << "\nPassword Was Not Changed!\n";
            }
        }
        else
        {
            tempFile << Username << "*" << Email << "*" << Password << "\n";
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found! Username or Email Doesn't Match.\n\n";
    }

    file.close();
    tempFile.close();

    remove(LOGIN_FILE.c_str());
    rename(TEMP_FILE.c_str(), LOGIN_FILE.c_str());
}