#include <iostream>
using namespace std;

int flip(int a){
	return -1*a;
}

char flip(char a){
	if('a' <= a && a <= 'z'){
		return 'A' + a - 'a';
	}else if('A' <= a && a <= 'Z'){
		return 'a' + a - 'A';
	}else{
		return a;
	}
}

int main(){
	cout << flip(10) << endl;
	cout << flip(-87) << endl;
	cout << flip('q') << endl;
	cout << flip('P') << endl;
}
