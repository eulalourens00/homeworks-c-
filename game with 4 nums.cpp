#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void start(vector<int>& player1, const int& size) {
    cout << "Enter a combination of four numbers (1 - 6): ";
    int number;
    player1.clear();
    for (int i = 0; i < size; i++) {
        cin >> number;
        if (number >= 1 && number <= 6) {
            player1.push_back(number);
        }
        else {
            cout << "Read rules again." << endl;
            i--;
        }
    }
}
void attempt_2player(const vector<int>& player1, const int& size) {
    int attempts = 6;
    vector<int> player2(size);

    while (attempts > 0) {
        cout << "\nYou need to guess! \nEnter a combination of four numbers (1 - 6): ";
        int number;
        player2.clear();

        for (int i = 0; i < size; i++) {
            cin >> number;
            if (number >= 1 && number <= 6) {
                player2.push_back(number);
            }
            else {
                cout << "Read rules again." << endl;
                i--; 
            }
        }

        if (player1 == player2) {
            cout << "You win! Ymnichka!" << endl;
            return; 
        }

        // Сколько чисел на нужных позициях и те, что не на нужных
        vector<int> duplicates;
        vector<int> indices;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (player1[i] == player2[j]) {
                    duplicates.push_back(i);
                    indices.push_back(j);
                }
            }
        }

        cout << "\nWhich elements from the first vector have these numbers (index): ";
        for (const auto& elem : duplicates) {
            cout << elem << " ";
        }
        cout << endl;

        cout << "This elements from the second vector (index): ";
        for (const auto& index : indices) {
            cout << index << " ";
        }
        cout << endl;

        attempts--;
        cout << "\nAttempts left: " << attempts << endl;

        if (attempts == 0) {
            cout << "\nGame over! You've used all your attempts." << endl;
            cout << "The answer was: ";
            for (int num : player1) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    const int size = 4;
    vector<int> player1(size);

    start(player1, size); 
    attempt_2player(player1, size); 

    return 0;
}