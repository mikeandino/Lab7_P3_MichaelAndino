#ifndef CLIENTE_H
#define CLIENTE_H
#include "User.h"
#include <string>
using namespace std;
  class Cliente : public User{
    private:
      string direccion;
      int rating;
    public:
      Cliente(string,string,string,string,string,int,string,int);
      string getDireccion();
      void setDireccion(string);
      int getRating();
      void setRating(int);
    };
    #include "Cliente.cpp"
#endif
