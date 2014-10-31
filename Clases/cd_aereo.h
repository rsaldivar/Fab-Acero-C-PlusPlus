
#ifndef AEREO_H_
#define AEREO_H_
#include "cb_vehiculo.h"

class aereo : public vehiculo {
private:
	float altura;
	float superfice_alar;
	char tipo_aereo[50];

public:
  aereo(){};
	aereo(char* nombre, char* fabricante , char* costo, char* fecha);

  void setTipo(char* tipo);
  void setAltura(float altura);
	void setSuperficieAlar(float sup);
  const char* getTipo()const;
	float getAltura()const;
	float getSuperficiAlar()const;


	virtual void detalle_tipo_vehiculo(char* tipo)const;
	virtual void detalle_tripulacion(char* tripulacion)const ;
	virtual void detalle_peso()const ;
	virtual void detalle_velocidad(float velocidad)const ;
	virtual ~aereo();
};

#endif /* AEREO_H_ */
