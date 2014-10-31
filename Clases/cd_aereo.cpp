
#include "cd_aereo.h"

aereo::aereo(char* nombre, char* fabricante , char* costo , char* fecha )
: vehiculo(nombre,fabricante,costo,fecha){}

void aereo::setAltura(float altura){
	this->altura = altura;
}
float aereo::getAltura()const{
	return altura;
}

void aereo::setTipo(char* tipo){
  strcpy(this->tipo_aereo , tipo);
}

const char* aereo::getTipo()const{
  return tipo_aereo;
}
void aereo::setSuperficieAlar(float sup){
	this->superfice_alar = sup;
}
float aereo::getSuperficiAlar()const{
	return superfice_alar;
}

void aereo::detalle_tipo_vehiculo(char* tipo = "aereo" )const{
	cout << " Vehiculo aereo tipo : " << tipo ;
}

void aereo::detalle_peso()const
{
  cout << " El peso del vechiculo aereo es : " <<  aereo::getPeso() <<  endl;
}
void aereo::detalle_tripulacion(char* tripulacion = "1 piloto ")const
{
  cout << " La tripulacion del vechiulo aereo es  : " << tripulacion << endl;
}

void aereo::detalle_velocidad(float v = 0)const{   
	cout << " La velocidad del vechiculo aeereo es . " << v << endl;
}


aereo::~aereo() {
}

