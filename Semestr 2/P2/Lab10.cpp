#include <iostream>
#include <vector>

using namespace std;

class Test
{
private:
	vector<int> v1{3,50,10};
	vector<int> v2{1,2,3,4};
	int arr[4] = {-1,-2,-3,-4};
public:
	Test(){};
	~Test(){};

	void step1() {
		v1.insert(v1.begin(), -50);
	}

	void step2() {
		v1.insert(v1.end(), {1,1,1});
	}

	void step3() {
		v1.insert(v1.begin() + 1,{v2[0],v2[1],v2[2]});
	}

	void step4() {
		v1.insert(v1.end(), arr, arr+4);
	}

	void step5() {
		v1.erase(v1.begin() + 1, v1.end() - 1);
	}

	void step6() {
		vector<int> temp = v1;
		v1 = v2;
		v2 = temp;
	}

	void print() {
		for (int i = 0; i < v1.size(); i++)
        	cout << v1[i] << " ";
		cout << endl;
		for (int i = 0; i < v2.size(); i++)
        	cout << v2[i] << " ";
		cout << endl;
	}
};

int main() {
	cout << "statycznie:" << endl;
	Test statycznie;
	statycznie.step1();
	statycznie.step2();
	statycznie.step3();
	statycznie.step4();
	statycznie.step5();
	statycznie.step6();
	statycznie.print();

	cout << "dynamicznie:" << endl;
	Test * dynamicznie = new Test;
	dynamicznie->step1();
	dynamicznie->step2();
	dynamicznie->step3();
	dynamicznie->step4();
	dynamicznie->step5();
	dynamicznie->step6();
	dynamicznie->print();

	return 0;
}