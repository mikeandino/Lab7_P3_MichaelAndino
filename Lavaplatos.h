#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H
#include "Personal.h"
#include <string>
using namespace std;
  class Lavaplatos : public Personal{
    private:
      int motivacion;
    public:
      Lavaplatos(string,string,string,string,string,int,string,long);
      int getMotivacion();
      void setMotivacion(int);
      bool Renunciar();
      void Aumento();
    };
    #include "Lavaplatos.cpp"
#endif
