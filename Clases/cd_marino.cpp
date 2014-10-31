/*
 * marino.cpp
 *  Created on: 13/05/2012
 *      Author: artser
 */

#include "cd_marino.h"

marino::marino(char* nombre, char* fabricante , char* costo , char* fecha )
: vehiculo(nombre,fabricante,costo,fecha){}

void marino::setHelices(int helices){
  this->helices = helices;
}
int marino::getHelices()const{
  return helices;
}


void marino::setEslora(float eslora){
  this->eslora = eslora ;
}
float marino::getEslora()const{
  return eslora;
}


void marino::setManga(float manga){
  this->manga= manga;
}
float marino::getManga()const{
  return manga;
}

void marino::setSistemaPropulsion(char* sistema_propulsion){
  strcpy(this->sistema_propulsion , sistema_propulsion);
}


const char* marino::getSistemaPropulsion()const{
  return sistema_propulsion;
}


void marino::detalle_peso()const{
}
void marino::detalle_tipo_vehiculo(char* x)const{
}
void marino::detalle_tripulacion(char* x)const{
}
void marino::detalle_velocidad(float v)const{
}

marino::~marino() {
}

