#include <iostream>
#include <fstream>
using namespace std;

void ingresar();
void mostrar();

  string nombre,apellido, carrera,Narchivo;
  int edad;
  char a;
  ofstream archivo1;
 

int main() 
{
  int opcion;
  do
  {
  cout<<"*******************"<<endl;
  cout <<"MENU DE OPCIONES"<<endl;
  cout<<"1.Ingresar datos"<<endl;
  cout<<"2.Mostrar datos"<<endl;
  cout<<"*******************"<<endl;
  cout <<"Ingrese una opcion: ";
  //while(getchar()!='\n')
  cin>>opcion;
    switch(opcion)
  {
    case 1:
    {
    cout<<"A selecionado ingresar datos"<<endl;
    ingresar();
    }
    break;
    case 2:
    cout<<"A selecionado mostrar datos"<<endl;
    mostrar();
    break;
    case 3:
    cout <<"La opcion seleccionada es incorrecta";

  }
  }while(a=='n'&& 'N');
  
}

void ingresar()
{
    cout<<"Ingrese el nombre del archivo: ";
    while(getchar()!='\n');
    getline(cin,Narchivo);
    archivo1.open(Narchivo.c_str(), ios::out);
  do{
    cout<<"\t Ingrese nombre: ";
    getline(cin,nombre);
    cout<<"\t Ingrese apellido: ";
    getline(cin,apellido);
    cout<<"\t Ingrese carrera: ";
    getline(cin,carrera);
    cout<<"\t Ingrese edad: ";
    cin>>edad;
    archivo1<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Quiere ingresar otro contacto [s/n]: ";
    cin>>a;
    cin.ignore();
  }while(a=='s');
  archivo1.close();

}

void mostrar()
{
  ifstream archivolecura(Narchivo.c_str());
  string texto;
  if(archivolecura.fail()){
   cout<<"EL ARCHIVO NO SE A PODIDO LEER";
 }
 else{
   while(!archivolecura.eof()){
    archivolecura>>nombre>>apellido>>carrera>>edad;
  if(!archivolecura.eof())
     {
     cout<<"Nombre: "<<nombre<<endl;
     cout<<"Apellido: "<<apellido<<endl;
     cout<<"Carrera: "<<carrera<<endl;
     cout<<"Edad: "<<edad<<endl;
     }
   }
 }
 archivolecura.close();
}

