// Copyright 2021 Kochankov Ilya
#ifndef MODULES_TASK_3_KOCHANKOV_I_SHELL_SORT_SIMPLE_TBB_SHELL_SORT_SIMPLE_TBB_H_
#define MODULES_TASK_3_KOCHANKOV_I_SHELL_SORT_SIMPLE_TBB_SHELL_SORT_SIMPLE_TBB_H_

#include <vector>


std::vector<int> getRandomVector(int size);
std::vector<int> RadixSort(std::vector<int> vect, int size);
std::vector<int> RadixSort_tbb(std::vector<int> v);
std::vector<int> Merge(const std::vector<int>& vect_left,
                          const std::vector<int>& vect_right);


#endif  // MODULES_TASK_3_KOCHANKOV_I_SHELL_SORT_SIMPLE_TBB_SHELL_SORT_SIMPLE_TBB_H_
