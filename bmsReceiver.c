#include <stdio.h>
#include "bmsReceiver.h"

struct BMSParameters bmsParameters;
struct BMSProcessedParameters processedParameters;

int ReadParameters(void)
{
    for (int i = 0; i< 50;i++)
    { 
        scanf("%f,%f\n", &bmsParameters.temperature[i], &bmsParameters.chargeRate[i]);

        processedParameters.maxTemp = calculateMaxValue (bmsParameters.temperature[i], processedParameters.maxTemp);
        processedParameters.minTemp = calculateMinValue (bmsParameters.temperature[i], processedParameters.minTemp);
        
        processedParameters.maxChargeRate = calculateMaxValue (bmsParameters.chargeRate[i], processedParameters.maxChargeRate);
        processedParameters.minChargeRate = calculateMinValue (bmsParameters.chargeRate[i], processedParameters.minChargeRate);
    }
}

int 
displayReadData(void)
{
    for (int i = 0; i< 50; i++)
    { 
        printf("Temp-%f,CR-%f\n", bmsParameters.temperature[i], bmsParameters.chargeRate[i]);
    }

    printf ("MaxTemp = %f\t MinTemp= %f\t MaxCR = %f\t MinCR =%f",
        processedParameters.maxTemp, processedParameters.minTemp,
        processedParameters.maxChargeRate, processedParameters.minChargeRate);
}

float
calculateMaxValue(float currentValue, float maxValue)
{
    if (currentValue != 0 && currentValue <= maxValue)
    {
        return maxValue;
    }

    return currentValue;
}

float
calculateMinValue(float currentValue, float minValue)
{
    if (currentValue != 0 && currentValue >= minValue)
    {
        return minValue;
    }

    return currentValue;
}

int main()
{
    ReadParameters();
    displayReadData();
}