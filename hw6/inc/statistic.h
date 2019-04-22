#ifndef _STATISTIC_H_
#define _STATISTIC_H_

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

/* This is an abstract base class which Statistic classes extend.
 */
class Statistic {
 public:
  /* Not a pure virtual so that children may not override if unused
   */
   virtual ~Statistic() {}

  /* Defined by children
   */
  virtual void Collect(double) = 0;

  /* Defined by children
   */
  virtual double Calculate() const = 0;
};

#endif // !_STATISTIC_H_
