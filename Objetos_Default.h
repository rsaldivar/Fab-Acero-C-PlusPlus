#include "Clases/cd_marino.h"
#include "Clases/cd_terrestre.h"
#include "Clases/cd_aereo.h"
#include <vector>
#include <fstream>
#include "Excepciones.h"

void Crear_Archivo_Aereos(){

     vector <aereo * > obj_Aereo(6);
     
     obj_Aereo[0] = new aereo("A-10 Thunderbolt II", "Fairchild-Republic EUA" , "11.7 millones de dolares" , " 1972-1984 ");
     obj_Aereo[0]->setPathImagen("imagen/aereo1.png");
     obj_Aereo[0]->setPeso(13786);
     obj_Aereo[0]->setVelocidad(2410);
     obj_Aereo[0]->setTipo("Avion de Ataque a tierra");
     
     
     obj_Aereo[1] = new aereo("B-52 Stratofortress", "Boeing" , "53.4 millones de dolares" , "1952-1962");
     obj_Aereo[1]->setPathImagen("imagen/aereo2.png");
     obj_Aereo[1]->setTipo("Bombardero Estrategico");
     obj_Aereo[1]->setPeso(120000);
     obj_Aereo[1]->setVelocidad(1046);

     obj_Aereo[2] = new aereo("F-22 Raptor", "Lockheed Martin y Boeing" , "65 Millones de dolares" , "1997-2005");
     obj_Aereo[2]->setPathImagen("imagen/aereo3.png");
     obj_Aereo[2]->setTipo("Caza de Superioridad Aerea Furtivo");
     obj_Aereo[2]->setPeso(19700);
     obj_Aereo[2]->setVelocidad(2410);

     obj_Aereo[3] = new aereo("AH-64 Apache", "Boeing" , "10.5 Millones de Dolares" ," 1984-actualidad");
     obj_Aereo[3]->setPathImagen("imagen/aereo4.png");
     obj_Aereo[3]->setTipo("Helicoptero de Ataque");
     obj_Aereo[3]->setPeso(8000);
     obj_Aereo[3]->setVelocidad(293);

     obj_Aereo[4] = new aereo("U-2", "Lockheed" , "_SIN_ESPECIFICAR_" , " _SIN_ESPECIFICAR ");
     obj_Aereo[4]->setPathImagen("imagen/aereo5.png");
     obj_Aereo[4]->setTipo("Avion de  vigilancia ");
     obj_Aereo[4]->setPeso(6760);
     obj_Aereo[4]->setVelocidad(805);

     obj_Aereo[5] = new aereo("C-130J Super Hercules", "Lockheed Martin" , "62 Millones de dolares" , " 1996 - actualidad");
     obj_Aereo[5]->setPathImagen("imagen/aereo6.png");
     obj_Aereo[5]->setTipo("Avion de Transporte Tactico");
     obj_Aereo[5]->setPeso(34274);
     obj_Aereo[5]->setVelocidad(643);

     obj_Aereo[6] = new aereo("F-15E Strike Eagle", "McDonnell Douglas" , "31.1 Millones de Dolares" , "1986-actualidad");
     obj_Aereo[6]->setPathImagen("imagen/aereo7.png");
     obj_Aereo[6]->setTipo("Cazabombardero");
     obj_Aereo[6]->setPeso(14300);
     obj_Aereo[6]->setVelocidad(2660);
     
     try{ 
     ofstream arch_bin_out( "archivos/aereos.dat" , ios::out | ios::binary );
     
     if(!arch_bin_out)throw Excepcion_stream("aereos.dat DEFAULT");
     for(unsigned int  i = 0 ; i <= obj_Aereo.size() ; i++){
         arch_bin_out.write(reinterpret_cast<char *> (obj_Aereo[i]), sizeof(aereo));   
     }
     arch_bin_out.close();
     }
     catch(Excepcion_stream& e)
     {
       cout << " ERROR EN STREAM ";
     }
      
}

void Crear_Archivo_Marinos(){
     vector <marino * > obj_Marino(4);

     obj_Marino[0] = new marino("USS Long Beach (CGN-9)", "Bethlehem Steel" , "$2 billones" , "1961");
     obj_Marino[0]->setPathImagen("imagen/marino1.png");
     obj_Marino[0]->setVelocidad(17500);

     obj_Marino[1] = new marino("USS Nimitz CVN-68", "Newport News Shipbuiling" , "$4.5 billones" , "1975");
     obj_Marino[1]->setPathImagen("imagen/marino2.png");
     obj_Marino[1]->setVelocidad( 35000);//35kilotoneladas

     obj_Marino[2] = new marino("Pyotr Veliky", "Znamya Truda" , "_NO_DEFINIDO_" , "1986");
     obj_Marino[2]->setPathImagen("imagen/marino3.png");
     obj_Marino[2]->setVelocidad(30);//Nudos

     obj_Marino[3] = new marino("Ural", "los Astilleros Baltisky" , "$60.5 millones" , "1941");
     obj_Marino[3]->setPathImagen("imagen/marino4.png");
     obj_Marino[3]->setVelocidad(34640);

     obj_Marino[4] = new marino("El USS Gerald R. Ford (CVN-78)" , "RUSIA" , "$5.6 billones" , "1996-Actual");
     obj_Marino[4]->setPathImagen("imagen/marino5.png");
     obj_Marino[4]->setVelocidad(30);

     try{
     ofstream arch_bin_out( "archivos/marinos.dat", ios::out | ios::binary  );
     if(!arch_bin_out)throw Excepcion_stream("marios.dat DEFAULT");
     for(unsigned int i = 0 ; i <= obj_Marino.size()  ; i++){
         arch_bin_out.write(reinterpret_cast<char *> (obj_Marino[i]), sizeof(marino));
     }
     arch_bin_out.close();
     }
     catch(Excepcion_stream& e)
     {
       cout << " ERROR EN STREAM ";
     }  
     
}
void Crear_Archivo_Terrestres(){
     vector <terrestre * >obj_Terrestre(4);

     obj_Terrestre[0] = new terrestre( "T29 / T30 / T34", "U.S.A" , "32 millones" , "1944");
     obj_Terrestre[0]->setPathImagen("imagen/terrestre1.png");
     obj_Terrestre[0]->setPeso(64);//toneladas
     obj_Terrestre[0]->setArmamento(" un canon 1055 mm ametralladora 7.62mm");
     obj_Terrestre[0]->setVelocidad(25);

     obj_Terrestre[1] = new terrestre("Neubaufahrzeug", "ALEMANIA" , "20 millones" , "1935");
     obj_Terrestre[1]->setPathImagen("imagen/terrestre2.png");
     obj_Terrestre[1]->setPeso(23);
     obj_Terrestre[1]->setArmamento(" canon 75 mm KwK L/24 (unos 80 proyectiles)");
     obj_Terrestre[1]->setVelocidad(32);

     obj_Terrestre[2] = new terrestre("FCM Char 2C", "Francia" , "33 millones" , "1920");
     obj_Terrestre[2]->setPathImagen("imagen/terrestre3.png");
     obj_Terrestre[2]->setPeso(70);
     obj_Terrestre[2]->setArmamento("un canon APX 1897 de 75mm con 124 proyectiles con un visor de 2,5 x \n  4 ametralladoras de 8mm con 9.504 cartuchos disponibles");
     obj_Terrestre[2]->setVelocidad(12);

     obj_Terrestre[3] = new terrestre("Tanque Tortoise", "U.K" , "28 millones" , "1944");
     obj_Terrestre[3]->setPathImagen("imagen/terrestre4.png");
     obj_Terrestre[3]->setPeso(78);
     obj_Terrestre[3]->setArmamento("un canon de 32pdr (96 mm) y dos ametralladoras BESA de 7,92 mm ");
     obj_Terrestre[3]->setVelocidad(19);

     obj_Terrestre[4] = new terrestre("Independent", "UK" , "50 millones" , "1926");
     obj_Terrestre[4]->setPathImagen("imagen/terrestre5.png");
     obj_Terrestre[4]->setPeso(32);
     obj_Terrestre[4]->setArmamento("canon QF de 47 mm o 3 pdr (200 proyectiles disponibles) \n  4 ametralladoras Vickers, cada una en una torre (7.00 cartuchos disponibles)");
     obj_Terrestre[4]->setVelocidad(45);

     try{
     ofstream arch_bin_out("archivos/terrestres.dat", ios::out  |  ios::binary  );
     
     if(!arch_bin_out)throw Excepcion_stream("terrestres.dat DEFAULT");
     for(unsigned int i = 0 ; i <= obj_Terrestre.size()  ; i++){
        arch_bin_out.write(reinterpret_cast<char *> (obj_Terrestre[i]), sizeof(terrestre));
     }
     arch_bin_out.close();
     }
     catch(Excepcion_stream& e)
     {
       cout << " ERROR EN STREAM ";
     }  
}
