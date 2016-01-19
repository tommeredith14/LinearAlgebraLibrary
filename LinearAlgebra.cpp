#include "LinearAlgebra.h"
#include <cmath>
#include <iostream>

using std::ostream;
using std::istream;
using std::cout;
using std::endl;

namespace LinAlg {
	void Matrix::reset()
	{
		for (int i = 0; i < cols; i++)
			delete a[i];
		delete a;
		a = NULL;
	}
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
		reset();
		a = NULL;
		cout << "all deleted" << endl;
	}
	void Matrix::setDimensions(int row, int col) {
		
		reset();
		rows = row;
		cols = col;

	}

	void Matrix::setElement(int row, int col, double val)
	{
		a[col][row] = val;
	}

	double Matrix::getElement(int row, int col) const
	{
		return a[col][row];
	}

	bool Matrix::readIn(std::istream & in)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (!(in >> a[j][i]))
					return false;
		return true;
	}

	void Matrix::output(std::ostream & out)
	{
		out << std::fixed << std::setprecision(3);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				out << std::setw(6) << a[j][i];
			
			out << endl;
		}
		
	}
	
	int Matrix::getColumns()const {
		return cols;
	}
	int Matrix::getRows() const {
		return rows;
	}
	Matrix & Matrix::operator=(const Matrix & other)
	{
		if (*this == other)
			return *this;
		else {
			this->reset();
			this->rows = other.rows;
			this->cols = other.cols;
			for (int i = 0; i < cols; i++)
				for (int j = 0; j < rows; j++)
					this->a[i][j] = other.a[i][j];
			return *this;
		}
		
	}
	bool Matrix::operator==(Matrix const & other)const
	{
		if (rows != other.rows || cols != other.cols)
			return false;
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < rows; j++)
				if (a[i][j] != other.a[i][j])
					return false;
		return true;
	}
}