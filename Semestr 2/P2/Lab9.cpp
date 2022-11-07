#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Piatka
{
private:
public:
	Piatka() {};
	~Piatka() {};

	template <typename T>
	T znajdzMinimum(T x1, T x2, T x3, T x4, T x5) {
		T arr[5] = {x1, x2, x3, x4, x5};
		int n = sizeof(arr) / sizeof(arr[0]);
		sort(arr, arr + n);
		cout << "minimum: " << arr[0] << endl;
	}

	template <typename T>
	T znajdzMaximum(T x1, T x2, T x3, T x4, T x5) {
		T arr[5] = {x1, x2, x3, x4, x5};
		int n = sizeof(arr) / sizeof(arr[0]);
		sort(arr, arr + n);
		cout << "maximum: " << arr[4] << endl;
	}

	template <typename T>
	T znajdzSrodkowa(T x1, T x2, T x3, T x4, T x5) {
		T arr[5] = {x1, x2, x3, x4, x5};
		int n = sizeof(arr) / sizeof(arr[0]);
		sort(arr, arr + n);
		cout << "srodkowa: " << arr[2] << endl;
	}

	template <typename T>
	T znajdzDruga(T x1, T x2, T x3, T x4, T x5) {
		T arr[5] = {x1, x2, x3, x4, x5};
		int n = sizeof(arr) / sizeof(arr[0]);
		sort(arr, arr + n);
		cout << "druga: " << arr[1] << endl;
	}

	template <typename T>
	T znajdzPrzedostatnia(T x1, T x2, T x3, T x4, T x5) {
		T arr[5] = {x1, x2, x3, x4, x5};
		int n = sizeof(arr) / sizeof(arr[0]);
		sort(arr, arr + n);
		cout << "przedostatnia: " << arr[3] << endl;
	}
};


int main() {
	cout << "statycznie:" << endl;

	Piatka statycznie;
	statycznie.znajdzMinimum<int>(5, 3, 8, 1, 2);
	statycznie.znajdzMaximum<double>(5.0, 3.0, 8.0, 1.0, 2.0);
	statycznie.znajdzSrodkowa<char>('a', 'g', 'i','o', 'w');
	statycznie.znajdzDruga<string>("a", "g", "i", "o", "w");
	statycznie.znajdzPrzedostatnia<int>(5, 3, 8, 1, 2);

	cout << "dynamicznie:" << endl;

	Piatka * dynamicznie = new Piatka;
	dynamicznie->znajdzMinimum<int>(5, 3, 8, 1, 2);
	dynamicznie->znajdzMaximum<double>(5.0, 3.0, 8.0, 1.0, 2.0);
	dynamicznie->znajdzSrodkowa<char>('a', 'g', 'i','o', 'w');
	dynamicznie->znajdzDruga<string>("a", "g", "i", "o", "w");
	dynamicznie->znajdzPrzedostatnia<int>(5, 3, 8, 1, 2);

	delete dynamicznie;

	return 0;
}