#include "User.h"

User::User(){

};

User::User(string pNombre,string pUsername,string pPassword,string pNumero,string pId,int pEdad){
      nombre=pNombre;
      username=pUsername;
      password=pPassword;
      numero=pNumero;
      edad=pEdad;
      id=pId;
    }

string User::getNombre(){
  return nombre;
}

void User::setNombre(string pNombre){
  nombre = pNombre;
}

string User::getUsername(){
  return username;
}

void User::setUsername(string pUsername){
  username = pUsername;
}

string User::getPassword(){
  return password;
}

void User::setPassword(string pPassword){
  password = pPassword;
}

string User::getNumero(){
  return numero;
}

void User::setNumero(string pNumero){
  numero = pNumero;
}

int User::getEdad(){
  return edad;
}

string User::getId(){
  return id;
}

void User::setId(string pId){
  id = pId;
}

void User::setEdad(int pEdad){
  edad = pEdad;
}

User::~User(){

}
