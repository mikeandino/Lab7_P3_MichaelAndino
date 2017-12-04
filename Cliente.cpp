#include "Cliente.h"

Cliente::Cliente(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad,string pDireccion,int pRating):User(pNombre,pUsername,pPassword,pNumero,pId,pEdad){
      direccion = pDireccion;
      rating = pRating;
    }

string Cliente::getDireccion(){
  return direccion;
}

void Cliente::setDireccion(string pDireccion){
  direccion = pDireccion;
}

int Cliente::getRating(){
  return rating;
}

void Cliente::setRating(int pRating){
  rating = pRating;
}
