#include "median.h"

void Median::Collect(double datum) {
  list.push_back(datum);
  total++;
}

double Median::Calculate() const {
  double median;
  sort(list.begin, list.back);
  if (list.size % 2 == 0) {
    median = list.at((floor(&list.size / 2)));
    median += list.at(ceil(&list.size / 2));
    return median / 2;
  }
  return median = list.at(ceil(list.size/2));
}
