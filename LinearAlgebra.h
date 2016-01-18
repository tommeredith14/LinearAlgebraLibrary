#pragma once

#ifndef LINEARALGEBRA_H

#define LINEARALGEBRA_H

namespace LinAlg {

	class Matrix {

		int rows, cols;
		double** a; //a represents the matrix as a 2D array (cols by rows)

	public:
		Matrix();
		Matrix(int row, int col);
		~Matrix();
		void setDimensions(int row, int col);
		
		int getColumns()const;
		int getRows() const;
		

	};

}

#endif