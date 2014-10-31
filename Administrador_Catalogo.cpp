//============================================================================
// Name        : Admnitrador_Catalogo.cpp
// Authores    : RobertoSaldivarArmendariz . Jose Lam Cansino , Angel David Escobedo Castillo
// Version     : 2
// Description : Programa que mediante el manejo de ficheron en c++, 
//               crea archivos con la informacion de vehiculos militares.
//               y la muestra en pantalla , con la posibilidad de hacer
//                 altas , modificaciones y consultas , tambein fabrica un reporte .
//============================================================================
#include <iostream>
#include <fstream>
#include <cstring>//Realizar operaciones con string.h de c.
#include <cstdlib>//Llamadas al system
#include <iomanip>//Formato a flujos de entra-salida
#include "Objetos_Default.h"
#include "Modulo_Alta.h"
#include "Modulo_Consulta.h"
#include "Modulo_Modificaciones.h"
#include "Modulo_Reporte.h"

using namespace std;

void  Bienvenido();
void  Entrar_Sistema();
void  Validar_Usuario();
int   Menu_Sistema_Administracion();
char  Tipo_Vehiculo(const char* mensaje );
int   Agregar();
int   Consultar();
int   Modificar();
void  clean();
void  pauseClear();
void  Cargar_Clases_Default();

int main() {
  Bienvenido();
  Entrar_Sistema();
  return 0;
}

void Entrar_Sistema(){
  char opcion ;
  while(true)
  { cout << setw(8)  <<" Deseas ingresar al Sistema ? [s/n] : ";
    opcion = '\0';
    fflush(stdin);
    opcion = cin.get();
    if(  opcion == 's' || opcion == 'S' )Validar_Usuario();
    else if( opcion  == 'n' || opcion == 'N' ) exit(1);
         else Excepcion_respuesta_SN();
    pauseClear();
  }
    
}

void Validar_Usuario()
{ char const *name = "usuario";
  char const *pass = "12345";
  char  nombre[30];
  char  contra[20];
  while (true)
  { clean();
    cout << "\n\n\t\t INGRESA LOS SIGUIENTES DATOS " <<endl;
    cout << "\n\n\t Nombre  default(usuario)  : ";
    cin.getline(nombre,30)  ;
    cout << "\n\n\t Matricula default(12345  ): ";
    cin.getline(contra ,20);
    if( strcmp(name , nombre) == 0 )
      if (strcmp(pass , contra) == 0) Menu_Sistema_Administracion();
      else cout << "Password incorrecto ";
    else cout<< "Usuario Invalido";
    pauseClear();
  }
}

int Menu_Sistema_Administracion()
{ system("cls");
  cout << "Quieres Cargar los Objetos POr Defualt ?? [s/n] :" << endl ;
  if( cin.get() == 's' )Cargar_Clases_Default();//Crea 7objetos aereo,5marinos y 5 terrestres,
  
  char opcion ;
  while(true)
  {
   system("title ****************************************** MENU-ADMINISTRADOR*************************");
   clean();
   cout <<"\n\t\t\t OPCIONES DE ADMINISTRADOR. "
        <<"\n\n\n\t\t\t 1) ALTA."
        <<"\n\n\n\t\t\t 2) CONSULTA."
        <<"\n\n\n\t\t\t 3) MODIFICACIONES."
        <<"\n\n\n\t\t\t 4) REPORTES."
        <<"\n\n\n\t\t\t 5) SALIR."
        <<"\n\n\n\t\t\t Opcion : ";
  cin >> opcion;
  switch(opcion)
  {
    case '1': { system("title ALTA");
                Agregar();
              }
    break;
    case '2': { system("title CONSULTA");
                Consultar();
              }
    break;
    case '3': { system("title MODIFICAR");
                Modificar();
              }
    break;
    case '4': { system("title REPORTE");
                Reporte();
              }
    break;
    case '5': exit(1) ;
    break;
    default : cout << "Opocion invalidad concentrate porfavor!!";
    break;
  }//Finswitch
}//Finwhile
  return 0;
}//Fin ControlAdminitracion



char Tipo_Vehiculo(const char* mensaje )
{ clean();
  cout <<"\n\t\t" << mensaje ;
  cout <<"\n\n\t\t\t TIPOS DE VEHICULOS. "
       <<"\n\n\n\t\t\t 1) AEREO."
       <<"\n\n\n\t\t\t 2) MARITIMO."
       <<"\n\n\n\t\t\t 3) TERRESTRE."
       <<"\n\n\n\t\t\t 4) Ninguno."
       <<"\n\n\n\t\t\t Opcion : ";
 
  return cin.get();
}


int Agregar()
{
  while(true)
  {
    switch (Tipo_Vehiculo("######### ALTAS #########"))
    { case '1':{ clean(); Agregar_Registro( 1 );}
      break;
      case '2':{ clean(); Agregar_Registro( 2 );}
      break;
      case '3':{ clean(); Agregar_Registro( 3 );}
      break;
      case '4': return 0 ;
      break;
    }
    pauseClear();
  }
  return 0;
}

int Consultar()
{ while(true)
  {
    switch (Tipo_Vehiculo("######### CONSULTAS #########" ) )
    { case '1': Consulta( 1 );
      break;
      case '2': Consulta( 2 );
      break;
      case '3': Consulta( 3 );
      break;
      case '4': return 0;
      break;
    }
    pauseClear();
  }
  return 0;
}

int Modificar()
{ while(true)
  {
    switch (Tipo_Vehiculo("######### MODIFICACIONES #########" ) )
    { case '1': Modificacion( 1 );
      break;
      case '2': Modificacion( 2 );
      break;
      case '3': Modificacion( 3 );
      break;
      case '4': return '0';
      break;
    }
    pauseClear();
  }
  return '0';
}


void Bienvenido()
{system("color f0 & title ADMI_VEHICULOS");
}
void Cargar_Clases_Default()
{ Crear_Archivo_Aereos();
  Crear_Archivo_Marinos();
  Crear_Archivo_Terrestres(); 

}
void clean()
{ system("cls");
  fflush(stdin);
}
void pauseClear()
{ cout <<"\n\n\t\t\t\t";
  system("pause & cls");
}
