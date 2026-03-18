#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(inverse_tests, subtest_1) {
    S21Matrix mat1(1, 1);
    mat1(0, 0) = 7;

    S21Matrix exp(1, 1);
    exp(0, 0) = 1.0 / 7.0;

    S21Matrix result = mat1.InverseMatrix();

    ASSERT_TRUE(result.EqMatrix(exp));
}

TEST(inverse_tests, subtest_2) {
    // arrange
    S21Matrix mat1(3, 3);
    mat1(0, 0) = 15;
    mat1(0, 1) = 165.1;
    mat1(0, 2) = 984;
    mat1(1, 0) = -184;
    mat1(1, 1) = 9446;
    mat1(1, 2) = -494.055;
    mat1(2, 0) = 445;
    mat1(2, 1) = 135.54;
    mat1(2, 2) = 648;

    // act
    S21Matrix result = mat1.InverseMatrix();

    // assert
    ASSERT_NEAR(result(0, 0), -1.5149711102115e-3, ACCURACY_EQ);
    ASSERT_NEAR(result(0, 1), -6.46e-6, ACCURACY_EQ);
    ASSERT_NEAR(result(0, 2), 0.002295586313, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 0), 2.463491e-5, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 1), 1.048243282e-4, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 2), 4.2512702776e-5, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 0), 0.0010352208769, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 1), -1.7489426e-5, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 2), -4.212666863e-5, ACCURACY_EQ);
}

TEST(inverse_tests, subtest_3) {
    // arrange
    S21Matrix mat1(4, 4);

    mat1(0, 0) = 3;
    mat1(0, 1) = 4;
    mat1(0, 2) = 23;
    mat1(0, 3) = 44;
    mat1(1, 0) = 63;
    mat1(1, 1) = 45;
    mat1(1, 2) = 52;
    mat1(1, 3) = -44;
    mat1(2, 0) = 453;
    mat1(2, 1) = -14;
    mat1(2, 2) = 1;
    mat1(2, 3) = 5;
    mat1(3, 0) = 87;
    mat1(3, 1) = 45;
    mat1(3, 2) = 115;
    mat1(3, 3) = -14;

    // act
    S21Matrix result = mat1.InverseMatrix();

    // assert
    ASSERT_NEAR(result(0, 0), 0.000932559197852838, ACCURACY_EQ);
    ASSERT_NEAR(result(0, 1), 0.00145294216742607, ACCURACY_EQ);
    ASSERT_NEAR(result(0, 2), 0.00216487583437313, ACCURACY_EQ);
    ASSERT_NEAR(result(0, 3), -0.000862319392096906, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 0), 0.0384750138661216, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 1), 0.0476284383696308, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 2), -0.00126677353179257, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 3), -0.0292203247009548, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 0), -0.0126243278199766, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 1), -0.0190625021754937, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 2), -0.00107746536014388, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 3), 0.0198494532030024, ACCURACY_EQ);
    ASSERT_NEAR(result(3, 0), 0.0257650410636686, ACCURACY_EQ);
    ASSERT_NEAR(result(3, 1), 0.00553556750126259, ACCURACY_EQ);
    ASSERT_NEAR(result(3, 2), 0.000530776588803638, ACCURACY_EQ);
    ASSERT_NEAR(result(3, 3), -0.00766066287929422, ACCURACY_EQ);
}

TEST(inverse_tests, subtest_4) {
    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix exp(3, 3);
    mat1(0, 0) = 2;
    mat1(0, 1) = 4;
    mat1(0, 2) = -1;
    mat1(1, 0) = 7;
    mat1(1, 1) = 3;
    mat1(1, 2) = 1;
    mat1(2, 0) = -3;
    mat1(2, 1) = 5;
    mat1(2, 2) = 6;
    exp(0, 0) = -13.0 / 198.0;
    exp(0, 1) = 29.0 / 198.0;
    exp(0, 2) = -7.0 / 198.0;
    exp(1, 0) = 5.0 / 22.0;
    exp(1, 1) = -1.0 / 22.0;
    exp(1, 2) = 1.0 / 22.0;
    exp(2, 0) = -2.0 / 9.0;
    exp(2, 1) = 1.0 / 9.0;
    exp(2, 2) = 1.0 / 9.0;

    // act
    S21Matrix result = mat1.InverseMatrix();

    // assert
    ASSERT_TRUE(result.EqMatrix(exp));
}

TEST(inverse_tests, subtest_5) {
    // arrange
    S21Matrix mat1(5, 2);

    // assert
    ASSERT_THROW(mat1.InverseMatrix(), std::logic_error);
}
