#include <iostream>
#include <string>

using namespace std;

string Xor (const string& input, const string& key) {
    string output = input; 

    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key[i % key.size()]; 
    }
    return output;
}

int main() {
    string choice;
    cout << "Choose an action (encrypt/decrypt): ";
    cin >> choice;

    if (choice == "encrypt") {
        string key, message;
        cout << "Enter key: ";
        cin >> key;

        cin.ignore(); // игнорирование строки (символ)

        cout << "Enter message to encrypt: ";
        getline(cin, message);

        string encryptedMessage = Xor(message, key);
        cout << "Encrypted message: " << encryptedMessage << endl;

    }
    else if (choice == "decrypt") {
        string key, encryptedMessage;
        cout << "Enter key: ";
        cin >> key;
        cin.ignore();

        cout << "Enter message to decrypt: ";
        getline(cin, encryptedMessage);

        string decryptedMessage = Xor(encryptedMessage, key);
        cout << "Decrypted message: " << decryptedMessage << endl;

    }
    else {
        cout << "Invalid choice. Please choose 'encrypt' or 'decrypt'." << endl;
    }

    return 0;
}