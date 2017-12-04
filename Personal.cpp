#include "Personal.h"

Personal::Personal(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad,string pFecha,long pSueldo):User(pNombre,pUsername,pPassword,pNumero,pId,pEdad){
      fecha = pFecha;
      sueldo = pSueldo;
    }

string Personal::getFecha(){
  return fecha;
}

void Personal::setFecha(string pFecha){
  fecha = pFecha;
}

long Personal::getSueldo(){
  return sueldo;
}

void Personal::setSueldo(long pSueldo){
  sueldo = pSueldo;
}
