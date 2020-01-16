/* Copyright 2019 Benjamin Kronemeyer */

#include "gradebook.h" // NOLINT

void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}
double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}

size_t GradeBook::GetSize() const {
  return grades_.capacity();
}

double GradeBook::GetMax() const {
  double max = 0;
  size_t size = GetSize() - 1;
  for (size_t i = 0; i < size; i++) {
    if (grades_.at(i) > max)
      max = grades_.at(i);
  }
  return max;
}

double GradeBook::GetGPA() const {
  size_t size = GetSize() - 1;
  double gpa = 0;
  if (!(size == NAN)) {
    for (size_t i = 0; i < size; i++) {
      gpa += grades_.at(i);
    }
  }
  return gpa / size;
}

const GradeBook GradeBook::operator+(double rhs) const {
  GradeBook book;
  size_t index = 0;
  size_t size = GetSize();
  while (index < size) {
    book.Add(Get(index++));
  }
  book.Add(rhs);
  return book;
}

const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook book;
  size_t index = 0;
  size_t size = GetSize();
  while (index < size) {
    book.Add(Get(index++));
  }
  size = rhs.GetSize() - 1;
  index = 0;
  while (index < size) {
    book.Add(rhs.Get(index++));
  }
  return book;
}

bool GradeBook::operator==(const GradeBook& rhs) const {
  double gpa1 = GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = rhs.GetGPA();
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

bool GradeBook::operator==(double rhs) const {
  double gpa1 = GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = rhs;
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

bool GradeBook::operator<(const GradeBook& rhs) const {
  double gpa1 = GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = rhs.GetGPA();
  if (std::isnan(gpa2)) {
    gpa2 = -INFINITY;
  }
  if (gpa1 < gpa2) {
    return true;
  }
  if (gpa1 == gpa2) {
    double gpamax1 = GetMax();
    double gpamax2 = rhs.GetMax();
    if (gpamax1 < gpamax2) {
      return true;
    }
  }
  return false;
}

bool GradeBook::operator<(double rhs) const {
  double gpa1 = GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = rhs;
  if (std::isnan(gpa2)) {
    gpa2 = -INFINITY;
  }
  if (gpa1 < gpa2) {
    return true;
  }
  return false;
}

const GradeBook operator+(double lhs, const GradeBook& rhs) {
  GradeBook book;
  size_t size = rhs.GetSize();
  if (!(size == NAN)) {
    for (size_t i = 0; i < size; i++) {
      book.Add(rhs.Get(i));
    }
  }
  book.Add(lhs);
  return book;
}

bool operator==(double lhs, const GradeBook& rhs) {
  double gpa1 = rhs.GetGPA();
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  double gpa2 = lhs;
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

bool operator<(double lhs, const GradeBook& rhs) {
  double gpa2 = rhs.GetGPA();
  if (std::isnan(gpa2)) {
    gpa2 = -INFINITY;
  }
  double gpa1 = lhs;
  if (std::isnan(gpa1)) {
    gpa1 = -INFINITY;
  }
  if (gpa1 < gpa2) {
    return true;
  }
  return false;
}
