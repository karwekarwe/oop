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
}

 