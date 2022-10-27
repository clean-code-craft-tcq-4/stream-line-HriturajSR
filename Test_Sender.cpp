#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <iostream>
#include "TEMPERATURE.hpp"
#include "CHARGE.hpp"
#include "SendSensorData.hpp"

using namespace std;
int SendSendersize(int total_reading);
{ 
    vector<int> tempData = generateTemperatureValues(MAX_TEMPERATURE_VALUE, MIN_TEMPERATURE_VALUE, total_reading);
    vector<int> chargeData = generateChargeValues(MAX_CHARGE_VALUE, MIN_CHARGE_VALUE, total_reading);
    int tSize = tempData.size();
    int cSize = chargeData.size();
    if (transferData(tempData, chargeData))
    {
        REQUIRE(tSize == TOTAL_READINGS);
        REQUIRE(cSize == TOTAL_READINGS);
    }
    else
    {
        REQUIRE(tSize == 0);
        REQUIRE(cSize == 0);
    }
}
TEST_CASE("To check if Negetive scenario is working properly")

{
   SendSendersize(0);
}

TEST_CASE("To check if temperature and charge values are generated correctlyY")

{
    SendSendersize(TOTAL_READINGS);

}
