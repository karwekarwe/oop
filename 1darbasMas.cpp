#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    int *namuDarbai;
 // int ndCount;
    int egzaminas;
    double galutinis;
};

int main() {
    int studSk = 0;
    int balas, temNDCount;
    char pabaiga;


    Stud *studentai = nullptr;

    while (true) {
        cout << "Vardas: ";
        cin >> studentai[studSk].vardas; //vardas
        cout << "Pavarde: ";
        cin >> studentai[studSk].pavarde; //pavarde

        cout << "Namu darbu balai (-1 norint baigti): ";

        int *tempND = new int[100]; 

        while (true) {
            cin >> balas;
            if (balas == -1){
            break;
            }
            tempND[temNDCount++] = balas;
        }
        studentai[studSk].namuDarbai = tempND; //nd array


        cout << "Iveskite egzamino bala: ";
        cin >> studentai[studSk].egzaminas; //egzaminas


        studSk++;
        cout << "Ar baigete ivesti studentus? (y/n): ";
        cin >> pabaiga;
        if (pabaiga == 'y' || pabaiga == 'Y'){
            break;
        }

    delete tempND;
    }





    delete studentai;
}

/*int main() {
    int studentuSkaicius = 0;
    int namuDarbuSkaicius = 0;

    // Studentų masyvas
    Studentas *studentai = nullptr;

    // Duomenų įvedimas
    string vardas, pavarde;
    int balas;
    char baigti;
    while (true) {
        cout << "Iveskite studento varda: ";
        cin >> vardas;
        cout << "Iveskite studento pavarde: ";
        cin >> pavarde;
        cout << "Iveskite namu darbu balus (-1 norint baigti): ";
        int *tempNamuDarbai = new int[100]; // Pakeičiam namų darbų dydį
        int tempNamuDarbaiKiekis = 0;
        while (true) {
            cin >> balas;
            if (balas == -1) {
                break;
            }
            tempNamuDarbai[tempNamuDarbaiKiekis++] = balas;
        }
        cout << "Iveskite egzamino bala: ";
        cin >> balas;

        // Pridedame naują studentą į masyvą
        Studentas *tempStudentai = new Studentas[studentuSkaicius + 1];
        for (int i = 0; i < studentuSkaicius; ++i) {
            tempStudentai[i] = studentai[i];
        }
        tempStudentai[studentuSkaicius].vardas = vardas;
        tempStudentai[studentuSkaicius].pavarde = pavarde;
        tempStudentai[studentuSkaicius].namuDarbai = tempNamuDarbai;
        tempStudentai[studentuSkaicius].namuDarbaiKiekis = tempNamuDarbaiKiekis;
        tempStudentai[studentuSkaicius].egzaminas = balas;

        delete[] studentai;
        studentai = tempStudentai;
        ++studentuSkaicius;

        cout << "Ar baigete ivesti studentus? (y/n): ";
        cin >> baigti;
        if (baigti == 'y' || baigti == 'Y') {
            break;
        }
    }

    // Pasirinkimas dėl galutinio balo skaičiavimo metodo
    char pasirinkimas;
    cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
    cin >> pasirinkimas;

    // Skaičiavimas ir išvedimas
    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Vid.)" << endl;
        cout << string(50, '-') << endl;
        for (int i = 0; i < studentuSkaicius; ++i) {
            studentai[i].galutinis = vidurkis(studentai[i]);
            cout << setw(20) << left << studentai[i].vardas << setw(20) << left << studentai[i].pavarde << setw(10) << right << fixed << setprecision(2) << studentai[i].galutinis << endl;
        }
    } else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Med.)" << endl;
        cout << string(50, '-') << endl;
        for (int i = 0; i < studentuSkaicius; ++i) {
            studentai[i].galutinis = mediana(studentai[i]);
            cout << setw(20) << left << studentai[i].vardas << setw(20) << left << studentai[i].pavarde << setw(10) << right << fixed << setprecision(2) << studentai[i].galutinis << endl;
        }
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
    }

    // Atlaisvinamas naudojamas atmintis
    for (int i = 0; i < studentuSkaicius; ++i) {
        delete[] studentai[i].namuDarbai;
    }
    delete[] studentai;
    return 0;
}  
*/