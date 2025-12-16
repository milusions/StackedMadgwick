#include "high_pass_filter.h"

HighPassFilter::HighPassFilter(float alpha) {
  _alpha = alpha;
  _previousHpfValue = 0.0;
  _hpfValue = 0.0;
  _previousRawValue = 0.0;
}

void HighPassFilter::setAlpha(float alpha) {
  _alpha = alpha;
}

float HighPassFilter::getHpfValue() {
  return _hpfValue;
}

float HighPassFilter::getPreviousHpfValue() {
  return _previousHpfValue;
}

void HighPassFilter::update(float rawValue) {

  _previousHpfValue = _hpfValue;
  _hpfValue = _alpha * ( _hpfValue +  rawValue - _previousRawValue);
  _previousRawValue = rawValue;
}