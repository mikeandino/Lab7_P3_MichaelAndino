#ifndef PERSONAL_H
#define PERSONAL_H
#include "User.h"
#include <string>
using namespace std;
  class Personal : public User{
  protected:
      string fecha;
      long sueldo;
    public:
      Personal(string,string,string,string,string,int,string,long);
      string getFecha();
      void setFecha(string);
      long getSueldo();
      void setSueldo(long);
    };
    #include "Personal.cpp"
#endif
