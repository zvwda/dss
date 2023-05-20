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

using namespace std;

class Course
{
public:

    string name;
    int code;
    bool requirement_or_elective;
    int max_num_std;
    double hours;
    string instructor;
    vector<string> prerequisites;
    int CourseCount = 0;
    Course();
    Course(string name, int code, bool requirement_or_elective, int max_num_std, double hours, string instructor);
    void add_prerequisite(string prerequisite);
    void print_prerequisites();

};