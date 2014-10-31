//============================================================================
// Name        : Proyecto_C++_Vehiculos.cpp
// Authores    : RobertoSaldivarArmendariz . Jose Lam Cansino , Angel David Escobedo Castillo
// Version     : 2
// Description : Programa que mediante el manejo de ficheron en c++, 
//               lee varchivos con la informacion de vehiculos militares.
//               y la muestra en pantalla.
//============================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Clases/cd_aereo.h"
#include "Clases/cd_marino.h"
#include "Clases/cd_terrestre.h"
#include "Excepciones.h"
#include "Open_Cv.h"

using namespace std;
 
// DIrecciones de los arhivos  
const char *dir1 = "archivos/aereos.dat";
const char *dir2 = "archivos/marinos.dat";
const char *dir3 = "archivos/terrestres.dat";


int vista_previa( const char* dir )
{
  // Asignar a la imagen el archivo con la direccion dir.  
  imagen = cvLoadImage(  dir  );//Cargar la imagen segun su direccion
  cvNamedWindow("CATALOGO  DE VEHICULOS  ",CV_WINDOW_AUTOSIZE); // Crear una ventana
  cvMoveWindow("CATALOGO  DE VEHICULOS  ",300,300);//Posicion de la ventana emergente
  
  for(int i = 0 ; i < 50 ; i++)
  {
  cvSmooth( imagen, imagen,CV_GAUSSIAN,3,3,1,0);//Aplicacion de efeccto smooth
  cvShowImage("CATALOGO  DE VEHICULOS  ",imagen);//Mostra La imagen
  cvWaitKey(60);//Pausa de 60 milisegundos.
 }    
}
 
  
 
int main() {
  //Objetos que usaremos para mostrar la informacion, y leer con stream archivo  
  aereo *obj1 = new aereo();
  marino *obj2 = new marino();
  terrestre *obj3  = new terrestre(); 
  
  //Asignarle color blanco a cmd y un titulo ala ventana    
  system("color f0 & title INFORMACION IMAGEN");
  
  try{
  ifstream arch1( dir1 , ios::in | ios::binary );  //Apertura del archivo en modo lectura
  if(!arch1)throw Excepcion_stream(dir1);
  do{   arch1.read( reinterpret_cast<char *>(obj1) , sizeof(aereo));
       if(arch1.eof())break;
       
       system("cls");
       cout << "Nombre                  :  " <<  obj1->getNombre() << endl;
       cout << "Fabricante              :  " <<  obj1->getFabricante() <<endl;
       cout << "Fecha produccion        :  " <<  obj1->getFecha() << endl;
       cout << "Costo                   :  " <<  obj1->getCosto() << endl;      
       vista_previa( obj1->getPathImage()  ); 
   }while(true);
   arch1.close();
  }
  catch(Excepcion_stream& e)
  {
  cout << "Falta un archivo , consuta al administrador ";
  }

     try{
  ifstream arch2( dir2 , ios::in | ios::binary );
  if(!arch2)throw Excepcion_stream(dir2);
  
  do{  arch2.read( reinterpret_cast<char *>(obj2) , sizeof(marino));
       if(arch2.eof())break;
       system("cls");
       cout << "Nombre                  :  " <<  obj2->getNombre() << endl;
       cout << "Fabricante              :  " <<  obj2->getFabricante() <<endl;
       cout << "Fecha produccion        :  " <<  obj2->getFecha() << endl;
       cout << "Costo                   :  " <<  obj2->getCosto() << endl;      
       vista_previa( obj2->getPathImage()  ); 
   }while(true);
   arch2.close();
  }
  catch(Excepcion_stream& e)
  {
  cout << "Falta un archivo , consuta al administrador ";
  } 
  
  
  try{
  ifstream arch3( dir3 , ios::in | ios::binary );
  if(!arch3)throw Excepcion_stream(dir3);
  
  do{  arch3.read( reinterpret_cast<char *>(obj3) , sizeof(terrestre));
       if(arch3.eof())break;
       system("cls");
       cout << "Nombre                  :  " <<  obj3->getNombre() << endl;
       cout << "Fabricante              :  " <<  obj3->getFabricante() <<endl;
       cout << "Fecha produccion        :  " <<  obj3->getFecha() << endl;
       cout << "Costo                   :  " <<  obj3->getCosto() << endl;      
       vista_previa( obj3->getPathImage()  ); 
   }while(true);
   arch3.close();
  }
  catch(Excepcion_stream& e)
  {
  cout << "Falta un archivo , consuta al administrador ";
  }
  
  
  
  
  return 0;
}
