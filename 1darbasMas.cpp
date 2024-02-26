#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    int *namuDarbai;
    int ndCount;
    int egzaminas;
    double galutinis;
};
void ranka(Stud* &studentai, int m, int n, int &dydis);
void genPaz(Stud* &studentai, int m, int &dydis);
void gen(Stud* &studentai, int m, int &dydis);

double vidurkis(Stud&);
double mediana(Stud&);



int main() {
    int m = 0; // studentu sk
    int n = 0; // namu darbu sk
    int dydis = 2;
    char pabaiga;    

    Stud *studentai = new Stud[dydis];
    
    srand(time(0));

    while (true) {
    char input;
    cout << "Pasirinkite programos eigą: \n 1. Įvestis ranka. \n 2. Generuoti namų darbų ir egzamino pažymius. \n 3. Generuoti ir pažymius, ir vardus bei pavardes. \n 4. Baigti darbą."<< endl;
    cin >> input;


    while (true) {

        if (input == '4') {
            delete[] studentai;
            exit(0);
        } 
        else if (input == '1'){
            ranka(studentai, m, n, dydis);
        }
        else if (input == '2'){
            genPaz(studentai, m, dydis);
        }
        else if (input == '3'){
            gen(studentai, m, dydis);
        }

        else {
        cout << "Neteisinga įvestis. Įveskite skaičių nuo 1 iki 4."<<endl;
        }
            m++;
            while (true) {
                cout << "Ar baigete ivesti studentus? (y/n): ";
                cin >> pabaiga;
                if (pabaiga == 'y' || pabaiga == 'Y') {
                   break;
                } 
                else if (pabaiga == 'n' || pabaiga == 'N') {
                    break;
                } 
                else {
                    cout << "Įveskite 'n' arba 'y'" << endl;
                }
            } 
   
            if (pabaiga == 'y' || pabaiga == 'Y') {
                break;
        }
           
    }

    char pasirinkimas;
        while (true) {
            cout << endl;
            cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
            cin >> pasirinkimas;

            if (pasirinkimas == 'V' || pasirinkimas == 'v') {
                cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Vid.)" << endl;
                cout << "--------------------------------------------" << endl;
                for (int i = 0; i < m; ++i) {
                    studentai[i].galutinis = vidurkis(studentai[i]); // galutinis i struct
                    cout << setw(20) << left << studentai[i].vardas << setw(20) << left << studentai[i].pavarde << setw(10) << right << fixed << setprecision(2) << studentai[i].galutinis << endl;
                }
                cout << "--------------------------------------------" << endl;
                break;
            } 
            else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
                cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Med.)" << endl;
                cout << "--------------------------------------------" << endl;
                for (int i = 0; i < m; ++i) {
                    studentai[i].galutinis = mediana(studentai[i]); // galutinis i struct
                    cout << setw(20) << left << studentai[i].vardas << setw(20) << left << studentai[i].pavarde << setw(10) << right << fixed << setprecision(2) << studentai[i].galutinis << endl;
                }
                cout << "--------------------------------------------" << endl;
                break;
            } 
            else {
                cout << "Neteisinga įvestis." << endl;
            }
            cout << endl;
        }
        }
    
    delete[] studentai;
    
    return 0;

}

    void ranka ( Stud* &studentai, int m, int n, int &dydis) {

            if (m >= dydis) {
                dydis *= 2;
                Stud *temp = new Stud[dydis];

                for (int i = 0; i < m; ++i) {
                temp[i] = studentai[i]; 
                }
                delete[] studentai;
                studentai = temp;
            } 

            int balas, egzBalas;
            int tempNDSize = 2;
            int *tempND = new int[100];

            int i = 1;
            cout << "Vardas: "<< endl;
            cin >> studentai[m].vardas; //vardas i struct
            cout << "Pavarde: "<< endl;
            cin >> studentai[m].pavarde; //pavarde i struct
            do{
                cout << "Namu darbu "<< i <<" balas (-1 norint baigti): "<< endl;
                cin >> balas;

                if (cin.fail() || balas == 0 || balas < -1 || balas > 10) {
                    cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    continue; 
                }
                if (balas == -1){
                    if (n == 0) {
                        cout << "Įveskite bent 1 pažymį: " << endl;
                        continue; 
                    }
                    else {
                        break; 
                    }
                }

                if (n >= tempNDSize) {
                    int nDyd = tempNDSize * 2;
                    int *newTempND = new int[nDyd];
                    for (int j = 0; j < n; ++j) {
                        newTempND[j] = tempND[j];
                    }
                    delete[] tempND;
                    tempND = newTempND;
                    tempNDSize = nDyd;
            	}

                
                tempND[n++] = balas;
                studentai[m].namuDarbai = tempND; //nd array i struct
                studentai[m].ndCount = n;
                i++;


            } while (true);
       
            do {
                cout << "Iveskite egzamino bala: ";
                            cin >> egzBalas;

                if (cin.fail() || egzBalas < 1 || egzBalas > 10) {
                    cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    continue; 
                }
                else {
                    studentai[m].egzaminas = egzBalas; // egzaminas i struct
                    break;
                }      
            } while (true); 

         }

        void genPaz(Stud* &studentai, int m, int &dydis) {
            
            if (m >= dydis) {
                dydis *= 2;
                Stud *temp = new Stud[dydis];

                for (int i = 0; i < m; ++i) {
                    temp[i] = studentai[i]; 
                }
                delete[] studentai;
                studentai = temp;
            } 

            cout << "Vardas: "<< endl;
            cin >> studentai[m].vardas; //vardas i struct
            cout << "Pavarde: "<< endl;
            cin >> studentai[m].pavarde; //pavarde i struct

            int numBal = rand() % 10 + 1;
            studentai[m].ndCount = numBal;
            studentai[m].namuDarbai = new int[numBal];

            for (int i = 0; i < numBal; i++) {
                studentai[m].namuDarbai[i] =  rand() % 10 + 1; // random nd i struct
            }
                studentai[m].egzaminas = rand() % 10 + 1; // random egzaminas i struct
          
        }

        void gen( Stud* &studentai, int m, int &dydis) {
            
            if (m >= dydis) {
                dydis *= 2;
                Stud *temp = new Stud[dydis];

                for (int i = 0; i < m; ++i) {
                temp[i] = studentai[i]; 
                }
                delete[] studentai;
                studentai = temp;
            } 

            string vardai[] = {"Jonas", "Petras", "Antanas", "Juozas", "Ona", "Marija", "Gražina", "Laima"};
            string pavardes[] = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Onaitė", "Marijaitė", "Gražinaitė", "Laimaitė"};


            int numBal = rand() % 10 + 1;
            studentai[m].ndCount = numBal;
            studentai[m].namuDarbai = new int[numBal];

            for (int i = 0; i < numBal; i++) {
                studentai[m].vardas = vardai[rand() % (sizeof(vardai) / sizeof(vardai[0]))]; // vardas i struct
                studentai[m].pavarde = pavardes[rand() % (sizeof(pavardes) / sizeof(pavardes[0]))]; //pavarde i struct

                studentai[m].namuDarbai[i] =  rand() % 10 + 1; // random nd i struct
            }
            studentai[m].egzaminas = rand() % 10 + 1; // random egzaminas i struct
            cout << "Sugeneruotas studentas " << studentai[m].vardas << " " << studentai[m].pavarde << endl;
        
       
        }

    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
        for (int i =0; i < s.ndCount; i++) {
            suma+= s.namuDarbai[i];
        }
        avg = suma / s.ndCount;
        gal = avg*0.4 + s.egzaminas*0.6;

        return gal;
    }

    double mediana (Stud& s) {
        double med = 0;
        double gal;
        sort(s.namuDarbai, s.namuDarbai+s.ndCount);
        if (s.ndCount % 2 == 0) {
            med = (s.namuDarbai[s.ndCount / 2 - 1] + s.namuDarbai[s.ndCount / 2]) / 2;
        }
        else {
            med = s.namuDarbai[s.ndCount / 2];
        }
        gal = med*0.4 + s.egzaminas*0.6;

        return gal;
    }