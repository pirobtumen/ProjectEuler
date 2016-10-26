/*
 * Project Euler - Problema 14
 *
 *	Longest Collatz sequence
 *
 * Alberto Sola - 2015
 */

#include <iostream>

using namespace std;

typedef unsigned int uint_t;

class SecuenciaCollatz{
	private:
		static const int MINIMO_SEC = 1;
		int numero_secuencia;

		uint_t Par( uint_t  numero ){
			return numero / 2;
		}

		uint_t Impar( uint_t  numero ){
			return 3 * numero + 1;
		}

	public:
		SecuenciaCollatz( int inicio )
		{
			if( inicio < 2 ){
				numero_secuencia = 2;
			}
			else{
				numero_secuencia = inicio;
			}
		}

		int LongCadena( uint_t numero ){
			int longitud = 1;
			uint_t n = numero;

			while(n > MINIMO_SEC){

				if( n % 2 == 0 ){
					n = Par( n );
				}
				else{
					n = Impar( n );
				}

				longitud++;
			}

			return longitud;
		}

		int MayorCadena( int maximo ){
			int numero_max;
			int longitud_max = 0;
			int longitud;

			for(int numero = numero_secuencia; numero <= maximo; numero++){

				longitud = LongCadena( numero );

				if( longitud > longitud_max ){
					longitud_max = longitud;
					numero_max = numero;
				}

			}

			return numero_max;
		}

};

int main(){

	const int INICIO = 2;
	const int MAX = 1000000;

	int numero_resultado;

	SecuenciaCollatz secuencia( INICIO );
	numero_resultado = secuencia.MayorCadena( MAX );

	cout << numero_resultado;

}
