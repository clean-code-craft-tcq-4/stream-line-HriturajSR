#include "CHARGE.hpp"

vector<int> generateChargeValues(int maxValue, int minValue, int readingCount)
{
    vector<int> valueList;
    for(int count = 0; count < readingCount; count++)
    {
        int rValue = rand() % maxValue + minValue;
        valueList.push_back(rValue);
    }
    return valueList;
}
