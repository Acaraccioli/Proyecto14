#ifndef BLOQUEA_H
#define BLOQUEA_H
#include "archivo.h"
#include <stdio.h>
#include <iostream>
using namespace std;


class BloqueA
{
    public:
        BloqueA();
        virtual ~BloqueA();
        int tambloque;
        int tamnombre;
        char * nombre;
        int tamcont;
        char * contenido;
        int primerbloque;
        int ultimobloque;
        archivo *arch;
        void InitFromChar(char * info);
        char * BloqueArchtoChar();
        void Guardar();

    protected:

    private:
};

#endif // BLOQUEA_H
