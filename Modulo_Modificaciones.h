#include <iostream>
#include <fstream>
#include "Clases/cd_aereo.h"
#include "Clases/cd_marino.h"
#include "Clases/cd_terrestre.h"
using namespace std;

void Menu_Modificacion_General()
{ 
  cout << " === menu de modificaciones == \n\n" 
       << " 1 )  Nombre \n"
       << " 2 )  Fabricante \n"
       << " 3 )  Fecha fabricacion \n"
       << " 4 )  costo  \n";
}
void Menu_Modificacion_Aereos()
{
  cout << " 5 )  altura \n"
       << " 6 )  superficie alar \n"
       << " 7 )  Tipo de vehiculo aereo \n"
       << " x )  Ninguna \n"
       << " Opcion  :  ";
}
void Menu_Modificacion_Marinos()
{
  cout << " 5 )  Eslora    \n"
       << " 6 )  Helices   \n"
       << " 7 )  Manga     \n"
       << " 8 )  Sistema Propulsion  \n"
       << " x )  Ninguna   \n"
       << " Opcion  :  ";
}
void Menu_Modificacion_Terrestres()
{
  cout << " 5 )  Altura \n"
       << " 6 )  Anchura \n"
       << " 7 )  Armamento  \n"
       << " 8 )  Blindaje  \n"
       << " 9 )  Longuitud \n"
       << " 0 ) Motor  \n"
       << " x )  Ninguna \n"
       << " Opcion  :  ";
}



/*MOdificacion , realiza la busqueda del registro segun el tipo del vehiculo recibido como parametro*/
int Modificacion(int tipo  ){
  
  aereo obj1;
  marino obj2;
  terrestre obj3; 
  
  int clave = 0 , contador = 0 ;
  char x[30];
           
  try{
      
  system("cls");
  cout << "\n\n CLAVE  \t NOMBRE VEHICULO \n\n"<<endl;
  clave = 0; contador = 0; 
    
  switch(tipo)
  {
  case 1 :{
           fstream arch("archivos/aereos.dat" , ios::out | ios::in | ios::binary );
           if(!arch)throw Excepcion_stream("No existe aereos.dat");//VALIDAMOS QUE EXISTA EL ARCHIVO
           arch.clear();//Limpiar el error eof
           arch.seekg(0,ios::beg);//NOS POSUCIONAMOS AL INICIO DEL ARCHIVO
           do{
           arch.read( reinterpret_cast<char *>(&obj1) , sizeof(aereo));//LEEMOS DEL ARCHIVO Y GUARDAMOS EL OBJETO
           if(arch.eof())break;//DETENEMOS EL BUCLE SI ES FIN DE ARCHIVO
           contador++;
           cout << contador << " : \t  "<< obj1.getNombre() << endl ; //MOSTRAMOS EL NOMBRE LEIDO
           }while(true);
           
           cout << " \n\t\t INGRESA LA CLAVE DEL VEHICULO : ";
           cin >> clave;
           if( clave > contador  && clave < 0  ){ cout << "CLAVE INVALIDA"; return -1; }//VALIDAMOS LA CLAVE
           clave--;
           arch.clear();
           arch.seekg (  sizeof(aereo)*clave  );
           arch.read( reinterpret_cast<char *> (&obj1), sizeof(aereo)) ;
  
  
           Menu_Modificacion_General();
           Menu_Modificacion_Aereos();
           char opcion ;
           fflush(stdin);
           cin >> opcion;
           cout << "Ingrea el nuevo valor : ";
           fflush(stdin);
           cin.getline(x,30);
           
           switch( opcion )
           {                            
            case '1': obj1.setNombre( x );
            break;
            case '2': obj1.setFabricante(x);
            break;
            case '3': obj1.setFecha(x);
            break;
            case '4': obj1.setCosto(x);
            break;  
            case '5': obj1.setAltura(  atof(x) );
            break; 
            case '6': obj1.setSuperficieAlar( atof(x));
            break;  
            case '7': obj1.setTipo(x);
            break;  
            case 'x': return 0;
            break;  
           
           }
          
           arch.seekp(0,ios::beg );
           arch.seekp( sizeof( aereo )*clave );
           arch.write( (char*)(&obj1) , sizeof(aereo));     
           arch.close();
          
           }break;
           
   case 2 :{
           
           fstream arch("archivos/marinos.dat" , ios::out | ios::in | ios::binary );
           if(!arch)throw Excepcion_stream("No existe marinos.dat");
           arch.clear();//Limpiar el error eof
           arch.seekg(0,ios::beg);
           do{
           arch.read( reinterpret_cast<char *>(&obj2) , sizeof(marino));
           if(arch.eof())break;
           contador++;
           cout << contador << " : \t  "<< obj2.getNombre() << endl ; 
           }while(true);
 
           cout << " \n\t\t INGRESA LA CLAVE DEL VEHICULO : ";
           cin >> clave;
           if( clave >= contador  && clave < 0  ){ cout << "CLAVE INVALIDA"; return -1; }
           clave--;
           arch.clear();//Limpiar el error eof
           arch.seekg (sizeof(marino)*clave);
           arch.read( reinterpret_cast<char *>(&obj2) , sizeof(marino));
           
           
           Menu_Modificacion_General();
           Menu_Modificacion_Marinos();
           char opcion ;
           fflush(stdin);
           cin >> opcion;
           cout << "Ingrea el nuevo valor : ";
           fflush(stdin);
           cin.getline(x,30);
           
           switch( opcion )
           {                            
            case '1': obj2.setNombre( x );
            break;
            case '2': obj2.setFabricante(x);
            break;
            case '3': obj2.setFecha(x);
            break;
            case '4': obj2.setCosto(x);
            break;  
            case '5': obj2.setEslora( atof(x) );
            break; 
            case '6': obj2.setHelices( atoi(x) );
            break;  
            case '7': obj2.setManga( atof(x));
            break;  
            case '8': obj2.setSistemaPropulsion( x );
            break;  
            case 'x': return 0;
            break;  
           
           }
          
           arch.seekp(0,ios::beg );
           arch.seekp( sizeof( marino )*clave-1);
           arch.write( (char*)(&obj2) , sizeof(marino));     
           arch.close();
  
           }break;
   case 3 :{
           
           fstream arch("archivos/terrestres.dat" , ios::out | ios::in | ios::binary );
           if(!arch)throw Excepcion_stream("No existe terrestres.dat");
           arch.clear();//Limpiar el error eof
           arch.seekg(0,ios::beg);
           do{
           arch.read( reinterpret_cast<char *>(&obj3) , sizeof(terrestre));
           if(arch.eof())break;
           contador++;
           cout << contador << " : \t  "<< obj3.getNombre() << endl ; 
           }while(true);
 
           cout << " \n\t\t INGRESA LA CLAVE DEL VEHICULO : ";
           cin >> clave;
           if( clave >= contador  && clave < 0  ){ cout << "CLAVE INVALIDA"; return -1; }
           clave--;
           arch.clear();//Limpiar el error eof
           arch.seekg (sizeof(terrestre)*clave);
           arch.read( reinterpret_cast<char *>(&obj3) , sizeof(terrestre));
           
           
           Menu_Modificacion_General();
           Menu_Modificacion_Terrestres();
           char opcion ;
           fflush(stdin);
           cin >> opcion;
           cout << "Ingrea el nuevo valor : ";
           fflush(stdin);
           cin.getline(x,30);
           
           
           switch( opcion )
           {                            
            case '1': obj3.setNombre( x );
            break;
            case '2': obj3.setFabricante(x);
            break;
            case '3': obj3.setFecha(x);
            break;
            case '4': obj3.setCosto(x);
            break;  
            case '5': obj3.setAltura(  atof(x) );
            break; 
            case '6': obj3.setAnchura( atof(x));
            break;  
            case '7': obj3.setArmamento( x );
            break;  
            case '8': obj3.setBlindaje( x );
            break;  
            case '9': obj3.setLonguitud( atof(x));
            break;  
            case '0': obj3.setMotor( x );
            break;  
            case 'x': return 0;
            break;  
           
           }
          
           arch.seekp(0,ios::beg );
           arch.seekp( sizeof( terrestre )*clave);
           arch.write( (char*)(&obj3) , sizeof( terrestre ));     
           arch.close();;
           
          }break;
   }
  }//Ftry
  catch( Excepcion_stream& e )
  {
    cout << " NO SE PEUDEN REALIZAR CONSULTAS ";
    return -1;
  }
  
}

