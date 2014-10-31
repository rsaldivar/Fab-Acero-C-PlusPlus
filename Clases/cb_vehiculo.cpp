/*
 * vehiculo.cpp
 *
 *  Created on: 13/05/2012
 *      Author: artser
 */
#include "cb_vehiculo.h"

vehiculo::vehiculo(char* nombre , char* fabricante , char* costo , char* fecha = "No identificada")
{
  strcpy(this->nombre_vehiculo,nombre);                          
  strcpy(this->fabricante_vehiculo ,fabricante);                          
  strcpy(this->costo_vehiculo,costo);
  strcpy(this->fecha_vehiculo,fecha);
}

void vehiculo::setNombre(char* nombre){
	strcpy(this->nombre_vehiculo,nombre);
}
const char* vehiculo::getNombre()const{
	return this->nombre_vehiculo;
}

void vehiculo::setFabricante(char* fabricante){
	strcpy(this->fabricante_vehiculo,fabricante);
}
const char* vehiculo::getFabricante()const{
	return this->fabricante_vehiculo;
}

void vehiculo::setPathImagen(const char *dir ){
 strcpy(this->imagen_vechiculo,dir );
}
const char* vehiculo::getPathImage()const{
	return this->imagen_vechiculo;
}

void vehiculo::setCosto(char* costo){
	strcpy( this->costo_vehiculo  , costo);
}

const char* vehiculo::getCosto()const{
	return this->costo_vehiculo;
}

void vehiculo::setFecha(char* fecha){
	strcpy( this->fecha_vehiculo , fecha );
}
const char* vehiculo::getFecha()const{
	return this->fecha_vehiculo;
}

void vehiculo::setPeso(float peso){
	this->peso_vechiculo = peso ;
}
float vehiculo::getPeso()const{
	return this->peso_vechiculo;
}

void vehiculo::setVelocidad(float velocidad){
	this->velocidad_vehiculo = velocidad ;
}
float vehiculo::getVelocidad()const{
	return this->velocidad_vehiculo;
}

vehiculo::~vehiculo(){};
