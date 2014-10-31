#ifndef MODULO_REPORTE_H_
#define MODULO_REPORTE_H_

#include <cstdlib>
#include <fstream>
#include "Clases/cd_aereo.h"
#include "Clases/cd_marino.h"
#include "Clases/cd_terrestre.h"
#include "Excepciones.h"

using namespace std;

template<class T1 , class T2 , class T3 , class T4 , class T5 >
void escribir_reporte( ostream& fout  ,T1 nombre , T2 fecha , T3 costo , T4 fabricante, T5 clave ){
 
  fout << "# ----------------------------------------#";
  fout << clave << endl;
  fout << "NOMBRE           : " << nombre     << endl;
  fout << "FECHA            : " << fecha      << endl;
  fout << "COSTO            : " << costo      << endl;
  fout << "FABRICANTE       : " << fabricante << endl;

}

void Generar_Reportes()
{ //Streams para leer el archivo, e imprimir del reporte 
  
  aereo obj1;
  marino obj2;
  terrestre obj3;
  int contador = 0;
  
  ///CREAR REPORTE DE AEREOS
  try{
  ifstream fin( "archivos/aereos.dat", ios::in |  ios::binary );
  if(!fin)throw Excepcion_stream("No existe aereos.dat");
  fin.seekg(0,ios::beg);
  
  ofstream fout( "reporte_aereos.txt" , ios::out );
  if(!fout)throw Excepcion_stream( "reporte aereo" );
  fout <<  "\n\t############### REPORTE AEREOS ###################" <<endl ;
  
  do{
      fin.read( reinterpret_cast<char *>(&obj1) , sizeof(aereo));//LEEMOS DEL ARCHIVO Y GUARDAMOS EL OBJETO
      if(fin.eof())break;//DETENEMOS EL BUCLE SI ES FIN DE ARCHIVO
      contador++;
      escribir_reporte(fout,obj1.getNombre() ,obj1.getFecha() , obj1.getFabricante() ,obj1.getCosto(), contador );

      }while(true);//BUCLE DOWHILE 
  fin.close();
  fout.close();

  }catch(Excepcion_stream& e)
  { cout << "Error Stream ";
  }
 

  ///CREAR REPORTE DE MARINOS
  try{
  ifstream  fin( "archivos/marinos.dat", ios::in |  ios::binary );
  if(!fin)throw Excepcion_stream("No existe marinos.dat");
  fin.seekg(0,ios::beg);
  
  ofstream fout( "reporte_marinos.txt" , ios::out );
  if(!fout)throw Excepcion_stream( "reporte marinos" );
  fout <<  "\n\t############### REPORTE MARINOS ###################" <<endl ;
  
  contador = 0;
  do{
      fin.read( reinterpret_cast<char *>(&obj2) , sizeof(marino));//LEEMOS DEL ARCHIVO Y GUARDAMOS EL OBJETO
      if(fin.eof())break;//DETENEMOS EL BUCLE SI ES FIN DE ARCHIVO
      contador++;
      escribir_reporte(fout,obj2.getNombre() ,obj2.getFecha() , obj2.getFabricante() ,obj2.getCosto(), contador );

      }while(true);//BUCLE DOWHILE 
  fin.close();
  fout.close();
  }catch(Excepcion_stream& e)
  { cout << "Error Stream ";
  }
  
  
  
  ///CREAR REPORTE DE TERRESTRES
  try{
  ifstream  fin( "archivos/terrestres.dat", ios::in |  ios::binary );
  if(!fin)throw Excepcion_stream("No existe terrestres.dat");
  fin.seekg(0,ios::beg);
  
  ofstream  fout( "reporte_terrestres.txt" , ios::out );
  if(!fout)throw Excepcion_stream( "reporte terrestres" );
  fout <<  "\n\t############### REPORTE ESTRES ###################" <<endl ;
 
  contador = 0;
  do{
      fin.read( reinterpret_cast<char *>(&obj3) , sizeof(terrestre));//LEEMOS DEL ARCHIVO Y GUARDAMOS EL OBJETO
      if(fin.eof())break;//DETENEMOS EL BUCLE SI ES FIN DE ARCHIVO
      contador++;
      escribir_reporte(fout,obj3.getNombre() ,obj3.getFecha() , obj3.getFabricante() ,obj3.getCosto(), contador );

      }while(true);//BUCLE DOWHILE 
  fin.close();
  fout.close();  
  }catch(Excepcion_stream& e)
  { cout << "Error Stream ";
  }
   
}


int Reporte()
{ system("cls");
  Generar_Reportes();
  cout << "\n\n\n\t ***"
       << "\n\t\t a) Abrir Reporte Vehiculos Aereos"
       << "\n\t\t m) Abrir Reporte Vehiculos Marino"
       << "\n\t\t t) Abrir Reporte Vehiculos Terrestre"
       << "\n\t\t x) ninguno"
       
       <<"\n\n INGRESA LA OPCION :";
  fflush(stdin);
  switch(cin.get()) 
  {
    case 'a':{system("reporte_aereos.txt & pause");} 
    break ;
    case 'm':{system("reporte_marinos.txt & pause");}
    break ;
    case 't':{system("reporte_terrestres.txt & pause");}
    break ;
    case 'x': return 0;
    break ;                 
  }     
  
}
#endif /* MODULO_ALTA_H_ */
