/*
 * Project Euler - Problema 12
 *
 * Primer número triangular con más de 500
 * divisores.
 *
 * Ineficiente.
 *
 * Alberto Sola
 */

#include <iostream>
#include <ctime>

using namespace std;

class Timer{
	private:
		clock_t start;
		clock_t end;

		double last_timer;

		double MiliSecods(){
			/*
			 * Miliseconds between start and end timers.
			 */
			return (end - start)/(CLOCKS_PER_SEC/1000.0);
		}

	public:
		Timer(){
			last_timer = 0;
			end = clock();
			start = clock();
		}

		double Time(){
			/*
			 * Set the 'end' timer.
			 * Then it calculates the time between both timers.
			 * Also it updates the 'last_timer'.
			 */
			end = clock();
			last_timer = MiliSecods();

			return last_timer;
		}

		double LastTime(){
			/*
			 * Return the last measure between timers.
			 */
			return last_timer;
		}

};

class NumeroTriangular{
	private:
		static const int TAMANIO = 10000;
		int vector[TAMANIO];
		int numero_triangular;
		int n;

		int Divisores( int numero ){
			/*
			 * Calcula los divisores de un número.
			 * Divide hasta numero / 2.
			 */
			int numero_divisores = 2;	// Siempre va a ser divisible por él mismo
												// y por uno.
			int tope = numero / 2;

			for(int i = 2; i <= tope; i++){

				if( numero % i == 0 ){
					numero_divisores++;
				}

			}

			return numero_divisores;
		}

	public:
		NumeroTriangular()
		{
			numero_triangular = 1;
			n = 1;
		}

		// Prec: indice >= 0 && indice < TAMANIO
		void SetTriangular(int indice, int valor){

			vector[indice] = valor;

		}

		// Prec: indice >= 0 && indice < TAMANIO
		int GetTriangular(int indice){
			return vector[indice];
		}

		void SiguienteTriangular(){
			numero_triangular += n + 1;
			n++;
		}

		int ConDivisores( int numero_divisores ){
			/*
			 * Calcula el primer número triangular con N
			 * divisores.
			 */
			bool encontrado = false;
			bool acotado = false;

			int divisores;
			int tope_inf = 0;
			int tope_sup = TAMANIO - 1;
			int tope_siguiente = tope_sup / 2;

			// Acotamos la búsqueda:
			while(!acotado){

				for(int i = 0; i < TAMANIO; i++){
					vector[i] = numero_triangular;
					SiguienteTriangular();
				}

				divisores = Divisores( GetTriangular( tope_sup ) );

				if(divisores == numero_divisores){
					acotado = true;
					encontrado = true;
				}
				else if(divisores > numero_divisores){
					acotado = true;
				}
			}

			// Buscamos dentro del vector:
			while(!encontrado){

				tope_siguiente = (tope_inf + tope_sup)/2;

				divisores = Divisores( GetTriangular( tope_siguiente ));

				if( divisores > numero_divisores ){
					tope_sup = tope_siguiente;
				}
				else if(divisores < numero_divisores ){
					tope_inf = tope_siguiente;
				}
				else{
					encontrado = true;
				}


			}

			return GetTriangular(tope_siguiente);
		}



};

int main(){

	const int MAX_DIVISORES = 5;
	double resultado;
	double tiempo_ms;

	NumeroTriangular triangular;

	Timer tiempo;
	resultado = triangular.ConDivisores( MAX_DIVISORES );
	tiempo_ms = tiempo.Time();

	cout << "El número es: " << resultado << endl;
	cout << "Tiempo 1: " << tiempo_ms << endl;

}
