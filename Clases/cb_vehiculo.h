#ifndef VEHICULO_H_
#define VEHICULO_H_
#include <iostream>
#include <cstring>
using namespace std;

class vehiculo {
private:
  int    clave_vehiculo;      
  char   nombre_vehiculo[50];
  char   imagen_vechiculo[50];
  char   fabricante_vehiculo[50];
  char   fecha_vehiculo[50];
  char   costo_vehiculo[50];
  float  peso_vechiculo;
  float  velocidad_vehiculo;
  
public:
  vehiculo(){};     
  vehiculo(char* nombre, char* fabricante , char* costo , char* fecha );
  
  void setClave(int clave_vehiculo){this->clave_vehiculo=clave_vehiculo; };
  void setNombre(char* nombre);
  void setFabricante(char* fabricante);
  void setPathImagen(const char* direccion= "NULL");
  void setCosto(char* costo);
  void setFecha(char* fecha);
  void setPeso(float peso);
  void setVelocidad(float velocidad);
 
  const char* getNombre()const;
  const char* getFabricante()const;
  const char* getCosto()const;
  const char* getFecha()const;
  const char* getPathImage()const;
  float getPeso()const;	
  float getVelocidad()const;
  int  getClave(){return clave_vehiculo;}
  
  virtual void detalle_tipo_vehiculo(char* tipo)const = 0;
  virtual void detalle_tripulacion(char* tripulacion)const = 0 ;
  virtual void detalle_peso()const = 0 ;
  virtual void detalle_velocidad(float velocidad)const = 0;
  
  virtual ~vehiculo();
};

#endif /* VEHICULO_H_ */
