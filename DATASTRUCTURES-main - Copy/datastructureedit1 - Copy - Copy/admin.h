#pragma once
#include <iostream>
#include <vector>
#include<list>
#include<set>   
#include<sstream>
#include<fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include"Course.h"
#include"Student.h"
#include"Graph.h"


using namespace std;

class Admin
{
    string name;
    string password;
public:
    vector<Admin>admins;
    Admin(string name, string password);

    void add_student(string name, int id, string password, int max_hours_allowed, set<string>finished_courses, set<double> gradesfor_finished_courses, set<string>inprogress_courses, string academic_year);
    void add_new_course(Course c);
    void remove_course(Course c);
    void Enter_course_prerequisite(Course c, string nameofprereq);
    void addcoursegrade(Student x);
    void editCourseData(Course c);
    void viewListOfStudCourses(Student x);
    void View_List_of_all_students_in_a_specific_course(Course c);
    bool adminLogin(string input_name, string input_password);

};