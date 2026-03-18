#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "main_test.h"

using namespace std;

TEST(complements_tests, subtest_1) {
    // arrange
    S21Matrix mat1(1, 1);
    mat1(0, 0) = 1;

    S21Matrix exp(1, 1);
    exp(0, 0) = 1;

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    ASSERT_TRUE(result.EqMatrix(exp));
}

TEST(complements_tests, subtest_2) {
    // arrange
    S21Matrix mat1(1, 1);
    mat1(0, 0) = 7;

    S21Matrix exp(1, 1);
    exp(0, 0) = 1;

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    ASSERT_TRUE(result.EqMatrix(exp));
}

TEST(complements_tests, subtest_3) {
    /**
     *  -3  -6   -9          0  0  0
     *   6   12   18    M =  0  0  0
     *  -9  -18  -27         0  0  0
     */

    // arrange
    S21Matrix mat1(3, 3);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, i + 1) * (i + 1) * (j + 1) * 3;
        }
    }

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            ASSERT_DOUBLE_EQ(result(i, j), 0);
        }
    }
}

TEST(complements_tests, subtest_4) {
    // arrange
    S21Matrix mat1(4, 4);
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            mat1(i, j) = pow(-1, (i + 1) * (j + 1)) * (i + 1) * (j + 1);
        }
    }

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            ASSERT_DOUBLE_EQ(result(i, j), 0);
        }
    }
}

TEST(complements_tests, subtest_5) {
    // arrange
    S21Matrix mat1(2, 2);
    mat1(0, 0) = 8;
    mat1(0, 1) = 44;
    mat1(1, 0) = 5;
    mat1(1, 1) = 6;

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    ASSERT_DOUBLE_EQ(result(0, 0), 6);
    ASSERT_DOUBLE_EQ(result(0, 1), -5);
    ASSERT_DOUBLE_EQ(result(1, 0), -44);
    ASSERT_DOUBLE_EQ(result(1, 1), 8);
}

TEST(complements_tests, subtest_6) {
    // arrange
    S21Matrix mat1(5, 5);
    S21Matrix exp(5, 5);
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

    exp(0, 0) = -5.203296562853859e+21;
    exp(0, 1) = 1.5083720799772544e+21;
    exp(0, 2) = 4.64169698221028540416e+20;
    exp(0, 3) = -4.51850129895310462287872e+23;
    exp(0, 4) = -2.047911470933746246483968e+24;
    exp(1, 0) = 68669878018766720;
    exp(1, 1) = -19142343757428116;
    exp(1, 2) = -5890902965069325;
    exp(1, 3) = 199363329626026912;
    exp(1, 4) = -1.3049034387665002496e+19;
    exp(2, 0) = -3.75363792283625455616e+20;
    exp(2, 1) = 1785447279231121.25;
    exp(2, 2) = 549431368131906.25;
    exp(2, 3) = -587458375179320832;
    exp(2, 4) = -2424101824642003968;
    exp(3, 0) = 1.8988636934444957696e+19;
    exp(3, 1) = -22634369763781348;
    exp(3, 2) = 1.4471015053374261248e+19;
    exp(3, 3) = -644237642396910464;
    exp(3, 4) = 1.4781996898043975680e+19;
    exp(4, 0) = 1.04687329756187721728e+20;
    exp(4, 1) = 1.7261834435445645312e+19;
    exp(4, 2) = -9165789302952707072;
    exp(4, 3) = -1.78617640269851197440e+20;
    exp(4, 4) = -2.3381345653980288516096e+22;

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    for (int i = 0; i < mat1.getRows(); i++) {
        for (int j = 0; j < mat1.getCols(); j++) {
            ASSERT_DOUBLE_EQ(result(i, j), exp(i, j));
        }
    }
}

TEST(complements_tests, subtest_7) {
    // arrange
    S21Matrix mat1(5, 5);
    S21Matrix exp(5, 5);

    // act
    S21Matrix result = mat1.CalcComplements();

    // assert
    ASSERT_TRUE(result.EqMatrix(exp));
}

TEST(complements_tests, subtest_8) {
    // arrange
    S21Matrix mat1(5, 2);

    // assert
    ASSERT_THROW(mat1.CalcComplements(), std::logic_error);
}
