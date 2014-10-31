#include "Open_Cv.h"
#include <iostream>
#include <fstream>
#include "Clases/cd_aereo.h"
#include "Clases/cd_marino.h"
#include "Clases/cd_terrestre.h"
using namespace std;


int info_general(vehiculo *VEHICULO)
{
  system("cls ");
  cout << "Nombre                  :  " <<  VEHICULO->getNombre() << endl;
  cout << "Fabricante              :  " <<  VEHICULO->getFabricante() <<endl;
  cout << "Fecha produccion        :  " <<  VEHICULO->getFecha() << endl;
  cout << "Costo                   :  " <<  VEHICULO->getCosto() << endl;      

}

int vista_previa(vehiculo *VEHICULO)
{
  #ifdef opencv
    cout << "\n\n\n\n\n\n\n\n\n"
         << "###################################\n"
         << "click en la imagen para continuar!!\n"
         << "###################################\n";
    
    imagen = cvLoadImage( VEHICULO->getPathImage()  );//Cargar la imagen segun su direccion
    cvNamedWindow(VEHICULO->getNombre(),CV_WINDOW_AUTOSIZE); // Crear una ventana
    cvMoveWindow(VEHICULO->getNombre(),500,0);//Posicion de la ventana emergente
    cvShowImage(VEHICULO->getNombre(),imagen);//Mostra La imagen
    cvWaitKey(0);//esperar la pulsacion de una tecla 
    cvDestroyWindow(VEHICULO->getNombre());//Destruir la ventana
  #endif
      
}

int Consulta(int tipo  ){
  
  //Objetos que usaremos para almacenar los objetos leidos del archivo
  aereo obj1 ;
  marino obj2 ;
  terrestre obj3; 
  int clave = 0 , contador = 0 ;
  
  try{
      
  system("cls");
  cout << "\n\n CLAVE  \t NOMBRE VEHICULO \n\n"<<endl;
  clave = 0; contador = 0; 
    
  switch(tipo)
  {
              
  case 1 :{
           ifstream arch_bin_in("archivos/aereos.dat", ios::in |  ios::binary );//ABRIMOS EL ARCHIVO EN MODO LECTURA, BINARIO
           if(!arch_bin_in)throw Excepcion_stream("No existe aereos.dat");//VALIDAMOS QUE EXISTA EL ARCHIVO
           arch_bin_in.seekg(0,ios::beg);//NOS POSUCIONAMOS AL INICIO DEL ARCHIVO
           do{
           arch_bin_in.read( reinterpret_cast<char *>(&obj1) , sizeof(aereo));//LEEMOS DEL ARCHIVO Y GUARDAMOS EL OBJETO
           if(arch_bin_in.eof())break;//DETENEMOS EL BUCLE SI ES FIN DE ARCHIVO
           contador++;
           cout << contador << " : \t  "<< obj1.getNombre() << endl ; //MOSTRAMOS EL NOMBRE LEIDO
           }while(true);//BUCLE DOWHILE 
 
           cout << " \n\t\t INGRESA LA CLAVE DEL VEHICULO : ";
           cin >> clave;
           if( clave > contador  && clave < 0  ){ cout << "CLAVE INVALIDA"; return -1; }
           clave--;
           arch_bin_in.clear();//Limpiar el error eof
           arch_bin_in.seekg (  sizeof(aereo)*clave  );
           arch_bin_in.read( reinterpret_cast<char *> (&obj1), sizeof(aereo)) ;
           
           info_general(&obj1);
           cout << "Superficie alar         : " << obj1.getSuperficiAlar() << endl;
           cout << "Altura maxima           : " << obj1.getAltura() <<endl;
           cout << "Tipo de aereo           : " << obj1.getTipo( ) <<endl;
           vista_previa(&obj1);
           arch_bin_in.close();
           }break;
           
   case 2 :{

           ifstream arch_bin_in("archivos/marinos.dat", ios::in | ios::binary );
           if(!arch_bin_in)throw Excepcion_stream("No existe marinos.dat");
           arch_bin_in.seekg(0,ios::beg);
           do{
           arch_bin_in.read( reinterpret_cast<char *>(&obj2) , sizeof(marino));
           if(arch_bin_in.eof())break;
           contador++;
           cout << contador << " : \t  "<< obj2.getNombre() << endl ; 
           }while(true);
 
           cout << " \n\t\t INGRESA LA CLAVE DEL VEHICULO : ";
           cin >> clave;
           if( clave >= contador  && clave < 0  ){ cout << "CLAVE INVALIDA"; return -1; }
           clave--;
           arch_bin_in.clear();//Limpiar el error eof
           arch_bin_in.seekg (sizeof(marino)*clave);
           arch_bin_in.read( reinterpret_cast<char *>(&obj2) , sizeof(marino));
           
           info_general(&obj2);   
           cout << "Elices                  : " << obj2.getHelices() << endl;
           cout << "Sistema propulsion      : " << obj2.getSistemaPropulsion() << endl;
           cout << "Eslora                  : " << obj2.getEslora() << endl;
           cout << "Manga                   : " << obj2.getManga() <<endl;
           vista_previa(&obj2);
           
           arch_bin_in.close();
           }break;
   
   case 3 :{
           
           ifstream arch_bin_in("archivos/terrestres.dat", ios::in | ios::binary );
           if(!arch_bin_in)throw Excepcion_stream("No existe terrestres.dat");
           arch_bin_in.seekg(0,ios::beg);
           do{
           arch_bin_in.read( reinterpret_cast<char *>(&obj3) , sizeof(terrestre));
           if(arch_bin_in.eof())break;
           contador++;
           cout << contador << " : \t  "<< obj3.getNombre() << endl ; 
           }while(true);
 
           cout << " \n\t\t INGRESA LA CLAVE DEL VEHICULO : ";
           cin >> clave;
           if( clave >= contador  && clave < 0  ){ cout << "CLAVE INVALIDA"; return -1; }
           clave--;
           arch_bin_in.clear();//Limpiar el error eof
           arch_bin_in.seekg (sizeof(terrestre)*clave);
           arch_bin_in.read( reinterpret_cast<char *>(&obj3) , sizeof(terrestre));
           
           
           info_general(&obj3);    
           cout << "Altura                  : " << obj3.getAltura()    << endl;
           cout << "Anchura                 : " << obj3.getAnchura()   << endl;
           cout << "Longuitud               : " << obj3.getLonguitud() << endl;
           cout << "Blindaje                : " << obj3.getBlindaje( ) << endl;
           cout << "Motor                   : " << obj3.getMotor( )    << endl;
           cout << "Armamento               : " << obj3.getArmamento() << endl;
           vista_previa(&obj3); 
           arch_bin_in.close();
           }break;
   }
  }//Ftry
  catch( Excepcion_stream& e )
  {
    cout << " NO SE PEUDEN REALIZAR CONSULTAS ";
    return -1;
  }
  
}

