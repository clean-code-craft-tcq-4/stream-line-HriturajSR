#include "SendSensorData.hpp"

bool transferData()
{
    bool sendStatus = false;
    vector<int> tempData = generateTemperatureValues(MAX_TEMPERATURE_VALUE , MIN_TEMPERATURE_VALUE , TOTAL_READINGS);
    vector<int> chargeData = generateChargeValues(MAX_CHARGE_VALUE , MIN_CHARGE_VALUE , TOTAL_READINGS);
    if((tempData.size() == TOTAL_READINGS) && (chargeData.size() == TOTAL_READINGS))
    {
        for(int count = 0; count < TOTAL_READINGS; count ++)
        {
            std::cout << tempData[count]<< "," << chargeData[count] << std::endl;
        }
        sendStatus = true;
    }
    return sendStatus;

}
