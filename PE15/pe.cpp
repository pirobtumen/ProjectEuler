/*
	Alberto Sola
*/

#include <iostream>
#include <cstdint>
#include <ctime>

using namespace std;

class SecuenciaEnteros{
	private:
		static const int MAX = 40;
		int secuencia[ MAX ];

		int total_utilizados;

	public:
		SecuenciaEnteros()
		: total_utilizados(0)
		{}

		int Capacidad(){
			return MAX;
		}

		int Utilizados(){
			return total_utilizados;
		}

		void EliminaTodos(){
			total_utilizados = 0;
		}

		int Elemento( int indice ){
			return secuencia[ indice ];
		}

		void Modifica( int indice, int elemento ){
			secuencia[indice] = elemento;
		}

		void Aniade(int elemento){

			if(total_utilizados < MAX){

				secuencia[total_utilizados] = elemento;
				total_utilizados++;

			}
		}

		void AniadeFactorial( int numero ){

			for(int i = 1; i <= numero; i++){
				Aniade(i);
			}

		}

		uint64_t Factorial(){
			uint64_t factorial = 1;

			for(int i = 0; i < total_utilizados; i++){
				factorial = factorial*Elemento(i);
			}

			return factorial;
		}

		void EliminaSecuencia( SecuenciaEnteros elimina ){
			int long_elimina = elimina.Utilizados();
			int pos_escritura = 0;

			bool esta = false;

			// Recorremos los números de este vector.
			for(int i = 0; i < total_utilizados; i++){

				for(int j = 0; j < long_elimina && !esta; j++){

					if( Elemento(i) == elimina.Elemento(j)){
						esta = true;
					}

				}

				// Si está lo borramos.
				if( !esta ){
					Modifica( pos_escritura, Elemento(i) );
					pos_escritura++;
				}
				else{
					esta = false;
				}

			}

			total_utilizados = pos_escritura;
		}

		uint64_t Combinatorio( int a, int b){
			uint64_t combinatorio;
			SecuenciaEnteros simplificador;
			int resta = a - b;
			int numero_primero,
				 numero_segundo;
			bool mayor = resta > b;
			bool simplificado = false;

			EliminaTodos();

			AniadeFactorial(a);

			// Nos quedamos con la secuencia más larga.
			if( mayor ){
				simplificador.AniadeFactorial(resta);
			}
			else{
				simplificador.AniadeFactorial(b);
			}
			// Simplificamos
			EliminaSecuencia(simplificador);

			// Actualizamos
			simplificador.EliminaTodos();
			if( mayor ){
				simplificador.AniadeFactorial(b);
			}
			else{
				simplificador.AniadeFactorial(resta);
			}

			// Simplificamos los factores
			/*
			 * Recorremos los elementos del denominador y buscamos factores.
			 */

			for(int i = 0; i < simplificador.Utilizados() ; i++){
				numero_primero = simplificador.Elemento(i);
				for(int j = numero_primero; j >= 2; j--){

					if( numero_primero % j == 0 ){

						for(int k = 0; k < total_utilizados && !simplificado; k++){
							numero_segundo = Elemento(k);

							if( numero_segundo % j == 0 ){
								numero_primero = numero_primero / j;
								numero_segundo = numero_segundo / j;

								simplificador.Modifica(i, numero_primero);
								Modifica(k, numero_segundo);
								simplificado = true;
							}

						}

						simplificado = false;

					}

				}
			}

			numero_primero = Factorial();
			numero_segundo = simplificador.Factorial();

			// Calculamos
			combinatorio = Factorial() / simplificador.Factorial();

			return combinatorio;
		}

};



int main(){
	/*
	 * Lattice paths
	 *
	 * ( a + b )
	 * (	 b   )
	 *
	 */
	const int MAX = 20;

	SecuenciaEnteros caminos;

	uint64_t resultado;

	resultado = caminos.Combinatorio( 2*MAX, MAX);


	cout << resultado;
}
