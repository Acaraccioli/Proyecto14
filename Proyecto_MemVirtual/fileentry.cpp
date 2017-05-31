#include "fileentry.h"

fileentry::fileentry(char *nom, int e, int t, bool f, int t)
{
    this->tamnom=strlen(nom);
    this->nombre=nom;
    this->empieza=e;
    this->termina=t;
    this->EsFolder=f;
    this->TamanoArchivo=t;
    //tamano de que?
}

fileentry::~fileentry()
{
    //dtor
}
