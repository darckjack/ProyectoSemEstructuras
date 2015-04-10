/*
* Nombre: Juan Jesus Gomez Barajas
* Codigo: 214519467
* Seccion: D01
*/

#ifdef _WIN32
#define LIMPIAR "cls"
#else
#define LIMPIAR "clear"
#endif // _WIN32

#include <iostream>

#include "include/Fotografo.h"
#include "include/Obra.h"
#include "include/Categoria.h"
#include "include/Node.h"
#include "include/ListF.h"
#include "include/ListO.h"
#include "include/ListCat.h"

using namespace std;

void addCat();
void deletecat();

ListCat<Categoria> myCatList;
ListF myFotList;
ListO myObList;
Obra myObra;
Fotografo myFot;
Categoria myCat;
void addFot ();
void delFot ();
void foundFot ();

int main() {
    char OpcionMen;
    int OpcionFot, OpcionObr, OpcionCat;

    do {
        system("cls");
        cout << "   Galeria de arte " << endl << endl;
        cout << " 1.Fotografo\n 2.Obra\n 3.Categoria\n 4.Salir" << endl << endl;
        cout << "Elige una opcion: ";
        cin  >> OpcionMen;

        switch(OpcionMen) {

        case '1': {
            int End = 1;

            do {
                system("cls");
                cout << "El contenido de la lista es ";
                myFotList.print();
                cout << endl << endl;
                cout << "                 Fotografo   " << endl << endl;
                cout << " 1.Dar de alta un fotografo" << endl;
                cout << " 2.Mostrar lista de fotografos" << endl;
                cout << " 3.Buscar fotografo" << endl;
                cout << " 4.Eliminar" << endl;
                cout << " 5.Regresar al menu anterior" << endl << endl;
                cout << " Elige una opcion: ";
                cin >> OpcionFot;

                switch(OpcionFot) {
                case 1: {
                    addFot();
                }
                break;

                case 2: {
                    myFotList.print();
                    system("pause");
                }
                break;

                case 3: {
                    foundFot();
                }
                break;

                case 4: {
                    delFot();
                }
                break;

                case 5: {
                    End = 0;
                }
                break;

                default:
                    cout << "Esta opcion es invalida";
                    system("pause");

                }//fin switch
            } while(End);
        }
        break;

        case '2': {
            system("cls");
            cout << "                 Obras   " << endl << endl;
            cout << " 1.Dar de alta una obra" << endl;
            cout << " 2.Mostrar lista de obras" << endl;
            cout << " 3.Modificar obra" << endl;
            cout << " 4.Buscar obra" << endl;
            cout << " 5.Eliminar" << endl;
            cout << " 6.Regresar al menu anterior" << endl << endl;
            cout << " Elige una opcion: ";
            cin >> OpcionObr;
        }
        break;

        case '3': {
            int End = 1;

            do {
                system("cls");
                cout << "El contenido de la lista es: " << endl;
                myCatList.print();
                cout << endl;
                cout << "        Categoria      " << endl << endl;
                cout << " 1.Capturar categoria" << endl;
                cout << " 2.Eliminar" << endl;
                cout << " 3.Mostrar lista de categorias" << endl;
                cout << " 4.Regresar al menu anterior" << endl;
                cout << " Elige una opcion: ";
                cin  >> OpcionCat;

                switch (OpcionCat) {
                case 1: {
                    addCat();
                }
                break;

                case 2: {
                    deletecat();
                }
                break;

                case 3: {
                    myCatList.print();
                }
                break;

                case 4: {
                    End = 0;
                }
                break;

                default:
                    cout << "Esta opcion es invalida";
                    system("pause");
                }//fin switch
            } while (End);//fin while
        }
        break;


        }

    } while(OpcionMen != '4');//Fin while
}//Fin main

void addCat() {
    string myStr;
    char opcionadd;

    do {
        system("cls");
        cout << "Ingrese el nombre de la categoria: ";
        cin.ignore();
        cout<<"aki";

        getline(cin, myStr);
        cout<<"aki 2";
        myCat.setName(myStr);
        cout<<"aki 3";
        myCatList.insertData(myCatList.lastPos(), myCat);

        cout << "Otra? (s/n)";
        cin >> opcionadd;
        cin.ignore();

    } while (opcionadd != 'n');

}

void deletecat() {
    char opciondelete;
    int pos;

    do {
        cout << "Ingrese el numero de la categoria a eliminar: ";
        cin >> pos;
        myCatList.deleteData(pos);

        cout << endl << "Otra? (s/n)";
        cin >> opciondelete;

    } while (opciondelete != 'n');
}

void addFot () {
    string myStr;
    int myInt;
    char opcionadd;

    do {
        system("cls");
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, myStr);
        myFot.setName(myStr);
        cout << "Experiencia: ";
        cin >> myInt;
        cin.ignore();
        myFot.setExperience(myInt);
        cout << "Ciudad de origen: ";
        getline(cin, myStr);
        myFot.setCity(myStr);
        cout << "Edad: ";
        cin >> myInt;
        cin.ignore();
        myFot.setAge(myInt);
        cout << "Telefono: ";
        getline(cin, myStr);
        myFot.setPhone(myStr);

        myFotList.insertData(myFotList.lastPos(), myFot);

        cout << "Otra? (s/n)";
        cin >> opcionadd;
        cin.ignore();

    } while (opcionadd != 'n');

}

void delFot () {
    char opciondelete;
    string myStr;
    Fotografo myFotg;


    do {
        cout << "Ingrese el nombre del fotografo a eliminar: ";
        cin >> myStr;
        myFotg.setName(myStr);
        myFotList.deleteData(myFotList.findData(myFotg));

        cout << endl << "Otra? (s/n)";
        cin >> opciondelete;

    } while (opciondelete != 'n');
}


void foundFot () {
    string myStr;

    cout << "Dame el nombre del fotografo a buscar: ";
    getline(cin, myStr);
    cin.ignore();
    myFot.setName(myStr);

    myFotList.findData(myFot);

}
