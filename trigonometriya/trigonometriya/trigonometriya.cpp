#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//1.
double formula (const double &PI, double &x, double &y) {
	x = (x * PI) / 180 ;
	y = (y * PI) / 180;

	double result = pow((1 - tan(x)), (cos(x) / sin(x)) - cos(x - y));

	return result;
}

//2.
double fly(double &T, double &V) {
	const double g = 9.81;
	const double PI = asin(1.0);
	double a = (g * T / (2 * V));

	if (-1<= a && a <= 1) {
		a = asin(a);
		return a * (90/ PI);
	}
	else {
		cout << "Mistake" << endl;
	}

}

//3.
void comparison(int &number) {
	vector<int> parts;
	while (number > 0) {
		parts.push_back(number % 10);
		number /= 10;
	}

	reverse(begin(parts), end(parts));
	
	//сравнение цифр
	if (parts.size() > 0) {
		for (int i = 0; i < parts.size(); i++) {
			for (int j = 0; j < parts.size(); j++) {
				if (i != j) {
					if (parts[i] == parts[j]) {
						cout << "Number " << parts[i] << " = number " << parts[j] << endl;
					}
					else {
						cout << "Number " << parts[i] << " != number " << parts[j] << endl;
					}
				}
			}
		}
	}

	//разряды
	cout << "Type part of number:" << endl;

	for (int i = 0; i < parts.size(); i++) {
		if (i == parts.size() - 1) {
			cout << parts[i] << " - units" << endl;    /*единицы*/
		}
		else if (i == parts.size() - 2) {
			cout << parts[i] << " - dozens" << endl;	/*десятки*/
		}
		else if (i == parts.size() - 3) {
			cout << parts[i] << " - hundreds" << endl;
		}
		else {
			cout << parts[i] << " - " << (int)pow(10, parts.size() - 1 - i) << " (type)" << endl;
		}
	}
	
	cout << "All: ";

	for (int i = 0; i < parts.size(); i++) {
		cout << parts[i] << " ";
	}
	cout << endl;
}

//4.
double average(const int& size_of_m, double* chisla) {
	for (int i = 0; i < size_of_m; i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> chisla[i];
	}

	cout << "You entered: ";
	for (int i = 0; i < size_of_m; i++) {
		cout << chisla[i] << " ";
	}
	cout << endl;

	double sum = 0;
	for (int i = 0; i < size_of_m; i++) {
		sum += chisla[i];
	}
	return sum / size_of_m;
}

//5.
int five_numbers(int& finish) {
	int sum = 0;
	vector<int> need_numbers;

	for (int i = 0; i <= finish; i++) {
		if (i % 5 == 0) {
			sum += i;
			need_numbers.push_back(i);
		}
	}

	need_numbers.erase(need_numbers.begin() + 0);  /*удаление нуля из вектора*/

	cout << "Numbers divisible by five (5): ";
	for (int i = 0; i < need_numbers.size(); i++) {
		cout << need_numbers[i] << " ";
	}
	cout << endl;

	return sum;
}

int main()
{
	const double PI = 3.14159265358979323846;

	//1.
	double x, y;
	cout << "Enter x and y: ";
	cin >> x >> y;

	cout << "Result is " << formula(PI, x, y) << endl;

	//2.
	double T, V;
	cout << "Enter T and V: ";
	cin >> T >> V;

	cout << "The alpha angle is " << fly( T, V) << endl;

	//3.
	int number;
	cout << "Enter number: ";
	cin >> number;

	if (number < 0) {
		number = -number;    /*если число отрицательное, делаем его положительным*/
	}
	comparison(number);

	//4.
	int size_of_m;
	cout << "Enter a size of massive: ";
	cin >> size_of_m;

	double* chisla = new double[size_of_m];

	double avg = average(size_of_m, chisla);
	cout << "Average: " << avg << endl;

	delete[] chisla;

	//5.
	int finish;
	cout << "Enter the last number of section (0 - n): ";
	cin >> finish;

	cout << "Summa of numbers divisible by five (5) is " << five_numbers(finish) << endl;


	return 0;
}

