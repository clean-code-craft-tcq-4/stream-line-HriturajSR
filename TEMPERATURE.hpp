#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <vector>
#include <iostream>
#include <cstdlib>

#define MAX_TEMPERATURE_VALUE 100
#define MIN_TEMPERATURE_VALUE -50

using namespace std;

vector<int> generateTemperatureValues(int maxTempValue, int minTempValue, int readingCount);
#endif
