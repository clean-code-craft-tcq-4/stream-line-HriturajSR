struct BMSProcessedParameters{
    float minTemp;
    float maxTemp;

    float minChargeRate;
    float maxChargeRate;

    float smaChargeRate;
    float smaTemp;
};
struct BMSParameters{
    float temperature[50];
    float chargeRate[50];
};

float
calculateMaxValue(float currentValue, float maxValue);

float
calculateMinValue(float currentValue, float minValue);