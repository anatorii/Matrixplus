#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(det_tests, subtest_1) {
    /**
     *  -3  -6   -9
     *   6   12   18
     *  -9  -18  -27
     */

    // arrange
    S21Matrix mat1(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1) * 3;
        }
    }

    // act
    double result = mat1.Determinant();

    // assert
    ASSERT_DOUBLE_EQ(result, 0);
}

TEST(det_tests, subtest_2) {
    /**
     *  -1   2  -3
     *   2   4   6
     *  -3   6  -9
     *   4   8   12
     */

    // arrange
    S21Matrix mat1(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
    }

    // act
    double result = mat1.Determinant();

    // assert
    ASSERT_DOUBLE_EQ(result, 0);
}

TEST(det_tests, subtest_3) {
    // arrange
    S21Matrix mat1(1, 1);
    mat1(0, 0) = 8;

    // act
    double result = mat1.Determinant();

    // assert
    ASSERT_DOUBLE_EQ(result, 8);
}

TEST(det_tests, subtest_4) {
    // arrange
    S21Matrix mat1(5, 5);
    mat1(0, 0) = -0.1234578;
    mat1(0, 1) = 846.3946115468;
    mat1(0, 2) = 5.1124868;
    mat1(0, 3) = 81.4621;
    mat1(0, 4) = -0.000001234578;
    mat1(1, 0) = 0.984631151;
    mat1(1, 1) = 1234567946;
    mat1(1, 2) = 999999.132456;
    mat1(1, 3) = -7135.11111111;
    mat1(1, 4) = 911111.64331;
    mat1(2, 0) = 94654.1231468;
    mat1(2, 1) = 881.7777;
    mat1(2, 2) = -124868;
    mat1(2, 3) = -3481.4621;
    mat1(2, 4) = 500;
    mat1(3, 0) = 1.000000001;
    mat1(3, 1) = -7946;
    mat1(3, 2) = -2456546;
    mat1(3, 3) = -7135.11111111;
    mat1(3, 4) = 1011.64331;
    mat1(4, 0) = 1.000000001;
    mat1(4, 1) = -763146;
    mat1(4, 2) = -2546;
    mat1(4, 3) = -7135.22211111;
    mat1(4, 4) = 1011.64331;

    double exp = -3.5528964488536425913909248e+25;

    // act
    double result = mat1.Determinant();

    // assert
    ASSERT_NEAR(result, exp, ACCURACY_EQ);
}

TEST(det_tests, subtest_5) {
    // arrange
    S21Matrix mat1(2, 2);
    mat1(0, 0) = 8;
    mat1(0, 1) = 44;
    mat1(1, 0) = 5;
    mat1(1, 1) = 6;

    double exp = -172;

    // act
    double result = mat1.Determinant();

    // assert
    ASSERT_NEAR(result, exp, ACCURACY_EQ);
}

TEST(det_tests, subtest_6) {
    // arrange
    S21Matrix mat1(1, 1);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = i + j + 1;
        }
    }

    // act
    double result = mat1.Determinant();

    // assert
    ASSERT_DOUBLE_EQ(result, 1.0);
}

TEST(det_tests, subtest_7) {
    // arrange
    S21Matrix mat1(3, 3);
    mat1(0, 0) = 4000.87;
    mat1(0, 1) = 454.0;
    mat1(0, 2) = 4.0;
    mat1(1, 0) = 2.0;
    mat1(1, 1) = 1.897;
    mat1(1, 2) = 3.0;
    mat1(2, 0) = 0.000087;
    mat1(2, 1) = 2.5668;
    mat1(2, 2) = 1.0;

    // act
    double result = mat1.Determinant();

    ASSERT_NEAR(result, -24105.996724156, ACCURACY_EQ);
}

TEST(det_tests, subtest_8) {
    // arrange
    S21Matrix mat1(5, 2);

    // assert
    ASSERT_THROW(mat1.Determinant(), std::logic_error);
}
