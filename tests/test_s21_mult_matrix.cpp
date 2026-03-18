#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(mult_tests, subtest_1) {
    /**
     *  -3  -6   -9     -1  -2  -3    18  36   54
     *   6   12   18  x  2   4   6 = -36 -72  -108
     *  -9  -18  -27    -3  -6  -9    54  108  162
     */

    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1) * 3;
            mat2(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    mat1.MulMatrix(mat2);

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), 18);
    ASSERT_DOUBLE_EQ(mat1(0, 1), 36);
    ASSERT_DOUBLE_EQ(mat1(0, 2), 54);
    ASSERT_DOUBLE_EQ(mat1(1, 0), -36);
    ASSERT_DOUBLE_EQ(mat1(1, 1), -72);
    ASSERT_DOUBLE_EQ(mat1(1, 2), -108);
    ASSERT_DOUBLE_EQ(mat1(2, 0), 54);
    ASSERT_DOUBLE_EQ(mat1(2, 1), 108);
    ASSERT_DOUBLE_EQ(mat1(2, 2), 162);
}

TEST(mult_tests, subtest_2) {
    /**
     *  -1   2      -1  -2  -3    5  10  15
     *   2   4  x    2   4   6  = 6  12  18
     *  -3   6                    15 30  45
     *   4   8                    12 24  36
     */

    // arrange
    S21Matrix mat1(4, 2);
    S21Matrix mat2(2, 3);

    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < mat2.getRows(); i++) {
        for (int j = 0; j < mat2.getCols(); j++) {
            mat2(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    mat1.MulMatrix(mat2);

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), 5);
    ASSERT_DOUBLE_EQ(mat1(0, 1), 10);
    ASSERT_DOUBLE_EQ(mat1(0, 2), 15);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 6);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 12);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 18);
    ASSERT_DOUBLE_EQ(mat1(2, 0), 15);
    ASSERT_DOUBLE_EQ(mat1(2, 1), 30);
    ASSERT_DOUBLE_EQ(mat1(2, 2), 45);
    ASSERT_DOUBLE_EQ(mat1(3, 0), 12);
    ASSERT_DOUBLE_EQ(mat1(3, 1), 24);
    ASSERT_DOUBLE_EQ(mat1(3, 2), 36);
}

TEST(mult_tests, subtest_3) {
    // arrange
    S21Matrix mat1(7, 4);
    S21Matrix mat2(4, 3);
    S21Matrix res(7, 3);

    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) /
                         pow((i + 1) * (j + 1), (i + 1) * (j + 1));
        }
    }
    for (int i = 0; i < mat2.getRows(); i++) {
        for (int j = 0; j < mat2.getCols(); j++) {
            mat2(i, j) = pow(-1, (i + 1) * (j + 1)) /
                         pow((i + 1) * (j + 1), (i + 1) * (j + 1) * 2);
        }
    }
    for (int i = 0; i < res.getRows(); i++) {
        for (int j = 0; j < res.getCols(); j++) {
            res(i, j) = 0;
            for (int k = 0; k < mat1.getCols(); k++) {
                res(i, j) += mat1(i, k) * mat2(k, j);
            }
        }
    }

    // act
    mat1.MulMatrix(mat2);

    // assert
    for (int i = 0; i < res.getRows(); i++) {
        for (int j = 0; j < res.getCols(); j++) {
            ASSERT_DOUBLE_EQ(mat1(i, j), res(i, j));
        }
    }
}

TEST(mult_tests, subtest_4) {
    // arrange
    S21Matrix mat1(2, 5);
    S21Matrix mat2(5, 2);

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

    mat2(0, 0) = 94654.1231468;
    mat2(0, 1) = 881.7777;
    mat2(1, 0) = -124868;
    mat2(1, 1) = -3481.4621;
    mat2(2, 0) = 500;
    mat2(2, 1) = 1.000000001;
    mat2(3, 0) = -7946;
    mat2(3, 1) = -2456546;
    mat2(4, 0) = -7135.11111111;
    mat2(4, 1) = 1011.64331;

    // act
    mat1.MulMatrix(mat2);

    // assert
    ASSERT_NEAR(mat1(0, 0), -106344029.7388216041997, ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 1), -203062190.4194414850981, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 0), -154163974375579.15624, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 1), -4279651064348.3173828125, ACCURACY_EQ);
}

TEST(mult_tests, subtest_5) {
    // arrange
    S21Matrix mat1(5, 5);
    S21Matrix mat2(5, 5);
    S21Matrix exp(5, 5);

    // act
    mat1.MulMatrix(mat2);

    // assert
    ASSERT_TRUE(exp.EqMatrix(mat1));
}

TEST(mult_tests, subtest_6) {
    /**
     *  -3  -6   -9     -1  -2  -3    18  36   54
     *   6   12   18  x  2   4   6 = -36 -72  -108
     *  -9  -18  -27    -3  -6  -9    54  108  162
     */

    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1) * 3;
            mat2(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    S21Matrix mat3 = mat1 * mat2;

    // assert
    ASSERT_DOUBLE_EQ(mat3(0, 0), 18);
    ASSERT_DOUBLE_EQ(mat3(0, 1), 36);
    ASSERT_DOUBLE_EQ(mat3(0, 2), 54);
    ASSERT_DOUBLE_EQ(mat3(1, 0), -36);
    ASSERT_DOUBLE_EQ(mat3(1, 1), -72);
    ASSERT_DOUBLE_EQ(mat3(1, 2), -108);
    ASSERT_DOUBLE_EQ(mat3(2, 0), 54);
    ASSERT_DOUBLE_EQ(mat3(2, 1), 108);
    ASSERT_DOUBLE_EQ(mat3(2, 2), 162);

    // act
    mat1 *= mat2;

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), 18);
    ASSERT_DOUBLE_EQ(mat1(0, 1), 36);
    ASSERT_DOUBLE_EQ(mat1(0, 2), 54);
    ASSERT_DOUBLE_EQ(mat1(1, 0), -36);
    ASSERT_DOUBLE_EQ(mat1(1, 1), -72);
    ASSERT_DOUBLE_EQ(mat1(1, 2), -108);
    ASSERT_DOUBLE_EQ(mat1(2, 0), 54);
    ASSERT_DOUBLE_EQ(mat1(2, 1), 108);
    ASSERT_DOUBLE_EQ(mat1(2, 2), 162);
}

TEST(mult_tests, subtest_7) {
    // arrange
    S21Matrix mat1(3, 2);
    S21Matrix mat2(3, 3);

    // assert
    ASSERT_THROW(mat1 *= mat2, std::range_error);
}
