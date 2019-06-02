#include "Matrix.h"
#include<iostream>
#include <valarray>
using namespace std;


template <class T>
void Matrix<T>::createMatrix(int row, int col, T** num)
{
	this->row = row;
	this->col = col;
	data = new T*[row];
	for (int i = 0; i < row; i++)	data[i] = new T[col];
	
	

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
		
			data[i][j] = num[i][j];

		}
	}



};

template <class T>
Matrix<T> Matrix<T>:: operator+  (Matrix& mat2)
{
	Matrix result;
	T** num;
	num = new T*[row];
	for (int i = 0; i < row; i++)	num[i] = new T [col];

	if (this->row == mat2.row && this->col == mat2.col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				num[i][j] = mat2.data[i][j] + data[i][j];

			}
		}
		result.createMatrix(row, col, num);
		return result;
	}
	else {
		cout << "Can't be added" << endl;
		return result;
	}

};

template <class T>
Matrix<T> Matrix<T> :: operator-  (Matrix mat2)
{

	Matrix result;
	T** num;
	num = new T*[row];
	for (int i = 0; i < row; i++)	num[i] = new T[col];
	if (this->row == mat2.row && this->col == mat2.col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				num[i][j] = data[i][j] - mat2.data[i][j];

			}
		}
		result.createMatrix(row, col, num);
		return result;
	}
	else {
		cout << "Can't be subtracted" << endl;
	}
	return result;
};

template <class T>
Matrix<T>  Matrix<T>:: operator*  (Matrix mat2)
{
	Matrix ans;
	T** num;
	num = new T*[row];
	for (int i = 0; i < row; i++)	num[i] = new T[mat2.col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			num[i][j] = 0;
		}
	}

	if (this->col == mat2.row) {
		
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < mat2.col; ++j)
				for (int k = 0; k < col; ++k)
				{
					num[i][j] += this->data[i][k] * mat2.data[k][j];
				}
		ans.createMatrix(this->row, mat2.col, num);
		return ans;
	}
	else {
		cout << " matrices can not be multiplied because the first matches has a number of columns not matching the number of rows of the second. and the first matrix was :" << endl;
		return *this;
		
	}
};
template <class T>

Matrix<T>  Matrix<T>::transpose()
{
	Matrix ans;
	T** num;
	num = new T*[col];
	for (int i = 0; i < col; i++)	num[i] = new T[row];
	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->row; j++) {
			num[i][j] = data[j][i];
		}
	}
	ans.createMatrix(col, row, num);
	return ans;
};
template <class T>

istream& operator>> (istream& in, Matrix<T> &mat)
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

};

template <class T>
ostream& operator<< (ostream& out, Matrix<T> mat)
{
	for (int i = 0; i < mat.row; i++) {
		for (int j = 0; j < mat.col; j++) {

			out << mat.data[i][j] << ' ';

		}
		out << endl;

	}
	return out;
}

