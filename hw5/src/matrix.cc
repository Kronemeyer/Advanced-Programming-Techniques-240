/* Copyright 2019 Ben Kronemeyer */

#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "matrix.h"  // NOLINT

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles
}

Matrix::Matrix(const Matrix& that) : rows_(that.rows_), cols_(that.cols_) {
  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j)
      m_[i][j] = that.Get(i, j);
  }
}

Matrix::~Matrix() {
  delete* m_;
}

double Matrix::Get(unsigned int row, unsigned int col) const {
  assert(rows_ > row);
  assert(cols_ > col);

  return m_[row][col];
}

const Matrix& Matrix::operator=(const Matrix& rhs) {
  this->rows_ = rhs.rows_;
  this->cols_ = rhs.cols_;

  assert(this->rows_ == rhs.rows_);
  assert(this->cols_ == rhs.cols_);

  if (this == &rhs)  // not the same object
    return *this;

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j)
      m_[i][j] = rhs.Get(i, j);
  }
  return *this;
}

const Matrix& Matrix::operator*=(double rhs) {
  for (unsigned int f = 0; f < rows_; ++f) {
    for (unsigned int u = 0; u < cols_; ++u)
      m_[f][u] = Get(f, u)*rhs;
  }
  return *this;
}

const Matrix Matrix::operator+(const Matrix& rhs) const {
  Matrix matrix;
  matrix.rows_ = rhs.rows_;
  matrix.cols_ = rhs.cols_;

  assert(rows_ == rhs.rows_);
  assert(cols_ == rhs.cols_);

  matrix.m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    matrix.m_[i] = new double[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j)
      matrix.m_[i][j] = Get(i, j) + rhs.Get(i, j);
  }
  return matrix;
}
#endif  // NOLINT
