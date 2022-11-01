#include <stdio.h>
#include "bmsReceiver.h"

struct BMSParameters bmsParameters;
struct BMSProcessedParameters processedParameters;

int ReadParameters(void)
{
    for (int index = 0; index < TOTAL_READINGS; index++)
    { 
        scanf("%f,%f\n", &bmsParameters.temperature[index], &bmsParameters.chargeRate[index]);

        processedParameters.maxTemp = calculateMaxValue (bmsParameters.temperature[index], processedParameters.maxTemp);
        processedParameters.minTemp = calculateMinValue (bmsParameters.temperature[index], processedParameters.minTemp);
        
        processedParameters.maxChargeRate = calculateMaxValue (bmsParameters.chargeRate[index], processedParameters.maxChargeRate);
        processedParameters.minChargeRate = calculateMinValue (bmsParameters.chargeRate[index], processedParameters.minChargeRate);

        if (index >= SMA_CONSTANT)
        {
            processedParameters.smaTemp[index - SMA_CONSTANT] = calculateSMA (&bmsParameters.temperature[index]);
            processedParameters.smaChargeRate[index - SMA_CONSTANT] = calculateSMA (&bmsParameters.chargeRate[index]);
        }
    }
}

void 
displayReadData(void)
{
    for (int i = 0; i< 50; i++)
    { 
        printf("Temp-%f,CR-%f\n", bmsParameters.temperature[i], bmsParameters.chargeRate[i]);
    }

    printf ("\nMaxTemp = %f\t MinTemp= %f\t MaxCR = %f\t MinCR =%f\n\n",
        processedParameters.maxTemp, processedParameters.minTemp,
        processedParameters.maxChargeRate, processedParameters.minChargeRate);

    for (int j = 0; j < 45; j++)
    {
        printf("SMATemp-%f,SMACR-%f\n", processedParameters.smaTemp[j], processedParameters.smaChargeRate[j]);
    }
}

float
calculateMaxValue(float currentValue, float maxValue)
{
    if (maxValue != 0 && currentValue <= maxValue)
    {
        return maxValue;
    }

    return currentValue;
}

float
calculateSMA(float *currentValue)
{
    float sum = 0;

    for (int index=0; index<SMA_CONSTANT; index++)
    {
        sum += currentValue[-index];
    }
    sum = sum/5;
    return sum;
}

float
calculateMinValue(float currentValue, float minValue)
{
    if (minValue != 0 && currentValue >= minValue)
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