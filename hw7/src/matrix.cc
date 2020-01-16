/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */
/* Copyright 2019 Benjamin Kronemeyer Finalized Templatization */

#ifndef _MATRIX_TEMPLATE_CC_
#define _MATRIX_TEMPLATE_CC_

template<typename T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& that)
  : rows_(that.rows_), cols_(that.cols_) {
  m_ = new T * [rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new T[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j)
      m_[i][j] = that.Get(i, j);
  }
}

template<typename T>
Matrix<T>::~Matrix() {
  delete* m_;
}

template<typename T>
T Matrix<T>::Get(unsigned int row, unsigned int col) const {
  assert(rows_ > row);
  assert(cols_ > col);

  return m_[row][col];
}

template<typename T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  this->rows_ = rhs.rows_;
  this->cols_ = rhs.cols_;

  assert(this->rows_ == rhs.rows_);
  assert(this->cols_ == rhs.cols_);

  if (this == &rhs)  // not the same object
    return *this;

  m_ = new T* [rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new T[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j)
      m_[i][j] = rhs.Get(i, j);
    }
  return *this;
}

template<typename T>
const Matrix<T>& Matrix<T>::operator*=(T rhs) {
  for (unsigned int f = 0; f < rows_; ++f) {
    for (unsigned int u = 0; u < cols_; ++u)
      m_[f][u] = Get(f, u) * rhs;
  }
  return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix& rhs) const {
  Matrix matrix;
  matrix.rows_ = rhs.rows_;
  matrix.cols_ = rhs.cols_;

  assert(rows_ == rhs.rows_);
  assert(cols_ == rhs.cols_);

  matrix.m_ = new T* [rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    matrix.m_[i] = new T[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j)
      matrix.m_[i][j] = Get(i, j) + rhs.Get(i, j);
  }
  return matrix;
}

#endif
