#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <chrono>


using namespace std;
extern chrono::milliseconds totalTime;



void failuGen(const string& failPav, int numRecords) {



    ofstream file(failPav);
    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo gen" << endl;
        return;
    }        
    
    
    int ndSk;
    cout << "kiek namu darbu pazymiu?"<<endl;
    cin >> ndSk;

    auto startGen = chrono::steady_clock::now();

    file << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= ndSk; ++i) {
        file << setw(8) << "ND" + to_string(i);
    }
    file << setw(8) << "Egz." << endl;

    srand(time(NULL)); 

    for (int i = 1; i <= numRecords; ++i) {
        file << "Vardas" + to_string(i) << setw(20 - to_string(i).length()) << "Pavarde" + to_string(i);

        for (int j = 0; j < ndSk; ++j) {
            file << setw(8) << rand() % 10 + 1; 
        }

        file << setw(8) << rand() % 10 + 1 << endl; 
    }

    file.close();

     auto endGen = chrono::steady_clock::now(); 
        auto elapsedGen = chrono::duration_cast<chrono::milliseconds>(endGen - startGen);
        cout << failPav << " generuoti uztruko: " << elapsedGen.count() << " milisekundes" << endl;
        totalTime += elapsedGen;
}


