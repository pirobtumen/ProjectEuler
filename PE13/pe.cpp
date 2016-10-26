/*
 * Project Euler - Problema 13
 *
 * Alberto Sola
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

struct MeLlevo{
		int digito;
		int sobra;
};

class BigNumero{
		/*
		 * Clase para trabajar con números de 50 dígitos.
		 *
		 * Almacena los números al revés.
		 */
	private:
		static const int CAPACIDAD = 200;
		int big_numero[CAPACIDAD];

		int total_utilizados;

		void Aniade( int numero ){
			if(total_utilizados < CAPACIDAD){

				big_numero[total_utilizados] = numero;

				total_utilizados++;
			}
		}

		MeLlevo Check( int numero ){
			const int MODULO = 10;
			MeLlevo sobra;

			if( numero >= MODULO ){
				sobra.digito = numero % MODULO;
				sobra.sobra = (numero - sobra.digito) / MODULO;
			}
			else{
				sobra.digito = numero;
				sobra.sobra = 0;
			}

			return sobra;
		}

		MeLlevo SumaDigitos(int primer_sum, int segundo_sum, int sobra){

			int suma = 0;

			suma += primer_sum;
			suma += segundo_sum;
			suma += sobra;

			MeLlevo digito( Check( suma ) );

			return digito;
		}

	public:
		BigNumero()
		:total_utilizados(0)
		{}

		// No comprueba que haya elementos que no sea dígitos.
		void AniadeStr( string cadena ){
			/*
			 * Recorremos la string y añadimos los números al
			 * vector.
			 * Se introducen al reves.
			 */
			const char AMPLITUD = '0';
			int cadena_long = cadena.size();

			for(int i = cadena_long - 1; i >= 0; i--){
				Aniade( cadena.at(i) - AMPLITUD );
			}

		}

		int Longitud(){
			return total_utilizados;
		}

		// Prec: indice >= 0 && indice < total_utilizados
		// Prec: valor [0,9]
		void Modifica( int indice, int valor ){

			big_numero[indice] = valor;

		}

		// Prec: indice >= 0 && indice < total_utilizados
		int Elemento( int indice ){
			return big_numero[indice];
		}


		BigNumero Suma( BigNumero sumando ){
			/*
			 * Calcula la suma de dos BigNumeros.
			 *
			 */
			BigNumero resultado;
			MeLlevo digito;

			digito.digito = 0;
			digito.sobra = 0;

			int long_this = Longitud();
			int long_sumando = sumando.Longitud();

			bool longitud = long_this > long_sumando;

			int tope_inferior;
			int tope_superior;

			// Calculamos el tope:
			if( longitud ){
				tope_inferior = long_sumando;
				tope_superior = long_this;
			}
			else{
				tope_inferior = long_this;
				tope_superior = long_sumando;
			}

			// Sumamos los dígitos comunes:
			for(int i = 0; i < tope_inferior; i++){
				digito = SumaDigitos(Elemento(i), sumando.Elemento(i), digito.sobra );

				resultado.Aniade(digito.digito);
			}

			if(longitud){
				// Sumamos los dígitos que nos falten:
				for(int i = tope_inferior; i < tope_superior; i++){
					digito = SumaDigitos(Elemento(i), 0, digito.sobra );
					resultado.Aniade(digito.digito);
				}
			}
			else{
				// Sumamos los dígitos que nos falten:
				for(int i = tope_inferior; i < tope_superior; i++){
					digito = SumaDigitos(sumando.Elemento(i), 0, digito.sobra );
					resultado.Aniade(digito.digito);
				}
			}

			// Comprobamos si ha sobrado algo:
			if(digito.sobra != 0){
				resultado.Aniade(digito.sobra);
			}

			return resultado;
		}

};

class MuestraBigNumero{
	private:
		BigNumero * big_numero;

	public:
		MuestraBigNumero(BigNumero * puntero)
		:big_numero(puntero)
		{}

		void Muestra(){
			int longitud = big_numero -> Longitud();

			for(int i = longitud - 1; i >= 0; i--){
				cout << big_numero -> Elemento(i);
			}

			cout << endl;

			cout << big_numero -> Longitud() << endl;

		}

};

int main(){
	const int NUMEROS = 100;


	fstream fichero;
	fichero.open("numeros.txt", fstream::in);
	string numero;

	BigNumero n_vector[NUMEROS];
	BigNumero resultado;

	for(int i = 0; i < NUMEROS; i++){
		getline(fichero,numero);
		n_vector[i].AniadeStr( numero );
	}

	resultado = n_vector[0];

	for(int i = 1; i < NUMEROS; i++){
		resultado = resultado.Suma( n_vector[i] );
	}

	//MuestraBigNumero muestra(&resultado);
	//muestra.Muestra();

	// Como nos pide los 10 primeros números:
	MuestraBigNumero muestra(&resultado);
	muestra.Muestra();

}// 5537376230
