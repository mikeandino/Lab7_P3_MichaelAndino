#include "Mesero.h"

Mesero::Mesero(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad,string pFecha,long pSueldo):Personal(pNombre,pUsername,pPassword,pNumero,pId,pEdad,pFecha,pSueldo){

    }

vector<string> Mesero::getPlatillos(){
  return platillos;
}

void Mesero::setPlatillos(vector<string> pPlatillos){
  platillos = pPlatillos;
}

void Mesero::addPlatillo(string pPlatillo){
  platillos.push_back(pPlatillo);
}

void Mesero::entregarPlatillo(){
  if (platillos.size()!=0) {
    for (int i = 0; i < platillos.size(); i++) {
      cout << i << ' ' << platillos.at(i) << '\n';
    }
    cout << "Ingrese el numero del platillo que desea entregar: ";
    int eleccion;
    cin >> eleccion;
    while (eleccion < 0 || eleccion >= platillos.size()) {
      cout << "Opcion invalida, por favor vuelva a ingresar: ";
      cin >> eleccion;
    }
    cout << "El platillo " << platillos.at(eleccion) << "a sido entregado." << '\n';
    platillos.erase(platillos.begin() + eleccion);
  }else{
    cout << "No hay platillos que entregar" << '\n';
  }
}

void Mesero::entregarPlatillos(){
  if (platillos.size()!=0) {
    platillos.erase(platillos.begin(),platillos.end());
    cout << "Todos los platillos han sido entregados." << '\n';
  }else{
    cout << "No hay platillos que entregar" << '\n';
  }
}
