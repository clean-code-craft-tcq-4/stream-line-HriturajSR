#include <stdio.h>
#include <assert.h>

#include "bmsReceiver.h"

struct BMSParameters testbmsParameters[10]
        = {{11,74},{29,74},{29,69},{14,79},{11,43},{40,67},{6,40},{9,60},{38,39},{8,70}};
struct BMSProcessedParameters testprocessedParameters;
void
TEST_MAX_AND_MIN_FUNC (void)
{
    initializeProcessedParameters(testbmsParameters, &testprocessedParameters);

    calculateMaxandMin(testbmsParameters, &testprocessedParameters, 9);

    calculateSMA(testbmsParameters, &testprocessedParameters, 9);

    assert (testprocessedParameters.maxChargeRate == 79);
    assert (testprocessedParameters.minChargeRate == 39);
    assert (testprocessedParameters.maxTemp == 40);
    assert (testprocessedParameters.minTemp == 6);

}

void
TEST_SMA(void)
{
    for (int i = 0; i <=5;i++)
    {
        printf("TEST: %f - %f",testprocessedParameters.smaChargeRate[i],testprocessedParameters.smaTemp[i]);
    }
    assert (testprocessedParameters.smaChargeRate[0] == 67.8);
    assert (testprocessedParameters.smaChargeRate[1] == 66.4);
    assert (testprocessedParameters.smaChargeRate[2] == 59.6);
    assert (testprocessedParameters.smaChargeRate[3] == 57.8);
    assert (testprocessedParameters.smaChargeRate[4] == 49.8);
    assert (testprocessedParameters.smaChargeRate[5] == 55.2);

    assert (testprocessedParameters.smaTemp[0] == 18.8);
    assert (testprocessedParameters.smaTemp[1] == 24.6);
    assert (testprocessedParameters.smaTemp[2] == 20);
    assert (testprocessedParameters.smaTemp[3] == 14.2);
    assert (testprocessedParameters.smaTemp[4] == 20.8);
    assert (testprocessedParameters.smaTemp[5] == 20.2);
}

void
TEST_RUN (void)
{
    TEST_MAX_AND_MIN_FUNC();
    TEST_SMA();
}