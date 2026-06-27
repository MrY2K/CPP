#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        size_t getJacobsthal(size_t n) const;
        void printVector(const std::string& prefix) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseInput(int argc, char** argv);
        void sortVector();
        void sortDeque();
        void execute();
};
