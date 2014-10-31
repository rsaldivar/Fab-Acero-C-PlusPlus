
#ifndef TERRESTRE_H_
#define TERRESTRE_H_
#include "cb_vehiculo.h"

class terrestre : public vehiculo {
  float altura;
  float anchura;
  char  armamento[200];
  char  blindaje[50];
  float longuitud;
  char  motor[50];
	
public:
    terrestre(){};
	terrestre(char* nombre, char* fabricante , char* costo, char* fecha);

	void setAltura(float altura);
	void setAnchura(float anchura);
	void setLonguitud(float longuitud);
	void setBlindaje(char* blindaje);
	void setMotor(char* motor);
	void setArmamento(char* armamento);

	float getAltura()const;
	float getAnchura()const;
	float getLonguitud()const;
	const char* getBlindaje()const;
	const char* getMotor()const;
	const char* getArmamento()const;

	virtual void detalle_tipo_vehiculo(char* tipo)const;
    virtual void detalle_tripulacion(char* tripulacion)const ;
    virtual void detalle_peso()const ;
    virtual void detalle_velocidad(float velocidad)const ;

	virtual ~terrestre();
};

#endif /* TERRESTRE_H_ */
