#include "Student.h"

template<>
void Student<int>::showMark() {
    cout << "Twoja ocena int to: " << mark << endl;
}
template<>
void Student<float>::showMark() {
    cout << "Twoja ocena int to: " << mark << endl;
}
