#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


1 task
bool isBool(int i) { return ((i % 2) == 1); }

int help(vector<int>& numbers) {
   int result = count_if(numbers.begin(), numbers.end(), isBool);
   return result;
}

int main() {

   vector<int> numbers{ 10, 23, 34, 45, 56, 147 };
   int result = help(result);
   cout << result;
   return 0;
}

2 task
vector<double> moving_average(const vector<double>& data, size_t window_size) {
   vector<double> averages;

   if (window_size == 0 || data.size() < window_size) {
       return averages;
   }

   for (size_t i = 0; i <= data.size() - window_size; ++i) {
       double sum = accumulate(data.begin() + i, data.begin() + i + window_size, 0.0);
       averages.push_back(sum / window_size);
   }

   return averages;
}

int main() {
   vector<double> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   size_t window_size = 3;

   vector<double> result = moving_average(data, window_size);

   cout << "Result is: ";
   for (double avg : result) {
       cout << avg << " ";
   }
   cout << endl;

   return 0;
}


3 task
vector<double> c_vector(const vector<double>& data) {
   vector<double> c_data;
   double mean = accumulate(data.begin(), data.end(), 0.0) / data.size();

   for (double value : data) {
       c_data.push_back(value - mean);
   }

   return c_data;
}

int main() {
   vector<double> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

   vector<double> centered = c_vector(data);

   cout << "Center vector: ";
   for (double value : centered) {
       cout << value << " ";
   }
   cout << endl;

   return 0;
}
4 task

int maxelement(vector<int>& numbers, vector<int>& bar) {
	auto it = copy_if(numbers.begin(), numbers.end(), bar.begin(), [](int i) {return i % 13 == 0; });
	bar.resize(distance(bar.begin(), it));

	cout << "Numbers which %13 == 0 :";
	for (int& x : bar) cout << ' ' << x;
	cout << '\n';

	int max_val = *max_element(bar.begin(), bar.end());
	return max_val;
}

int main() {
	
	vector<int> numbers = { 13, 23, 39, 45, 143, 147 };
	vector<int> bar(numbers.size());

	cout << maxelement(numbers, bar) << " - is max ";
	return 0;
}

5 task
double mediana(vector<int>& numbers) {
	int mediana = numbers.size() / 2;
	int n = numbers.size();
	if (mediana % 2 != 0) {
		double r = (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
		return r;
	}
	else {
		double c = n / 2.0;
		return c;
	}
}


int main() {
	vector<int> numbers{ 10, 23, 34, 45, 56, 147 };
	double result = mediana(numbers);
	cout << "Mediana is " << result;
}

6 task
int moreN(int N, const vector<int>& numbers) {
   int result = count_if(numbers.begin(), numbers.end(), [N](int i){ return i > N; });
   return result;
}

int main() {
   int N;
   cout << "Enter N: ";
   cin >> N; 

   vector<int> numbers{ 10, 23, 34, 45, 56, 147 };

   int result = moreN(N, numbers);
   cout << "Count of numbers " << N << ": " << result << endl;

   return 0;
}