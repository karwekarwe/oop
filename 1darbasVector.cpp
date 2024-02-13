#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

double vidurkis(Stud&);
double mediana(Stud&);

int main() {
    int m = 0; // studentu sk
    int balas;
    char pabaiga;

    vector<Stud> studentai;
  

    while (true) {

        Stud naujasS;

        cout << "Vardas: ";
        cin >> naujasS.vardas; //vardas i struct
        cout << "Pavarde: ";
        cin >> naujasS.pavarde; //pavarde i struct

        cout << "Namu darbu balai (-1 norint baigti): ";
        while (true) {
            cin >> balas;
            if (balas == -1){
                break;
            }
            naujasS.namuDarbai.push_back(balas);
        }

        cout << "Iveskite egzamino bala: ";
        cin >> naujasS.egzaminas; //egzaminas i struct

        studentai.push_back(naujasS); 


        cout << "Ar baigete ivesti studentus? (y/n): ";
        cin >> pabaiga;
        if (pabaiga == 'y' || pabaiga == 'Y'){
            break;
        }      
    }

    char pasirinkimas;
    cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
    cin >> pasirinkimas;

     if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Vid.)" << endl;
         cout << "--------------------------------------------" << endl;
        for (auto& studentas : studentai) {
            studentas.galutinis = vidurkis(studentas); // galutinis i struct
            cout << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
        }
    } else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Med.)" << endl;
         cout << "--------------------------------------------" << endl;
        for (auto& studentas : studentai) {
            studentas.galutinis = mediana(studentas); // galutinis i struct
            cout << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
        }
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
    }

    return 0;

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