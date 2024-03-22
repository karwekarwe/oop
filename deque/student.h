#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <deque>

struct Stud {
    std::string vardas;
    std::string pavarde;
    std::deque<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

#endif
