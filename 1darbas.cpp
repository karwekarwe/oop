#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    int tarp;
    int egz;
};

int main() {
    int studNum;
    cout << "kiek studentu? " <<endl;
    cin >> studNum;
  
    Stud* a = new Stud[studNum]; 

        for (int i = 0; i < studNum; ++i) {
            cout << "vardas " << i+1 <<endl;
            cin >> a[i].vardas;
            cout << "pavarde " << i+1 <<endl;
            cin >> a[i].pavarde;
            cout << "tarpiniai rez " << i+1 <<endl;
            cin >> a[i].tarp;
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

}


 