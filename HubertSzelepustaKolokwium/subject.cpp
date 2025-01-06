//
// Created by Hubert on 13.12.2024.
//

#include "subject.h"

subject::subject() {
}

subject::subject(long id, string subject_name, string teacher, int ects, int amount_of_lessons) {
    this->id=id;
    this->subject_name=subject_name;
    this->teacher=teacher;
    this->ects=ects;
    this->amount_of_lessons=amount_of_lessons;
}

void subject::setId(long id) {
    this->id=id;
}

void subject::setSubject_name(string subject_name) {
    this->subject_name=subject_name;
}

void subject::setTeacher(string teacher) {
    this->teacher=teacher;
}

void subject::setEcts(int ects) {
    this->ects=ects;
}

void subject::setAmount_of_lessons(int amount_of_lessons) {
    this->amount_of_lessons=amount_of_lessons;
}

long subject::getId() {
    return id;
}

string subject::getSubject_name() {
    return subject_name;
}

string subject::getTeacher() {
    return teacher;
}

int subject::getEcts() {
    return ects;
}

int subject::getAmount_of_lessons() {
    return amount_of_lessons;
}

bool subject::operator<(const subject &others) const {
    return this->id<others.id;
}
