
#include <cassert>
// using assert


class MatrixTester;

class Matrix {
 public:
  friend class MatrixTester;

  Matrix(); // for testing, useless in practice
  Matrix(unsigned int rows, unsigned int cols);

  /* Copy Constructor: 2 Points
   *   Performs deep copy.
   */
  Matrix(const Matrix& that);

  /* Destructor: Required For Any Points
   *   Cleans up memory to avoid leaks
   */
  ~Matrix();

  /* Accessor: 1 Point
   *   Precondition(s):
   *   - Parameter row is less than rows in matrix
   *   - Parameter col is less than cols in matrix
   *   Does what you would expect.
   */
  double Get(unsigned int row, unsigned int col) const;

  /* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
  const Matrix& operator=(const Matrix& rhs);

  /* Times Equals Op: 2 Points
   *   Returns calling object with matrix scaled by rhs.
   */
  const Matrix& operator*=(double rhs);

  /* Add Op: 2 points
   *   Returns the sum of calling object's matrix and rhs's matrix as a new
   *   object.
   * Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   */
  const Matrix operator+(const Matrix& rhs) const;

 private:
   double **m_;
   unsigned int rows_;
   unsigned int cols_;
};
