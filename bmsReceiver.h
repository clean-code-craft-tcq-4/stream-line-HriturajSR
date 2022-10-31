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