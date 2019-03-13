#include <iostream>
using namespace std;

template<typename T>
T getMax(T a, T b){
	return (a > b ? a : b);
}

int getMax(int a, int b){
	cout << "int";
	return (a > b ? a : b);
}


int main(){
	cout << getMax(2, 3) << endl;
	cout << getMax(3.2, 9.4) << endl;
	cout << getMax(5, 3) << endl;
	cout << getMax((double)-20, 22.2) << endl;
	cout << getMax('a', 'z') << endl;
}
