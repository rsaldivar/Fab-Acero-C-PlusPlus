
#ifndef EXEPCIONES_H_
#define EXEPCIONES_H_
#ifndef EXCEPCIONES_H_
#define EXCEPCIONES_H_
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class Excepcion_respuesta_SN
{
  public :
        Excepcion_respuesta_SN( )
        {
          cout << "Ingresa  <s/n> o <S/N>" ;
        }
};

class Excepcion_stream: public runtime_error
{
  public :
          Excepcion_stream(const char *mag ) : runtime_error(mag){
            cout << "ERROR EN STREAM :  !! " << mag << "  !!" ;
          }
};

#endif /* EXCEPCIONES_H_ */
#endif /* EXEPCIONES_H_ */
