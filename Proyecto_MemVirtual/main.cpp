#include <iostream>
#include "DiscoVirtual.h"

using namespace std;

int main()
{
    DiscoVirtual *dv = new DiscoVirtual("C",1024*1024);

   /* archivo * ar = new archivo("disco", 1024*1024);
    BloqueA * ba = new BloqueA("Archivo", "Contenido", 2, 2, ar);
    BloqueF * bf = new BloqueF("Folder1",4096,5,5,ar);

    ba->Guardar();
    bf->Guardar();

    BloqueA * ba2 = new BloqueA("","", 0, 0, ar);
    ba2->InitFromChar(ar->Read(2*4096, 4096));
    BloqueF * bf2 =new BloqueF("",0,0,0,ar);
    bf2->InitFromChar(ar->Read(5*4096,4096));


    cout << ba2->nombre << endl;
    cout << ba2->contenido << endl;
    cout <<dv->foldActual->nombre<<endl;
    cout <<bf2->nombre<<endl;
    cout <<bf2->numerobloque<<endl;

    cout << "Hello world!5" << endl;*/
    dv->AgregarFolder("Foldeer1");
    dv->AgregarFolder("Foldeer2");
    dv->AgregarFolder("Foldeer3");
    dv->AbrirFolder();






    return 0;
}
