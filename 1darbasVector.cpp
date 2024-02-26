#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdlib> 
#include <ctime>


using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

void ranka(Stud&);
void genPaz(Stud&);
void gen(Stud&);

double vidurkis(Stud&);
double mediana(Stud&);

int main() {
    int m = 0; // studentu sk
  
    char pabaiga;

    vector<Stud> studentai;
    srand(time(0));

    while (true) {
    char input;
 
    cout << "Pasirinkite programos eigą: \n 1. Įvestis ranka. \n 2. Generuoti namų darbų ir egzamino pažymius. \n 3. Generuoti ir pažymius, ir vardus bei pavardes. \n 4. Baigti darbą."<< endl;
    cin >> input;

    while (true) {

        Stud naujasS;

        if (input == '4') {
            exit(0);
        }
        else if (input == '1'){
            ranka (naujasS);
        }
        else if (input == '2'){
            genPaz (naujasS);
        }
        else if (input == '3'){
            gen (naujasS);
        }  
        else {
            cout << "Neteisinga įvestis."<<endl;
        }
            studentai.push_back(naujasS); 

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
                cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): " << endl;
                cin >> pasirinkimas;

                if (pasirinkimas == 'V' || pasirinkimas == 'v') {
                    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Vid.)" << endl;
                    cout << "--------------------------------------------" << endl;
                    for (auto& studentas : studentai) {
                        studentas.galutinis = vidurkis(studentas); // galutinis i struct
                        cout << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
                    }
                    cout << "--------------------------------------------" << endl;
                    break;
                } 
                else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
                    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Med.)" << endl;
                    cout << "--------------------------------------------" << endl;
                    for (auto& studentas : studentai) {
                        studentas.galutinis = mediana(studentas); // galutinis i struct
                        cout << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
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
    return 0;

}
    void ranka (Stud& naujasS) {
        int balas, egzBalas;
        cout << "Vardas: "<< endl;
        cin >> naujasS.vardas; //vardas i struct
        cout << "Pavarde: "<< endl;
        cin >> naujasS.pavarde; //pavarde i struct

        int i = 1;
            do {
                cout << "Namu darbu "<< i <<" balas (-1 norint baigti): " << endl;
                cin >> balas;

                    if (cin.fail() || balas == 0 || balas < -1 || balas > 10) {
                        cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        continue; 
                    }
                    if (balas == -1){
                        if (naujasS.namuDarbai.empty()) {
                            cout << "Įveskite bent 1 pažymį: " << endl;
                            continue; 
                        } 
                        else {
                            break; 
                        }
                        }
                
                    naujasS.namuDarbai.push_back(balas); //namu darbu balai i struct
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
                    naujasS.egzaminas = egzBalas; // egzaminas i struct
                    break;
                }      
            } while (true);

    }

    void genPaz(Stud& naujasS) {
            cout << "Vardas: "<< endl;
            cin >> naujasS.vardas; //vardas i struct
            cout << "Pavarde: "<< endl;
            cin >> naujasS.pavarde; //pavarde i struct

            int numBal = rand() % 10 + 1;
            for (int i = 0; i < numBal; i++) {
                naujasS.namuDarbai.push_back(rand() % 10 + 1); // random nd i struct
            }
                naujasS.egzaminas = rand() % 10 + 1; // random egzaminas i struct
    }
    void gen(Stud& naujasS) {
         vector<string> vardai = {"Jonas", "Petras", "Antanas", "Juozas", "Ona", "Marija", "Gražina", "Laima"};
            vector<string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Onaitė", "Marijaitė", "Gražinaitė", "Laimaitė"};

            int numBal = rand() % 10 + 1;
            for (int i = 0; i < numBal; i++) {
                naujasS.vardas = vardai[rand() % vardai.size()]; // vardas i struct
                naujasS.pavarde = pavardes[rand() % pavardes.size()]; //pavarde i struct

                naujasS.namuDarbai.push_back(rand() % 10 + 1); // random nd i struct                
            }
                naujasS.egzaminas = rand() % 10 + 1; // random egzaminas i struct
                cout << "Sugeneruotas studentas " << naujasS.vardas << " " << naujasS.pavarde << endl;

    }


    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
        for (int balas : s.namuDarbai) {
            suma+= balas;
        }
        avg = suma / s.namuDarbai.size();
        
        gal = avg*0.4 + s.egzaminas*0.6;

        return gal;
    }

    double mediana (Stud& s) {
        double med = 0;
        double gal;
        sort(s.namuDarbai.begin(), s.namuDarbai.end());
        if (s.namuDarbai.size() % 2 == 0) {
            med = (s.namuDarbai[s.namuDarbai.size() / 2 - 1] + s.namuDarbai[s.namuDarbai.size() / 2]) / 2.0;
        }
        else {
            med = s.namuDarbai[s.namuDarbai.size() / 2];
        }
        gal = med*0.4 + s.egzaminas*0.6;

        return gal;
    }
    