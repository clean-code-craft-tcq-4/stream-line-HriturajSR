#include "SendSensorData.hpp"

bool transferData(std::vector<int>tempData,std::vector<int>chargeData)
{
    bool sendStatus = false;
    if((tempData.size() == TOTAL_READINGS) && (chargeData.size() == TOTAL_READINGS))
    {
        for(int count = 0; count < TOTAL_READINGS; count ++)
        {
            std::cout<<tempData[count]<<","<< chargeData[count]<<std::endl;
        }
        sendStatus = true;
    }
    return sendStatus;

}
