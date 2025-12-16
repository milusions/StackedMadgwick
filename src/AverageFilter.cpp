#include "AverageFilter.h"
#include "ArrayOperations.h"

AverageFilter::AverageFilter() {
}

bool AverageFilter::isValueReady() {
  return _isAvgValueReady;
}

float AverageFilter::getAvgValue() {
  return _avgValue;
}

void AverageFilter::update(float rawValue) {
  addElementFirst(rawValue, _samples,_sampleSize);

  if (_sampleIndex == (_sampleSize - 1)) {

    _avgValue = calculateMean(_samples,_sampleSize);
    _isAvgValueReady = true;
    nullify(_samples,_sampleSize);
    _sampleIndex=0;
  } else {
    _isAvgValueReady = false;
  }

  _sampleIndex++;
}
