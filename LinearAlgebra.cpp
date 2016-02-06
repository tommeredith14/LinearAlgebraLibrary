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

	Matrix::Matrix(const Matrix & other)
	{
		rows = other.rows;
		cols = other.cols;
		a = new double*[cols];
		for (int i = 0; i < cols; i++)
		{
			a[i] = new double[rows];
			for (int j = 0; j < rows; j++)
				a[i][j] = 0;
		}
		cout << "copying";
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				a[j][i] = other.a[j][i];
		cout << "copied";
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
		a = new double*[cols];
		for (int i = 0; i < cols; i++)
		{
			a[i] = new double[rows];
			for (int j = 0; j < rows; j++)
				a[i][j] = 0;
		}

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
		cout << other.getColumns();

		if (*this == other)
			return *this;
		else {

			
			this->setDimensions(other.rows, other.cols);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
				{
					this->a[j][i] = other.a[j][i];
					std::cout << "okay \n";
				}
	
			return *this;
		}
		
	}
	const Matrix Matrix::operator+(const Matrix & other) const
	{
		if (rows == other.rows && cols == other.cols) {
			Matrix sum(rows, cols);
			
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					sum.a[j][i] = a[j][i] + other.a[j][i];
			cout << "added successfully\n";
			
			return sum;
		}
		
	}
	const Matrix Matrix::operator-(const Matrix & other) const
	{
		if (rows == other.rows && cols == other.cols) {
			Matrix difference(rows, cols);

			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					difference.a[j][i] = a[j][i] - other.a[j][i];
			cout << "added successfully\n";

			return difference;
		}

	}
	const Matrix Matrix::operator*(const Matrix & other) const
	{
		if (cols == other.rows) {
			Matrix product(rows, other.cols);
			for (int i = 0; i < product.rows; i++) {
				for (int j = 0; j < product.cols; j++) {
					double value = 0;
					for (int index = 0; index < (*this).cols; index++)
						value += a[index][i] * other.a[j][index];
					product.a[j][i] = value;
				}
			}
			return product;
		}
		
		
	}
	const Matrix Matrix::operator*(double scalar) const
	{
		Matrix scMult(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				scMult.a[j][i] = scalar * a[j][i];
		return scMult;
	}
	int Matrix::deteminant() const
	{
		if (rows == cols && rows > 0) {
			if (rows == 1)
				return a[0][0];
			if (rows == 2)
				return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
			double det = 0;
			for (int colNum = 0; colNum < cols; colNum++) {
				//Make resultant matrix
				Matrix cofactor(rows - 1, cols - 1);
				for (int cofCol = 0, originalCol = 0; cofCol < cofactor.rows; cofCol++, originalCol++) {
					if (originalCol == colNum)
						originalCol++;

					for (int row = 0; row < cofactor.rows; row++)
						cofactor.a[cofCol][row] = this->a[originalCol][row + 1];
				}
				//cofactor.output(cout);
				det += pow(-1, colNum) * a[colNum][0] * cofactor.deteminant();
				//cout<< det << endl;


			}
			return det;



		}
		
		
		return 0;
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
	const Matrix operator*(double scalar, Matrix const & matrixToMultiply)
	{
		return matrixToMultiply * scalar;
	}


	void Vector::reset() {
		delete val;
		val = NULL;
	}
	Vector::Vector() {
		dimension = 0;
	}
	Vector::Vector(int dim) {
		dimension = dim;
		val = new double[dim];
		for (int i = 0; i < dim; i++)
		{
			val[i] = dim;
		}
	}
	Vector:: ~Vector() {
		delete val;
		val = NULL;
	}
	void Vector:: setDimension(int newDim) {
		reset();
		dimension = newDim;
		val = new double[newDim];
		for (int i = 0; i < newDim; i++) {
			val[i] = 0;
		}
	}







}