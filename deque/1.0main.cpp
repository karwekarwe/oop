#include <iostream>
#include <deque>
#include <chrono>


#include "student.h"
#include "funkcijos.h"

using namespace std;

chrono::milliseconds totalTime(0); 

int main() {


    deque<Stud> studentai;
    string failPav;


        try {
                char ne;
                cout << "Generuoti nauja ar naudoti esama? (Nauja - N. Esama - E)" << endl;
                cin >> ne;

                char pasDyd;
                cout << "Pasirinkite, su kokio dydzio failu norite dirbti: 1. 1000 2. 10000 3. 100000 4. 1000000 5. 10000000"<< endl;
                cin >> pasDyd;

     


                if (ne == 'N' || ne == 'n') {


                    switch (pasDyd) {
                        case '1':
                        failuGen("studentai1000.txt", 1000);
                        failPav = "studentai1000.txt";
                        break;
                        case '2':
                        failuGen("studentai10000.txt", 10000);
                        failPav = "studentai10000.txt";
                        break;
                        case '3':
                        failuGen("studentai100000.txt", 100000);
                        failPav = "studentai100000.txt";
                        break;
                        case '4':
                        failuGen("studentai1000000.txt", 1000000);
                        failPav = "studentai1000000.txt";
                        break;
                        case '5':
                        failuGen("studentai10000000.txt", 10000000);
                        failPav = "studentai10000000.txt";
                        break;
                        default:
                        throw invalid_argument("Klaida");

                    }
                    cout << "Failas sugeneruotas." << endl;
                    isFailo(failPav, studentai); 
                    rusiavimasGen(failPav, studentai); 
  

                }
                else if (ne == 'E' || ne == 'e') {

                    switch (pasDyd) {
                        case '1':
                        failPav = "studentai1000.txt";
                        break;
                        case '2':
                        failPav = "studentai10000.txt";
                        break;
                        case '3':
                        failPav = "studentai100000.txt";
                        break;
                        case '4':
                        failPav = "studentai1000000.txt";
                        break;
                        case '5':
                        failPav = "studentai10000000.txt";
                        break;
                        default:
                        throw invalid_argument("Klaida");
                    }

                    isFailo(failPav, studentai); 
                    rusiavimasGen(failPav, studentai); 
                }

            


        } catch (const invalid_argument& e) {
            cout << "Klaida: " << e.what() << " Prašome įvesti tinkamą pasirinkimą.\n";
        } catch (const exception& e) {
            cout << "Neatpažinta klaida: " << e.what() << " Programa baigia darba.\n";
            return 1;
        }



    cout << "Visos programos veikimo laikas: " << totalTime.count() << " milisekundes" << endl;

    return 0;
}

