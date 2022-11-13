#include <stdio.h>
#include "bmsReceiver.h"

struct BMSParameters bmsParameters[TOTAL_READINGS];
struct BMSProcessedParameters processedParameters;

/**
 * @brief main()
 * 
 * @return int 
 */
int main()
{
    struct BMSProcessedParameters *processedResults;
    processedResults = processSensorInputs();
    displayReadData(processedResults);
    
    TEST_RUN ();

    return 0;
}

/**
 * @brief                                   Read and Analyze the data from console 
 * 
 * @return struct BMSProcessedParameters*   structure array for inputs
 */
struct BMSProcessedParameters
*processSensorInputs(void)
{
    for (int index = 0; index < TOTAL_READINGS; index++)
    {
        bmsParameters[index] = ReadParameters();

        if (index == 0)
        {
            initializeProcessedParameters(bmsParameters, &processedParameters);
        }

        calculateMaxandMin(bmsParameters, &processedParameters, index);

        calculateSMA(bmsParameters, &processedParameters, index);   
    }

    for (int i = 0; i< 50; i++)
    { 
        printf("Temperature = %f,Charge Rate = %f\n", bmsParameters[i].temperature, bmsParameters[i].chargeRate);
    }

    return &processedParameters;
}

/**
 * @brief                          Read the data from console
 * 
 * @return struct BMSParameters    structure array for inputs
 */
struct BMSParameters
ReadParameters(void)
{
    struct BMSParameters p1;
    
        scanf("%f,%f\n", &p1.temperature, &p1.chargeRate);

        return p1;
}

/**
 * @brief                       Initialize the max and min variables
 * 
 * @param bmsParameters         structure array for inputs
 * @param processedParameters   Results structure
 */
void
initializeProcessedParameters(struct BMSParameters bmsParameters[], struct BMSProcessedParameters *processedParameters)
{
    processedParameters->maxTemp = bmsParameters[0].temperature;
    processedParameters->minTemp = bmsParameters[0].temperature;

    processedParameters->maxChargeRate = bmsParameters[0].chargeRate;
    processedParameters->minChargeRate = bmsParameters[0].chargeRate;
}

/**
 * @brief                       Sends data to calculate SMA for both temp and cr
 * 
 * @param bmsParameters         structure array for inputs
 * @param processedParameters   Results structure
 * @param index                 Index of the reading
 */
void
calculateSMA(struct BMSParameters bmsParameters[], struct BMSProcessedParameters *processedParameters, int index)
{
    if (index >= (SMA_CONSTANT - 1))
    {
        processedParameters->smaTemp[index - (SMA_CONSTANT-1)] = calculateSMAforTemp (bmsParameters, index);
        processedParameters->smaChargeRate[index - (SMA_CONSTANT-1)] = calculateSMAforCR (bmsParameters, index);
        printf("SMATemperature= %f, SMAChargeRate= %f\n", processedParameters->smaTemp[index - (SMA_CONSTANT-1)], 
                                                processedParameters->smaChargeRate[index - (SMA_CONSTANT-1)]);
    }
}

/**
 * @brief                       Calculates the max and min for both temp and CR
 * 
 * @param bmsParameters         structure array for inputs
 * @param processedParameters   Results structure
 * @param index                 Index of the reading
 */
void
calculateMaxandMin(struct BMSParameters bmsParameters[], struct BMSProcessedParameters *processedParameters, int index)
{
    processedParameters->maxTemp = calculateMaxValue (bmsParameters[index].temperature, processedParameters->maxTemp);
    processedParameters->minTemp = calculateMinValue (bmsParameters[index].temperature, processedParameters->minTemp);
    
    processedParameters->maxChargeRate = calculateMaxValue (bmsParameters[index].chargeRate, processedParameters->maxChargeRate);
    processedParameters->minChargeRate = calculateMinValue (bmsParameters[index].chargeRate, processedParameters->minChargeRate);
}

/**
 * @brief                       Displays the all the analysed data
 * 
 * @param processedParameters   Results structure
 */
void 
displayReadData(struct BMSProcessedParameters *processedParameters)
{
    printf ("\nMaxTemperature = %f\t MinTemperature = %f\t MaxChargeRate = %f\t MinChargeRate =%f\n\n",
        processedParameters->maxTemp, processedParameters->minTemp,
        processedParameters->maxChargeRate, processedParameters->minChargeRate);
}

/**
 * @brief               Calculates the maximum value
 * 
 * @param currentValue  Current reading
 * @param maxValue      Previous stored maximum value
 * @return float        Returns latest maximum value
 */
float
calculateMaxValue(float currentValue, float maxValue)
{
    if (currentValue <= maxValue)
    {
        return maxValue;
    }

    return currentValue;
}

/**
 * @brief               Calculates the minimum value
 * 
 * @param currentValue  Current reading
 * @param minValue      Previous stored minimum value
 * @return float        Returns latest minimum value
 */
float
calculateMinValue(float currentValue, float minValue)
{
    if (currentValue >= minValue)
    {
        return minValue;
    }

    return currentValue;
}

/**
 * @brief                   Calculates the simple moving average value for temperature
 * 
 * @param bmsParameters     structure array for inputs
 * @param index             Index of the reading
 * @return float            Returns simple moving average of 5 readings
 */
float
calculateSMAforTemp(struct BMSParameters bmsParameters[], int index)
{
    float sum = 0;

    for (int i=4; i >= 0; i--)
    {
        sum += bmsParameters[index - i].temperature;
    }
    
    sum = sum/5;
    
    return sum;
}

/**
 * @brief                   Calculates the simple moving average value for charge rate
 * 
 * @param bmsParameters     structure array for inputs
 * @param index             Index of the reading
 * @return float            Returns simple moving average of 5 readings
 */
float
calculateSMAforCR(struct BMSParameters bmsParameters[], int index)
{
    float sum = 0;

    for (int i=4; i >= 0; i--)
    {
        sum += bmsParameters[index - i].chargeRate;
    }
    
    sum = sum/5;
    
    return sum;
}