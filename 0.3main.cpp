#include <iostream>
#include <vector>


#include "student.h"
#include "funkcijos.h"


using namespace std;



int main() {

    vector<Stud> studentai;
    char pasirinkimas;

    cout << "Pasirinkite, kaip norite ivesti duomenis: \n 1. Ranka \n 2. Is failo\n";
    cin >> pasirinkimas;

    if (pasirinkimas == '1') {
        ranka(studentai);
    } else if (pasirinkimas == '2') {
        isFailo(studentai);
    } else {
        cout << "Netinkamas pasirinkimas. Programa baigia darba.\n";
        return 1;
    }

    return 0;
}
