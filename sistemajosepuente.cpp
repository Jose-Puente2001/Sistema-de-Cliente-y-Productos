#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int opcion;
void clientes();
void productos();
void menu();


//variables para gestionar a los clientes
int edad;
string nombre;
string apellido;
string cedula;
int telefono;

//variables para gestionar los productos
int cantidad;
string codigo;
string nombreproducto;

void menu(){
cout<<"...................................................."<<endl;
cout<<"Realizador por:   "<<endl;
cout<<"Jose Gabriel Puente Salgueiro. C.I: 28.340.072  "<<endl;
cout<<"Ingenieria de Sistemas 3er semestre seccion A "<<endl;
cout<<"...................................................."<<endl;

cout<<"Sistema"<<endl;
cout<<"1)Clientes"<<endl;
cout<<"2)Productos"<<endl;
cout<<"Elige una opcion: ";
cin>>opcion;

switch(opcion){

 case 1: 
   clientes();
  break;
  case 2:
    productos();
  break;
}

}

void clientes(){


   ofstream archivo;
   ofstream fichero;
  
  archivo.open("datos-cliente.txt",ios::app);
  fichero.open("cedula-clientes.txt",ios::app);

  cout<<"ingresa la cedula del cliente: ";
  cin>>cedula;

ifstream indata("cedula-clientes.txt");
string line;

/*Aqui lo que hago es primero leer el archivo y luego verifico si existe en el archivo. Despuès convierto el string a un entero. Esto lo logro gracias a la libreria sstream 
 que lo que hace es convertir un string a un entero. Lo cual luego me facilita buscar ese dato en el archivo y realizar la comparacion de 
 cada línea  que se lea en el  archivo se va haciendo la comparación con la cadena de búsqueda que entre por consola
  si se encuentra se termina la lectura. Esta misma logica la implemento con los productos.
*/

while (getline(indata, line)) {
   istringstream iss(line);
    string cedulasingresada, cedulaalmacenada;

    if (!(iss >> cedulasingresada >> cedulaalmacenada)) { 
           break; 
      }

    while(cedula==cedulaalmacenada) {
      cout << "la cedula ya existe en el sistema!. Por favor ingresa una cedula diferente"<<endl;
      cout<<"ingresa la cedula del cliente: ";
      cin>>cedula;
    }
   
       

  }


fichero<<"cedula:  "<<cedula<<endl;
fichero.close();

cout<<"ingresa la edad del cliente: ";
  cin>>edad;

  while(edad<18){
  
   cout<<"Solo se permite clientes mayores de edad!. Por favor ingresa de nuevo la edad "<<endl;
   cout<<"ingresa la edad del cliente: ";
   cin>>edad;

 }


archivo<<"Edad: "<<edad<<endl;
 cout<<"ingresa el nombre del cliente: ";
  cin>>nombre;
  cout<<"ingresa el apellido del cliente: ";
  cin>>apellido;
  cout<<"ingresa el numero de telefono del cliente: ";
  cin>>telefono;
  archivo<<"Nombre: "<<nombre<<endl;
  archivo<<"Apellido: "<<apellido<<endl;
  archivo<<"telefono:"<<telefono<<endl;

  archivo.close();
  

}





void productos(){

   ofstream archivo;
   archivo.open("producto.txt",ios::app);

  cout<<"ingresa el codigo del producto: ";
  cin>>codigo;
  

  ifstream indata("producto.txt");
  string line;

  while (getline(indata, line)) {
   istringstream iss(line);
    string codigoingresado, codigoalmacenado;

   if (!(iss >> codigoingresado >> codigoalmacenado)) { 
           break; 
      }

    while (codigo== codigoalmacenado) {
      cout << "el codigo de producto ya existe en el sistema!. Por favor ingresa un codigo diferente"<<endl;
      cout<<"ingresa el codigo del producto: ";
      cin>>codigo;
    
    }
   
       

  }

  archivo<<"Codigo:  "<<codigo<<endl;
 

  cout<<"ingresa el nombre del producto: ";
  cin>>nombreproducto;
  cout<<"ingresa la cantidad del producto: ";
  cin>>cantidad;
  archivo<<"Nombre:  "<<nombreproducto<<endl;
  archivo<<"Cantidad:  "<<cantidad<<endl;

 archivo.close();

}




int main(){

menu();


return 0;
}
