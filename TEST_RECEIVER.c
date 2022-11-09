#include <stdio.h>
#include <assert.h>

#include "bmsreceiver.h"

struct BMSParameters bmsParameters[10]
        = [[11,74],[29,74],[29,69],[14,79],[11,43],[40,67],[6,40],[9,60],[38,39],[8,70]];
struct BMSProcessedParameters processedParameters;
void
TEST_MAX_AND_MIN_FUNC (void)
{
    if (index == 0)
    {
        initializeProcessedParameters(bmsParameters);
    }

    calculateMaxandMin(bmsParameters, 9);

    calculateSMA(bmsParameters, 9);

    assert (processedParameters.maxChargeRate == 79);
    assert (processedParameters.minChargeRate == 39);
    assert (processedParameters.maxTemp == 40);
    assert (processedParameters.minTemp == 6);

}

void
TEST_SMA(void)
{
    for (int i = 0; i <=5;i++)
    {
        printf("TEST: %f - %f",processedParameters.smaChargeRate[i],processedParameters.smaTemp[i]);
    }
    assert (processedParameters.smaChargeRate[0] == 67.8);
    assert (processedParameters.smaChargeRate[1] == 66.4);
    assert (processedParameters.smaChargeRate[2] == 59.6);
    assert (processedParameters.smaChargeRate[3] == 57.8);
    assert (processedParameters.smaChargeRate[4] == 49.8);
    assert (processedParameters.smaChargeRate[5] == 55.2);

    assert (processedParameters.smaTemp[0] == 18.8);
    assert (processedParameters.smaTemp[1] == 24.6);
    assert (processedParameters.smaTemp[2] == 20);
    assert (processedParameters.smaTemp[3] == 14.2);
    assert (processedParameters.smaTemp[4] == 20.8);
    assert (processedParameters.smaTemp[5] == 20.2);
}