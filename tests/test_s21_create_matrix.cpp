#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(create_tests, subtest_1) {
    // arrange
    S21Matrix mat;
    int rows = 10;
    int columns = 10;

    // assert
    ASSERT_EQ(rows, mat.getRows());
    ASSERT_EQ(columns, mat.getCols());
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            ASSERT_DOUBLE_EQ(0, mat(i, j));
        }
    }
}

TEST(create_tests, subtest_2) {
    // arrange
    S21Matrix mat(3, 5);
    int rows = 3;
    int columns = 5;

    // assert
    ASSERT_EQ(rows, mat.getRows());
    ASSERT_EQ(columns, mat.getCols());
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            ASSERT_DOUBLE_EQ(0, mat(i, j));
        }
    }
}

TEST(create_tests, subtest_3) {
    // arrange
    S21Matrix mat;

    // act
    mat.setCols(mat.getCols() - 1);

    // assert
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            ASSERT_DOUBLE_EQ(0, mat(i, j));
        }
    }
}

TEST(create_tests, subtest_4) {
    // arrange
    S21Matrix mat;

    // act
    mat.setCols(mat.getCols() + 1);

    // assert
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            ASSERT_DOUBLE_EQ(0, mat(i, j));
        }
    }
}

TEST(create_tests, subtest_5) {
    // arrange
    S21Matrix mat;

    // act
    mat.setRows(mat.getRows() - 1);

    // assert
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            ASSERT_DOUBLE_EQ(0, mat(i, j));
        }
    }
}

TEST(create_tests, subtest_6) {
    // arrange
    S21Matrix mat;

    // act
    mat.setRows(mat.getRows() + 1);

    // assert
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            ASSERT_DOUBLE_EQ(0, mat(i, j));
        }
    }
}

TEST(create_tests, subtest_7) {
    // arrange
    S21Matrix mat(5, 5), exp(5, 5);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            mat(i, j) = exp(i, j) = i * j;
        }
    }

    // act
    mat.setRows(mat.getRows() + 1);
    mat.setCols(mat.getCols() + 1);

    // assert
    for (int i = 0; i < mat.getRows() - 1; i++) {
        for (int j = 0; j < mat.getCols() - 1; j++) {
            ASSERT_DOUBLE_EQ(mat(i, j), exp(i, j));
        }
    }
    for (int i = 0; i < mat.getCols(); i++) {
        ASSERT_DOUBLE_EQ(mat(mat.getRows() - 1, i), 0);
    }
    for (int i = 0; i < mat.getRows(); i++) {
        ASSERT_DOUBLE_EQ(mat(i, mat.getCols() - 1), 0);
    }
}

TEST(create_tests, subtest_8) {
    // arrange
    S21Matrix mat(5, 5), exp(5, 5);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            mat(i, j) = exp(i, j) = i * j;
        }
    }

    // act
    S21Matrix newMatrix;
    newMatrix = mat;

    // assert
    ASSERT_TRUE(exp.EqMatrix(mat));
    ASSERT_EQ(newMatrix.getRows(), exp.getRows());
    ASSERT_EQ(newMatrix.getCols(), exp.getCols());

    for (int i = 0; i < exp.getRows() - 1; i++) {
        for (int j = 0; j < exp.getCols() - 1; j++) {
            ASSERT_DOUBLE_EQ(newMatrix(i, j), exp(i, j));
        }
    }
}

TEST(create_tests, subtest_9) {
    // arrange
    S21Matrix mat(5, 5);

    // assert
    ASSERT_THROW(double d = mat(10, 10); (void)d, std::out_of_range);
    ASSERT_THROW(double d = mat(-10, -10); (void)d, std::out_of_range);
}
