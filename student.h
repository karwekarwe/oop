#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Stud {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

#endif