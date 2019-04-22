#ifndef _MEAN_H_
#define _MEAN_H_

#include "statistic.h"

/* This class inherits from the Statistic class such that it may be used
 * polymorphically.
 */
class Mean : public Statistic {
 public:
   ~Mean() {
   }
  /* Stores data (datum) such than an average may be calculated.
   * - NOTE: You do not necessarily need to store each datum.
   */
  void Collect(double datum);

  /* Returns the mean of the data (datum) from the Collect method.
   */
  double Calculate() const;
private:
  double kData;
  double total;
};
#endif // !_MEAN_H_