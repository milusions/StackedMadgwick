#include "LowPassFilter.h"

LowPassFilter::LowPassFilter(float alpha){
  _alpha = alpha;
  _previousLpfValue = 0.0;
  _lpfValue = 0.0;
}

void LowPassFilter::setAlpha(float alpha){
  _alpha = alpha;
}

float LowPassFilter::getLpfValue(){
  return _lpfValue;
}

float LowPassFilter::getPreviousLpfValue(){
  return _previousLpfValue;
}

void LowPassFilter::update(float rawValue){
  _previousLpfValue = _lpfValue;
  _lpfValue = _alpha*_previousLpfValue  + (1 - _alpha) * rawValue;
}