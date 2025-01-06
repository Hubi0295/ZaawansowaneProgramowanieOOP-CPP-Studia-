//
// Created by Hubert on 13.12.2024.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>

using namespace std;
class subject {
private:
    long id;
    string subject_name;
    string teacher;
    int ects;
    int amount_of_lessons;
public:
    subject();
    subject(long id, string subject_name, string teacher, int ects, int amount_of_lessons);
    void setId(long id);
    void setSubject_name(string subject_name);
    void setTeacher(string teacher);
    void setEcts(int ects);
    void setAmount_of_lessons(int amount_of_lessons);
    long getId();
    string getSubject_name();
    string getTeacher();
    int getEcts();
    int getAmount_of_lessons();
    bool operator<(const subject &others) const;
};



#endif //SUBJECT_H
