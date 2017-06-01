#ifndef BLOQUEF_H
#define BLOQUEF_H
#include <list>
#include "fileentry.h"
#include <stdio.h>
#include "archivo.h"
using namespace std;


class BloqueF
{
    public:
        BloqueF(char *nombre, int capacidad,int numero, int siguientebloque, archivo *a);
        virtual ~BloqueF();
        int numerobloque;
        int tambloque;
        int capacidadbloque;
        int tamnombre;
        char * nombre;
        int sigbloque;
        list <fileentry*> FE;
        archivo *arch;
        void InitFromChar(char * datos);
        char * BloqueFtoChar();
        void Guardar();
        void agregarfe(fileentry * fe);

    protected:

    private:
};

#endif // BLOQUEF_H
