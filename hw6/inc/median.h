#ifndef _MEDIAN_H_
#define _MEDIAN_H_

#include "statistic.h"

/* This class inherits from the Statistic class such that it  may be used
 * polymorphically.
 */
class Median : public Statistic {
public:
  ~Median() {
    delete list.~vector;
  }
  /* Stores data (datum) such than the median may be determined.
  */
  void Collect(double datum);

  /* Calculates the median of the data (datum) from the Collect method.
   */
  double Calculate() const;
private:
  vector<double> list;
  double total;
}
#endif // !_MEDIAN_H_