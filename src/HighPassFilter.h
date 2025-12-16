#ifndef HIGH_PASS_FILTER_H
#define HIGH_PASS_FILTER_H


class HighPassFilter {

public:
  HighPassFilter(float alpha);
  void setAlpha(float alpha);
  float getHpfValue();
  float getPreviousHpfValue();
  void update(float rawValue);

private:
 float _previousRawValue;
  float _previousHpfValue;
  float _hpfValue;
  float _alpha;
};


#endif