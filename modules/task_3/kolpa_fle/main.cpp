// Copyright 2021 Kochankov Ilya
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <tbb/tbb.h>
#include "./bitwise_sort_simple_tbb.h"


TEST(RadixSort_tbb, no_exceptions) {
    auto vect = getRandomVector(100);
    ASSERT_NO_THROW(RadixSort_tbb(vect));
}

TEST(RadixSort_tbb, size_one_no_exceptions) {
    auto vect = getRandomVector(1);
    ASSERT_NO_THROW(RadixSort_tbb(vect));
}

TEST(RadixSort_tbb, size_two_no_exceptions) {
    auto vect = getRandomVector(2);
    ASSERT_NO_THROW(RadixSort_tbb(vect));
}

TEST(RadixSort_tbb, works_size_two) {
    auto vect = std::vector<int>({2, 1});
    auto sorted = RadixSort_tbb(vect);
    ASSERT_EQ(sorted, std::vector<int>({1, 2}));
}

TEST(RadixSort_tbb, works_size_three) {
    auto vect = std::vector<int>({3, 2, 1});
    auto sorted = RadixSort_tbb(vect);
    ASSERT_EQ(sorted, std::vector<int>({1, 2, 3}));
}

TEST(RadixSort_tbb, works_size_five) {
    auto vect = std::vector<int>({3, 2, 1, 6, 7});
    auto sorted = RadixSort_tbb(vect);
    ASSERT_EQ(sorted, std::vector<int>({1, 2, 3, 6, 7}));
}

TEST(RadixSort_tbb, works_size_zero) {
    auto vect = std::vector<int>();
    auto sorted = RadixSort_tbb(vect);
    ASSERT_EQ(sorted, std::vector<int>());
}

TEST(RadixSort_tbb, works_random_size_100) {
    auto vect = getRandomVector(100);
    auto sorted = RadixSort_tbb(vect);
    std::sort(vect.begin(), vect.end());
    ASSERT_EQ(vect, sorted);
}

TEST(RadixSort_tbb, works_random_size_1000) {
    auto vect = getRandomVector(1000);
    auto sorted = RadixSort_tbb(vect);
    std::sort(vect.begin(), vect.end());
    ASSERT_EQ(vect, sorted);
}

TEST(RadixSort_tbb, works_random_size_10000) {
    auto vect = getRandomVector(10000);
    auto sorted = RadixSort_tbb(vect);
    std::sort(vect.begin(), vect.end());
    ASSERT_EQ(vect, sorted);
}

TEST(RadixSort_tbb, get_time) {
    auto vect = getRandomVector(1000000);

    tbb::tick_count t0 = tbb::tick_count::now();
    auto p_sorted = RadixSort_tbb(vect);
    tbb::tick_count t1 = tbb::tick_count::now();
    std::cout << "Parallel sort time: " << (t1 - t0).seconds() << std::endl;

    tbb::tick_count t2 = tbb::tick_count::now();
    auto l_sorted = RadixSort(vect, vect.size());
    tbb::tick_count t3 = tbb::tick_count::now();
    std::cout << "Linear sort time: " << (t3 - t2).seconds() << std::endl;

    ASSERT_EQ(p_sorted, l_sorted);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
