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
#include"Graph.h"
using namespace std;
class Student {



public:

    static unordered_map<string, Course> courses;
    static unordered_map<int, Student> students;

    string name;
    string email;
    int id;
    string password;
    int max_hours_allowed;
    set<string>finished_courses;
    set<double> gradesfor_finished_courses;
    set<string>inprogress_courses;
    vector<string>checkprereq;
    string academic_year;
    float gpa;
    int studCount = 0;
    Student();
    Student(string name, int id, string password, int max_hours_allowed, set<string>finished_courses, set<double> gradesfor_finished_courses, set<string>inprogress_courses, string academic_year);
    bool login(string email, int id, string input_password);
    void View_List_of_all_available_courses(Student s);
    void filter_courses(Student s);
    void viewDetailsOfSpecificCourse(Course c);
    void edit_data(Student s);
    void viewAllCourses(Student s);
    void registerCourse(Student s, Course c);
    double get_course_credit_hours(string course_name);
    void get_cumulative_gpa(Student s);
    void print_finished_course_grades(Student s);
};