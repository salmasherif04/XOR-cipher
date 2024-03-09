#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string xorCipher(string message, string key, char mode) {
    string result;
    int keyIndex = 0;
    for (char c : message) {
        char keyChar = key[keyIndex % key.length()];
        result += char(int(c) ^ int(keyChar));
        keyIndex++;
    }
    return (mode == 'e' || mode == 'E') ? result : xorCipher(result, key, 'd'); // Decrypt if mode is 'd' or 'D'
}

int main() {
    string message, key;
    char choice;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the key (one or more letters): ";
    getline(cin, key);

    cout << "Encrypt (E) or Decrypt (D)? ";
    cin >> choice;

    string encryptedMessage = xorCipher(message, key, choice);

    cout << "Result: " << encryptedMessage << endl;
    if (choice == 'e' || choice == 'E') {
        cout << "Hexadecimal: ";
        for (char c : encryptedMessage) {
            cout << hex << setw(2) << setfill('0') << int(c) << " ";
        }
        cout << endl;
    }

    return 0;
}
