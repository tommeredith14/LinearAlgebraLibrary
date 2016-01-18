#include "LinearAlgebra.h"
#include <cmath>
#include <iostream>

using std::ostream;
using std::istream;
using std::cout;
using std::endl;

namespace LinAlg {
	Matrix::Matrix() {
		rows = 1;
		cols = 1;
		a = new double*[cols];
		a[0] = new double[rows];
		a[0][0] = 0;

	}
	Matrix::Matrix(int row, int col) {
		rows = row;
		cols = col;
		a = new double*[cols];
		for (int i = 0; i < cols; i++)
		{
			a[i] = new double[rows];
			for (int j = 0; j < rows; j++)
				a[i][j] = 0;
		}
	}

	Matrix:: ~Matrix() {
		for (int i = 0; i < cols; i++)
			delete a[i];
		delete a;
		a = NULL;
		cout << "all deleted" << endl;
	}
	void Matrix::setDimensions(int row, int col) {
		
		for (int i = 0; i < cols; i++)
			delete a[i];
		delete a;
		a = NULL;
		rows = row;
		cols = col;

	}
	
	int Matrix::getColumns()const {
		return cols;
	}
	int Matrix::getRows() const {
		return rows;
	}
}