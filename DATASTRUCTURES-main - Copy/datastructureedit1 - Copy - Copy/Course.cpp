#include"Course.h"


Course::Course() {
    this->name = "";
    this->requirement_or_elective = true;
    this->code = 0000;
    this->max_num_std = 20;
    this->hours = 2;
    this->instructor = "";
}
Course::Course(string name, int code, bool requirement_or_elective, int max_num_std, double hours, string instructor) {
    this->name = name;
    this->code = code;
    this->requirement_or_elective = requirement_or_elective;
    this->max_num_std = max_num_std;
    this->hours = hours;
    this->instructor = instructor;
}



void Course::add_prerequisite(string prerequisite) {
    prerequisites.push_back(prerequisite);
}



void Course::print_prerequisites() {
    cout << "Prerequisites for " << name << ":" << endl;
    for (int i = 0; i < prerequisites.size(); i++) {
        cout << "- " << prerequisites[i] << endl;
    }
}

