#ifndef IMU_FILTER_FLOW_H
#define IMU_FILTER_FLOW_H

#include "low_pass_filter.h"
#include "avg_filter.h"
#include "moving_avg_filter.h"

class IMUFilterFlow {

public:
  IMUFilterFlow();
  bool isFilterReady();
  void pushValue(float value);
  float getFilteredValue();
  float getFilteredAvgValue();
private:
  float _lowPassFilterAlpha = 0.2;
  float _filteredValue;
  bool _isFilterReady;
  LowPassFilter _lowPassFilter;
  AverageFilter _averageFilter;
  MovingAverageFilter _movingAverageFilter;
};

#endif