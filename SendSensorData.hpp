#ifndef SENDDATA_H
#define SENDDATA_H

#include <iostream>
#include <vector>
#include "TEMPERATURE.hpp"
#include "CHARGE.hpp"

#define TOTAL_READINGS 50
using namespace std;

bool transferData(std::vector<int>tempData,std::vector<int>chargeData);


#endif
