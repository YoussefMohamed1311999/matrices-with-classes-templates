#include "MatrixCalculator.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

template <class Type>
MatrixCalculator<Type>::MatrixCalculator()
{
	int choice;
	
start:
	
	cout << "welcome to youssef's Matrix Calculator \n--------------------------------- \n 1- Perform Matrix Addition \n 2- Perform Matrix Subtraction \n 3- Perform Matrix Multiplication \n 4- Matrix Transpose \n 0-exit \n\n";
	
	cin >> choice;
	Matrix<Type> m1, m2;



	if (choice == 1) {
		cout << "enter your first matrix's dimensions :";
		cin >> m1;
		cout << "\nenter the second matrix's dimensions :";
		cin >> m2;
		cout << "\n the resultant matrix is  :\n" << m1 + m2<<endl;
		goto start;
		}
	
	else if (choice == 2) {
		cout << "enter your first matrix's dimensions :";
		cin >> m1;
		cout << "\nenter the second matrix's dimensions :";
		cin >> m2;
		cout << "\nthe resultant matrix is :\n" << m1 - m2 << endl;
		goto start;
		}
	
	else if (choice == 3) {
		cout << "enter your first matrix's dimensions :";
		cin >> m1;
		cout << "\nenter the second matrix's dimensions :";
		cin >> m2;
		cout << "\nthe resultant matrix is : \n" << m1 * m2 << endl;
		goto start;

		}
	
	else if (choice == 4) {
		cout << "enter your the matrix's dimensions :";
		cin >> m1;
		cout << m1.transpose();
		goto start;
		}

	else if (choice == 0) {
		exit;
		}
}
