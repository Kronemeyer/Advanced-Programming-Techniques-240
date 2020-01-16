/*
Copyright 2019 Benjamin Kronemeyer
*/
#include "parse_scores.h"  // NOLINT
#include <string>
using std::stoi;
using std::stod;

int check_corruption(const std::string values[], int size) {
  int index = 0, students = 0, grades = 0, counter = 1;
  students = std::stoi(values[index++]);
  counter += students;
  for (int j = 0; j < students; j++) {
    index++;
    grades = std::stoi(values[index++]);
    counter += grades + 1;
    for (int k = 0; k < (grades); k++) {
      index++;
    }
  }
  if (counter != size)
    return -10;
  else
    return 0;
}

int get_num_grades(int id, const std::string values[], int size) {
  if (check_corruption(values, size)== -10) {
    return -10;
  }
  int idSearch = 0;
  while (std::stoi(values[idSearch]) != id && idSearch < size-1) {
    idSearch++;
  }
  if (std::stoi(values[idSearch]) == id) {
    int num_of_grades = std::stoi(values[idSearch + 1]);
    return num_of_grades;
  } else {
    return -1;
  }
}

int get_grades(int id, const std::string values[], int size, double grades[]) {
  int idSearch = 0;
  if (check_corruption(values, size)== -10) {
    return -10;
  }
  while (std::stoi(values[idSearch]) != id && idSearch < size - 1) {
    idSearch++;
  }
  if (std::stoi(values[idSearch]) == id) {
    int numberOfGrades = std::stoi(values[++idSearch]);
    for (int j = 0; j < numberOfGrades; j++) {
      grades[j] = std::stod(values[++idSearch]);
    }
    return numberOfGrades;
  } else {
    return -1;
  }
}

double get_grade(int id, int grade_index,
                   const std::string values[], int size) {
  int idSearch = 0;
  if (check_corruption(values, size)== -10) {
    return -10;
  }
  while (std::stoi(values[idSearch]) != id
           && idSearch < size - 1) {
    idSearch++;
  }
  if (idSearch == size - 1) {
    return -1;
  }
  if (std::stoi(values[++idSearch]) > grade_index)
    return std::stod(values[idSearch + grade_index + 1]);
  else
    return -2;
}

int get_max_grade_id(const std::string values[], int size) {
  if (check_corruption(values, size)== -10) {
    return -10;
  }
  int index = 0, students = 0, id = 0, grades = 0, total_grades = 0, max_id = 0;
  double max_grade = 0;
  students = std::stoi(values[index++]);  // sets students to values[0]
  if (students == 0)
    return -1;
  for (int j = 0; j < students; j++) {  // loops for each student
    id = std::stoi(values[index++]);  // moves to first id value
    grades = std::stoi(values[index++]);  // sets amount of grades
    total_grades += grades;
    for (int k = 0; k < grades; k++) {
      if (std::stod(values[index++]) > max_grade) {
        max_grade = std::stod(values[index - 1]);
        max_id = id;
      }
    }
    if (total_grades == 0)
      return -2;
    }
  return max_id;
}

double get_max_grade(const std::string values[], int size) {
  if (check_corruption(values, size)== -10) {
    return -10;
  }

  int index = 0, students = 0, grades = 0,
        total_grades = 0;
  double max_grade = 0;
  students = std::stoi(values[index++]);  // sets students to values[0]
  if (students == 0)
    return -1;
  for (int j = 0; j < students; j++) {  // loops for each student
    index++;
    grades = std::stoi(values[index++]);  // sets amount of grades
    if (grades == 0)
      return -2;
    total_grades += grades;
    for (int k = 0; k < grades; k++) {  // loops for each grade
      if (std::stod(values[index]) > max_grade) {
        max_grade = std::stod(values[index - 1]);
      }
      if (index != 11) {
        index++;
      }
    }
    if (std::stod(values[11]) > max_grade)
      max_grade = std::stod(values[11]);
    if (total_grades == 0)
      return -2;
    }
  return max_grade;
}

int get_student_ids(const std::string values[], int size, int ids[]) {
  int index = 0, id = 0, students = 0, grades = 0, counter = 1;
  students = std::stoi(values[index++]);
  counter += students;
  for (int j = 0; j < students; j++) {
    id = std::stoi(values[index++]);
    ids[j] = id;
    grades = std::stoi(values[index++]);
    counter += grades + 1;
    for (int k = 0; k < grades; k++) {
      index++;
    }
  }
  if (counter != size) {
    return -10;
  }
  return students;
}
