#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <chrono>
#include <sstream>


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

    stringstream ss;

    ss << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= ndSk; ++i) {
        ss << setw(8) << "ND" + to_string(i);
    }
    ss << setw(8) << "Egz." << endl;

    srand(time(NULL)); 

    for (int i = 1; i <= numRecords; ++i) {
        ss << "Vardas" + to_string(i) << setw(20 - to_string(i).length()) << "Pavarde" + to_string(i);

        for (int j = 0; j < ndSk; ++j) {
            ss << setw(8) << rand() % 10 + 1; 
        }

        ss << setw(8) << rand() % 10 + 1 << endl; 
    }

    file << ss.str();
    
    file.close();

     auto endGen = chrono::steady_clock::now(); 
        auto elapsedGen = chrono::duration_cast<chrono::milliseconds>(endGen - startGen);
        cout << failPav << " generuoti uztruko: " << elapsedGen.count() << " milisekundes" << endl;
        totalTime += elapsedGen;
}


