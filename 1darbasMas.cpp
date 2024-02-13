#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    int *namuDarbai;
    int ndCount;
    int egzaminas;
    double galutinis;
};

double vidurkis(Stud&);
double mediana(Stud&);

int main() {
    int m = 0; // studentu sk
    int n = 0; // namu darbu sk
    int balas;
    char pabaiga;

    Stud *studentai = new Stud[100];
    int *tempND = new int[100];

    while (true) {
        cout << "Vardas: ";
        cin >> studentai[m].vardas; //vardas i struct
        cout << "Pavarde: ";
        cin >> studentai[m].pavarde; //pavarde i struct

        cout << "Namu darbu balai (-1 norint baigti): ";
        while (true) {
            cin >> balas;
            if (balas == -1){
            break;
            }
            tempND[n++] = balas;
        }
        studentai[m].namuDarbai = tempND; //nd array i struct
        studentai[m].ndCount = n;

        cout << "Iveskite egzamino bala: ";
        cin >> studentai[m].egzaminas; //egzaminas i struct

        m++;
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
        for (int i = 0; i < m; ++i) {
            studentai[i].galutinis = vidurkis(studentai[i]); // galutinis i struct
            cout << setw(20) << left << studentai[i].vardas << setw(20) << left << studentai[i].pavarde << setw(10) << right << fixed << setprecision(2) << studentai[i].galutinis << endl;
        }
    } else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Med.)" << endl;
         cout << "--------------------------------------------" << endl;
        for (int i = 0; i < m; ++i) {
            studentai[i].galutinis = mediana(studentai[i]); // galutinis i struct
            cout << setw(20) << left << studentai[i].vardas << setw(20) << left << studentai[i].pavarde << setw(10) << right << fixed << setprecision(2) << studentai[i].galutinis << endl;
        }
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
    }

    delete[] tempND;
    delete[] studentai;
}


    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
        for (int i =0; i < s.ndCount; i++) {
            suma+= s.namuDarbai[i];
        }
        avg = suma / s.ndCount;
        gal = avg*0.4 + s.egzaminas*0.6;

        return gal;
    }

    double mediana (Stud& s) {
        double med = 0;
        double gal;
        sort(s.namuDarbai, s.namuDarbai+s.ndCount);
        if (s.ndCount % 2 == 0) {
            med = (s.namuDarbai[s.ndCount / 2 - 1] + s.namuDarbai[s.ndCount / 2]) / 2;
        }
        else {
            med = s.namuDarbai[s.ndCount / 2];
        }
        gal = med*0.4 + s.egzaminas*0.6;

        return gal;
    }