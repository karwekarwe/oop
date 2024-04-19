#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*struct Stud {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};*/

class Stud {
private:
  string vardas_, pavarde_;
  int egzaminas_;
  double galv_, galm_;
  vector<int> namuDarbai_;
public:
  Stud() : egzaminas_(0) { }  // default konstruktorius
  Stud(const vector <int>& namuDarbai, const string& vardas, const string& pavarde, int egzaminas, double galv, double galm)
    : namuDarbai_(namuDarbai), vardas_(vardas), pavarde_(pavarde), egzaminas_(egzaminas), galv_(galv), galm_(galm) {}
};




#endif
