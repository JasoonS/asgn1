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
      std::cout << "you SAVED:" <<name << studentNum <<classRec<< std::endl;
      return ret;
}


void SMYJAS002::add_student(std::string name, std::string surname, std::string studentNum, std::string classRec){
    RecordsCollection.push_back(make_record(name, surname, studentNum, classRec));
    std::cout << "the inserted name was: " << RecordsCollection.back().Name << std::endl;
}

void SMYJAS002::read_database() {
  std::cout << "reading database" << std::endl;
};

void SMYJAS002::save_database() {
  std::cout << "saving database" << std::endl;
  std::fstream fs;
  
  	// Delete old file (if exists) to create new file
	std::remove("database.csv");
	
  fs.open ("database.csv", std::fstream::in);

  fs << "First Name,Surname,Student Number,Class Record";
  for (StudentRecord i : RecordsCollection) {
      fs << i.Name << "," << i.Surname << "," << i.StudentNumber << "," << i.ClassRecord << std::endl;
  }

  fs.close();
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
