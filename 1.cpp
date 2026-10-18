#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char* nume;
    int nota;
    char** materii;
    int nrMaterii;
    int anStudiu;
    int id;

public:
    Student()
    {
        nume = nullptr;
        nota = 0;
        materii = nullptr;
        nrMaterii = 0;
        anStudiu = 1;
        id = 0;
    }

    Student(const char* nume, int nota, char** materii, int nrMaterii, int anStudiu, int id)
    {
        if (nota < 1 || nota > 10) nota = 1;
        if (nrMaterii < 0) nrMaterii = 0;
        if (anStudiu < 1 || anStudiu > 5) anStudiu = 1;
        if (id < 0) id = 0;

        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->nota = nota;
        this->nrMaterii = nrMaterii;
        this->anStudiu = anStudiu;
        this->id = id;

        if (nrMaterii > 0)
        {
            this->materii = new char* [nrMaterii];
            for (int i = 0; i < nrMaterii; i++)
            {
                this->materii[i] = new char[strlen(materii[i]) + 1];
                strcpy(this->materii[i], materii[i]);
            }
        }
        else
        {
            this->materii = nullptr;
        }
    }


    Student(const Student& s)
    {
        if (s.nume != nullptr)
        {
            nume = new char[strlen(s.nume) + 1];
            strcpy(nume, s.nume);
        }
        else nume = nullptr;

        nota = s.nota;
        nrMaterii = s.nrMaterii;
        anStudiu = s.anStudiu;
        id = s.id;

        if (nrMaterii > 0)
        {
            materii = new char* [nrMaterii];
            for (int i = 0; i < nrMaterii; i++)
            {
                materii[i] = new char[strlen(s.materii[i]) + 1];
                strcpy(materii[i], s.materii[i]);
            }
        }
        else
        {
            materii = nullptr;
        }
    }


    Student& operator=(const Student& s)
    {
        if (this == &s) return *this;

        if (nume) delete[] nume;
        if (materii)
        {
            for (int i = 0; i < nrMaterii; i++)
                delete[] materii[i];
            delete[] materii;
        }


        if (s.nume != nullptr)
        {
            nume = new char[strlen(s.nume) + 1];
            strcpy(nume, s.nume);
        }
        else nume = nullptr;

        nota = s.nota;
        nrMaterii = s.nrMaterii;
        anStudiu = s.anStudiu;
        id = s.id;


        if (nrMaterii > 0)
        {
            materii = new char* [nrMaterii];
            for (int i = 0; i < nrMaterii; i++)
            {
                materii[i] = new char[strlen(s.materii[i]) + 1];
                strcpy(materii[i], s.materii[i]);
            }
        }
        else
        {
            materii = nullptr;
        }

        return *this;
    }


    ~Student()
    {
        if (nume) delete[] nume;

        if (materii)
        {
            for (int i = 0; i < nrMaterii; i++)
                delete[] materii[i];

            delete[] materii;
        }
    }


    int getNota() const { return nota; }

    void setNota(int nota)
    {
        if (nota >= 1 && nota <= 10)
            this->nota = nota;
    }


    int getAnStudiu() const { return anStudiu; }

    void setAnStudiu(int an)
    {
        if (an >= 1 && an <= 5)
            anStudiu = an;
    }


    int getId() const { return id; }

    void setId(int id)
    {
        if (id >= 0)
            this->id = id;
    }


    void afisare() const
    {
        cout << "Nume: " << (nume ? nume : "undefined") << "\n";
        cout << "Nota: " << nota << "\n";
        cout << "An studiu: " << anStudiu << "\n";
        cout << "ID: " << id << "\n";
        cout << "Materii (" << nrMaterii << "): ";
        for (int i = 0; i < nrMaterii; i++)
            cout << materii[i] << " ";
        cout << "\n\n";
    }
};

int main()
{

    char* materii1[] = { (char*)"POO", (char*)"Algoritmi" };

    Student s1("Balan Dragos", 9, materii1, 2, 2, 101);
    cout << "Student s1:\n";
    s1.afisare();


    Student s2 = s1;
    cout << "Student s2 (copiat din s1):\n";
    s2.afisare();


    Student s3;
    s3 = s1;
    cout << "Student s3 (atribuit din s1):\n";
    s3.afisare();


    s3.setNota(10);
    s3.setAnStudiu(3);
    s3.setId(202);

    cout << "Student s3 dupa modificari:\n";
    s3.afisare();

    return 0;
}