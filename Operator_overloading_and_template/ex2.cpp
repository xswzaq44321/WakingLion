#include <iostream>
using namespace std;

class Matrix{
	public:
		Matrix(){}
		Matrix(int data[3][3]){
			for(int i = 0; i < 3; ++i){
				for(int j = 0; j < 3; ++j){
					this->data[i][j] = data[i][j];
				}
			}
		}

		int data[3][3];

		Matrix operator*(const Matrix& rhs);
		Matrix operator+(const Matrix& rhs);
		Matrix operator-(const Matrix& rhs);
};

Matrix Matrix::operator*(const Matrix& rhs){
	Matrix ans;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			int temp;
			for(int k = 0; k < 3; ++k){
				temp += this->data[i][k] * rhs.data[k][j];
			}
			ans.data[i][j] = temp;
		}
	}
	return ans;
}
Matrix Matrix::operator+(const Matrix& rhs){
	Matrix ans;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			ans.data[i][j] = this->data[i][j] + rhs.data[i][j];
		}
	}
	return ans;
}
Matrix Matrix::operator-(const Matrix& rhs){
	Matrix ans;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			ans.data[i][j] = this->data[i][j] - rhs.data[i][j];
		}
	}
	return ans;
}

int main(){
	int data1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int data2[3][3] = {{5, 3, 9}, {1, 2, 2}, {9, 8, 9}};
	Matrix a(data1);
	Matrix b(data2);
	Matrix ans = a*b;
	cout << "a * b:" << endl;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cout << ans.data[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	ans = a + b;
	cout << "a + b:" << endl;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cout << ans.data[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	ans = a - b;
	cout << "a - b:" << endl;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cout << ans.data[i][j] << " ";
		}
		cout << endl;
	}
}
