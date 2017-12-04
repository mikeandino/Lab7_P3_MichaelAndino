#include "Chef.h"
#include "Lavaplatos.h"

Chef::Chef(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad,string pFecha,long pSueldo,string pPlatillo):Personal(pNombre,pUsername,pPassword,pNumero,pId,pEdad,pFecha,pSueldo){
      platillo = pPlatillo;
    }

string Chef::getPlatillo(){
  return platillo;
}

void Chef::setPlatillo(string pPlatillo){
  platillo = pPlatillo;
}

void Chef::Gritar(Lavaplatos* victima,int valor){
  victima->setMotivacion(victima->getMotivacion()-valor);
  cout << "La motivacion de " << victima->getNombre() << " a bajado a " << victima->getMotivacion() << '.' << '\n';
}

void Chef::Agradar(Lavaplatos* alero,int valor){
  alero->setMotivacion(alero->getMotivacion()+valor);
  cout << "La motivacion de " << alero->getNombre() << " a subido a " << alero->getMotivacion() << '.' << '\n';
}
