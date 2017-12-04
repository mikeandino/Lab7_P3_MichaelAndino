#include "Lavaplatos.h"

Lavaplatos::Lavaplatos(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad,string pFecha,long pSueldo):Personal(pNombre,pUsername,pPassword,pNumero,pId,pEdad,pFecha,pSueldo){
      motivacion = 50;
    }

int Lavaplatos::getMotivacion(){
  return motivacion;
}

void Lavaplatos::setMotivacion(int pMotivacion){
  motivacion = pMotivacion;
}

bool Lavaplatos::Renunciar(){
  if (motivacion <= 25)
    cout << nombre << " a renunciado." << '\n';
  else
    cout << "Aun no puedes renunciar." << '\n';
  return (motivacion <= 25);
}

void Lavaplatos::Aumento(){
  if (motivacion >= 100){
    cout << "Ingrese el aumento: ";
    int aumento;
    cin>>aumento;
    while (aumento>sueldo) {
      cout << "Aumento muy grande, por favor ingresar otra vez: ";
      cin>>aumento;
    }
    sueldo=sueldo+aumento;
    cout << "Su sueldo es ahora de " << sueldo << '.' << '\n';
  }else{
    cout << "No tienes la motivacion suficente para pedir un aumento." << '\n';
  }
}
