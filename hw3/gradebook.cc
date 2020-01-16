/*Copyright 2019 Ben Kronemeyer*/
#include "gradebook.h"  // NOLINT
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

/* Adds a new grade to the gradebook instance, increasing size by 1.
   */
void GradeBook::Add(double grade) {
  return _gb.push_back(grade);
}

/* Returns the grade at the supplied index. When that index is out of range, a
 * value of NAN (from cmath) is returned.
 */
double GradeBook::Get(std::size_t index) const {
  if (Empty()) {
    return NAN;
  }
  return _gb.at(index);
}


/* Adds two GradeBook instances together and returns their join as a new
 * object.
 * Order is maintained by adding the calling instance's grades to the new
 * Gradebook instance, followed by the parameter GradeBook's instances.
 */

const GradeBook GradeBook::Add(const GradeBook& that) const {
  GradeBook gb3;
  size_t index = 0;
  size_t size = GetSize();
  while (index < size) {
    gb3.Add(Get(index++));
  }
  size = that.GetSize() - 1;
  index = 0;
  while (index < size) {
    gb3.Add(that.Get(index++));
  }
  return gb3;
}


/* Returns the average of all grades stored in GradeBook instance, or NAN(from
 * cmath) if the the GradeBook instance is empty.
 */
double GradeBook::GetGPA() const {
  if (Empty()) {
    return NAN;
  }
  double gpa = 0;
  size_t size = GetSize() - 1;
  for (std::size_t i = 0; i < size; i++) {
    gpa += _gb.at(i);
  }
  return gpa / size;
}


/* Returns the max grade in the GradeBook or NAN if the calling instance is
 * empty.
 */
double GradeBook::GetMax() const {
  if (Empty()) {
    return NAN;
  }
  double max = 0;
  std::size_t size = GetSize() - 1;
  for (size_t i = 0; i < size; i++) {
    if (_gb.at(i) > max)
      max = _gb.at(i);
  }
  return max;
}


/* Returns the number of grades currently stored by the GradeBook.
 */
const size_t GradeBook::GetSize() const {
  return _gb.capacity();
}

bool GradeBook::Empty() const {
  return _gb.empty();
}

/* Returns true when two GradeBook instances have the same average grade
 * value; returns false otherwise. An empty instance is treated as having an
 * average grade value of -infinity.
 * Equality should be true if the grades are within 0.00001 of each other.
 */
bool GradeBook::Equals(const GradeBook& that) const {
  double gpa1 = GradeBook::GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = that.GetGPA();
  if (std::isnan(gpa2)) {
    gpa2 = -INFINITY;
  }
  if (gpa1 == -INFINITY && gpa2 != -INFINITY) {
    return false;
  }
  if ((gpa1 - gpa2) <= .00001) {
    return true;
  }
  return false;
}


/* Returns true when the calling instance has a smaller grade average than the
 * parameter instance's average. If they are even, it compares their max
 * grades. An empty instance is treated as having an average grade value of
 * -infinity.
 */
bool GradeBook::LessThan(const GradeBook& that) const {
  double gpa1 = GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = that.GetGPA();
  if (std::isnan(gpa2)) {
    gpa2 = -INFINITY;
  }
  if (gpa1 < gpa2) {
    return true;
  }
  if (gpa1 == gpa2) {
    double gpamax1 = GetMax();
    double gpamax2 = that.GetMax();
    if (gpamax1 < gpamax2) {
      return true;
    }
}
return false;
}
