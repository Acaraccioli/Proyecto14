#ifndef MB_H
#define MB_H
#include "archivo.h"
#include <stdio.h>
using namespace std;


class MB
{
    public:
        MB(int tamArch, int tamB, archivo *a);
        int TamanoBloque;
        int CantidadBloques;
        //primer bloque archivo?
        int SiguienteBloqueDisponible;
        archivo *arch;
        char *MasterBlockToChar();
        void Guardar();
        void Initfromchar(char *data);
        void Cargar();
        virtual ~MB();

    protected:

    private:
};

#endif // MB_H
