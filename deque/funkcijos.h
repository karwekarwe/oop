#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "student.h"

bool rusiavimas(const Stud& a, const Stud& b, char metPas);
double vidurkis(Stud&);
double mediana(Stud&);
void isFailo(const std::string& failPav, std::deque<Stud>& studentai);
void failuGen(const std::string& failPav, int numRecords);
void rusiavimasGen(const std::string& failPav, std::deque<Stud>& studentai);


#endif 
