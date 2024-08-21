#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
class EzenRLGL
{
public:
    void updateRandomNumbers(std::set<int>& randomNumbers, int min, int max, int growltrigger) {
        randomNumbers.clear();
        while (randomNumbers.size() < growltrigger) {
            int num = min + (rand() % (max - min + 1));
            randomNumbers.insert(num);
        }
    }
};

