/**
* Author: Jason Smythe
*/

#include <iostream>
// TODO: use extern, use database.h rather than *.cpp
#include "database.cpp"

int main() {
  using namespace std;
  using namespace SMYJAS002;

  int selection;
  // string name;

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
    // TODO: add error handling if not an int
    cin >> selection;

    cout << "your selection was: " << selection << endl;

    std::string name;
    std::string price;
    std::string mystr;
    std::string s;
    switch(selection){
    case 1 :
      // cin >> name;
      // cout << "tried to get the whole line: " << name << endl;
    // if ( selection == 1 ) {
      // std::cout << "Enter string:" << flush;
      // std::getline(std::cin, name);
      std::cout << "Enter string:";
      cin.get();
      std::getline(std::cin, s);
      // std::getline(std::cin, s);
      std::cout << "the string was: " << s << std::endl << flush;
      // std::cout << "the string was: " << name << std::endl;
      std::cout << "!!!!!!!!!!!!!!!!!!------------!!!!!!!!!!!!!!!!!" << std::endl;
      add_student("jason");
    // }
      break;
    case 2 :
      read_database();
      break;
    case 3 :
       save_student();
       break;
    case 4 :
      display_data();
      break;
    case 5 :
       grade_student();
       break;
    case 9 :
      goto stoprun;
    default :
      cout << selection << "was not a valid option, please try again" << endl;
    }
  }

  //used as a goto, to break out of io loop
  stoprun:

  return 0;
}
