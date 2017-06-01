#include "MB.h"

MB::MB(int tamArch, int tamB, archivo *a)
{
    this->TamanoBloque=tamB;
    this->CantidadBloques=((tamArch*1024*1024)/tamB);
    this->SiguienteBloqueDisponible=1;
    this->arch=a;

}
char * MB::MasterBlockToChar()
{
    int pos=0;
    char * datos= new char[12];
    memcpy(&datos[pos],&TamanoBloque,4);
    pos+=4;
    memcpy(&datos[pos],&CantidadBloques,4);
    pos+=4;
    memcpy(&datos[pos],&SiguienteBloqueDisponible,4);
    pos+=4;
    return datos;

}

void MB::Initfromchar(char * datos)
{
    int pos=0;
    memcpy(&TamanoBloque,&datos[pos],4);
    pos+=4;
    memcpy(&CantidadBloques,&datos[pos],4);
    pos+=4;
    memcpy(&SiguienteBloqueDisponible,&datos[pos],4);
    pos+=4;

}
void MB::Cargar()
{
    this->arch->Open();
    Initfromchar(this->arch->Read(0,TamanoBloque));
}
void MB::Guardar()
{
    this->arch->Open();
    this->arch->Write(0,MasterBlockToChar(),TamanoBloque);
}
MB::~MB()
{
    //dtor
}
