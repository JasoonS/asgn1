/**
* Author: Jason Smythe
* Student #: SMYJAS002
*/

#include <iostream>
#include "database.h"

int main() {
  using namespace std;
  using namespace SMYJAS002;

  int selection;

  cout << "Please click the corresponding number." << endl;


  // user input loop
  for (;;) {
    cout << "1) add student" << endl;
    cout << "2) read database" << endl;
    cout << "3) save database" << endl;
    cout << "4) display given student data" << endl;
    cout << "5) grade student" << endl;
    cout << "9) exit the program" << endl;

    cout << "Please select an option : ";

  // error checking on user input.
  while (!(cin >> selection)) {
    // first 'clear' the error, then 'ignore' the input.
    cin.clear();
    string selectedWrong;
    cin >> selectedWrong;
    cout << "We don't have " << selectedWrong << " as an option. Please, try again: ";
    cin.ignore(10000, '\n');
  }

    string name;
    string surname;
    string studentNum;
    string classRecord;

    switch(selection){
    case 1 :
      std::cout << "Enter student's first name(s):";
      cin.get();
      getline(cin, name);
      std::cout << "Enter student's your surname:";
      getline(cin, surname);
      std::cout << "Enter student's student number:";
      getline(cin, studentNum);
      // prevent enteringing two students with the same sutdent number.
      while(find_student(studentNum) != -1) {
        cout << "That student number is already in the database. Please input correctly." << endl;
        std::cout << "Enter student's student number:";
        getline(cin, studentNum);
      }
      std::cout << "Enter student's class record:";
      getline(cin, classRecord);
      std::cout << "you SAVED:" <<name << studentNum <<classRecord<< std::endl;
      add_student(name, surname, studentNum, classRecord);
      break;
    case 2 :
      read_database();
      break;
    case 3 :
       save_database();
       break;
    case 4 :
      std::cout << "Enter student's student number:";
      cin.get();
      getline(cin, studentNum);
      display_data(studentNum);
      break;
    case 5 :
      std::cout << "Enter student's student number:";
      cin.get();
      getline(cin, studentNum);
      grade_student(studentNum);
       break;
    case 9 :
      // used to break out of the loop.
      goto stoprun;
    default :
      cout << selection << " was not a valid option, please try again" << endl;
      break;
    }
  }

  //used as a goto, to break out of io loop
  stoprun:

  return 0;
}
