#include "mean.h"

void Mean::Collect(double datum) {
  kData += datum;
  total++;
}

double Mean::Calculate() const {
  double mean = kData / total;
  return mean;
}

