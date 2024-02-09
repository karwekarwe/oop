#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    double tarp;
    int egz;
};

int main() {
    int studNum, pazNum, pazymys;


    cout << "kiek studentu? " <<endl;
    cin >> studNum;
    cout << "kiek namu darbu pazymiu? " <<endl;
    cin >> pazNum;
  
    Stud* a = new Stud[studNum]; 

        for (int i = 0; i < studNum; ++i) {    
            
            double avg = 0;

            cout << "vardas " << i+1 <<endl;
            cin >> a[i].vardas;
            cout << "pavarde " << i+1 <<endl;
            cin >> a[i].pavarde;

            for (int j = 0; j < pazNum; j++) {
                cout << "pazymys" << j+1 << ": " <<endl;
                cin >> pazymys;
                avg += pazymys/pazNum;
            }

            a[i].tarp = avg;
            cout << "tarpiniai rez " << i + 1 << ": " << a[i].tarp << endl;

            cout << "egzamino rez "<< i+1 <<endl;
            cin >> a[i].egz;
        
        cout << endl;
    }

    
     cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
     cout << "--------------------------------------------" << endl;
        for (int i = 0; i < studNum; i++) {
        cout << left << setw(15) << a[i].vardas << setw(15) << a[i].pavarde << fixed << setprecision(2) << 0.4 * a[i].tarp + 0.6 * a[i].egz << endl;
        cout << endl;
        }

          delete[] a; 

          return 0;

}


 