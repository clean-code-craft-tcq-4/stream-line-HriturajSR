#include <stdio.h>
#include "bmsReceiver.h"

struct BMSParameters bmsParameters[TOTAL_READINGS];
struct BMSProcessedParameters processedParameters;

struct BMSParameters
ReadParameters(void)
{
    struct BMSParameters p1;
    
        scanf("%f,%f\n", &p1.temperature, &p1.chargeRate);

        return p1;
}

void
processSensorInputs(void)
{
    for (int index = 0; index < TOTAL_READINGS; index++)
    {
        bmsParameters[index] = ReadParameters();

        if (index == 0)
        {
            initializeProcessedParameters();
        }

        calculateMaxandMin(index);

        calculateSMA(index);        
    }
}

void
calculateSMA(int index)
{
    if (index >= (SMA_CONSTANT - 1))
    {
        processedParameters.smaTemp[index - (SMA_CONSTANT-1)] = calculateSMAforTemp (index);
        processedParameters.smaChargeRate[index - (SMA_CONSTANT-1)] = calculateSMAforCR (index);
        printf("%d SMATemp-(%f),SMACR-(%f)\n",index - (SMA_CONSTANT-1), processedParameters.smaTemp[index - (SMA_CONSTANT-1)], 
                                                processedParameters.smaChargeRate[index - (SMA_CONSTANT-1)]);
    }
}

void
initializeProcessedParameters(void)
{
    processedParameters.maxTemp = bmsParameters[0].temperature;
    processedParameters.minTemp = bmsParameters[0].temperature;

    processedParameters.maxChargeRate = bmsParameters[0].chargeRate;
    processedParameters.minChargeRate = bmsParameters[0].chargeRate;
}

void
calculateMaxandMin(int index)
{
        processedParameters.maxTemp = calculateMaxValue (bmsParameters[index].temperature, processedParameters.maxTemp);
        processedParameters.minTemp = calculateMinValue (bmsParameters[index].temperature, processedParameters.minTemp);
        
        processedParameters.maxChargeRate = calculateMaxValue (bmsParameters[index].chargeRate, processedParameters.maxChargeRate);
        processedParameters.minChargeRate = calculateMinValue (bmsParameters[index].chargeRate, processedParameters.minChargeRate);
}

void 
displayReadData(void)
{
    for (int i = 0; i< 50; i++)
    { 
        printf("Temp-%f,CR-%f\n", bmsParameters[i].temperature, bmsParameters[i].chargeRate);
    }

    printf ("\nMaxTemp = %f\t MinTemp= %f\t MaxCR = %f\t MinCR =%f\n\n",
        processedParameters.maxTemp, processedParameters.minTemp,
        processedParameters.maxChargeRate, processedParameters.minChargeRate);

    for (int j = 0; j <= 45; j++)
    {
        printf("SMATemp-%f,SMACR-%f\n", processedParameters.smaTemp[j], processedParameters.smaChargeRate[j]);
    }
}

float
calculateMaxValue(float currentValue, float maxValue)
{
    if (currentValue <= maxValue)
    {
        return maxValue;
    }

    return currentValue;
}

float
calculateSMAforTemp(int index)
{
    float sum = 0;

    for (int i=4; i >= 0; i--)
    {
        sum += bmsParameters[index - i].temperature;
    }
    
    sum = sum/5;
    
    return sum;
}

float
calculateSMAforCR(int index)
{
    float sum = 0;

    for (int i=4; i >= 0; i--)
    {
        sum += bmsParameters[index - i].chargeRate;
    }
    
    sum = sum/5;
    
    return sum;
}

float
calculateMinValue(float currentValue, float minValue)
{
    if (currentValue >= minValue)
    {
        return minValue;
    }

    return currentValue;
}

int main()
{
    processSensorInputs();
    displayReadData();

    return 0;
}