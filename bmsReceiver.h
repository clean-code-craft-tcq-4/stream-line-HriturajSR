#define SMA_CONSTANT 5
#define TOTAL_READINGS 50
struct BMSProcessedParameters{
    float minTemp;
    float maxTemp;

    float minChargeRate;
    float maxChargeRate;

    float smaChargeRate[45];
    float smaTemp[45];
};
struct BMSParameters{
    float temperature[50];
    float chargeRate[50];
};

float
calculateMaxValue(float currentValue, float maxValue);

float
calculateMinValue(float currentValue, float minValue);

float
calculateSMA(float *currentValue);