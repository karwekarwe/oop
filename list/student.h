#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>

struct Stud {
    std::string vardas;
    std::string pavarde;
    std::list<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

#endif
