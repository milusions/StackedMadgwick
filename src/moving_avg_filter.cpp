#include "moving_avg_filter.h"
#include "array_ops.h"

MovingAverageFilter::MovingAverageFilter() {
}

bool MovingAverageFilter::isValueReady() {
  return _isMovingAvgValueReady;
}

float MovingAverageFilter::getMovingAvgValue() {
  return _movingAvgValue;
}

void MovingAverageFilter::update(float rawValue) {
  addElementFirst(rawValue, _samples,_sampleSize);

  if (_sampleIndex == (_sampleSize - 1)) {

    _movingAvgValue = calculateMean(_samples,_sampleSize);
    _isMovingAvgValueReady = true;

    _sampleIndex=0;
  } else {
    _isMovingAvgValueReady = false;
  }

  _sampleIndex++;
}
