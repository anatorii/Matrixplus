#ifndef s21_matrix_oop_h
#define s21_matrix_oop_h

#define ACCURACY_EQ 1e-7

class S21Matrix {
   private:
    int rows_, cols_;
    double** matrix_;

   public:
    int getRows() const;
    int getCols() const;
    void setRows(int rows);
    void setCols(int cols);

   public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    bool EqMatrix(const S21Matrix& other) const;
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();

    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator=(S21Matrix&& other);
    double& operator()(int row, int col);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix operator+(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double number);
    S21Matrix operator*(const S21Matrix& other) const;
    S21Matrix operator*(const double number) const;
    bool operator==(const S21Matrix& other) const;

    friend S21Matrix operator*(double number, const S21Matrix& matrix);

   private:
    S21Matrix MinorMatrix(int i, int j);
};

#endif
