#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iterator>


#include "student.h"
#include "funkcijos.h"

using namespace std;
extern chrono::milliseconds totalTime;


void rusiavimasGen(const string& failPav, vector<Stud>& studentai) {

    auto startRus = chrono::steady_clock::now();
    

    vector<Stud> luzeriukai;



    ofstream outputFileUnder("luzeriukai " + failPav);
    if (!outputFileUnder.is_open()) {
        cerr << "Nepavyko sukurti naujo failo. outputFileUnder" << endl;
        return;
    }
    ofstream outputFileOver("intelektualai " + failPav);
    if (!outputFileOver.is_open()) {
        cerr << "Nepavyko sukurti naujo failo. outputFileOver" << endl;
        return;
    }

int index = 0; 

for (int i = 0; i < studentai.size(); ++i) {
    if (studentai[i].galutinis < 5.0) {
        luzeriukai.push_back(std::move(studentai[i])); // maziau uz 5 i luzeriukus
    } else {
        studentai[index++] = std::move(studentai[i]); // daugiau uz 5 i studentu pradzia
    }
}

studentai.resize(index); 


            auto endRus = chrono::steady_clock::now(); 
            auto elapsedRus = chrono::duration_cast<chrono::milliseconds>(endRus - startRus);
            cout  << failPav << "Studentu skirstymo  i dvi grupes uztruko: " << elapsedRus.count() << " milisekundes" << endl;
    totalTime += elapsedRus;

        


        char rusPas;

        while (true) {
            cout << "Pasirinkite rikiavimo metoda (V - vardas, P - pavarde, G - galutinis): ";
            cin >> rusPas;
            rusPas = toupper(rusPas);

            if (rusPas != 'V' && rusPas != 'P' && rusPas != 'G') {
                cout << "Neteisinga įvestis" << endl;
            }
            else {
                break;
            }

        }   

auto startIsved = chrono::steady_clock::now(); 

    sort(studentai.begin(), studentai.end(), [&rusPas](const Stud& a, const Stud& b) {
    return rusiavimas(a, b, rusPas);
  });
      sort(luzeriukai.begin(), luzeriukai.end(), [&rusPas](const Stud& a, const Stud& b) {
    return rusiavimas(a, b, rusPas);
  });
  
            auto endIsved = chrono::steady_clock::now(); 
            auto elapsedIsved = chrono::duration_cast<chrono::milliseconds>(endIsved - startIsved);
            cout << failPav << "Studentu rusiavimas didejimo tvarka konteineryje (funkcija sort) uztruko: " << elapsedIsved.count() << "  milisekundes" << endl;
    
               totalTime += elapsedIsved;


        for (const auto& studentas : luzeriukai){
            outputFileUnder<< studentas.vardas << setw(20) << studentas.pavarde << setw(20) << studentas.galutinis << endl;
        }
        for (const auto& studentas : studentai){
            outputFileOver<< studentas.vardas << setw(20) << studentas.pavarde << setw(20) << studentas.galutinis << endl;
        }        



}