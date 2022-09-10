#include "TEMPERATURE.hpp"

vector<int> generateTemperatureValues(int maxTempValue, int minTempValue, int readingCount)
{
    vector<int> tempValueList;
    for(int count = 0; count < readingCount; count++)
    {
        int rValue = rand() % maxTempValue + minTempValue;
        tempValueList.push_back(rValue);
    }
    return tempValueList;
}
