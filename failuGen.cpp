#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <chrono>


using namespace std;


void failuGen(const string& filename, int numRecords) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failas nerastas" << endl;
        return;
    }

    auto start = chrono::steady_clock::now();

    file << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 10; ++i) {
        file << setw(8) << "ND" + to_string(i);
    }
    file << setw(8) << "Egz." << endl;

    srand(time(NULL)); 

    for (int i = 1; i <= numRecords; ++i) {
        file << "Vardas" + to_string(i) << setw(20 - to_string(i).length())
             << "Pavarde" + to_string(i);

        for (int j = 0; j < 10; ++j) {
            file << setw(8) << rand() % 10 + 1; 
        }

        file << setw(8) << rand() % 10 + 1 << endl; 
    }

    file.close();

     auto end = chrono::steady_clock::now(); 
        auto elapsed = chrono::duration_cast<chrono::seconds>(end - start);
        cout << "generuoti uztruko: " << elapsed.count() << " sekundes" << endl;
}
