#include "admin.h"

Admin::Admin(string name, string password)
{
	this->name = name;
	this->password = password;
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::add_student(string name, int id, string password, int max_hours_allowed, set<string>finished_courses, set<double> gradesfor_finished_courses, set<string>inprogress_courses, string academic_year) {

	Student student(name, id, password, max_hours_allowed, finished_courses, gradesfor_finished_courses, inprogress_courses, academic_year);
	student.name = name;
	student.id = id;
	student.email = to_string(id) + "@cis.asu.edu.eg"; // auto-generated email
	student.password = password;
	student.max_hours_allowed = max_hours_allowed;
	student.academic_year = academic_year;
	//have to put fun outo here 
	student.gpa = 0.0;

	Student::students[id] = student;
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::add_new_course(Course c)
{
	Graph g;
	g.add_course(c);
	Student::courses[c.name] = c;

}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::remove_course(Course c)
{

	Graph g;
	g.remove_course(c);
	Student::courses.erase(c.name);

}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::Enter_course_prerequisite(Course c, string nameofprereq)
{
	Graph g;
	g.add_prerequisite(c, nameofprereq);
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::viewListOfStudCourses(Student x) {
	set<string> ::iterator inprog;
	for (inprog = x.inprogress_courses.begin(); inprog != x.inprogress_courses.end(); inprog++) {
		cout << *inprog << endl;

	}
	set<string> ::iterator finished;
	for (finished = x.finished_courses.begin(); finished != x.finished_courses.end(); finished++) {
		cout << *finished << endl;

	}
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::View_List_of_all_students_in_a_specific_course(Course c)
{
	bool flag = false;
	//to loop on map of student 
	for (auto it = Student::students.begin(); it != Student::students.end(); ++it) {
		//to loop on finishid courses on each std
		for (auto jt = it->second.finished_courses.begin(); jt != it->second.finished_courses.end(); ++jt) {
			if (c.name == *jt) {
				flag = true;
				break;
			}
			if (flag == true) {
				cout << " " << it->second.name << "  ";
			}
		}
	}
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
bool Admin::adminLogin(string input_name, string input_password)
{
	for (Admin x : admins)
	{
		if (input_name == x.name && input_password == x.password) {
			cout << "Login successful. Welcome, " << x.name << "!" << endl;
			return true;
		}
	}
	cout << "Invalid login . Please try again." << endl;
	cout << "1- try again " << endl;
	cout << "2- break " << endl;

	return false;
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::addcoursegrade(Student x) {

	set<string>::iterator it;

	for (it = x.finished_courses.begin(); it != x.finished_courses.end(); it++) {

		double grade = 0;
		cout << "Enter grade of " << *it << endl;
		cin >> grade;
		x.gradesfor_finished_courses.insert(grade);

	}
}
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void Admin::editCourseData(Course c) {
	cout << "Enter the new course name: " << endl;
	cin >> c.name;
	cout << "Enter the new course code: " << endl;
	cin >> c.code;
	cout << "Is it required or elective?" << endl << "Type 1 for required or 2 for elective " << endl;
	while (true) {

		int flag;
		cout << "if requirment enter 1 if elective enter 2" << endl;
		cin >> flag;
		if (flag == 1) {
			c.requirement_or_elective = true;
			break;
		}
		else if (flag == 2) {
			c.requirement_or_elective = false;
			break;
		}
		else continue;
	}


	cout << "Enter the maximum number of studients allowed to have the course " << endl;
	cin >> c.max_num_std;
	cout << "Enter the course hours: " << endl;
	cin >> c.hours;
	cout << "Enter the new instructor's name: " << endl;
	cin >> c.name;

}

