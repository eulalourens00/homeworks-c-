#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct cat {
    string name;
    int age;
    string color;
    string breed;
};

void start();
cat recentCat;
vector<cat> savedCats;

ostream &operator<<(ostream &os, cat &cat) {
    os << "Name:\t" << cat.name << "\nAge:\t" << cat.age << "\nColor:\t" << cat.color << "\nBreed:\t" << cat.breed << "\n\n";
    return os;
}

ostream &operator<<(ostream &os, vector<cat> &cats) {
    os << "Vector of cats: " << endl;
    for (auto cat : cats) {
        os << "Name:\t" << cat.name << "\nAge:\t" << cat.age << "\nColor:\t" << cat.color << "\nBreed:\t" << cat.breed << "\n\n";
    }
    return os;
}

istream &operator>>(istream &is, cat &cat) {
    is >> cat.name >> cat.age >> cat.color >> cat.breed;
    return is;
}

void createCat(vector<cat> &savedCats, cat &recentCat) {
    system("cls");

    cout << "Create a record of cat\n" << "Pattern: {name} {age} {color} {breed}" << endl;
    cat newCat;
    cin >> newCat;
    recentCat = newCat;
    cout << "Save, add it at list? (yes/no)" << endl;

    char ch;
    cin >> ch;
    if (tolower(ch) == 'y') {
        savedCats.push_back(newCat);
        cout << "Save" << endl;
    } else {
        cout << "Not saved" << endl;
    }

    start();
}

void start() {
    vector<char> allowedKeys = {'1', '2', '3'};
    cout << "Choose a func: \n" << "1. Create a cat\n2. The last cat\n3. The list of saved cats" << endl;
    char ch;
    cin >> ch;

    if (ch == '1') {
        createCat(savedCats, recentCat);
    } else if (ch == '2') {
        system("cls");
        cout << "The last cat: \n" << recentCat;
    } else if (ch == '3') {
        system("cls");
        cout << savedCats;
    } else if (ch == 27) { // ESC key
        exit(0);
    } else {
        cout << "Mistake\n";
    }

    start();
}

int main() {
    system("chcp 65001");
    system("cls");
    cout << "ESC - Close programm" << endl;
    start();
}