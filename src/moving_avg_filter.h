#ifndef MOVING_AVERAGE_FILTER_H
#define MOVING_AVERAGE_FILTER_H

class MovingAverageFilter {

public:
  MovingAverageFilter();
  bool isValueReady();
  float getMovingAvgValue();
  void update(float rawValue);

private:
  int _sampleIndex = 0;
  static const int _sampleSize = 4;
  bool _isMovingAvgValueReady;
  float _movingAvgValue;
  float _samples[_sampleSize];
};


#endif