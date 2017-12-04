#ifndef MESERO_H
#define MESERO_H
#include "Personal.h"
#include <string>
#include <vector>
using namespace std;
  class Mesero : public Personal{
    private:
      vector<string> platillos;
    public:
      Mesero(string,string,string,string,string,int,string,long);
      vector<string> getPlatillos();
      void setPlatillos(vector<string>);
      void addPlatillo(string);
      void entregarPlatillo();
      void entregarPlatillos();
    };
    #include "Mesero.cpp"
#endif
