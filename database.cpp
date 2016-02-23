/**
*.cpp file:
*/
#include "database.h"

void SMYJAS002::add_student(std::string name){

    RecordsCollection.push_back(StudentRecord());
    RecordsCollection.back().Name = name;
    std::cout << "the inserted name was: " << RecordsCollection.back().Name << std::endl;
}

void SMYJAS002::read_database() {
  std::cout << "reading database" << std::endl;
};

void SMYJAS002::save_student() {
  std::cout << "reading database" << std::endl;
};

void SMYJAS002::display_data() {
  std::cout << "reading database" << std::endl;
};

void SMYJAS002::grade_student() {
  std::cout << "reading database" << std::endl;
};
