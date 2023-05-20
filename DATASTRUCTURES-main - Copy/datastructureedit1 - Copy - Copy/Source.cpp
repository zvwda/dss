#include"files_mg.h"
#include"admin.h"
#include "Source.h"

using namespace std;


void main() {
    files_mg f;
    f.load_coarse_data_from_files();
    f.load_std_data_from_files(); 
    Admin admin1("ziad", "Alibaba123");
    admin1.admins.push_back(admin1);
    Student s;
    while (true)
    {
        cout << "---Welcome to the ain shams University Management System!---" << endl;
        // Prompt the user to select their role
        cout << "Are you a student or an admin?\n";
        cout << "1. Student\n";
        cout << "2. Admin\n";
        int choice;
        cin >> choice;
        system("cls");
        if (choice == 2) {
            while (true)
            {
                string adminname, adminpassword;
                cout << "enter your name " << endl;
                cin >> adminname;
                cout << " enter your pssword " << endl;
                cin >> adminpassword;

                if (admin1.adminLogin(adminname, adminpassword) == true) {
                    while (true)
                    {
                        int choise_what_admin_want_to_do;
                        system("cls");
                        cout << "1- Add new student " << endl;
                        cout << "2- Add a new course." << endl;
                        cout << "3- Enter course prerequisite." << endl;
                        cout << "4- View List of all students in a specific course." << endl;
                        cout << "5- Add course grade for each student." << endl;
                        cout << "6- View List of all courses(Finished - Progressed) of a specific student." << endl;
                        cout << "7- Edit all course data." << endl;
                        cout << "8- to exit." << endl;

                        cin >> choise_what_admin_want_to_do;
                        if (choise_what_admin_want_to_do == 1) {
                            string name;
                            cout << "enter his name " << endl;
                            cin >> name;
                            int id;
                            cout << " enter his id " << endl;
                            cin >> id;
                            string password;
                            cout << " enter his password " << endl;
                            cin >> password;
                            int max_hours_allowed;
                            cout << " enter his max hours allowed " << endl;
                            cin >> max_hours_allowed;
                            set<string>finished_courses;
                            cout << " enter number of his finished courses " << endl;
                            int numoffinished;
                            cin >> numoffinished;
                            cout << "enter his finished courses " << endl;
                            for (int i = 0; i < numoffinished; i++) {
                                string c;
                                cin >> c;
                                finished_courses.insert(c);
                            }
                            set<double> gradesfor_finished_courses;
                            cout << "enter his grades for finished courses " << endl;
                            for (int i = 0; i < numoffinished; i++) {
                                double c;
                                cin >> c;
                                gradesfor_finished_courses.insert(c);
                            }
                            set<string>inprogress_courses;
                            cout << " enter number of his inprogress courses " << endl;
                            int numofinprogress;
                            cin >> numofinprogress;
                            cout << "enter his inprogress courses " << endl;
                            for (int i = 0; i < numofinprogress; i++) {
                                string c;
                                cin >> c;
                                inprogress_courses.insert(c);
                            }
                            string academic_year;
                            cout << " enter number of his academic year " << endl;
                            cin >> academic_year;
                            admin1.add_student(name, id, password, max_hours_allowed, finished_courses, gradesfor_finished_courses, inprogress_courses, academic_year);
                        }
                        if (choise_what_admin_want_to_do == 2) {
                            string name;
                            cout << "enter his name " << endl;
                            cin >> name;
                            int code;
                            cout << "enter his code " << endl;
                            cin >> code;
                            bool requirement_or_elective{};
                            cout << "if requirment enter 1 if elective enter 2" << endl;
                            int test;
                            cin >> test;
                            if (test == 1) {
                                requirement_or_elective = true;
                            }
                            else if (test == 2) {
                                requirement_or_elective = false;
                            }
                            int max_num_std;
                            cout << "enter his max num of student  " << endl;
                            cin >> max_num_std;
                            double hours;
                            cout << "enter his hourse " << endl;
                            cin >> hours;
                            string instructor;
                            cout << "enter his name of instractor " << endl;
                            cin >> instructor;
                            Course c(name, code, requirement_or_elective, max_num_std, hours, instructor);
                            admin1.add_new_course(c);
                        }
                        if (choise_what_admin_want_to_do == 3) {
                            cout << " enter name of course" << endl;
                            string coursename;

                            cin >> coursename;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (coursename == it->first) {
                                    c = it->second;
                                    cout << "it is found" << endl;
                                }
                            }
                            cout << "enter number of prerequisite you want to add to " << c.name << endl;
                            int num;
                            cin >> num;
                            cout << " enter prerequisite you want to add" << endl;
                            for (int i = 0; i < num; i++)
                            {
                                string name;
                                cin >> name;
                                admin1.Enter_course_prerequisite(c, name);

                            }

                        }
                        if (choise_what_admin_want_to_do == 4) {
                            cout << "enter name of course to View List of all students in it" << endl;
                            string name;
                            cin >> name;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (name == it->first) {
                                    c = it->second;
                                    cout << "it is found" << endl;
                                }

                            }
                            admin1.View_List_of_all_students_in_a_specific_course(c);
                            cout << "enter sn" << endl;
                            int id;
                            cin >> id;
                        }
                        if (choise_what_admin_want_to_do == 5) {
                            cout << " enter student id " << endl;
                            int id;
                            cin >> id;
                            Student s;
                            for (auto it = Student::students.begin(); it != Student::students.end(); ++it) {
                                if (id == it->first) {
                                    s = it->second;
                                    cout << "it is found" << endl;
                                }
                            }
                            admin1.addcoursegrade(s);
                        }
                        if (choise_what_admin_want_to_do == 6) {
                            cout << "enter student id " << endl;
                            int id;
                            cin >> id;
                            Student s;
                            for (auto it = Student::students.begin(); it != Student::students.end(); ++it) {
                                if (id == it->first) {
                                    s = it->second;
                                    cout << "it is found" << endl;
                                }
                            }
                            admin1.viewListOfStudCourses(s);
                            int v;
                            cout << "press any number" << endl;
                            cin >> v;
                        }
                        if (choise_what_admin_want_to_do == 7) {
                            cout << "enter name of course to edit" << endl;
                            string name;
                            cin >> name;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (name == it->first) {
                                    c = it->second;
                                    cout << "it is found" << endl;
                                }
                            }
                            admin1.editCourseData(c);
                        }
                        if (choise_what_admin_want_to_do == 8) {
                            break;
                        }
                    }
                    break;
                }
                else {
                    int out_or_try_again;
                    cin >> out_or_try_again;
                    if (out_or_try_again == 1) {
                        continue;
                    }
                    else if (out_or_try_again == 2) {
                        break;

                    }
                }
            }
            cout << "1- back " << endl;
            cout << "2- exit" << endl;
            int testcho;
            cin >> testcho;
            if (testcho == 1) {
                continue;
            }
            else if (testcho == 2)
            {
                break;
            }
        }
        //---------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------
        else if (choice == 1) {
            while (true)
            {
                string email;
                cout << "enter your email " << endl;
                cin >> email;
                int id;
                cout << "enter your id " << endl;
                cin >> id;
                string password;
                cout << " enter your password " << endl;
                cin >> password;
                if (s.login(email, id, password) == true) {
                    while (true)
                    {
                        int choise_what_std_want_to_do;
                        system("cls");
                        cout << "1- View List of all available courses" << endl;
                        cout << "2- Filter courses" << endl;
                        cout << "3- View details of a specific course." << endl;
                        cout << "4- Register for a course." << endl;
                        cout << "5- View all his/her courses." << endl;
                        cout << "6- View his/her courses grades and cumulative GPA" << endl;
                        cout << "7- Edit his/her data." << endl;
                        cout << "8- to exit." << endl;
                        cin >> choise_what_std_want_to_do;

                        if (choise_what_std_want_to_do == 1) {
                            s.View_List_of_all_available_courses(Student::students[id]);
                            cout << "sd";
                            int ifd;
                            cin >> ifd;
                        }
                        if (choise_what_std_want_to_do == 2) {
                            s.filter_courses(Student::students[id]);
                        }
                        if (choise_what_std_want_to_do == 3) {
                            cout << " enter name of course " << endl;
                            string namecourse;
                            cin >> namecourse;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (namecourse == it->first) {
                                    c = it->second;
                                }
                            }
                            s.viewDetailsOfSpecificCourse(c);
                            cout << "press any number to back " << endl;
                            int n;
                            cin >> n;
                        }
                        if (choise_what_std_want_to_do == 4) {
                            cout << " enter name of course " << endl;
                            string coursename;
                            cin >> coursename;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (coursename == it->first) {
                                    c = it->second;
                                    cout << "found" << endl;
                                }
                            }
                            s.registerCourse(Student::students[id], c);
                            cout << "press any number to back " << endl;
                            int n;
                            cin >> n;
                        }
                        if (choise_what_std_want_to_do == 5) {
                            s.viewAllCourses(Student::students[id]);
                            cout << "press any number to back " << endl;
                            int n;
                            cin >> n;
                        }
                        if (choise_what_std_want_to_do == 6) {
                            s.print_finished_course_grades(Student::students[id]);
                            s.get_cumulative_gpa(Student::students[id]);
                            int e;
                            cin >> e;
                        }
                        if (choise_what_std_want_to_do == 7) {
                            s.edit_data(Student::students[id]);
                            int n;
                            cin >> n;

                        }
                        if (choise_what_std_want_to_do == 8) {
                            break;
                        }
                    }
                    break;
                }
                else {
                    int out_or_try_again;
                    cin >> out_or_try_again;
                    if (out_or_try_again == 1) {
                        continue;
                    }
                    else if (out_or_try_again == 2) {
                        break;

                    }
                }
            }
                cout << "1- back " << endl;
                cout << "2- exit" << endl;
                int testcho;
                cin >> testcho;
                if (testcho == 1) {
                    continue;
                }
                else if (testcho == 2)
                {
                    break;
                }
            }
        }
        f.save_course_data_into_files();
        f.save_std_data_into_files();
        
 }


