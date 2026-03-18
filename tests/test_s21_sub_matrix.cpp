#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(sub_tests, subtest_1) {
    /**
     *  -3  -6   -9     -1  -2  -3    -2  -4  -6
     *   6   12   18  -  2   4   6 =   4   8   12
     *  -9  -18  -27    -3  -6  -9    -6  -12 -18
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
    mat1.SubMatrix(mat2);

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), -2);
    ASSERT_DOUBLE_EQ(mat1(0, 1), -4);
    ASSERT_DOUBLE_EQ(mat1(0, 2), -6);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 4);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 8);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 12);
    ASSERT_DOUBLE_EQ(mat1(2, 0), -6);
    ASSERT_DOUBLE_EQ(mat1(2, 1), -12);
    ASSERT_DOUBLE_EQ(mat1(2, 2), -18);
}

TEST(sub_tests, subtest_2) {
    /**
     *  -1   2  -3      -1  -2  -3    0  4  0
     *   2   4   6  -    2   4   6  = 0  0  0
     *  -3   6  -9      -3  -6  -9    0  12 0
     *   4   8   12      4   8   12   0  0  0
     */

    // arrange
    S21Matrix mat1(4, 3);
    S21Matrix mat2(4, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
            mat2(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // act
    mat1.SubMatrix(mat2);

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), 0);
    ASSERT_DOUBLE_EQ(mat1(0, 1), 4);
    ASSERT_DOUBLE_EQ(mat1(0, 2), 0);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 0);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 0);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 0);
    ASSERT_DOUBLE_EQ(mat1(2, 0), 0);
    ASSERT_DOUBLE_EQ(mat1(2, 1), 12);
    ASSERT_DOUBLE_EQ(mat1(2, 2), 0);
    ASSERT_DOUBLE_EQ(mat1(3, 0), 0);
    ASSERT_DOUBLE_EQ(mat1(3, 1), 0);
    ASSERT_DOUBLE_EQ(mat1(3, 2), 0);
}

TEST(sub_tests, subtest_3) {
    // arrange
    S21Matrix mat1(2, 5);
    S21Matrix mat2(2, 5);

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
    mat2(0, 2) = -124868;
    mat2(0, 3) = -3481.4621;
    mat2(0, 4) = 500;
    mat2(1, 0) = 1.000000001;
    mat2(1, 1) = -7946;
    mat2(1, 2) = -2456546;
    mat2(1, 3) = -7135.11111111;
    mat2(1, 4) = 1011.64331;

    // act
    mat2.SubMatrix(mat1);

    // assert
    ASSERT_NEAR(mat2(0, 0), 94654.2466046, ACCURACY_EQ);
    ASSERT_NEAR(mat2(0, 1), 35.3830884532, ACCURACY_EQ);
    ASSERT_NEAR(mat2(0, 2), -124873.1124868, ACCURACY_EQ);
    ASSERT_NEAR(mat2(0, 3), -3562.9242, ACCURACY_EQ);
    ASSERT_NEAR(mat2(0, 4), 500.000001234578, ACCURACY_EQ);
    ASSERT_NEAR(mat2(1, 0), 0.0153688500000001, ACCURACY_EQ);
    ASSERT_NEAR(mat2(1, 1), -1234575892, ACCURACY_EQ);
    ASSERT_NEAR(mat2(1, 2), -3456545.132456, ACCURACY_EQ);
    ASSERT_NEAR(mat2(1, 3), 0, ACCURACY_EQ);
    ASSERT_NEAR(mat2(1, 4), -910100, ACCURACY_EQ);
}

TEST(sub_tests, subtest_4) {
    // arrange
    S21Matrix mat1(5, 5);
    S21Matrix mat2(5, 5);
    S21Matrix exp(5, 5);

    // act
    mat1.SubMatrix(mat2);

    // assert
    ASSERT_TRUE(exp.EqMatrix(mat1));
}

TEST(sub_tests, subtest_5) {
    // arrange
    S21Matrix mat1;
    S21Matrix mat2;

    // act
    mat1.SubMatrix(mat2);

    // assert
    ASSERT_TRUE(mat1.EqMatrix(mat2));
}

TEST(sub_tests, subtest_6) {
    /**
     *  -3  -6   -9     -1  -2  -3    -2  -4  -6
     *   6   12   18  -  2   4   6 =   4   8   12
     *  -9  -18  -27    -3  -6  -9    -6  -12 -18
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
    S21Matrix mat3 = mat1 - mat2;

    // assert
    ASSERT_DOUBLE_EQ(mat3(0, 0), -2);
    ASSERT_DOUBLE_EQ(mat3(0, 1), -4);
    ASSERT_DOUBLE_EQ(mat3(0, 2), -6);
    ASSERT_DOUBLE_EQ(mat3(1, 0), 4);
    ASSERT_DOUBLE_EQ(mat3(1, 1), 8);
    ASSERT_DOUBLE_EQ(mat3(1, 2), 12);
    ASSERT_DOUBLE_EQ(mat3(2, 0), -6);
    ASSERT_DOUBLE_EQ(mat3(2, 1), -12);
    ASSERT_DOUBLE_EQ(mat3(2, 2), -18);

    // act
    mat1 -= mat2;

    // assert
    ASSERT_DOUBLE_EQ(mat1(0, 0), -2);
    ASSERT_DOUBLE_EQ(mat1(0, 1), -4);
    ASSERT_DOUBLE_EQ(mat1(0, 2), -6);
    ASSERT_DOUBLE_EQ(mat1(1, 0), 4);
    ASSERT_DOUBLE_EQ(mat1(1, 1), 8);
    ASSERT_DOUBLE_EQ(mat1(1, 2), 12);
    ASSERT_DOUBLE_EQ(mat1(2, 0), -6);
    ASSERT_DOUBLE_EQ(mat1(2, 1), -12);
    ASSERT_DOUBLE_EQ(mat1(2, 2), -18);
}

TEST(sub_tests, subtest_7) {
    // arrange
    S21Matrix mat1(3, 2);
    S21Matrix mat2(3, 3);

    // assert
    ASSERT_THROW(mat1 -= mat2, std::range_error);
}
