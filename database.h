/**
*.h file:
*/
#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include <string>

namespace SMYJAS002 {

  struct StudentRecord {
    std::string Name;
    std::string Surname;
    std::string StudentNumber;
    std::string ClassRecord;
  };

	// Initialiser for the Student record struct
  StudentRecord make_record(std::string name, std::string surname, std::string studentNum, std::string classRec);

  void add_student(std::string name, std::string surname, std::string studentNum, std::string classRec);

  void read_database();

  void save_database();

  void display_data(std::string studentNumber);

  void grade_student(std::string studentNumber);
  
  int find_student(std::string studentNum);
}
#endif
