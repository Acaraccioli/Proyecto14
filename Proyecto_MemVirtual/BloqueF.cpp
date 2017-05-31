#include "BloqueF.h"

BloqueF::BloqueF(char *nombre, int capacidad,int numero int siguientebloque, archivo a)
{
    this->numerobloque=numero;
    this->sigbloque=siguientebloque;
    this->capacidadbloque=capacidad;
    this->tamnombre=strlen(nombre);
    this->nombre=nombre;
    this->arch=a;
    this->tambloque=16+tamnombre;
    //16 o 20??
    //sigbloque aqui siempre -1?
}
char * BloqueF::BloqueFtoChar()
{
    int pos=0;
    char *datos=new char[tambloque];
    memcpy(&datos[pos],numerobloque,4);
    pos+=4;
    memcpy(&datos[pos],sigbloque,4);
    pos+=4;
    memcpy(&datos[pos], capacidadbloque,4);
    pos+=4;
    memcpy(&datos[pos],tamnombre,4);
    pos+=4;
    memcpy(&datos[pos],nombre, tamnombre);
    pos+=tamnombre;
    return datos;

}
void BloqueF::InitFromChar(char * datos)
{
    int pos=0;
    memcpy(numerobloque,&datos[pos],4);
    pos+=4;
    memcpy(sigbloque,&datos[pos],4);
    pos+=4;
    memcpy(capacidadbloque,&datos[pos],4);
    pos+=4;
    memcpy(tamnombre,&datos[pos],4);
    pos+=4;
    memcpy(nombre,&datos[pos],tamnombre);
    pos+=tamnombre;
}
void BloqueF::Guardar()
{


    this->arch->Open();
    this->arch->Write(numerobloque*4096,BloqueFtoChar(),tambloque);

}
BloqueF::~BloqueF()
{
    //dtor
}
