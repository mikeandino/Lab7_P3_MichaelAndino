#ifndef CHEF_H
#define CHEF_H
#include "Personal.h"
#include "Lavaplatos.h"
#include <string>
using namespace std;
  class Chef : public Personal{
    private:
      string platillo;
    public:
      Chef(string,string,string,string,string,int,string,long,string);
      string getPlatillo();
      void setPlatillo(string);
      void Gritar(Lavaplatos*,int);
      void Agradar(Lavaplatos*,int);
    };
    #include "Chef.cpp"
#endif
