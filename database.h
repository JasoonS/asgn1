/**
*.h file:
*/
#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>
#include <fstream>

namespace SMYJAS002 {

  struct StudentRecord {
    std::string Name;
    std::string Surname;
    std::string StudentNumber;
    std::string ClassRecord;
  };

  std::vector<StudentRecord> RecordsCollection;

  StudentRecord make_record(std::string name, std::string surname, std::string studentNum, std::string classRec);

  void add_student(std::string name, std::string surname, std::string studentNum, std::string classRec);

  void read_database();

  void save_database();

  void display_data();

  void grade_student();
}
#endif
