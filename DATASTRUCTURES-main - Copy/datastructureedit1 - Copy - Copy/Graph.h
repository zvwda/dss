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
#include"course.h"
#include"Student.h"

using namespace std;


class Graph
{
public:
	unordered_map<string, vector<string>> adjacency_list;
	Graph();
	void add_course(Course course);
	void add_prerequisite(Course& course, string prerequisite);
	void remove_course(Course course);
	void print_graph();
};



