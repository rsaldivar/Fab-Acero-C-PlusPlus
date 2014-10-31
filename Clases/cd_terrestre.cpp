/*
 * terrestre.cpp
 *
 *  Created on: 13/05/2012
 *      Author: artser
 */

#include "cd_terrestre.h"

terrestre::terrestre(char* nombre, char* fabricante , char* costo , char* fecha )
: vehiculo(nombre,fabricante,costo,fecha){}

void terrestre::setAltura(float altura ){
  this->altura = altura;
}
float terrestre::getAltura()const {
  return altura;
}

void terrestre::setAnchura(float anchura){
  this->anchura = anchura;
}
float terrestre::getAnchura()const{
  return anchura;
}

void terrestre::setBlindaje(char* blindaje){
  strcpy(this->blindaje ,blindaje);
}

const char* terrestre::getBlindaje()const{
  return blindaje;
}


void terrestre::setMotor(char* motor){
  strcpy(this->motor , motor);
}
const char* terrestre::getMotor()const{
  return motor;
}

void terrestre::setArmamento(char* armamento){
  strcpy(this->armamento , armamento);
}
const char* terrestre::getArmamento()const{
  return armamento;
}

void terrestre::setLonguitud(float longuitud){
 this->longuitud=longuitud;
}
float terrestre::getLonguitud()const{
 return longuitud;
}



void terrestre::detalle_peso()const{
}
void terrestre::detalle_tipo_vehiculo(char* x)const{
}
void terrestre::detalle_tripulacion(char* x)const{
}
void terrestre::detalle_velocidad(float v)const{
}

terrestre::~terrestre() {
	// TODO Auto-generated destructor stub
}

