#include <iostream>
#include <iomanip> 
#include <string>
#include <algorithm>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    double tarp;
    int egz;
};

int main() {
    int studNum, pazNum, pazymys;
    double galutinis;
    string budas;

    cout << "kiek studentu? " <<endl;
    cin >> studNum;
    cout << "kiek namu darbu pazymiu? " <<endl;
    cin >> pazNum;
    
    cout << "Vidurkis ar mediana?" <<endl;
    cin >> budas;
    transform(budas.begin(), budas.end(), budas.begin(), ::tolower); 
  
    Stud* a = new Stud[studNum]; 

        for (int i = 0; i < studNum; ++i) {    
            
            double avg = 0, med = 0;
            double* pazymiai = new double[pazNum];

            cout << "vardas " << i+1 <<endl;
            cin >> a[i].vardas;
            cout << "pavarde " << i+1 <<endl;
            cin >> a[i].pavarde;

            for (int j = 0; j < pazNum; j++) {
                cout << "pazymys" << j+1 << ": " <<endl;
                cin >> pazymys;
                avg += pazymys;
                pazymiai[j] = pazymys; 
            }
            cout << "egzamino rez "<< i+1 <<endl;
            cin >> a[i].egz;
               
            if (budas == "vidurkis") {

            a[i].tarp = avg/pazNum;  //vidurkis 
            cout <<endl;
            }

            else if (budas == "mediana") {
            sort(pazymiai, pazymiai + pazNum);

            if (pazNum % 2 == 0) {
                med = (pazymiai[pazNum / 2 - 1] + pazymiai[pazNum / 2]) / 2.0;
            } else {
                med = pazymiai[pazNum / 2];
            }       
            a[i].tarp = med;  //mediana 
            cout <<endl;
            }       

        }
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15); 
        if (budas == "vidurkis") {cout  << "Galutinis (Vid.)" << endl; }
        else if (budas == "mediana") {cout  << "Galutinis (Med.)" << endl;}
        cout << "--------------------------------------------" << endl;

            for (int i = 0; i < studNum; i++) {
            galutinis = 0.4 * a[i].tarp + 0.6 * a[i].egz;

            cout << left << setw(15) << a[i].vardas << setw(15) << a[i].pavarde << fixed << setprecision(2) << galutinis << endl;
            cout << endl;
            }
           
    delete[] a; 
return 0;
}


 