// Copyright 2021 Rachin Igor
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "./lin_hist_stret.h"

TEST(LinearStretchingOmp, Test_random_matrix_with_negative_size) {
    std::vector<int> empty;  // empty vector
    int size = -5;
    ASSERT_EQ(getRandomMatrix(size, size), empty);
}

TEST(LinearStretchingOmp, Test_negative_size_stretching) {
    std::vector<int> empty;  // empty vector
    std::vector<int> test;
    int size = -5;
    ASSERT_EQ(histogramStretching(test, size, size), empty);
}

TEST(LinearStretchingOmp, Test_values_range_of_random_matrix) {
    int size = 4;
    int rightRange = 1;
    std::vector<int> test = getRandomMatrix(size, size);
    for (int i = 0; i < size * size; i++) {
        if (test[i] < 0 || test[i]>255) {
            rightRange = 0;
        }
    }
    ASSERT_EQ(rightRange, 1);
}

TEST(LinearStretchingOmp, Test_stretching_of_manual_matrix) {
    int size = 3;
    std::vector<int> test{ 100, 245, 100,
                           45, 245, 45,
                           100, 245, 100};
    std::vector<int> result{ 55, 200, 55,
                             0, 200, 0,
                             55, 200, 55 };
    ASSERT_EQ(histogramStretching(test, size, size), result);
}

TEST(LinearStretchingOmp, Test_stretching_of_random_matrix) {
    int size = 1000;
    std::vector<int> test = getRandomMatrix(size, size);
    std::vector<int> empty;  // empty vector
    test = histogramStretching(test, size, size);
    ASSERT_NE(test, empty);
}

TEST(LinearStretchingOmp, Test_negative_size_omp_stretching) {
    std::vector<int> empty;  // empty vector
    std::vector<int> test;
    int size = -5;
    ASSERT_EQ(histogramStretchingOmp(test, size, size), empty);
}

TEST(LinearStretchingOmp, Test_omp_stretching_of_manual_matrix) {
    int size = 3;
    std::vector<int> test{ 100, 245, 100,
                           45, 245, 45,
                           100, 245, 100 };
    std::vector<int> result{ 55, 200, 55,
                             0, 200, 0,
                             55, 200, 55 };
    ASSERT_EQ(histogramStretchingOmp(test, size, size), result);
}

TEST(LinearStretchingOmp, Comparison_seq_with_omp) {
    int size = 5000;
    std::vector<int> mx = getRandomMatrix(size, size);
    std::vector<int> seq;
    std::vector<int> omp;
    seq = histogramStretching(mx, size, size);
    omp = histogramStretchingOmp(mx, size, size);
    ASSERT_EQ(seq, omp);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
