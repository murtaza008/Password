#include <iostream>

using namespace std;

/*Assume a simple login system in which user can provide its password as a string and your
program will validate its password. The password should be from 8 to 16 characters long. The
password can contain only alphabets, digits and special symbols (@, $, %, &, *). The password
must have one upper case alphabet, one digit and one special symbol. The password cannot
start from a special symbol. */

int main()
{
    string password; // declared variable
    bool hasUppercase = false, hasDigit = false, hasSpecialSymbol = false; // initialized variable

    // Prompt user to enter password
    cout << "Password: ";
    getline(cin, password);

    if (password.length() >= 8 && password.length() <= 16) // Check if password length is between 8 and 16 characters
    {
        for (char c : password) // Check each character in password to see if it meets certain requirements
        {
            if (isupper(c)) // Check if password has an uppercase letter
            {
                hasUppercase = true;
            }
            else if (isdigit(c)) // Check if password has a digit
            {
                hasDigit = true;
            }
            else if (c == '@' || c == '$' || c == '%' || c == '&' || c == '*') // Check if password has a special symbol
            {
                hasSpecialSymbol = true;
            }
        }

        if (password[0] == '@' || password[0] == '$' || password[0] == '%' || password[0] == '&' || password[0] == '*') // check if password starts with a special symbol
        {
            cout << "Invalid, Password cannot start with special symbol" << endl;
        }
        else if (hasUppercase && hasDigit && hasSpecialSymbol) // Check if password meets all requirements and is valid
        {
            cout << "Valid" << endl;
        }
        else if (hasDigit && hasSpecialSymbol && !hasUppercase) // Check if password does not have a uppercase
        {
            cout << "Invalid, Must have one uppercase letter" << endl;
        }
        else if (hasDigit && hasUppercase && !hasSpecialSymbol) // Check if password does not have a special symbol
        {
            cout << "Invalid, No special symbol" << endl;
        }
        else if (hasSpecialSymbol && hasUppercase && !hasDigit) //Check if password does not have a digit
        {
            cout << "Invalid, Must have one digit" << endl;
        }
    }
    else // If password length is not between 8 and 16 characters
    {
        cout << "Invalid, Length of password must be between 8 and 16 characters" << endl;
    }

    return 0; // program end
}
