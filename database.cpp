/**
*.cpp file:
*/
#include "database.h"


namespace SMYJAS002 {
	using namespace std;
	StudentRecord make_record(std::string name, std::string surname, std::string studentNum, std::string classRec)
	{
		  StudentRecord ret;
		  ret.Name = name;
		  ret.Surname = surname;
		  ret.StudentNumber = studentNum;
		  ret.ClassRecord = classRec;
		  std::cout << "you SAVED:" <<name << studentNum <<classRec<< std::endl;
		  return ret;
	}


	void add_student(std::string name, std::string surname, std::string studentNum, std::string classRec){
		// Convert the student number to lowwer case as standard.
		transform(studentNum.begin(), studentNum.end(), studentNum.begin(), ::tolower);
		
		RecordsCollection.push_back(make_record(name, surname, studentNum, classRec));
	}

	void read_database() {
		fstream fs;
		
		fs.open ("database.csv", std::fstream::in);
		string student;
		
		//~ getline(fs, student);
		
		//~ cout << "boolean value of while" << (!fs.eof())
		RecordsCollection.clear();
		while (getline(fs, student)) {
			StudentRecord record;
			istringstream ss(student);
			
			getline(ss, record.Name, ',');
			getline(ss, record.Surname, ',');
			getline(ss, record.StudentNumber, ',');
			getline(ss, record.ClassRecord, ',');
			
			RecordsCollection.push_back(record);
			
			//~ while (getline(ss, studentDetail, ',')) {
				//~ cout << "~~ " << studentDetail << "~~" <<endl;
			//~ }
			cout << "Student, added: " << student << endl;
		}
		
		cout << student << endl;
		
	  std::cout << "reading database" << std::endl;
	};

	void save_database() {
		fstream fs;
		
	  std::cout << "saving database" << std::endl;
		
	  fs.open ("database.csv", fstream::out | fstream::trunc);

	  //~ fs << "First Name,Surname,Student Number,Class Record" << endl;
	  for (StudentRecord i : RecordsCollection) {
		  fs << i.Name << "," << i.Surname << "," << i.StudentNumber << "," << i.ClassRecord << std::endl;
	  }

	  fs.close();
	};

	void display_data(string studentNumber) {
	  std::cout << "Records in database" << std::endl;
	  StudentRecord student = RecordsCollection[find_student(studentNumber)];
	  //~ for (StudentRecord i : RecordsCollection) {
		  cout << "Name:           " << student.Name << endl;
		  cout << "Surname:        " << student.Surname << endl;
		  cout << "Student Number: " << student.StudentNumber << endl;
		  cout << "Student Record: " << student.ClassRecord << endl;
	  //~ }
	};

	void grade_student(string studentNumber) {
	  std::cout << "reading database" << std::endl;
	  StudentRecord student = RecordsCollection[find_student(studentNumber)];
	  
	  istringstream ss(student.ClassRecord);
	  int grade;
	  int count = 0;
	  int total = 0;
	  
	  //~ ss >> itemCal>> ws;
		while (!ss.eof()) {
			count++;
			ss >> grade >> ws;
			cout << "Your grade is: " << grade << endl;
			total += grade;
		}

		cout << "Grade average is: " << total/(double)count << endl;
	};

	int find_student(std::string studentNum) {
		transform(studentNum.begin(), studentNum.end(), studentNum.begin(), ::tolower);
		
		for (int i = 0; i < RecordsCollection.size(); i++ ) {
			if (RecordsCollection[i].StudentNumber == studentNum) {
				cout << "you found the student: " << i << " : " << RecordsCollection[i].StudentNumber << endl;
				return i;
			}
		}
		
		return -1;
	}
}
