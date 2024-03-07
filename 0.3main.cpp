#include <iostream>
#include <vector>

#include "student.h"
#include "funkcijos.h"

using namespace std;

int main() {

    vector<Stud> studentai;
    char pasirinkimas;

    while (true) {
        cout << "Pasirinkite, kaip norite ivesti duomenis: \n 1. Ranka \n 2. Is failo\n";
        cin >> pasirinkimas;

        try {
            if (pasirinkimas == '1') {
                ranka(studentai);
                break; 
            } else if (pasirinkimas == '2') {
                isFailo(studentai);
                break; 
            } else {
                throw invalid_argument("Netinkamas pasirinkimas.");
            }
        } catch (const invalid_argument& e) {
            cout << "Klaida: " << e.what() << " Prašome įvesti tinkamą pasirinkimą.\n";
        } catch (const exception& e) {
            cout << "Neatpažinta klaida: " << e.what() << " Programa baigia darba.\n";
            return 1;
        }
    }
    return 0;
}
