#include "Administrador.h"

Administrador::Administrador(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad,string pFecha,long pSueldo):Personal(pNombre,pUsername,pPassword,pNumero,pId,pEdad,pFecha,pSueldo){
      contratados = 0;
      despedidos = 0;
    }

int Administrador::getContratados(){
  return contratados;
}

void Administrador::setContratados(int pContratados){
  contratados = pContratados;
}

int Administrador::getDespedidos(){
  return despedidos;
}

void Administrador::setDespedidos(int pDespedidos){
  despedidos = pDespedidos;
}
