#include <iostream>
#include <iomanip> 
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    int *namuDarbai;
    double tarp;
    int egz;
};

int main() {
    int studNum, pazNum, pazymys;
    double galutinis;
    string verBudas;

    do {
        cout << "Studentų skaičius: " <<endl;
        cin >> studNum;
        if (cin.fail() || studNum <= 0 || studNum > 10) {
            cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                continue; 
        }        
    } while (studNum <= 0 || studNum > 10);
        

    do {
        cout << "Namų darbų pažymių skaičius: " <<endl;
        cin >> pazNum;
        if (cin.fail() || pazNum <= 0) {
            cout << "Įvekite skaičių, didesnį už 0" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                continue; 
        }        
    } while (pazNum <= 0);

     do {
        cout << "Pasirinkite skaičiavimo metodą (V - vidurkis, M - mediana):" <<endl;
        cin >> verBudas;
        transform(verBudas.begin(), verBudas.end(), verBudas.begin(), ::tolower); 
        if (verBudas != "v"  && verBudas != "m") {
            cout << "Klaidingas įvesties formatas. Prašome įvesti 'V' arba 'M'.\n";
        }
    } while (verBudas != "v" && verBudas != "m");
  
    Stud* a = new Stud[studNum]; 
    int tempEgz;

        for (int i = 0; i < studNum; ++i) {    
            
            double avg = 0, med = 0;
            a[i].namuDarbai = new int[pazNum];

            cout << "Vardas " << i+1 << ":" <<endl;
            cin >> a[i].vardas;
            cout << "Pavardė " << i+1 << ":" <<endl;
            cin >> a[i].pavarde;

            for (int j = 0; j < pazNum; j++) {
                cout << "Pažymys " << j+1 << ": " <<endl;
                cin >> pazymys;
                avg += pazymys;
                a[i].namuDarbai[j] = pazymys; // namu darbu pazymiu array

            }

            do {
                cout << "Egzamino rezultatas "<< i+1 << ":" <<endl;
                cin >> tempEgz;
                if (cin.fail() || tempEgz <= 0 || tempEgz > 10) {
                cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    continue; 
                }        
            } while (tempEgz <= 0 || tempEgz > 10);
            a[i].egz = tempEgz;
               
            if (verBudas == "v") {
            a[i].tarp = avg/pazNum;  //vidurkis 
            cout <<endl;
            }
 
            else if (verBudas == "m") {
            sort(a[i].namuDarbai, a[i].namuDarbai + pazNum);
            if (pazNum % 2 == 0) {
                med = (a[i].namuDarbai[pazNum / 2 - 1] + a[i].namuDarbai[pazNum / 2]) / 2.0;
            } else {
                med = a[i].namuDarbai[pazNum / 2];
            }       
            a[i].tarp = med;  //mediana 
            cout <<endl;
            }   
        }
        
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(15) <<endl; 
        if (verBudas == "v") {cout  << "Galutinis (Vid.)" << endl; }
        else if (verBudas == "m") {cout  << "Galutinis (Med.)" << endl;}
        cout << "--------------------------------------------" << endl;

            for (int i = 0; i < studNum; i++) {
            galutinis = 0.4 * a[i].tarp + 0.6 * a[i].egz;

            cout << left << setw(15) << a[i].vardas << setw(15) << a[i].pavarde << fixed << setprecision(2) << galutinis << endl;
            cout << endl;
            }
    for (int i = 0; i < studNum; ++i) {
        delete[] a[i].namuDarbai;
    }

    delete[] a; 
return 0;
}