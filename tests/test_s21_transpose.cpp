#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(trans_tests, subtest_1) {
    /**
     *  -1  -2  -3       -1  2  -3
     *   2   4   6 ^T  = -2  4  -6
     *  -3  -6  -9       -3  6  -9
     */

    // arrange
    S21Matrix mat1(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    S21Matrix result = mat1.Transpose();

    // assert
    ASSERT_DOUBLE_EQ(result(0, 0), -1);
    ASSERT_DOUBLE_EQ(result(0, 1), 2);
    ASSERT_DOUBLE_EQ(result(0, 2), -3);
    ASSERT_DOUBLE_EQ(result(1, 0), -2);
    ASSERT_DOUBLE_EQ(result(1, 1), 4);
    ASSERT_DOUBLE_EQ(result(1, 2), -6);
    ASSERT_DOUBLE_EQ(result(2, 0), -3);
    ASSERT_DOUBLE_EQ(result(2, 1), 6);
    ASSERT_DOUBLE_EQ(result(2, 2), -9);
}

TEST(trans_tests, subtest_2) {
    /**
     *  -1   2  -3       -1  2 -3  4
     *   2   4   6  ^T =  2  4  6  8
     *  -3   6  -9       -3  6 -9  12
     *   4   8   12
     */

    // arrange
    S21Matrix mat1(4, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
    }

    // act
    S21Matrix result = mat1.Transpose();

    // assert
    ASSERT_DOUBLE_EQ(result(0, 0), -1);
    ASSERT_DOUBLE_EQ(result(0, 1), 2);
    ASSERT_DOUBLE_EQ(result(0, 2), -3);
    ASSERT_DOUBLE_EQ(result(0, 3), 4);
    ASSERT_DOUBLE_EQ(result(1, 0), 2);
    ASSERT_DOUBLE_EQ(result(1, 1), 4);
    ASSERT_DOUBLE_EQ(result(1, 2), 6);
    ASSERT_DOUBLE_EQ(result(1, 3), 8);
    ASSERT_DOUBLE_EQ(result(2, 0), -3);
    ASSERT_DOUBLE_EQ(result(2, 1), 6);
    ASSERT_DOUBLE_EQ(result(2, 2), -9);
    ASSERT_DOUBLE_EQ(result(2, 3), 12);
}

TEST(trans_tests, subtest_3) {
    // arrange
    S21Matrix mat1(7, 4);
    S21Matrix exp(4, 7);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) /
                         pow((i + 1) * (j + 1), (i + 1) * (j + 1));
            exp(j, i) = pow(-1, (i + 1) * (j + 1)) /
                        pow((i + 1) * (j + 1), (i + 1) * (j + 1));
        }
    }

    // act
    S21Matrix result = mat1.Transpose();

    // assert
    for (int i = 0; i < result.getRows(); i++) {
        for (int j = 0; j < result.getCols(); j++) {
            ASSERT_DOUBLE_EQ(result(i, j), exp(i, j));
        }
    }
}

TEST(trans_tests, subtest_4) {
    // arrange
    S21Matrix mat1(2, 5);
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

    // act
    S21Matrix result = mat1.Transpose();

    // assert
    ASSERT_NEAR(result(0, 0), -0.1234578, ACCURACY_EQ);
    ASSERT_NEAR(result(0, 1), 0.984631151, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 0), 846.3946115468, ACCURACY_EQ);
    ASSERT_NEAR(result(1, 1), 1234567946, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 0), 5.1124868, ACCURACY_EQ);
    ASSERT_NEAR(result(2, 1), 999999.132456, ACCURACY_EQ);
    ASSERT_NEAR(result(3, 0), 81.4621, ACCURACY_EQ);
    ASSERT_NEAR(result(3, 1), -7135.11111111, ACCURACY_EQ);
    ASSERT_NEAR(result(4, 0), -0.000001234578, ACCURACY_EQ);
    ASSERT_NEAR(result(4, 1), 911111.64331, ACCURACY_EQ);
}

TEST(trans_tests, subtest_5) {
    // arrange
    S21Matrix mat1(2, 5);
    S21Matrix exp(5, 2);

    // act
    S21Matrix result = mat1.Transpose();

    // assert
    ASSERT_TRUE(result.EqMatrix(exp));
}
