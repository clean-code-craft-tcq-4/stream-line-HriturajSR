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
    float temperature;
    float chargeRate;
};

void
calculateMaxandMin(struct BMSParameters bmsParameters[], struct BMSProcessedParameters *processedParameters, int index);

float
calculateMaxValue(float currentValue, float maxValue);

float
calculateMinValue(float currentValue, float minValue);

float
calculateSMAforTemp(struct BMSParameters bmsParameters[], int index);

float
calculateSMAforCR(struct BMSParameters bmsParameters[], int index);

void
initializeProcessedParameters(struct BMSParameters bmsParameters[], struct BMSProcessedParameters *processedParameters)

struct BMSParameters
ReadParameters(void);

struct BMSProcessedParameters
*processSensorInputs(void);

void
calculateSMA(struct BMSParameters bmsParameters[], struct BMSProcessedParameters *processedParameters, int index);

void 
displayReadData(struct BMSProcessedParameters *processedParameters);