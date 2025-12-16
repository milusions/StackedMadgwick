#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H


class LowPassFilter {

public:
  LowPassFilter(float alpha);
  void setAlpha(float alpha);
  float getLpfValue();
  float getPreviousLpfValue();
  void update(float rawValue);

private:
  float _previousLpfValue;
  float _lpfValue;
  float _alpha;
};


#endif