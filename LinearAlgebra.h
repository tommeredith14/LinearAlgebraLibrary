#pragma once

#ifndef LINEARALGEBRA_H

#define LINEARALGEBRA_H
#include<iostream>
#include<iomanip>
namespace LinAlg {

	class Matrix {

		int rows, cols;
		double** a; //a represents the matrix as a 2D array (cols by rows)
		void reset();


	public:
		Matrix();
		Matrix(int row, int col);
		Matrix(const Matrix & other);
		~Matrix();
		void setDimensions(int row, int col);
		void setElement(int row, int col, double val);
		double getElement(int row, int col)const;	
		bool readIn(std::istream & in);
		void output(std::ostream & out);
		
		
		int getColumns()const;
		int getRows() const;
	
		bool operator==(Matrix const & other)const;
		Matrix& operator=(const Matrix & other);
		const Matrix operator + (const Matrix & other) const;
		const Matrix operator - (const Matrix & other) const;
		const Matrix operator * (const Matrix & other) const;
		const Matrix operator * (double scalar) const;
		const friend Matrix operator * (double scalar, Matrix const & matrixToMultiply);
		int deteminant()const;

		//scalar *
		//+, -
	};


	class Vector {
		int dimension;
		double * val;
		void reset();

	public:
		Vector();
		Vector(int dim);
		~Vector();
		void setDimension(int newDim);

		


	};



}

#endif