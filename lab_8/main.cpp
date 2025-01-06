#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

#include "Comparator.h"
#include "Student.h"
using namespace std;
#include <boost/bind.hpp>
    #include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <regex>
using namespace std;
void zapiszDoPlikow(const vector<Student> &x) {
    ofstream plikK("k.csv");
    ofstream plikM("m.csv");

    if (!plikK.is_open() || !plikM.is_open()) {
        cerr << "Nie można otworzyć plików do zapisu." << endl;
        return;
    }

    // Nagłówki
    plikK << "Imie;Nazwisko;Plec;Ocena;Email" << endl;
    plikM << "Imie;Nazwisko;Plec;Ocena;Email" << endl;

    for (const auto &student : x) {
        ofstream &plik = (student.plec1() == "K") ? plikK : plikM;
        plik << student.imie1() << ";" << student.nazwisko1() << ";" << student.plec1() << ";"
             << student.ocena1() << ";" << student.mail1() << endl;
    }

    plikK.close();
    plikM.close();
}
void pokazXstudentow(vector<Student> studenci, int x) {
    if (x > studenci.size() || x < 0) {
        cout << "Nie ma tylu studentow w ksiazce." << endl;
        return;
    }
    cout << "Imie  \t" << "Nazwisko  \t" << "Plec  \t" << "Ocena  \t" << "Mail  " << endl;
    for (int i = 0; i < x; i++) {
        cout << studenci[i].imie1() << "  \t" << studenci[i].nazwisko1() << "  \t" << studenci[i].plec1() << "  \t"
             << studenci[i].ocena1() << "  \t" << studenci[i].mail1() << endl;
    }

}
void showONazwisku(Student x, string nazwisko) {
    if (x.nazwisko1() == nazwisko) {
        cout<<"Osoby o nazwisku "<<nazwisko<<endl;
        x.show();
    }

}
bool isValidName(string name){
    if (name.empty() || !isupper(name[0])) return false;
    return all_of(name.begin() + 1, name.end(), [](char c) { return isalpha(c); });
}

bool isValidGender(string gender) {
    return gender == "K" || gender == "M";
}

bool isValidEmail(string email) {
    const regex emailPattern(R"((\w+)(\.\w+)*@(\w+)(\.(\w+))+)");
    return regex_match(email, emailPattern);
}

void dodajDoKsiazki(vector<Student> &x) {
    string imie, nazwisko, plec, mail;
    int ocena, wybor;

    cout << "Podaj imie: ";
    cin >> imie;
    if (!isValidName(imie)) {
        cerr << "Niepoprawne imie. Musi zaczynać się dużą literą i zawierać tylko litery." << endl;
        return;
    }

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    if (!isValidName(nazwisko)) {
        cerr << "Niepoprawne nazwisko. Musi zaczynać się dużą literą i zawierać tylko litery." << endl;
        return;
    }

    cout << "Podaj plec (K/M): ";
    cin >> plec;
    if (!isValidGender(plec)) {
        cerr << "Niepoprawna plec. Wprowadź K dla kobiety lub M dla mężczyzny." << endl;
        return;
    }

    cout << "Podaj ocene: ";
    cin >> ocena;
    if (ocena < 1 || ocena > 6) {
        cerr << "Niepoprawna ocena. Wprowadź liczbę z zakresu 1-6." << endl;
        return;
    }

    cout << "Czy chcesz podać mail? T-1, N-0: ";
    cin >> wybor;
    ofstream plik("dane.csv");
    if (wybor == 1) {
        cout << "Podaj mail: ";
        cin >> mail;
        if (!isValidEmail(mail)) {
            cerr << "Niepoprawny email. Musi zawierać znak @." << endl;
            return;
        }
        x.push_back(Student(imie, nazwisko, plec, ocena, mail));
        plik << imie << ";" << nazwisko << ";" << plec << ";"
             << ocena << ";" << mail << endl;

    } else if (wybor == 0) {
        x.push_back(Student(imie, nazwisko, plec, ocena));
        plik << imie << ";" << nazwisko << ";" << plec << ";"
     << ocena<<endl;
    } else {
        cerr << "Niepoprawny wybór." << endl;
    }
    plik.close();

}

int main() {
    std::ifstream inputFile("kod.txt");
    std::ofstream outputFile("kod_bez_komentarzy.txt");

    if (!inputFile) {
        std::cerr << "Błąd: Nie można otworzyć pliku kod.txt" << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::string cleanLine;
        std::size_t pos = line.find("//");

        if (pos != std::string::npos) {
            cleanLine = line.substr(0, pos);
        } else {
            cleanLine = line;
        }
        cleanLine.erase(cleanLine.find_last_not_of(" \t") + 1);
        outputFile << cleanLine << std::endl;
    }

    std::cout << "Kod bez komentarzy zapisano w pliku kod_bez_komentarzy.txt" << std::endl;

    inputFile.close();
    outputFile.close();

    //zad2
    int suma = 0;
    int proby = 0;

    while (true) {
        try {
            cout << "Podaj dodatnia liczbe calkowita: ";
            string input;
            cin >> input;
            proby++;
            int liczba = stoi(input);

            if (liczba <= 0) {
                throw invalid_argument("Liczba musi być dodatnia i większa od zera.");
            }
            suma += liczba;
            if (suma == 21) {
                cout << "Oczko w  " << proby << " probach." << endl;
                break;
            } else if (suma > 21) {
                suma -= liczba;
                throw overflow_error("Suma przekroczyla 21. Sprobuj ponownie podac ostatnia liczbe.");
            }
        } catch (const invalid_argument &e) {
            cout << "Blad: " << e.what() << endl;
        } catch (const overflow_error &e) {
            cout << "Blad: " << e.what() << endl;
        } catch (...) {
            cout << "Nieznany błąd. Spróbuj ponownie." << endl;
        }
    }
    //zad3
    ifstream plik("dane.csv");

    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku dane.csv" << endl;
        return 1;
    }

    string linia;
    string dana;
    getline(plik, linia);
    vector<Student> students;
    while (getline(plik, linia)) {
        istringstream tokenStream(linia);
        vector<string> vec;
        while (getline(tokenStream, dana, ';')) {
            vec.push_back(dana);
        }
        if(vec.size()==4) {
            students.push_back(Student(vec[0], vec[1], vec[2], stoi(vec[3])));
        }
        else {
            students.push_back(Student(vec[0], vec[1], vec[2], stoi(vec[3]), vec[4]));
        }
    }
    dodajDoKsiazki(students);
    cout<<"Imie  \t"<< "Nazwisko  \t"<< "Plec  \t"<< "Ocena  \t"<< "Mail  "<<endl;
    for(auto i=students.begin(); i!=students.end(); i++) {
        cout<<i->imie1()<<"  \t"<<i->nazwisko1()<<"  \t"<<i->plec1()<<"  \t"<<i->ocena1()<<"  \t"<<i->mail1()<<endl;
    }
    plik.close();
    for_each(students.begin(), students.end(), boost::bind(showONazwisku, placeholders::_1, "Pies"));
    zapiszDoPlikow(students);
    cout<<"Pokazuj"<<endl;
    pokazXstudentow(students,4);
    sort(students.begin(),students.end(),Comparator());
    cout<<"Pokaz posortowne"<<endl;
    pokazXstudentow(students,students.size()-1);
    return 0;
}
