#include <iostream>
#include "DiscoVirtual.h"


using namespace std;

int main()
{
    DiscoVirtual *dv = new DiscoVirtual("C~",1024*1024);
//
//    archivo * ar = new archivo("disco", 1024*1024);
//    BloqueA * ba = new BloqueA("Archivo", "Contenido", 2, 2, ar);
//    BloqueF * bf = new BloqueF("Folder1",4096,5,5,ar);
//
//    ba->Guardar();
//    bf->Guardar();
//
//    BloqueA * ba2 = new BloqueA("","", 0, 0, ar);
//    ba2->InitFromChar(ar->Read(2*4096, 4096));
//    BloqueF * bf2 =new BloqueF("",0,0,0,ar);
//    bf2->InitFromChar(ar->Read(5*4096,4096));
//
//
//    cout << ba2->nombre << endl;
//    cout << ba2->contenido << endl;
//    cout <<dv->foldActual->nombre<<endl;
//    cout <<bf2->nombre<<endl;
//    cout <<bf2->numerobloque<<endl;
//
//    cout << "Hello world!5" << endl;
//    dv->AgregarFolder("Foldeer1");
//    dv->AgregarFolder("Foldeer2");
//    dv->AgregarFolder("Foldeer3");
//    cout<<"abriendo"<<endl;
//    dv->AbrirFolder();
    int opcion=0;
    while(opcion!=7)
    {
    cout << "1. Formatear Disco\n2. Crear Folder\n3. Crear Archivo\n4. Listar Archivos\n5. Abrir Documento\n6. Regresar a Folder Anterior\n7. Salir"<<endl;
    cin >> opcion;
    char *nom=new char[1];
    char * cont=new char[1];

    switch (opcion)
    {
    case 1:
        dv->formatear();
        break;
    case 2:
        cin >> nom;
        dv->AgregarFolder(nom);
        break;
    case 3:
        cin >> nom >>cont;
        dv->AgregaArchivo(nom,cont);
        break;
    case 4:
        dv->AbrirFolder();
        break;
    case 5:
        cin >> nom;
        dv->Abrir(nom);
        break;
    case 6:

        break;
    case 7:
        dv->ar->Close();
        cout<<"Cerrando Programa"<<endl;
        break;
    }
    }





    return 0;
}
