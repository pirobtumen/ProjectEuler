/* Project Euler Nº6

	Calcular la diferencia entre la suma de los cien primeros
	números al cuadrado, y la suma al cuadrado de los cien 
	primeros números.
*/

#include <iostream>

using namespace std;

int main(){
	const int PRIMER_NUMERO = 1;
	const int ULTIMO_NUMERO = 100;
	
	int suma_al_cuadrado = 0,
		 suma_de_cuadrados = 0,
		 diferencia;
		 
	for(int i = PRIMER_NUMERO; i <= ULTIMO_NUMERO; i++){
		suma_al_cuadrado += i;
	}
	suma_al_cuadrado = suma_al_cuadrado * suma_al_cuadrado;
	
	for(int i = PRIMER_NUMERO; i <= ULTIMO_NUMERO; i++){
		suma_de_cuadrados += i * i;
	}
	
	diferencia = suma_al_cuadrado - suma_de_cuadrados;
	
	cout << "El número es: " << diferencia << endl;
}
