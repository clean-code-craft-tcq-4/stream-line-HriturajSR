#define CATCH_CONFIG_MAIN
#include <vector>
#include <iostream>
#include "TEMPERATURE.hpp"
#include "CHARGE.hpp"
#include "SendSensorData.hpp"

using namespace std;

TEST_CASE("To check if temperature values are generated correctly") 
{
    vector<int> tempData = generateTemperatureValues(MAX_TEMPERATURE_VALUE , MIN_TEMPERATURE_VALUE , TOTAL_READINGS);
    int tSize = tempData.size();
    REQUIRE(tSize == TOTAL_READINGS);
}

TEST_CASE("To check if charge values are generated correctly") 
{
    vector<int> chargeData = generateChargeValues(MAX_CHARGE_VALUE , MIN_CHARGE_VALUE , TOTAL_READINGS);
    int cSize = chargeData.size();
    REQUIRE(cSize == TOTAL_READINGS);
}
