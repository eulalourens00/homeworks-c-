#include <iostream>

#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

//1.
void tabulashn() {
    for (int i = 0; i < 6; i++) {
        cout << i << "\t" << pow(i, 2) << endl;
    }
}

//2.
double summa_trig(const double& PI, int& sian) {
    double summa = 0.0;
    double current_sum = 0.0; //сумма синусов 1/sin1+1/(sin1+sin2)

    for (int i = 1; i <= sian; i++) {
        current_sum += sin(i * PI / 180);
        summa += 1 / current_sum;
    }
    return summa;
}

//3.   работает в онлайн, должны разобрать на паре. посмотреть дополнительно
//double cot(double &a, double& b, double& h) {
//    cout << setprecision(3);
//
//    for (double x = a; x <= b; x += h) {
//        double ln = log(x);
//        double cot = 1 / tan(ln);
//        double result = pow(cot, 2); // y = cot^2(x) * ln(x)
//        cout << result << "\n";
//    }
//}

//4. 
void rhomb() {
    char symbol;
    int height;
    cout << "Choose a symbol for your rhomb (* + #)  \nAnd enter height (with space):";
    cin >> symbol >> height;

    int width = height;

    switch (symbol) {
    case '*':
    case '+':
    case '#':
        //верх
        for (int i = 0; i < height / 2 + 1; i++) {
            for (int j = 0; j < width / 2 - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << symbol;
            }
            cout << endl;
        }

        // низ
        for (int i = height / 2 - 1; i >= 0; i--) {
            for (int j = 0; j < width / 2 - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << symbol;
            }
            cout << endl;
        }
        break;

    default: cout << "Mistake." << endl;
        break;
    }
}


//5.
void nechet() {
    vector<int>numbers;

    cout << "If u wanna stop - enter 0" << endl;
    while (true) {
        int n;
        cout << "Add number in vector: ";
        cin >> n;
        
        if (n == 0) {
            cout << "Set is finished" << endl;
            break;
        }
        else {
            numbers.push_back(n);
        }
        
    }

    cout << "Its your vector: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Odd numbers: ";
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {
            continue;
        }
        else {
            cout << numbers[i] << " ";
        }
    }
}

int main() {
    const double PI = 3.141592653589793238463;

    //1.
    tabulashn();

    //2.
    int sian;
    cout << "Choose a natural number for our task: ";
    cin >> sian;

    cout << "Result is " << summa_trig(PI, sian) << endl;

    //3.
    //double h = 0.1;
    //double a = 5.0 / 100;
    //double b = a + 0.5;

    //cout << cot(a, b, h) << endl;

    //4.
    rhomb();
    //5.
    nechet();
    return 0;
}