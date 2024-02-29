#include <iostream>
#include <vector>
#include <algorithm>

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

    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
        for (int balas : s.namuDarbai) {
            suma+= balas;
        }
        avg = suma / s.namuDarbai.size();
        
        gal = avg*0.4 + s.egzaminas*0.6;

        return gal;
    }

    double mediana (Stud& s) {
        double med = 0;
        double gal;
        sort(s.namuDarbai.begin(), s.namuDarbai.end());
        if (s.namuDarbai.size() % 2 == 0) {
            med = (s.namuDarbai[s.namuDarbai.size() / 2 - 1] + s.namuDarbai[s.namuDarbai.size() / 2]) / 2.0;
        }
        else {
            med = s.namuDarbai[s.namuDarbai.size() / 2];
        }
        gal = med*0.4 + s.egzaminas*0.6;

        return gal;
    }