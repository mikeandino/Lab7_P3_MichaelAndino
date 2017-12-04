#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "User.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Chef.h"
#include "Lavaplatos.h"
#include "Mesero.h"
using namespace std;

int main();

vector<User*> admin(Administrador*,vector<User*>);

vector<User*> emplear(vector<User*>);

void cliente(Cliente*,vector<User*>);

vector<User*>  chef(Chef*,vector<User*>);

vector<User*> lavaplatos(Lavaplatos*,vector<User*>);

void mesero(Mesero*);

vector<User*> creacliente(vector<User*>);

void promedio(vector<User*>);

int main() {
  vector<User*> lista;
  if (lista.size()==0) {
    string nombre,username,password,numero,id,fecha;
    int edad;
    long sueldo;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su username: ";
    cin >> username;
    cout << "Ingrese su password: ";
    cin >> password;
    cout << "Ingrese su numero de telefono: ";
    cin >> numero;
    cout << "Ingrese su edad: ";
    cin >> edad;
    while (edad < 18) {
      cout << "No es mayor de 18 años, ingrese otra edad: ";
      cin >> edad;
    }
    id="";
    srand(time(NULL));
    for (size_t i = 0; i < 16; i++) {
      id+=rand()%10;
    }
    cout << "Ingrese la fecha de su empleo: ";
    cin >> fecha;
    cout << "Ingrese su sueldo: ";
    cin >> sueldo;
    lista.push_back(new Administrador(nombre,username,password,numero,id,edad,fecha,sueldo));
  }
  int opcion=0;
  cout  << '\n';
  do {
    cout << "Restaurante sin Nombre." << '\n'
         << "  1. Login" << '\n'
         << "  2. Crear una cuenta de Cliente" << '\n'
         << "  3. Salir" << '\n'
         << "Ingrese una Opcion: ";
    cin >> opcion;
    if (opcion == 1) {
      bool login = false;
      string user, pass;
      cout << "Ingrese su username: ";
      cin >> user;
      cout << "Ingrese su password: ";
      cin >> pass;
      int pos;
      for (int i = 0; i < lista.size(); i++) {
        if ((lista.at(i)->getUsername()==user)&&lista.at(i)->getPassword()==pass) {
          login = true;
          pos = i;
        }
      }
      if (login) {
        if (dynamic_cast<Cliente *>(lista.at(pos))) {
          cout  << '\n';
          cliente((dynamic_cast<Cliente *>(lista.at(pos))),lista);
        } else if (dynamic_cast<Administrador *>(lista.at(pos))) {
          cout  << '\n';
          lista = admin((dynamic_cast<Administrador *>(lista.at(pos))),lista);
        }else if (dynamic_cast<Chef *>(lista.at(pos))) {
          cout  << '\n';
          lista = chef((dynamic_cast<Chef *>(lista.at(pos))),lista);
        } else if (dynamic_cast<Lavaplatos *>(lista.at(pos))) {
          cout  << '\n';
          lista = lavaplatos((dynamic_cast<Lavaplatos *>(lista.at(pos))),lista);
        } else {
          cout  << '\n';
          mesero((dynamic_cast<Mesero *>(lista.at(pos))));
        }
      } else {
        cout << "Usuario/Password incorrectos." << '\n';
      }
    }else if(opcion == 2){
      cout << '\n';
      lista=creacliente(lista);
    }else if(opcion == 3){

    }else if(opcion == 0){
      cout << '\n';
      for (int i = 0; i < lista.size(); i++) {
        cout << lista.at(i)->getNombre() << '\n';
      }
    }else{
      cout << "Opcion Invalida.\n\n";
    }
    cout << '\n';
  } while(opcion!=3);
  for (int i = 0; i < lista.size(); i++) {
    delete lista.at(i);
  }
  return 0;
}

vector<User*> admin(Administrador* yo, vector<User*> lista) {
  int opcion=0;
  cout << "Bienvenido "<< yo->getNombre() <<"." << '\n';
  do {
    cout << "  1. Contratar empleado." << '\n'
         << "  2. Despedir empleado" << '\n'
         << "  3. Conseguir al empleado con menor sueldo" << '\n'
         << "  4. Agregar platillo a un mesero." << '\n'
         << "  5. Conseguir al empleado con mayor sueldo." << '\n'
         << "  6. Conseguir el promedio de sueldo de todos los empleados." << '\n'
         << "  7. Log Out" << '\n'
         << "Ingrese una Opcion: ";
    cin >> opcion;
    if (opcion == 1) {
      cout << '\n';
      lista = emplear(lista);
      yo->setContratados(yo->getContratados()+1);
    } else if (opcion == 2) {
      cout << '\n';
      cout << "Ingrese el numero de la persona que desea despedir." << '\n';
      for (int i = 0; i < lista.size(); i++) {
        cout << i <<". " << lista.at(i)->getNombre() << endl;
      }
      cout << "Ingrese su opcion: ";
      int pos;
      cin >> pos;
      while (pos < 0 || pos >= lista.size()) {
        cout << "Opcion invalida" << '\n';
        cin >> pos;
      }
      if (yo->getUsername() == lista.at(pos)->getUsername()) {
        cout << "No se puede despedir a si mismo." << '\n';
      }else if (!(dynamic_cast<Cliente *>(lista.at(pos)))) {
        delete lista.at(pos);
        lista.erase(lista.begin()+pos);
        std::cout << "El empleado a sido despedido." << '\n';
        yo->setDespedidos(yo->getDespedidos()+1);
      }else{
        cout << "El usuario no es un empleado." << endl;
      }
    } else if (opcion == 3) {
      cout << '\n';
      cout << "El usuario con menor sueldo es: ";
      string menor = "";
      long sueldo = 900000000000;
      for (int i = 0; i < lista.size(); i++) {
        if (dynamic_cast<Personal *>(lista.at(i))) {
          Personal* p = dynamic_cast<Personal *>(lista.at(i));
          if (p->getSueldo() < sueldo) {
            sueldo = p->getSueldo();
            menor = p->getNombre();
          }else if (p->getSueldo() == sueldo) {
            menor += " y " + p->getNombre();
          }
        }
      }
      std::cout << menor << "." << '\n';
    } else if (opcion == 4) {
      cout << '\n';
      cout << "Ingrese el numero del mesero que desea añadir el platillo." << '\n';
      for (int i = 0; i < lista.size(); i++) {
        cout << i <<". " << lista.at(i)->getNombre() << endl;
      }
      cout << "Ingrese su opcion: ";
      int pos;
      cin >> pos;
      while (pos < 0 || pos >= lista.size()) {
        cout << "Opcion invalida" << '\n';
        cin >> pos;
      }
      if (yo->getUsername() == lista.at(pos)->getUsername()) {
        cout << "Usted no es un mesero." << '\n';
      }else if ((dynamic_cast<Mesero *>(lista.at(pos)))) {
        string platillo;
        cout << "Ingrese el nombre del platillo que desea agregarle a " << lista.at(pos)->getNombre() << ':';
        cin >> platillo;
        Mesero* m = dynamic_cast<Mesero *>(lista.at(pos));
        m->addPlatillo(platillo);
        cout << "El platillo a sido agregado." << '\n';
      }else{
        cout << "El usuario no es un mesero" << endl;
      }
    } else if (opcion == 5) {
      cout << '\n';
      cout << "El usuario con mayor sueldo es: ";
      string mayor = "";
      long sueldo = 0;
      for (int i = 0; i < lista.size(); i++) {
        if (dynamic_cast<Personal *>(lista.at(i))) {
          Personal* p = dynamic_cast<Personal *>(lista.at(i));
          if (p->getSueldo() > sueldo) {
            sueldo = p->getSueldo();
            mayor = p->getNombre();
          }else if (p->getSueldo() == sueldo) {
            mayor += " y " + p->getNombre();
          }
        }
      }
      cout << mayor << "." << '\n';
    } else if (opcion == 6) {
      long sueldo=0;
      long empleados = 0;
      for (int i = 0; i < lista.size(); i++) {
        if (dynamic_cast<Personal *>(lista.at(i))) {
          empleados++;
          Personal* p = dynamic_cast<Personal *>(lista.at(i));
          sueldo += p->getSueldo();
        }
      }
      int prom = sueldo/empleados;
      cout << "El promedio de todo los sueldos es: " << prom << '.' << '\n';
    } else if (opcion == 7) {
      /* code */
    } else {
      cout << "Opcion invalida" << '\n';
    }
    cout << '\n';
  } while(opcion!=7);
  return lista;
}

vector<User*> emplear(vector<User*> lista) {
  string nombre,username,password,numero,id,fecha;
  int edad;
  long sueldo;
  cout << "Ingrese el nombre del nuevo empleado: ";
  cin >> nombre;
  cout << "Ingrese el username del nuevo empleado: ";
  cin >> username;
  cout << "Ingrese el password del nuevo empleado: ";
  cin >> password;
  cout << "Ingrese el numero de telefono del nuevo empleado: ";
  cin >> numero;
  cout << "Ingrese la edad del nuevo empleado: ";
  cin >> edad;
  while (edad < 18) {
    cout << "No es mayor de 18 años, ingrese otra edad: ";
    cin >> edad;
  }
  id="";
  bool unico = false;
  do {
    srand(time(NULL));
    for (int i = 0; i < 16; i++) {
      id+=rand()%10;
    }
    for (size_t i = 0; i < lista.size(); i++) {
        if (!unico) {
          unico = (id == lista.at(i)->getId());
        }
    }
  } while(unico);
  cout << "Ingrese la fecha del empleo del nuevo empleado: ";
  cin >> fecha;
  cout << "Ingrese el sueldo del nuevo empleado: ";
  cin >> sueldo;
    cout << "El empleado sera?" << '\n'
         << "  1. Administrador." << '\n'
         << "  2. Chef" << '\n'
         << "  3. Lavaplatos" << '\n'
         << "  4. Mesero." << '\n'
         << "Ingrese una Opcion: ";
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 4) {
      cout << "Opcion invalida:";
      cin >> opcion;
    }
    if (opcion == 1) {
      lista.push_back(new Administrador(nombre,username,password,numero,id,edad,fecha,sueldo));
      cout << "Administrador creado." << '\n';
    } else if (opcion == 2) {
      string platillo;
      cout << "Ingrese el platillo favorito del chef: ";
      cin >> platillo;
      lista.push_back(new Chef(nombre,username,password,numero,id,edad,fecha,sueldo,platillo));
      cout << "Chef creado." << '\n';
    } else if (opcion == 3) {
      lista.push_back(new Lavaplatos(nombre,username,password,numero,id,edad,fecha,sueldo));
      cout << "Lavaplatos creado." << '\n';
    } else {
      lista.push_back(new Mesero(nombre,username,password,numero,id,edad,fecha,sueldo));
      cout << "Mesero creado." << '\n';
    }
    return lista;
}

vector<User*>  chef(Chef* yo,vector<User*> lista){
  int opcion=0;
  cout  << '\n';
  cout << "Bienvenido "<< yo->getNombre() <<"." << '\n';
  do {
    cout << "  1. Gritarle a un Lavaplatos." << '\n'
         << "  2. Agradarle a un lavaplatos" << '\n'
         << "  3. Log out" << '\n'
         << "Ingrese una Opcion: ";
    cin >> opcion;
    cout << '\n';
    if (opcion == 1) {
      cout << '\n';
      cout << "Ingrese el numero del lavaplatos que desea gritarle." << '\n';
      for (int i = 0; i < lista.size(); i++) {
        cout << i <<". " << lista.at(i)->getNombre() << endl;
      }
      cout << "Ingrese su opcion: ";
      int pos;
      cin >> pos;
      while (pos < 0 || pos >= lista.size()) {
        cout << "Opcion invalida" << '\n';
        cin >> pos;
      }
      if (yo->getUsername() == lista.at(pos)->getUsername()) {
        cout << "Haz gritado a ti mismo, pero no tiene efecto alguno." << '\n';
      }else if ((dynamic_cast<Lavaplatos *>(lista.at(pos)))) {
        Lavaplatos* victima = dynamic_cast<Lavaplatos *>(lista.at(pos));
        int valor;
        std::cout << "Inrese un valor a bajarle al lavaplatos: ";
        cin >> valor;
        while (valor<1) {
          cout << "No puede restarle numeros menor que 1: ";
          cin >> valor;
        }
        yo->Gritar(victima,valor);
      }else{
        cout << "El usuario no es un Lavaplatos" << endl;
      }
      cout << '\n';
    }else if (opcion == 2) {
      cout << '\n';
      cout << "Ingrese el numero del lavaplatos que deseas agradarle.";
      for (int i = 0; i < lista.size(); i++) {
        cout << i <<". " << lista.at(i)->getNombre() << endl;
      }
      cout << "Ingrese su opcion: ";
      int pos;
      cin >> pos;
      while (pos < 0 || pos >= lista.size()) {
        cout << "Opcion invalida" << '\n';
        cin >> pos;
      }
      if (yo->getUsername() == lista.at(pos)->getUsername()) {
        cout << "Tratas de agradarte a ti mismo, pero como siempre no tiene efecto alguno." << '\n';
      }else if ((dynamic_cast<Lavaplatos *>(lista.at(pos)))) {
        Lavaplatos* alero = dynamic_cast<Lavaplatos *>(lista.at(pos));
        int valor;
        std::cout << "Inrese un valor a incrementarle al lavaplatos: ";
        cin >> valor;
        while (valor<1) {
          cout << "No puede restarle numeros menor que 1: ";
          cin >> valor;
        }
        yo->Agradar(alero,valor);
      }else{
        cout << "El usuario no es un Lavaplatos" << endl;
      }
      cout << '\n';
    }else if (opcion == 3) {

    } else {
      cout << "Opcion Invalida" << '\n';
    }
  }while (opcion !=3);
  return lista;
}

vector<User*> lavaplatos(Lavaplatos* yo,vector<User*> lista){
  int opcion=0;
  cout  << '\n';
  cout << "Bienvenido "<< yo->getNombre() <<"." << '\n';
  do {
    cout << "  1. Renunciar." << '\n'
         << "  2. Pedir un aumento." << '\n'
         << "  3. Log out." << '\n'
         << "Ingrese una Opcion: ";
    cin >> opcion;
    cout << '\n';
    if (opcion == 1) {
      if (yo->Renunciar()) {
        int pos;
        for (int i = 0; i < lista.size(); i++) {
          if (yo->getUsername()==lista.at(i)->getUsername()) {
            pos = i;
          }
        }
        lista.erase(lista.begin()+pos);
        delete yo;
        opcion = 3;
      }
      cout << '\n';
    }else if (opcion == 2) {
      yo->Aumento();
      cout << '\n';
    }else if (opcion == 3) {

    } else {
      cout << "Opcion Invalida" << '\n';
    }
  }while (opcion !=3);
  return lista;
}

void mesero(Mesero* yo){
  int opcion=0;
  cout  << '\n';
  cout << "Bienvenido "<< yo->getNombre() <<"." << '\n';
  do {
    cout << "  1. Entregar un platillo." << '\n'
         << "  2. Entregar todos los platillos." << '\n'
         << "  3. Log out" << '\n'
         << "Ingrese una Opcion: ";
    cin >> opcion;
    cout << '\n';
    if (opcion == 1) {
      yo->entregarPlatillo();
      cout << '\n';
    }else if (opcion == 2) {
      yo->entregarPlatillos();
      cout << '\n';
    }else if (opcion == 3) {

    } else {
      cout << "Opcion Invalida" << '\n';
    }
  }while (opcion !=3);
}

void cliente(Cliente* yo,vector<User*> lista){
  int opcion=0;
  cout  << '\n';
  cout << "Bienvenido "<< yo->getNombre() <<"." << '\n';
  do {
    cout << "  1. Danos tu rating." << '\n'
         << "  2. Ver el promedio de los ratings." << '\n'
         << "  3. Log out" << '\n'
         << "Ingrese una Opcion: ";
    cin >> opcion;
    cout << '\n';
    if (opcion == 1) {
      int rating;
      cout << "Ingresa tu rating entre 1-5: " << '\n';
      cin >> rating;
      while (rating < 1 || rating > 5) {
        cout << "Opcion Invalida: ";
        cin >> rating;
      }
      yo->setRating(opcion);
      cout << "Gracias por su consideracion." << '\n';
      cout << '\n';
    }else if (opcion == 2) {
      promedio(lista);
      cout << '\n';
    }else if (opcion == 3) {

    } else {
      cout << "Opcion Invalida" << '\n';
      cout << '\n';
    }
  }while (opcion !=3);
}

vector<User*> creacliente(vector<User*> lista){
  string nombre,username,password,numero,id,direccion;
  int edad;
  cout << "Ingrese su nombre: ";
  cin >> nombre;
  cout << "Ingrese su username: ";
  cin >> username;
  cout << "Ingrese su password: ";
  cin >> password;
  cout << "Ingrese su numero de telefono : ";
  cin >> numero;
  cout << "Ingrese su edad: ";
  cin >> edad;
  while (edad < 18) {
    cout << "No es mayor de 18 años, ingrese otra edad: ";
    cin >> edad;
  }
  id="";
  bool unico = false;
  do {
    srand(time(NULL));
    for (int i = 0; i < 16; i++) {
      id+=rand()%10;
    }
    for (size_t i = 0; i < lista.size(); i++) {
        if (!unico) {
          unico = (id == lista.at(i)->getId());
        }
    }
  } while(unico);
  cout << "Ingrese su direccion: ";
  cin >> direccion;
  lista.push_back(new Cliente(nombre,username,password,numero,id,edad,direccion,1));
  return lista;
}

void promedio(vector<User*>lista){
  int ratings = 0;
  int clientes = 0;
  for (int i = 0; i < lista.size(); i++) {
    if (dynamic_cast<Cliente *>(lista.at(i))) {
      clientes++;
      Cliente* c = dynamic_cast<Cliente *>(lista.at(i));
      ratings += c->getRating();
    }
  }
  int prom = ratings/clientes;
  cout << "El promedio de todo los ratings es: " << prom << '.' << '\n';
}
