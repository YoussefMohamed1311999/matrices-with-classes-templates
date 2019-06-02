#pragma once
#include<iostream>
#include<valarray>
#include <vector>
using namespace std;

template <class T>
class Matrix
{
public:
	friend istream& operator>> (istream& in, Matrix<T> &mat)
	{
		int r, c;
		cin >> r >> c;
		T** num;
		num = new T*[r];
		for (int i = 0; i < r; i++)
			num[i] = new T[c];
		cout << "input the elements the matrix :" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				in >> num[i][j];

			}

		}
		mat.createMatrix(r, c, num);
		return in;

	}

	
	friend ostream& operator<< (ostream& out, Matrix<T> mat)
	{
		for (int i = 0; i < mat.row; i++) {
			for (int j = 0; j < mat.col; j++) {

				out << mat.data[i][j] << ' ';

			}
			out << endl;

		}
		return out;
	}
	void createMatrix(int row, int col, T** num);
	Matrix operator+  (Matrix& mat2);
	Matrix operator-  (Matrix mat2);
	Matrix operator*  (Matrix mat2);
	Matrix transpose();

private:
	int row, col;
	T** data;
};
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;


