#include "s21_matrix_oop.h"

#include <math.h>

#include <cstring>
#include <iostream>

S21Matrix::S21Matrix() {
    rows_ = 10;
    cols_ = 10;
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
        std::memset(matrix_[i], 0, cols_ * sizeof(double));
    }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
        std::memset(matrix_[i], 0, cols_ * sizeof(double));
    }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
        std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    if (this != &other) {
        matrix_ = other.matrix_;
        rows_ = other.rows_;
        cols_ = other.cols_;
        other.matrix_ = nullptr;
        other.rows_ = 0;
        other.cols_ = 0;
    }
}

S21Matrix::~S21Matrix() {
    if (matrix_) {
        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }
}

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setRows(int rows) {
    if (rows != rows_) {
        S21Matrix tmp(*this);

        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;

        rows_ = rows;
        matrix_ = new double*[rows_]();
        for (int i = 0; i < rows_; i++) {
            matrix_[i] = new double[cols_]();
        }

        int copy_r = rows > tmp.getRows() ? tmp.getRows() : rows;
        for (int i = 0; i < copy_r; i++) {
            for (int j = 0; j < tmp.getCols(); j++) {
                matrix_[i][j] = tmp(i, j);
            }
        }
    }
}

void S21Matrix::setCols(int cols) {
    if (cols > cols_) {
        S21Matrix tmp(*this);

        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;

        cols_ = cols;
        matrix_ = new double*[rows_]();
        for (int i = 0; i < rows_; i++) {
            matrix_[i] = new double[cols_]();
            std::memcpy(matrix_[i], tmp.matrix_[i],
                        tmp.getCols() * sizeof(double));
        }
    } else {
        cols_ = cols;
    }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
    bool result_status = true;
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        result_status = false;
    }
    if (result_status == true) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                double sub = fabsl(matrix_[i][j] - other.matrix_[i][j]);
                if (sub >= ACCURACY_EQ) {
                    result_status = false;
                    break;
                }
            }
            if (result_status == false) break;
        }
    }

    return result_status;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_ || rows_ == 0 ||
        cols_ == 0) {
        throw std::range_error(
            "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < rows_; i++) {
        for (auto j = 0; j < cols_; j++) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_ || rows_ == 0 ||
        cols_ == 0) {
        throw std::range_error(
            "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < rows_; i++) {
        for (auto j = 0; j < cols_; j++) {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

void S21Matrix::MulNumber(const double num) {
    for (auto i = 0; i < rows_; i++) {
        for (auto j = 0; j < cols_; j++) {
            matrix_[i][j] *= num;
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (cols_ != other.rows_) {
        throw std::range_error(
            "The number of columns of the first matrix is not equal to the "
            "number of rows of the second matrix.");
    }
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < result.rows_; i++) {
        for (int j = 0; j < result.cols_; j++) {
            result.matrix_[i][j] = 0;
            for (int k = 0; k < cols_; k++) {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    *this = result;
}

S21Matrix S21Matrix::Transpose() {
    S21Matrix result(cols_, rows_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.matrix_[j][i] = matrix_[i][j];
        }
    }
    return result;
}

S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_) {
        throw std::logic_error("The matrix is not square");
    }
    S21Matrix result(rows_, cols_);
    if (rows_ == 1) {
        result.matrix_[0][0] = 1;
    } else {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                S21Matrix minor = MinorMatrix(i, j);
                result.matrix_[i][j] =
                    minor.Determinant() * ((i + j) % 2 == 0 ? 1 : -1);
            }
        }
    }
    return result;
}

double S21Matrix::Determinant() {
    if (rows_ != cols_) {
        throw std::logic_error("The matrix is not square");
    }
    double det = 0;
    if (rows_ == 1) {
        det = matrix_[0][0];
    } else if (rows_ == 2) {
        det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
        for (int j = 0; j < cols_; j++) {
            S21Matrix minor = MinorMatrix(0, j);
            det += (j % 2 == 0 ? 1 : -1) * matrix_[0][j] * minor.Determinant();
        }
    }
    return det;
}

S21Matrix S21Matrix::InverseMatrix() {
    double det = Determinant();
    if (fabsl(det) <= ACCURACY_EQ) {
        throw std::logic_error("Matrix determinant is 0");
    }
    if (rows_ == 1) {
        S21Matrix result(rows_, cols_);
        result.matrix_[0][0] = 1.0 / matrix_[0][0];
        return result;
    } else {
        S21Matrix complements = CalcComplements();
        S21Matrix result = complements.Transpose();
        result.MulNumber(1 / det);
        return result;
    }
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;

        rows_ = other.rows_;
        cols_ = other.cols_;
        matrix_ = new double*[rows_]();
        for (int i = 0; i < rows_; i++) {
            matrix_[i] = new double[cols_]();
            std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
        }
    }
    return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
    if (this != &other) {
        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;

        rows_ = other.rows_;
        cols_ = other.cols_;
        matrix_ = other.matrix_;
        other.rows_ = 0;
        other.cols_ = 0;
        other.matrix_ = nullptr;
    }
    return *this;
}

double& S21Matrix::operator()(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return matrix_[row][col];
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    SumMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix result(*this);
    result.SumMatrix(other);
    return result;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    SubMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix result(*this);
    result.SubMatrix(other);
    return result;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    MulMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) {
    MulNumber(number);
    return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
    S21Matrix result(*this);
    result.MulMatrix(other);
    return result;
}

S21Matrix S21Matrix::operator*(const double number) const {
    S21Matrix result(*this);
    result.MulNumber(number);
    return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
    return EqMatrix(other);
}

S21Matrix S21Matrix::MinorMatrix(int r, int c) {
    S21Matrix result(rows_ - 1, cols_ - 1);

    int di = 0;
    for (int i = 0; i < rows_; i++) {
        if (i == r) continue;
        int dj = 0;
        for (int j = 0; j < cols_; j++) {
            if (j == c) continue;
            result.matrix_[di][dj] = matrix_[i][j];
            dj++;
        }
        di++;
    }

    return result;
}

S21Matrix operator*(double number, const S21Matrix& matrix) {
    S21Matrix result(matrix);
    result.MulNumber(number);
    return result;
}
