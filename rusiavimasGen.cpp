#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "student.h"
#include "funkcijos.h"

using namespace std;

void rusiavimasGen(const string& failPav, vector<Stud>& studentai) {

     ifstream failas(failPav);
    if (!failas) {
        throw runtime_error("Nepavyko atidaryti failo rus.");
    }

 /*   Surūšiuokite (padalinkite) studentus į dvi kategorijas:
Studentai, kurių galutinis balas < 5.0 galėtume vadinti “vargšiukai”, “nuskriaustukai” ir pan.
Studentai, kurių galutinis balas >= 5.0 galėtume vadinti "kietiakiai", "galvočiai" ir pan.
Surūšiuotus studentus išveskite į du naujus failus.*/

    /*atidarom faila, suskaiciuojam kiekvieno galutini, sortinam pagal galutini, isvedam i failus

*/


    ofstream outputFile("rusiuoti_" + failPav);
    if (!outputFile.is_open()) {
        cerr << "Nepavyko sukurti naujo failo." << endl;
        return;
    }


}

