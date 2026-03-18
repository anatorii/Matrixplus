#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(mult_num_tests, subtest_1) {
    /**
     *  -1  -2  -3        -3  -6   -9
     *   2   4   6  x 3 =  6   12   18
     *  -3  -6  -9        -9  -18  -27
     */

    // arrange
    double num = 3;
    S21Matrix mat1(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    mat1.MulNumber(num);

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), -3);
    ASSERT_DOUBLE_EQ(mat1(0, 1), -6);
    ASSERT_DOUBLE_EQ(mat1(0, 2), -9);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 6);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 12);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 18);
    ASSERT_DOUBLE_EQ(mat1(2, 0), -9);
    ASSERT_DOUBLE_EQ(mat1(2, 1), -18);
    ASSERT_DOUBLE_EQ(mat1(2, 2), -27);
}

TEST(mult_num_tests, subtest_2) {
    /**
     *  -1   2  -3            -1.0001   2.0002  -3.0003
     *   2   4   6  x 1.0001 = 2.0002   4.0004   6.0006
     *  -3   6  -9            -3.0003   6.0006  -9.0009
     *   4   8   12            4.0004   8.0008   12.0012
     */

    // arrange
    double num = 1.0001;
    S21Matrix mat1(4, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
    }

    // act
    mat1.MulNumber(num);

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), -1.0001);
    ASSERT_DOUBLE_EQ(mat1(0, 1), 2.0002);
    ASSERT_DOUBLE_EQ(mat1(0, 2), -3.0003);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 2.0002);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 4.0004);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 6.0006);
    ASSERT_DOUBLE_EQ(mat1(2, 0), -3.0003);
    ASSERT_DOUBLE_EQ(mat1(2, 1), 6.0006);
    ASSERT_DOUBLE_EQ(mat1(2, 2), -9.0009);
    ASSERT_DOUBLE_EQ(mat1(3, 0), 4.0004);
    ASSERT_DOUBLE_EQ(mat1(3, 1), 8.0008);
    ASSERT_DOUBLE_EQ(mat1(3, 2), 12.0012);
}

TEST(mult_num_tests, subtest_3) {
    // arrange
    double num = 132156.1216540001;
    S21Matrix mat1(7, 4);
    S21Matrix res(7, 4);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) /
                         pow((i + 1) * (j + 1), (i + 1) * (j + 1));
            res(i, j) = pow(-1, (i + 1) * (j + 1)) /
                        pow((i + 1) * (j + 1), (i + 1) * (j + 1)) * num;
        }
    }

    // act
    mat1.MulNumber(num);

    // assert
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            ASSERT_DOUBLE_EQ(mat1(i, j), res(i, j));
        }
    }
}

TEST(mult_num_tests, subtest_4) {
    // arrange
    double num = 132156.1216540001;
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
    mat1.MulNumber(num);

    // assert
    ASSERT_NEAR(mat1(0, 0), -16315.70403593, ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 1), 111856229.250869, ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 2), 675646.427495269, ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 3), 10765715.1977903, ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 4), -0.163157040359352, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 0), 130125.034175874, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 1), 163155711661705.02614079, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 2), 132156007002.749695802, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 3), -942948612.01466098, ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 4), 120408981173.65229313029, ACCURACY_EQ);
}

TEST(mult_num_tests, subtest_5) {
    // arange
    double num = 8;
    S21Matrix mat1;
    S21Matrix exp;

    // act
    mat1.MulNumber(num);

    // assert
    ASSERT_TRUE(mat1.EqMatrix(exp));
}

TEST(mult_num_tests, subtest_6) {
    /**
     *  -1  -2  -3        -3  -6   -9
     *   2   4   6  x 3 =  6   12   18
     *  -3  -6  -9        -9  -18  -27
     */

    // arrange
    double num = 3;
    S21Matrix mat1(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    S21Matrix mat3 = mat1 * num;

    // assert
    ASSERT_DOUBLE_EQ(mat3(0, 0), -3);
    ASSERT_DOUBLE_EQ(mat3(0, 1), -6);
    ASSERT_DOUBLE_EQ(mat3(0, 2), -9);
    ASSERT_DOUBLE_EQ(mat3(1, 0), 6);
    ASSERT_DOUBLE_EQ(mat3(1, 1), 12);
    ASSERT_DOUBLE_EQ(mat3(1, 2), 18);
    ASSERT_DOUBLE_EQ(mat3(2, 0), -9);
    ASSERT_DOUBLE_EQ(mat3(2, 1), -18);
    ASSERT_DOUBLE_EQ(mat3(2, 2), -27);

    // act
    S21Matrix mat4 = num * mat1;

    // assert
    ASSERT_DOUBLE_EQ(mat3(0, 0), -3);
    ASSERT_DOUBLE_EQ(mat3(0, 1), -6);
    ASSERT_DOUBLE_EQ(mat3(0, 2), -9);
    ASSERT_DOUBLE_EQ(mat3(1, 0), 6);
    ASSERT_DOUBLE_EQ(mat3(1, 1), 12);
    ASSERT_DOUBLE_EQ(mat3(1, 2), 18);
    ASSERT_DOUBLE_EQ(mat3(2, 0), -9);
    ASSERT_DOUBLE_EQ(mat3(2, 1), -18);
    ASSERT_DOUBLE_EQ(mat3(2, 2), -27);

    // act
    mat1 *= num;

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), -3);
    ASSERT_DOUBLE_EQ(mat1(0, 1), -6);
    ASSERT_DOUBLE_EQ(mat1(0, 2), -9);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 6);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 12);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 18);
    ASSERT_DOUBLE_EQ(mat1(2, 0), -9);
    ASSERT_DOUBLE_EQ(mat1(2, 1), -18);
    ASSERT_DOUBLE_EQ(mat1(2, 2), -27);
}
