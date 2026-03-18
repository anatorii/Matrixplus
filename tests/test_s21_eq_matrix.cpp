#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(eq_tests, subtest_1) {
    /**
     *  -1  -2  -3
     *   2   4   6
     *  -3  -6  -9
     */

    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
            mat2(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // assert
    ASSERT_NEAR(mat1(0, 0), mat2(0, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 1), mat2(0, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 2), mat2(0, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 0), mat2(1, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 1), mat2(1, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 2), mat2(1, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 0), mat2(2, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 1), mat2(2, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 2), mat2(2, 2), ACCURACY_EQ);
    ASSERT_TRUE(mat1.EqMatrix(mat2));
}

TEST(eq_tests, subtest_2) {
    /**
     *  -1   2  -3
     *   2   4   6
     *  -3   6  -9
     *   4   8   12
     */

    // arrange
    S21Matrix mat1(4, 3);
    S21Matrix mat2(4, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
            mat2(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
    }

    // assert
    ASSERT_NEAR(mat1(0, 0), mat2(0, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 1), mat2(0, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 2), mat2(0, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 0), mat2(1, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 1), mat2(1, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 2), mat2(1, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 0), mat2(2, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 1), mat2(2, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 2), mat2(2, 2), ACCURACY_EQ);
    ASSERT_TRUE(mat1.EqMatrix(mat2));
}

TEST(eq_tests, subtest_3) {
    /**
     *  -1   2  -3
     *   2   4   6
     *  -3   6  -9
     *   4   8   12
     *
     *  -1  -2  -3
     *   2   4   6
     *  -3  -6  -9
     *   4   8   12
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

    // assert
    ASSERT_FALSE(mat1.EqMatrix(mat2));
}

TEST(eq_tests, subtest_4) {
    /**
     *  -1   2  -3
     *   2   4   6
     *  -3   6  -9
     *   4   8   12
     *
     *  -1  -2  -3
     *   2   4   6
     *  -3  -6  -9
     */

    // arrange
    S21Matrix mat1(4, 3);
    S21Matrix mat2(3, 3);
    for (int j = 0; j < mat1.getCols(); j++) {
        for (int i = 0; i < mat1.getRows(); i++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
        for (int i = 0; i < mat2.getRows(); i++) {
            mat2(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1);
        }
    }

    // assert
    ASSERT_FALSE(mat1.EqMatrix(mat2));
}

TEST(eq_tests, subtest_5) {
    /**
     *  0.001     0.0001      0.00001
     *  0.000001  0.0000001   0.000001
     *  0.00001   0.0001      0.001
     */

    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(3, 3);

    mat1(0, 0) = 0.001;
    mat1(0, 1) = 0.0001;
    mat1(0, 2) = 0.00001;
    mat1(1, 0) = 0.000001;
    mat1(1, 1) = 0.0000001;
    mat1(1, 2) = 0.000001;
    mat1(2, 0) = 0.00001;
    mat1(2, 1) = 0.0001;
    mat1(2, 2) = 0.001;

    mat2(0, 0) = 0.001;
    mat2(0, 1) = 0.0001;
    mat2(0, 2) = 0.00001;
    mat2(1, 0) = 0.000001;
    mat2(1, 1) = 0.0000001;
    mat2(1, 2) = 0.000001;
    mat2(2, 0) = 0.00001;
    mat2(2, 1) = 0.0001;
    mat2(2, 2) = 0.001;

    // assert
    ASSERT_TRUE(mat1.EqMatrix(mat2));
}

TEST(eq_tests, subtest_6) {
    /**
     *  0.001         0.0001          0.00001
     *  0.000001      0.0000001       0.00000001
     *  0.000000001   0.0000000001    0.00000000001
     *
     *  0.001         0.0001          0.00001
     *  0.000001      0.0000001       0.00000005
     *  0.00000002    0.0             0.0000000999
     */

    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(3, 3);

    mat1(0, 0) = 0.001;
    mat1(0, 1) = 0.0001;
    mat1(0, 2) = 0.00001;
    mat1(1, 0) = 0.000001;
    mat1(1, 1) = 0.0000001;
    mat1(1, 2) = 0.00000001;
    mat1(2, 0) = 0.000000001;
    mat1(2, 1) = 0.0000000001;
    mat1(2, 2) = 0.00000000001;

    mat2(0, 0) = 0.001;
    mat2(0, 1) = 0.0001;
    mat2(0, 2) = 0.00001;
    mat2(1, 0) = 0.000001;
    mat2(1, 1) = 0.0000001;
    mat2(1, 2) = 0.00000005;
    mat2(2, 0) = 0.00000002;
    mat2(2, 1) = 0.0;
    mat2(2, 2) = 0.0000000999;

    // assert
    ASSERT_TRUE(mat1.EqMatrix(mat2));
    ASSERT_NEAR(mat1(0, 0), mat2(0, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 1), mat2(0, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 2), mat2(0, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 0), mat2(1, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 1), mat2(1, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 2), mat2(1, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 0), mat2(2, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 1), mat2(2, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 2), mat2(2, 2), ACCURACY_EQ);
}

TEST(eq_tests, subtest_7) {
    /**
     *   0.001     -0.0001       0.00001
     *  -0.000001   0.0000001   -0.000001
     *   0.00001   -0.0001       0.001
     *
     *   0.001        -0.0001      0.00001
     *  -0.00000101    0.0000001   0.00000005
     *  -0.00000002    0.0         0.0000000999
     */

    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(3, 3);

    mat1(0, 0) = 0.001;
    mat1(0, 1) = -0.0001;
    mat1(0, 2) = 0.00001;
    mat1(1, 0) = -0.000001;
    mat1(1, 1) = 0.0000001;
    mat1(1, 2) = -0.00000001;
    mat1(2, 0) = 0.000000001;
    mat1(2, 1) = -0.0000000001;
    mat1(2, 2) = 0.00000000001;

    mat2(0, 0) = 0.001;
    mat2(0, 1) = -0.0001;
    mat2(0, 2) = 0.00001;
    mat2(1, 0) = -0.00000101;
    mat2(1, 1) = 0.0000001;
    mat2(1, 2) = 0.00000005;
    mat2(2, 0) = -0.00000002;
    mat2(2, 1) = 0;
    mat2(2, 2) = 0.0000000999;

    // assert
    ASSERT_TRUE(mat1.EqMatrix(mat2));
    ASSERT_NEAR(mat1(0, 0), mat2(0, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 1), mat2(0, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(0, 2), mat2(0, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 0), mat2(1, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 1), mat2(1, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(1, 2), mat2(1, 2), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 0), mat2(2, 0), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 1), mat2(2, 1), ACCURACY_EQ);
    ASSERT_NEAR(mat1(2, 2), mat2(2, 2), ACCURACY_EQ);
}

TEST(eq_tests, subtest_8) {
    // arrange
    S21Matrix mat1(3, 3);
    S21Matrix mat2(5, 4);

    // assert
    ASSERT_FALSE(mat1.EqMatrix(mat2));
}

TEST(eq_tests, subtest_9) {
    /**
     *  -1   2  -3
     *   2   4   6
     *  -3   6  -9
     *   4   8   12
     *
     *  -1  -2  -3
     *   2   4   6
     *  -3  -6  -9
     *   4   8   12
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

    // assert
    ASSERT_FALSE(mat1 == mat2);
    ASSERT_FALSE(mat2 == mat1);
}
