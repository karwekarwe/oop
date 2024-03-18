#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>

#include "student.h"
#include "funkcijos.h"

using namespace std;

void rusiavimasGen(const string& failPav, vector<Stud>& studentai) {

    auto start = chrono::steady_clock::now();
    

    vector<Stud> luzeriukai;
    vector<Stud> intelektualai;

     ifstream failas(failPav);
    if (!failas) {
        throw runtime_error("Nepavyko atidaryti failo rusiavimas.");
    }

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

        for (const auto& studentas : studentai) {
            if (studentas.galutinis < 5.0) {
                luzeriukai.push_back(studentas);
            } else {
                intelektualai.push_back(studentas);
            }
        }


            auto end = chrono::steady_clock::now(); 
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "rusiavimas uztruko: " << failPav << elapsed.count() << " milisekundes" << endl;

        auto start = chrono::steady_clock::now();      


        for (const auto& studentas : luzeriukai){
            outputFileUnder<< studentas.vardas << " " << studentas.pavarde << " " << studentas.galutinis << endl;
        }
        for (const auto& studentas : intelektualai){
            outputFileOver<< studentas.vardas << " " << studentas.pavarde << " " << studentas.galutinis << endl;
        }        

            auto end = chrono::steady_clock::now(); 
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Surusiuotu isvedimas i du failus uztruko: " << failPav << elapsed.count() << " milisekundes" << endl;
    



}

