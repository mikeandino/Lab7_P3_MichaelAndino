#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "Personal.h"
#include <string>
using namespace std;
  class Administrador : public Personal{
    private:
      int contratados;
      int despedidos;
    public:
      Administrador(string,string,string,string,string,int,string,long);
      int getContratados();
      void setContratados(int);
      int getDespedidos();
      void setDespedidos(int);
    };
    #include "Administrador.cpp"
#endif
