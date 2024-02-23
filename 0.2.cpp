#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdlib> 
#include <ctime>
#include <sstream>


using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

double vidurkis(Stud&);
double mediana(Stud&);
void ranka(vector<Stud>& studentai);
void isFailo(vector<Stud>& studentai);

int main() {

    vector<Stud> studentai;
    char pasirinkimas;

    cout << "Pasirinkite, kaip norite ivesti duomenis: \n 1. Ranka \n 2. Is failo\n";
    cin >> pasirinkimas;

    if (pasirinkimas == '1') {
        ranka(studentai);
    } else if (pasirinkimas == '2') {
        isFailo(studentai);
    } else {
        cout << "Netinkamas pasirinkimas. Programa baigia darba.\n";
        return 1;
    }

    return 0;
}



    void ranka(vector<Stud>& studentai) {


    int m = 0; // studentu sk
    int balas, egzBalas;
    char pabaiga;


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
        else if (input == '2'){
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
        else if (input == '3'){

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

}

    void isFailo(vector<Stud>& studentai) {

    Stud naujasS;

    ifstream failas("studentai1000000.txt");
    if (!failas) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    vector<string> buffer; // bufferis
    buffer.reserve(10);

    string header;
    getline(failas, header);

    string line;
    while (getline(failas, line)) {
       buffer.push_back(line); // kiekvienas line i bufferi
    }

    for (const string& line : buffer) {
        stringstream stringBuferis(line); // kiekvienai line stringstream

        stringBuferis >> naujasS.vardas >> naujasS.pavarde; // vardas ir pavarde i struct

        for (int i = 0; i < 5; ++i) {
            int balas;
            stringBuferis >> balas;
            naujasS.namuDarbai.push_back(balas); // namu darbai u struct
        }
        stringBuferis >> naujasS.egzaminas; // egzaminas i struct

        studentai.push_back(naujasS);
    }

    failas.close();

        char pasirinkimas;

    while (true) {
        cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            for (auto& studentas : studentai) {
                studentas.galutinis = vidurkis(studentas); // galutinis i struct
            }
            break;
        } else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
            for (auto& studentas : studentai) {
                studentas.galutinis = mediana(studentas); // galutinis i struct
            }
            break;
        } else {
            cout << "Neteisinga įvestis." << endl;
        }
    }
    ofstream output("kursiokai.txt"); // Create an ofstream object to write to the file
    if (!output) {
        cout << "Nepavyko atidaryti rezultatų failo." << endl;
        return;
    }

    output << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis" << endl;
    output << "------------------------------------------------------------" << endl;
    for (auto& studentas : studentai) {
        output << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
    }
    output << "------------------------------------------------------------" << endl;

    output.close(); // Close the file stream

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