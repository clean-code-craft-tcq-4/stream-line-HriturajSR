#include <stdio.h>
float Temp[50];
float ChargingRate[50];

int ReadParameters(void)
{
 for (int i = 0; i< 50;i++)
 { 
   scanf("%f,%f\n", &Temp[i], &ChargingRate[i]);
 }
}

int displayReadData(void)
{
    for (int i = 0; i< 50;i++)
    { 
        printf("Temp-%f,CR-%f\n", Temp[i], ChargingRate[i]);
    }
}

int main()
{
    ReadParameters();
    displayReadData();
}