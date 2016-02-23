/**
*.cpp file:
*/
#include "database.h"

SMYJAS002::StudentRecord SMYJAS002::make_record(std::string name, std::string surname, std::string studentNum, std::string classRec)
{
      StudentRecord ret;
      ret.Name = name;
      ret.Surname = surname;
      ret.StudentNumber = studentNum;
      ret.ClassRecord = classRec;
      return ret;
}


void SMYJAS002::add_student(std::string name){
    RecordsCollection.push_back(make_record(name, "bla", "blab", "blabla"));
    std::cout << "the inserted name was: " << RecordsCollection.back().Name << std::endl;
}

void SMYJAS002::read_database() {
  std::cout << "reading database" << std::endl;
};

void SMYJAS002::save_student() {
  std::cout << "reading database" << std::endl;
};

void SMYJAS002::display_data() {
  std::cout << "displaying data" << std::endl;
  for (StudentRecord i : RecordsCollection) {
      std::cout << i.Name;
  }
};

void SMYJAS002::grade_student() {
  std::cout << "reading database" << std::endl;
};
