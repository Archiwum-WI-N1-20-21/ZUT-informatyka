#include <iostream>
#include <time.h>

template <class T>
class DynArr {
private:
	T *darray;
	const int initSize = 1;
	int capacity = initSize;
	int expandFactor = 2;
	int arrSize;

public:
	DynArr() { // constructor
		darray = new T[initSize];
		arrSize = 0;
	}
	~DynArr() { // destructor
		delete[] darray;
	}
	void expandArray() { // expands array by expand factor
		capacity *= expandFactor;
		T *temp = new T[capacity];
		std::copy(darray, darray + arrSize, temp);
		delete[] darray;
		darray = temp;
	}
	void insert(T data) { // appends new element to array
		changeElement(arrSize, data);
	}
	void elementInfo(int position) { // returns value of element
		std::cout << std::endl << "Element at position: " << position << " is: " << darray[position];
	}
	void changeElement(int position, T data) { // inserts/replaces element with new data
		if (arrSize == capacity) {
			expandArray();
		}
		for (int i = arrSize; i > position; i--) {
			darray[i] = darray[i - 1];
		}
		arrSize++;
		darray[position] = data;
	}
	void arrayInfo() { // displays information about array
		std::cout << std::endl << "Array size = " << arrSize << ", Array capacity: " << capacity << ", First 5 elements: ";
		for (int i = 0; i < 5; i++) {
			std::cout << darray[i] << " ";
		}
	}
	void sort() { // bubble sorts the array
		T temp;
		int counter = 0;
		int swapped = 0;
		for (int i = 0; i < arrSize; i++) {
			swapped = 0;
			for (int j = 0; j < arrSize - i - 1; j++) {
				if (darray[j] > darray[j + 1]) {
					temp = darray[j];
					darray[j] = darray[j + 1];
					darray[j + 1] = temp;
					swapped = 1;
				}
				counter += 1;
			}
			counter += 1;
			if (!swapped) break;
		}
	}
};

int main() {
	srand(time(0));
	DynArr<int> dArr;

	clock_t tBegin = 0, tEnd = 0, tElBegin = 0, tElEnd = 0;
	double timeTotal = 0, timeElement = 0, maxTimeElement = 0;
	int randData;

	tBegin = clock();

	for (int i = 0; i < pow(10, 7); i++) {
		randData = rand() % 100;
		tElBegin = clock();
		dArr.insert(randData);
		tElEnd = clock();
		timeElement = (double)(tElEnd - tElBegin);
		if (timeElement > maxTimeElement) {
			maxTimeElement = timeElement;
			std::cout << "New max time per element: " << maxTimeElement << std::endl;
		}
	}

	tEnd = clock();
	timeTotal = (double)(tEnd - tBegin);
	std::cout << "Total time: " << timeTotal << ", max time per element: " << maxTimeElement;
	dArr.arrayInfo();

	return 0;
}