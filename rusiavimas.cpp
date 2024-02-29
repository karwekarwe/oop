#include "funkcijos.h"
#include <iostream>

using namespace std;

bool rusiavimas(const Stud& a, const Stud& b, char metPas) {

    metPas = toupper(metPas);

    if (metPas == 'V') {
        return a.vardas < b.vardas;
    }
    else if (metPas == 'P') {
        return a.pavarde < b.pavarde;
    }
    else if (metPas == 'G') {
        return a.galutinis < b.galutinis;
    }
    else {
        cout << "Neteisinga įvestis." << endl;
        return false;
    }
}