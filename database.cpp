/**
* Author: Jason Smythe
* Student #: SMYJAS002
*/
#include "database.h"

namespace SMYJAS002 {
  using namespace std;

  // vector that acts as a database storring all the student records
  vector<StudentRecord> RecordsCollection;

  // populates the StudentRecord struct
  StudentRecord make_record(string name, string surname, string studentNum, string classRec)
  {
      StudentRecord ret;
      ret.Name = name;
      ret.Surname = surname;
      ret.StudentNumber = studentNum;
      ret.ClassRecord = classRec;
      cout << "you SAVED:" <<name << studentNum <<classRec<< endl;
      return ret;
  }

  // adds students to the structx
  void add_student(string name, string surname, string studentNum, string classRec){
    transform(studentNum.begin(), studentNum.end(), studentNum.begin(), ::tolower);

    RecordsCollection.push_back(make_record(name, surname, studentNum, classRec));
  }

  // reads an external .csv file into the RecordsCollection
  void read_database() {
    fstream fs;

    fs.open ("database.csv", fstream::in);
    string student;

    RecordsCollection.clear();
    while (getline(fs, student)) {
      StudentRecord record;
      istringstream ss(student);

      getline(ss, record.Name, ',');
      getline(ss, record.Surname, ',');
      getline(ss, record.StudentNumber, ',');
      getline(ss, record.ClassRecord, ',');

      RecordsCollection.push_back(record);

      cout << "Student added: " << student << endl;
    }

    cout << student << endl;
  };

  // save/backup the contents of the database into a .csv file
  void save_database() {
    fstream fs;

    cout << "saving database..." << endl;

    fs.open ("database.csv", fstream::out | fstream::trunc);

    for (StudentRecord i : RecordsCollection) {
      fs << i.Name << "," << i.Surname << "," << i.StudentNumber << "," << i.ClassRecord << endl;
    }

    fs.close();

    cout << "Your database has been backed up to the file 'database.csv'" << endl;
  };

  // display the details of a student from a givin student number
  void display_data(string studentNumber) {
    StudentRecord student = RecordsCollection[find_student(studentNumber)];
    cout << "Name:           " << student.Name << endl;
    cout << "Surname:        " << student.Surname << endl;
    cout << "Student Number: " << student.StudentNumber << endl;
    cout << "Student Record: " << student.ClassRecord << endl;
  };

  // Takes the mean of the given students class record values.
  void grade_student(string studentNumber) {
    StudentRecord student = RecordsCollection[find_student(studentNumber)];

    istringstream ss(student.ClassRecord);
    int grade;
    int count = 0;
    int total = 0;

    cout << "Your grades are: ";
    while (!ss.eof()) {
      count++;
      ss >> grade >> ws;
      cout << grade << "; " << endl;
      total += grade;
    }

    cout << "Grade average is: " << total/(double)count << endl;
  };

  // searches the vector for the given student and returns the index of the student in the vector
  // if it cannot find the student it returns -1
  int find_student(string studentNum) {
    transform(studentNum.begin(), studentNum.end(), studentNum.begin(), ::tolower);

    for (int i = 0; i < RecordsCollection.size(); i++ ) {
      if (RecordsCollection[i].StudentNumber == studentNum) {
        return i;
      }
    }

    return -1;
  }
}
