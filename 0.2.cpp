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
#include <chrono>


using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

bool rusiavimas(const Stud& a, const Stud& b, char metPas);
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
    auto start = chrono::steady_clock::now();

    Stud naujasS;

    ifstream failas("studentai1000000.txt");
    if (!failas) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string line;
    getline(failas, line); 




 int baluCount = 0;

  stringstream headerS(line);
    string headerItem;
    int headerItemC = 0;
    // Count the total number of items in the header line
    while (headerS >> headerItem) {
        headerItemC++;
    }
    // Subtract 3 for name, last name, and exam grade
    baluCount = headerItemC - 3;



    while (getline(failas, line)) {

        stringstream stringBuferis(line);

        stringBuferis >> naujasS.vardas >> naujasS.pavarde;

        naujasS.namuDarbai.clear();
       
    
         int balas;
        for (int i = 0; i < baluCount; ++i) {
           
            stringBuferis >> balas;
            naujasS.namuDarbai.push_back(balas);
        }

        stringBuferis >> naujasS.egzaminas;

        studentai.push_back(naujasS);
    }

    failas.close();
    
        auto end = chrono::steady_clock::now(); 
        auto elapsed = chrono::duration_cast<chrono::seconds>(end - start);
        cout << "uztruko: " << elapsed.count() << " sekundes" << endl;

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

 

        char metPas;
        while (true){    
        
            cout << "Pasirinkite rikiavimo metoda (V - vardas, P - pavarde, G - galutinis): ";
            cin >> metPas;
            metPas = toupper(metPas);

            if (metPas != 'V' && metPas != 'P' && metPas != 'G') {
                cout << "Neteisinga įvestis." << endl;
            }
            else {
                break;
            }
        }

   sort(studentai.begin(), studentai.end(), [&](const Stud& a, const Stud& b) {
        return rusiavimas(a, b, metPas);
    });
        
    ofstream output("kursiokai.txt"); 
    if (!output) {
        cout << "Nepavyko atidaryti rezultatų failo." << endl;
        return;
    }

    output << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis" << endl;
    for (const auto& studentas : studentai) {
        output << setw(20) << left << studentas.vardas << setw(20) << left << studentas.pavarde << setw(10) << right << fixed << setprecision(2) << studentas.galutinis << endl;
    }

    output.close();   
  
}

bool rusiavimas(const Stud& a, const Stud& b, char metPas) {

    metPas = toupper(metPas);

    if (metPas == 'V') {
        return a.vardas < b.vardas;
    }
    else if (metPas == 'P') {
        return a.pavarde < b.pavarde;
    }
    else if (metPas == 'G') {
        return a.galutinis < b.galutinis;
    }
    else {
        cout << "Neteisinga įvestis." << endl;
        return false;
    }
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