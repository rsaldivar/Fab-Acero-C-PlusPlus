#ifndef MODULO_ALTA_H_
#define MODULO_ALTA_H_
#include <cstdlib>
#include <fstream>
#include "Clases/cd_aereo.h"
#include "Clases/cd_marino.h"
#include "Clases/cd_terrestre.h"
#include "Excepciones.h"

int Agregar_Registro(int tipo)
{ 
  int id_clave_nueva , helices;
  char  nombre[30] , fabricante[30] , fecha[30] , costo[30] , tipo_Aereo[30];
  char  sist_prop[50], motor[50] , blindaje[50] , armamento[200];
  float peso , velocidad , sup_alar, anchura , altura , longuitud ,eslora,manga ;
  
  cout << "    INGRESA LOS SIGUIENTE DATOS "<<endl ;
  cout << "Nombre            (s): ";
  cin.getline( nombre , 30 );
  cout << "Fabricante        (s): ";
  cin.getline( fabricante , 30  );
  cout << "Costo             (s): ";
  cin.getline( costo , 30 );
  cout << "Fecha             (s): ";
  cin.getline(  fecha , 30 );
  cout << "Peso              (f): " ;
  cin >> peso;
  cout << "Velocidad         (f): " ;
  cin >> velocidad;
  
  aereo *obj1= new aereo(nombre, fabricante, costo , fecha);
  marino *obj2 = new marino(nombre, fabricante, costo , fecha);
  terrestre *obj3 = new terrestre(nombre, fabricante, costo, fecha);

 try{
  switch(tipo) //SEGUN SEA EL TIPO RECIVIDO CREAMOS UN OBJETO
  {
   case 1 :{   
               
               ofstream arch("archivos/aereos.dat", ios::app | ios::binary  );
               if(!arch)throw Excepcion_stream("NO SE CREO aereos.dat ");
               
               fflush(stdin);
               cout << "Altura max float  : " ; cin >> altura;
               obj1->setAltura(altura);
               cout << "Superficie Alar(f): " ; cin >> sup_alar;
               obj1-> setSuperficieAlar(sup_alar);
               fflush(stdin);
               cout << "Tipo aereo string : " ; cin.getline(tipo_Aereo,30);
               obj1->setTipo(tipo_Aereo);

               arch.write(reinterpret_cast<char *> (obj1), sizeof(aereo));
               arch.close();
               
           }
   break;
   case 2 :{  
               ofstream arch("archivos/marinos.dat", ios::app | ios::binary  );
               if(!arch)
               {  throw Excepcion_stream("NO SE CREO marinos.dat ");
               }
               cout << "Cantidad de helices      (d): "; cin >> helices; 
               obj2->setHelices(helices);
               fflush(stdin);
               cout << "Sistema de propulsion    (s): "; cin.getline(sist_prop,50);
               obj2->setSistemaPropulsion(sist_prop);
               cout << "Eslora                   (f): "; cin >> eslora;
               obj2->setEslora(eslora );
               cout << "Manga                    (f): "; cin >> manga;
               obj2->setManga( manga );
   
               arch.write(reinterpret_cast<char *> (obj2), sizeof(marino));
               arch.close();
               
           }  
   break;
   case 3 :{
               ofstream arch("archivos/terrestres.dat", ios::app | ios::binary  );
               if(!arch)
               {  throw Excepcion_stream("NO SE CREO terrestres.dat ");
               }
               cout << "Altura            (f): "; cin >> altura;
               obj3->setAltura(altura);
               cout << "Anchura           (f): "; cin >> anchura;
               obj3->setAnchura(anchura);
               cout << "Longitud          (f): "; cin >> longuitud;
               obj3->setLonguitud( longuitud );
               fflush(stdin);
               cout << "Blindaje          (s): "; cin.getline(blindaje,30);
               obj3->setBlindaje(blindaje);
               cout << "Motor             (s): "; cin.getline(motor ,50);
               obj3->setMotor( motor);
               cout << "Armamento         (s): "; cin.getline(armamento,200);
               obj3->setArmamento( armamento);
               
               arch.write(reinterpret_cast<char *> (obj3), sizeof(terrestre));
               arch.close();
              
            }
   break;
   }
  }
  catch(Excepcion_stream& e)
  {
     cout << " NO SE PUEDE DAR ALTAS " ;
     return -1;         
  }
  delete obj1,obj2,obj3;
}

#endif /* MODULO_ALTA_H_ */
