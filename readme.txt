Cpp Assignment 1: Jason Smythe: SMYJAS002

This assignment features all the features requested in the assignment document:

-------------Build & Run -------------------

Start the build and run by simply typing 'make' or 'make install.
	'make clean' deletes everything but the source files.
	'make driver' builds an executable that can be run using the command './driver'
	
While the program is running options 1-5 and 9 (to exit) can be typed into the keyboard.
	Incorrect imput is an edge case that is tested for (please try input something that is not an
	integer or a valid number to test this.



-------------functionality--------------	

Add Student prevents duplication of student data.

Read database reads data into the vector (database) from a file in .csv format
	the format is 'first name(s),surname,student number,class record'
	
Save database backs up the contents of the vector (database) into a .csv file format
	of the same form as in the previous comment. 
	NOTE: this is more a backup functionality, as the opperation of the database only 
		concerns the contents of the vector when searching, grading student, etc.
		
Student details finds a student according to student number and  displays his data.

Grade student, finds class record of a given student number and returns his class average.
