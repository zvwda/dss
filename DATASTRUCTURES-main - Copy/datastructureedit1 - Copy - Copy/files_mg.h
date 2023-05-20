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

using namespace std;

class files_mg
{
public:
	void save_course_data_into_files();
	void save_std_data_into_files();
	void load_coarse_data_from_files();
	void load_std_data_from_files();

};

