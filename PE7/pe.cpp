/* Project Euler Nº7

	Calcula el número primo que esté en la posición
	número 10.001.
	Para ello recorremos los numeros calculando si son
	primos.

	Autor: Alberto Sola
	Fecha: 11/10/2014
	Versión: 2.0
*/

#include <iostream>

using namespace std;

/* La función esPrimo(int) recibe un entero y lo divide
	por todos los números hasta él.
	Si en mitad encuentra que es divisible por otro que no
	sea el mismo, devuelve 'false' y sale del bucle.
	
	Para ser más eficiente, comprobamos si es divisble o no
	por 2 y luego comprobamos los impares.
*/
bool esPrimo(int numero_a_comprobar){
	
	if(numero_a_comprobar % 2 != 0){
		
		for(int i = 3; i <= numero_a_comprobar; i += 2){
			
			if(numero_a_comprobar % i == 0 && i != numero_a_comprobar){
				i = numero_a_comprobar + 1; 			//Salimos del bucle.
				return false;	
			}
			
		}
		
	}
	else {
		return false;	
	}
	
	return true;
}

int main(){
	const int POSICION_NUMERO_PRIMO = 10001;
	
	int numero_a_comprobar = 3,
		 contador_posicion = numero_a_comprobar - 2,
		 numero_primo = 0;
		
	/* Bucle principal del programa que se ejecuta siempre
		que el contador de números primos sea inferior al máximo.
		Así cuando finalice, el número va a ser el primo correspondiente
		más uno.
	*/
	while(contador_posicion < POSICION_NUMERO_PRIMO){
		
			if(esPrimo(numero_a_comprobar)){
				contador_posicion++;
			}
			
			numero_a_comprobar++;	
	}
	
	/* Guardamos el número primo, ya que al finalizar el bucle
		se le suma uno siempre al resultado.
	*/
	numero_primo = numero_a_comprobar -1;
	cout << "El número primo es: " << numero_primo << endl;
}
