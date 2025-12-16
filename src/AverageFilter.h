#ifndef AVERAGE_FILTER_H
#define AVERAGE_FILTER_H

class AverageFilter {

public:
  AverageFilter();
  bool isValueReady();
  float getAvgValue();
  void update(float rawValue);

private:
  int _sampleIndex = 0;
  static const int _sampleSize = 4;
  bool _isAvgValueReady;
  float _avgValue;
  float _samples[_sampleSize];
};


#endif