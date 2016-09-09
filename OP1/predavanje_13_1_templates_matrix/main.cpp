#include <iostream>
#include "Matrica.h"

using namespace std;

int main() {
    typedef int tip;

    int redovi = 4;
    int kolone = 4;


    Matrica<tip> matrica1(redovi, kolone);
    matrica1.istampajMatricu();

    Matrica<tip> matrica2 = matrica1;

    tip **element = matrica2.getMatrica();
    element[0][0] = 9;

    cout << "Stampanje matrice dva: " << endl;
    matrica2.istampajMatricu();

    cout << "Stampanje matrice jedan: " << endl;
    matrica1.istampajMatricu();
}