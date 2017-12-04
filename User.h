#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
  class User{
  protected:
    string nombre,username,password,numero,id;
    int edad;
  public:
    User();
    User(string,string,string,string,string,int);
    string getNombre();
    void setNombre(string);
    string getUsername();
    void setUsername(string);
    string getPassword();
    void setPassword(string);
    string getNumero();
    void setNumero(string);
    string getId();
    void setId(string);
    int getEdad();
    void setEdad(int);
    virtual ~User();
  };
  #include "User.cpp"
#endif
