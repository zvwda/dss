#include "Graph.h"
using namespace std;


Graph::Graph()
{
}

void Graph::add_course(Course course) {
    adjacency_list[course.name] = vector<string>();
}



void Graph::add_prerequisite(Course& course, string prerequisite) {
    adjacency_list[course.name].push_back(prerequisite);
    Student::courses[course.name].add_prerequisite(prerequisite);
}

void Graph::remove_course(Course course) {
    adjacency_list.erase(course.name);

    for (auto& pair : adjacency_list) {
        vector<string>& prerequisites = pair.second;
        prerequisites.erase(remove(prerequisites.begin(), prerequisites.end(), course.name), prerequisites.end());
    }
}
void Graph::print_graph() {
    for (auto& pair : adjacency_list) {
        string course_name = pair.first;
        vector<string>& prerequisites = pair.second;
        cout << course_name << " prerequisites:";
        for (int i = 0; i < prerequisites.size(); i++) {
            cout << " " << prerequisites[i];
        }
        cout << endl;
    }
}
