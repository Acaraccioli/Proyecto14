#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(char * nombre, int tam)
{
    this->nombre= nombre;
    this->tamano=tam;
    this->ar= new archivo(nombre,tam);
}

void DiscoVirtual::formatear()
{
    mb= new MB(int tamArch,int tamB,this->ar);
    BloqueF bf= new BloqueF(this->nombre,this->tamano,0,1,ar);
}
 list<fileentry*> DiscoVirtual::ListarArchivos(int actual)
 {
     //BloqueF bf= new BloqueF(this->nombre,this->tamano,actual,actual+1,ar);
     char *data= ar->Read(actual * mb->TamanoBloque,mb->TamanoBloque);
     BloqueF *bf= new BloqueF(data,mb->TamanoBloque,actual,mb->SiguienteBloqueDisponible,mb->arch);
     bf->InitFromChar(data);

     list<fileentry*> lista=bf->FE;
     for(int x=0,x<mb->CantidadBloques,x++){
        copyEntries(lista,list *destino);
     }
 }

 void DiscoVirtual::agregarNuevoBloque(char*nombre,char*cont,int actual,bool esFolder)
 {
     int pb=mb->SiguienteBloqueDisponible;
     int tam=20+strlen(nombre)+strlen(cont);
     int ub= pb+tam/mb->TamanoBloque;
     BloqueF foldActual= new BloqueF(NULL);
     char *data=ar->Read(actual*mb->TamanoBloque,mb->TamanoBloque);
     foldActual->InitFromChar(data);
     fileentry *fe= new fileentry(NULL);

     if(esFolder){
        BloqueF *bf= new BloqueF(nombre,mb->SiguienteBloqueDisponible,mb->TamanoBloque,mb->arch);
        bf->Guardar();
        mb->setSiguienteBD(pb+1);
        fileentry *f=new fileentry(nombre,pb,ub,true);
     }
     else{
        BloqueA ba= new BloqueA(nombre,cont,pb,ub,mb->arch);
        ba->Guardar();
        mb->setSiguienteBD(pb+1);
        fileentry *e= new fileentry(nombre,pb,false);
     }
     while(foldActual->sigbloque==-1){
        formatear();
        if(mb->SiguienteBloqueDisponible>fe->tamnom){
            foldActual->agregarfe(fe);
            foldActual->Guardar();
        }
        else{
            BloqueF folder= new BloqueF(fe->nombre,mb->SiguienteBloqueDisponible,mb->TamanoBloque,mb->arch);
            foldActual->setSig(folder->numerobloque);
            folder->agregarfe(fe);
            folder->Guardar();
            mb->setSig(mb->SiguienteBloqueDisponible+1);
            foldActual->Guardar();
            mb->Guardar();
        }
     }
 }
