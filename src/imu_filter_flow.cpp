#include "imu_filter_flow.h"



IMUFilterFlow::IMUFilterFlow()
  : _lowPassFilter(0.9) {

  _averageFilter = AverageFilter();
  _movingAverageFilter = MovingAverageFilter();
}

bool IMUFilterFlow::isFilterReady() {
  return _isFilterReady;
}

void IMUFilterFlow::pushValue(float value) {

  _isFilterReady = false;

  _averageFilter.update(value);

  if (!_averageFilter.isValueReady())
    return;
  float averageValue = _averageFilter.getAvgValue();

  _lowPassFilter.update(averageValue);


  float lpfValue = _lowPassFilter.getLpfValue();

  _movingAverageFilter.update(lpfValue);

  if (!_movingAverageFilter.isValueReady())
    return;
  float movingAverageValue = _movingAverageFilter.getMovingAvgValue();

  

  _isFilterReady = true;
  _filteredValue = movingAverageValue;
}

float IMUFilterFlow::getFilteredValue() {
  return _filteredValue;
}
