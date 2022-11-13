#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bmsReceiver.h"

struct BMSParameters testbmsParameters[10]
        = {{11,74},{29,74},{29,69},{14,79},{11,43},{40,67},{6,40},{9,60},{38,39},{8,70}};
struct BMSProcessedParameters testprocessedParameters;

/**
 * @brief process constant data for verification
 * 
 */
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
/**
 * @brief test maximum and minimum of temp and cr for constant inputs
 * 
 */
void
TEST_MAX_AND_MIN (void)
{
    assert (testprocessedParameters.maxChargeRate == 79.0f);
    assert (testprocessedParameters.minChargeRate == 39.0f);
    assert (testprocessedParameters.maxTemp == 40.0f);
    assert (testprocessedParameters.minTemp == 6.0f);
    printf("***********Max n min test passed***********\n");
}

/**
 * @brief test simple moving average of temp and cr
 * 
 */
void
TEST_SMA(void)
{
    assert (testprocessedParameters.smaChargeRate[0] == 67.8f);
    assert (testprocessedParameters.smaChargeRate[1] == 66.4f);
    assert (testprocessedParameters.smaChargeRate[2] == 59.6f);
    assert (testprocessedParameters.smaChargeRate[3] == 57.8f);
    assert (testprocessedParameters.smaChargeRate[4] == 49.8f);
    assert (testprocessedParameters.smaChargeRate[5] == 55.2f);

    assert (testprocessedParameters.smaTemp[0] == 18.8f);
    assert (testprocessedParameters.smaTemp[1] == 24.6f);
    assert (testprocessedParameters.smaTemp[2] == 20.0f);
    assert (testprocessedParameters.smaTemp[3] == 16.0f);
    assert (testprocessedParameters.smaTemp[4] == 20.8f);
    assert (testprocessedParameters.smaTemp[5] == 20.2f);
    printf("***********SMA test passed***********\n");
}

/**
 * @brief run test cases
 * 
 */
void
TEST_RUN (void)
{
    TEST_PROCESS_DATA();
    TEST_MAX_AND_MIN();
    TEST_SMA();

    printf("***********All test passed***********\n");
}