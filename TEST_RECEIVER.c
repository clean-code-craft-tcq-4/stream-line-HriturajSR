#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bmsReceiver.h"

struct BMSParameters testbmsParameters[10]
        = {{11,74},{29,74},{29,69},{14,79},{11,43},{40,67},{6,40},{9,60},{38,39},{8,70}};
struct BMSProcessedParameters testprocessedParameters;

void
TEST_PROCESS_DATA (void)
{
    for (int i = 0; i< 10; i++)
    {
        if (i == 0)
            initializeProcessedParameters(testbmsParameters, &testprocessedParameters);

        calculateMaxandMin(testbmsParameters, &testprocessedParameters, i);

        calculateSMA(testbmsParameters, &testprocessedParameters, i);

    }
}

void
TEST_MAX_AND_MIN (void)
{
    printf("TEST max n min : %f - %f - %f -%f\n",testprocessedParameters.maxChargeRate,testprocessedParameters.minChargeRate,
                testprocessedParameters.maxTemp, testprocessedParameters.minTemp);
    assert (abs(testprocessedParameters.maxChargeRate) == 79);
    assert (abs(testprocessedParameters.minChargeRate) == 39);
    assert (abs(testprocessedParameters.maxTemp) == 40);
    assert (abs(testprocessedParameters.minTemp) == 6);
    printf("***********Max n min test passed***********\n");
}

void
TEST_SMA(void)
{
    for (int i = 0; i <=5 ; i++)
        printf("TEST: %f - %f abs %f - %f\n",testprocessedParameters.smaChargeRate[i],testprocessedParameters.smaTemp[i],
                        abs(testprocessedParameters.smaChargeRate[i]),abs(testprocessedParameters.smaTemp[i]));
    assert (abs(testprocessedParameters.smaChargeRate[0]) == abs(67.8));
    assert (abs(testprocessedParameters.smaChargeRate[1]) == abs(66.4));
    assert (abs(testprocessedParameters.smaChargeRate[2]) == abs(59.6));
    assert (abs(testprocessedParameters.smaChargeRate[3]) == abs(57.8));
    assert (abs(testprocessedParameters.smaChargeRate[4]) == abs(49.8));
    assert (abs(testprocessedParameters.smaChargeRate[5]) == abs(55.2));

    assert (abs(testprocessedParameters.smaTemp[0]) == abs(18.8));
    assert (abs(testprocessedParameters.smaTemp[1]) == abs(24.6));
    assert (abs(testprocessedParameters.smaTemp[2]) == abs(20));
    assert (abs(testprocessedParameters.smaTemp[3]) == abs(14.2));
    assert (abs(testprocessedParameters.smaTemp[4]) == abs(20.8));
    assert (abs(testprocessedParameters.smaTemp[5]) == abs(20.2));
    printf("***********SMA test passed***********\n");
}

void
TEST_RUN (void)
{
    TEST_PROCESS_DATA();
    TEST_MAX_AND_MIN();
    TEST_SMA();

    printf("***********All test passed***********\n");
}