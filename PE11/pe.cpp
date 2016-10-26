/*
 * 	Project Euler - Problema 11
 *
 * 	"Largest product in a grid"
 *
 *
 * 	Alberto Sola - Pirobtumen - 2015
 */

#include <iostream>
#include <ctime>

using namespace std;

class Matriz{
	private:
		static const int TAMANIO = 20;
		int matriz[TAMANIO][TAMANIO];

		int total_utilizados;

		double ProductoHorizontal( int x, int y, int seguidos ){
			double producto = 1;
			int tope = y + seguidos;

			for(int i = y; i < tope; i++){
				producto = producto * Elemento(x,i);
			}

			return producto;
		}

		double ProductoVertical( int x, int y, int seguidos ){
			double producto = 1;
			int tope = x + seguidos;

			for(int i = x; i < tope; i++){
				producto = producto * Elemento(i,y);
			}

			return producto;
		}

		double ProductoDiagonalID( int x, int y, int seguidos ){
			double producto = 1;
			int tope_x = x + seguidos;

			int j = y;

			for(int i = x; i < tope_x; i++ ){
				producto = producto * Elemento(i,j);
				j++;
			}

			return producto;
		}

		double ProductoDiagonalDI( int x, int y, int seguidos ){
			double producto = 1;
			int tope_x = x + seguidos;
			int tope_y = y - seguidos;

			int j = y;

			if( tope_y <= TAMANIO){

				for(int i = x; i < tope_x; i++ ){
					producto = producto * Elemento(i,j);
					j--;
				}

			}

			return producto;
		}

	public:
		Matriz()
		: total_utilizados(0)
		{}

		int Capacidad(){
			return TAMANIO;
		}

		// Prec: x,y [o,TAMANIO[
		int Elemento(int x, int y){
			return matriz[x][y];
		}

		void Aniade( int numero ){
			/*
			 * Añade un elemento al final del vector matriz.
			 */

			const int MAX_ELEMENTOS = TAMANIO*TAMANIO;

			int x,y;

			// Comprobamos que haya espacio.
			if( total_utilizados < MAX_ELEMENTOS ){

				x = total_utilizados / TAMANIO;
				y = total_utilizados % TAMANIO;

				matriz[x][y] = numero;

				total_utilizados++;

			}

		}

		void AniadeString( string cadena ){
			/*
			 * Añiade a la matriz los elementos de una cadena.
			 * Descarta espacios y ceros a la izquierda (después de un espacio).
			 */
			const char AMPLITUD = '0';

			bool nuevo_caracter = true;
			int cadena_long = cadena.size();
			int elemento = 0;
			int caracter;
			int digito;

			for(int i = 0; i < cadena_long; i++ ){
				caracter = cadena.at(i);

				// Si es un espacio:
				if( caracter == ' ' ){
					// Si el caracter anterior no era un espacio:
					if(!nuevo_caracter){
						// Actualiza:
						nuevo_caracter = true;

						// Añade el elemento:
						Aniade(elemento);
						// Reseteamos:
						elemento = 0;
					}
				}
				else if( caracter == '0' && nuevo_caracter ){
					nuevo_caracter = false;
				}
				else{
					digito = caracter - AMPLITUD;

					if(nuevo_caracter){
						elemento += digito*10;
						nuevo_caracter = false;
					}
					else{
						elemento += digito;
					}

				}

			}

			// Añadimos el último elemento ya que está fuera del bucle:
			Aniade(elemento);


		}

		double MayorProducto( int seguidos ){
			/*
			 * Calcula el mayor producto de N número consecutivos,
			 * en horizontal/vertical/diagonal.
			 */
			double mayor_producto = 0;
			double producto = 0;
			int tope = TAMANIO - seguidos;
			// Recorremos los elementos:

			for(int i = 0; i <= tope; i++){
				for(int j = 0; j <= tope; j++){

					/*
					 * Para cada uno calculamos el producto de los 4 elementos
					 * adyacentes.
					 *
					 */
					producto = ProductoHorizontal(i,j,seguidos);
					if( producto > mayor_producto ){
						mayor_producto = producto;
					}

					producto = ProductoVertical(i,j,seguidos);
					if( producto > mayor_producto ){
						mayor_producto = producto;
					}

					producto = ProductoDiagonalID(i,j,seguidos);
					if( producto > mayor_producto ){
						mayor_producto = producto;
					}

					producto = ProductoDiagonalDI(i,j,seguidos);
					if( producto > mayor_producto ){
						mayor_producto = producto;
					}

				}

			}

			return mayor_producto;
		}

};

class MuestraMatriz{
	private:
		Matriz * matriz;
	public:
		MuestraMatriz( Matriz * puntero )
		:matriz(puntero)
		{}

		void Muestra(){
			int tamanio = matriz -> Capacidad();

			for(int i = 0; i < tamanio; i++){
				for(int j = 0; j < tamanio; j++){

					cout << matriz -> Elemento(i,j) << "   ";

				}

				cout << endl;

			}
		}
};

int main(){

	string contenido = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";
	clock_t inicio;
	clock_t final;
	double resultado;


	cout << fixed; // Ajustamos la precicisión.

	Matriz matriz;

	matriz.AniadeString(contenido);

	//MuestraMatriz muestra_matriz(&matriz);
	//muestra_matriz.Muestra();

	cout << endl;

	// Medimos el tiempo:
	inicio = clock();
	resultado = matriz.MayorProducto(4);
	final = clock();

	cout << resultado << " encontrado en " << (double)(final - inicio)/(CLOCKS_PER_SEC/1000.0) << " ms.";

}
