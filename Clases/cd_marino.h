
#ifndef MARINO_H_
#define MARINO_H_
#include "cb_vehiculo.h"

class marino : public vehiculo{
  float eslora;
  int helices;
  float manga;
  char sistema_propulsion[50];
  
public:
  marino(){};
  marino(char* nombre, char* fabricante , char* costo, char* fecha);

  /*Funciones set clase marino*/
  void setHelices(int helices);
  void setEslora(float eslora);
  void setManga(float manga);
  void setSistemaPropulsion(char* sistemaPropulsion);

  /*Funciones gets de clase marino */
  int getHelices()const;
  float getEslora()const;
  float getManga()const;
  const char* getSistemaPropulsion()const;

  /*Funciones virtuales heredadas*/
  virtual void detalle_tipo_vehiculo(char* tipo)const;
  virtual void detalle_tripulacion(char* tripulacion)const ;
  virtual void detalle_peso()const ;
  virtual void detalle_velocidad(float velocidad)const ;

  virtual ~marino();
};

#endif /* MARINO_H_ */
