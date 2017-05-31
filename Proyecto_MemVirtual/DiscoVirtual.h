#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H
#include "archivo.h"
#include "MB.h"

class DiscoVirtual
{
    public:
        DiscoVirtual(char * nombre, int tam);
        void formatear();
        list<fileentry*> ListarArchivos(int actual);
        void agregarNuevoBloque(char*nombre,char *cont,int actual,bool esFolder);
        archivo *ar;
        char* nombre
        MB *mb;
        int tamano;
    protected:

    private:
};

#endif // DISCOVIRTUAL_H
