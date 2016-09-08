//
// Created by Marta on 08/09/2016.
//

#pragma once

#include <iostream>
using namespace std;

template <class T>
class Matrica {
private:
   T **matrica;
   int redovi, kolone;

public:
    Matrica();
    Matrica(int redovi, int kolone);
    Matrica(Matrica& matrica);

    T** getMatrica();
    void istampajMatricu();

    T& operator()(int redovi, int kolone);

    ~Matrica();
};

/*sve definicije su ovde*/
/*template ne radi kada je u .cpp fajlu*/

template <class T>
Matrica<T>::Matrica() {
    redovi = 5;
    kolone = 6;

    matrica = new T*[redovi];

    for (int i = 0; i < redovi; i++) {
        matrica[i] = new T[kolone];
    }

    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            matrica[i][j] = (T)i * j;
        }
    }
}

template <class T>
Matrica<T>::Matrica(int redovi, int kolone) {
    this->redovi = redovi;
    this->kolone = kolone;

    matrica = new T*[redovi];
    for (int i = 0; i < redovi; i++) {
        matrica[i] = new T[kolone];
    }

    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            matrica[i][j] = (T)i * j;
        }
    }
}

template <class T>
Matrica<T>::Matrica(Matrica &kopija) {
    redovi = kopija.redovi;
    kolone = kopija.kolone;
    matrica = new T*[redovi];

    for (int i = 0; i < redovi; i++) {
        matrica[i] = new T[kolone];
    }

    for(int i=0; i<redovi; i++) {
        for(int j=0; j<kolone; j++) {
            matrica[i][j] = kopija.matrica[i][j];
        }
    }
}

template <class T>
T** Matrica<T>::getMatrica() {
    return this->matrica;
}

template <class T>
void Matrica<T>::istampajMatricu() {
    for(int i=0; i<this->redovi; i++) {
        for(int j=0; j<this->kolone; j++) {
            cout << matrica[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
T& Matrica<T>::operator()(int red, int kol) {
    if((kol >=0 && kol <=kolone) && (red >=0 && red<=redovi)) return matrica[redovi][kolone];
    else perror("Granice su prekoracene.");
}

template <class T>
Matrica<T>::~Matrica() {
    for(int i=0; i<redovi; i++) {
        delete matrica[i];
    }

    delete matrica;
}
