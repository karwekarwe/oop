#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <cstdlib> 
#include <algorithm>



#include "student.h"
#include "funkcijos.h"

using namespace std;

    void isFailo(vector<Stud>& studentai) {
    auto start = chrono::steady_clock::now();

    Stud naujasS;

    ifstream failas("studentai1000000.txt");
    if (!failas) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string line;
    getline(failas, line); 

    while (getline(failas, line)) {
        stringstream stringBuferis(line);

        stringBuferis >> naujasS.vardas >> naujasS.pavarde;

        naujasS.namuDarbai.clear();
        for (int i = 0; i < 5; ++i) {
            int balas;
            stringBuferis >> balas;
            naujasS.namuDarbai.push_back(balas);
        }

        stringBuferis >> naujasS.egzaminas;

        studentai.push_back(naujasS);
    }

    failas.close();
    
        auto end = chrono::steady_clock::now(); 
        auto elapsed = chrono::duration_cast<chrono::seconds>(end - start);
        cout << "uztruko: " << elapsed.count() << " sekundes" << endl;

    char pasirinkimas;
    while (true) {
        cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            for (auto& studentas : studentai) {
                studentas.galutinis = vidurkis(studentas); // galutinis i struct
            }
            break;
        } else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
            for (auto& studentas : studentai) {
                studentas.galutinis = mediana(studentas); // galutinis i struct
            }
            break;
        } else {
            cout << "Neteisinga įvestis." << endl;
        }
    }

 

        char metPas;
        while (true){    
        
            cout << "Pasirinkite rikiavimo metoda (V - vardas, P - pavarde, G - galutinis): ";
            cin >> metPas;
            metPas = toupper(metPas);

            if (metPas != 'V' && metPas != 'P' && metPas != 'G') {
                cout << "Neteisinga įvestis." << endl;
            }
            else {
                break;
            }
        }

   sort(studentai.begin(), studentai.end(), [&](const Stud& a, const Stud& b) {
        return rusiavimas(a, b, metPas);
    });
        
    ofstream output("kursiokai.txt"); 
    if (!output) {
        cout << "Nepavyko atidaryti rezultatų failo." << endl;
        return;
    }

    output << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis" << endl;
    for (const auto& studentas : studentai) {
        output << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
    }

    output.close();   
  
}


