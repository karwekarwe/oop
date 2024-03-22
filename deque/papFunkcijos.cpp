#include "funkcijos.h"
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

    
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

    bool rusiavimas(const Stud& a, const Stud& b, char metPas) {

try {
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
            throw std::invalid_argument("Neteisinga įvestis.");
        }
    } 
    catch (const std::invalid_argument& e) {
        cerr << e.what() << endl;
        return false;
    }
}
