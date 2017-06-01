#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(char*nombre,int tam)
{
    this->nombre= nombre;
    this->tamano=tam;
    this->ar= new archivo(nombre,tam);
    formatear();
}

void DiscoVirtual::formatear()
{
    mb= new MB(tamano,4096,this->ar);
    //BloqueF raiz= new BloqueF(this->nombre,this->tamano,0,1,ar);
    BloqueF * raiz= new BloqueF("raiz",this->tambloque,1,-1,ar);
    raiz->Guardar();
    mb->SiguienteBloqueDisponible=2;;
    mb->Guardar();
    this->foldActual=raiz;
}
 list<fileentry*> DiscoVirtual::ListarArchivos(int actual)
 {
     //BloqueF bf= new BloqueF(this->nombre,this->tamano,actual,actual+1,ar);
    char *data= ar->Read(actual * mb->TamanoBloque,mb->TamanoBloque);
    BloqueF *bf= new BloqueF("",0,0,0,ar);
    bf->InitFromChar(data);

    list<fileentry*> lista=bf->FE;
    while(foldActual->sigbloque!=-1){
        char*data=ar->Read(foldActual->numerobloque*tambloque,tambloque);
        foldActual->InitFromChar(data);
        list<fileentry*>::iterator it =lista.end();
        lista.splice(it, foldActual->FE);
    }

    return lista;
 }
 void DiscoVirtual::AbrirFolder()
 {
     cout<<2<<endl;
    // list<fileentry*> temp=ListarArchivos(foldActual->numerobloque);
        list<fileentry*> temp=foldActual->FE;

     for(list<fileentry*>::iterator l=temp.begin();l!=temp.end();l++)
        {
                    fileentry *imp=*l;
                    cout<<imp->nombre<<endl;
                    cout<<8<<endl;

        }


 }
 void DiscoVirtual::AgregarFolder(char * nom)
 {
     agregarNuevoBloque(nom," ",this->foldActual->numerobloque,true);
     cout <<"Se Agrego Folder"<<endl;
 }
void DiscoVirtual::AgregaArchivo(char * nom, char * cont)
{
    agregarNuevoBloque(nom,cont,this->foldActual->numerobloque,false);
    cout<<"Se Agrego Archivo"<<endl;
}
 void DiscoVirtual::agregarNuevoBloque(char*nombre,char*cont,int actual,bool esFolder)
 {
     int pb=mb->SiguienteBloqueDisponible;
     int tam=20+strlen(nombre)+strlen(cont);
     int ub= pb+tam/mb->TamanoBloque;
     BloqueF *foldActual= new BloqueF("", 0,0,0,ar);
     char *data=ar->Read(actual*mb->TamanoBloque,mb->TamanoBloque);
     foldActual->InitFromChar(data);
     fileentry *fe= new fileentry("",0,0,false,0);

     if(esFolder){
        BloqueF *bf= new BloqueF(nombre, tambloque, mb->SiguienteBloqueDisponible, -1, ar);
        bf->Guardar();
        mb->SiguienteBloqueDisponible = pb+1;
        fileentry *f=new fileentry(nombre,pb,pb,true, 17+strlen(nombre));
     }
     else{
        BloqueA * ba= new BloqueA(nombre,cont,pb,ub,ar);
        ba->Guardar();
        mb->SiguienteBloqueDisponible = pb+1;
        fileentry *e= new fileentry(nombre,pb, ub, false, 17+strlen(nombre));
     }
     while(foldActual->sigbloque!=-1){
        data = ar->Read(foldActual->sigbloque * tambloque, tambloque);
        foldActual->InitFromChar(data);
     }

     if(fe->TamanoArchivo<(foldActual->capacidadbloque-foldActual->tambloque)){
        foldActual->agregarfe(fe);
        foldActual->Guardar();
    }
    else{
        BloqueF *folder= new BloqueF(fe->nombre,tambloque,mb->SiguienteBloqueDisponible, -1, ar);
        foldActual->sigbloque = (folder->numerobloque);
        folder->agregarfe(fe);
        folder->Guardar();
        mb->SiguienteBloqueDisponible = (mb->SiguienteBloqueDisponible+1);
        foldActual->Guardar();
    }
 }
