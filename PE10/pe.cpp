/* Project Euler N�9

	@ Descripci�n: Calcula el n�mero primo que est� en la 
	  posici�n n�mero 10.001.
	  Para ello recorremos los numeros calculando si son
	  primos.

	@ Autor: Alberto Sola
	@ Fecha: 11/10/2014
	@ Versi�n: 1.0
*/

#include <iostream>

using namespace std;

/* La funci�n esPrimo(int) recibe un entero y lo divide
	por todos los n�meros hasta �l.
	Si en mitad encuentra que es divisible por otro que no
	sea el mismo, devuelve 'false' y sale del bucle.
	
	Para ser m�s eficiente, comprobamos si es divisble o no
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
	const int MAX_RANGO = 2000000;
	
	int numero_a_comprobar = 3; // Empezamos en el n�mero tres.
	unsigned long long numero_resultado = 2;   // Compensamos a�adiendo el 2. El 1 no lo cuenta como primo.
		
	/* Bucle principal del programa que se ejecuta siempre
		que el contador de n�meros primos sea inferior al m�ximo.
		As� cuando finalice, el n�mero va a ser el primo correspondiente
		m�s uno.
	*/
	while(numero_a_comprobar <= MAX_RANGO){
		
			if(esPrimo(numero_a_comprobar)){
				numero_resultado += numero_a_comprobar;
			}
			
			numero_a_comprobar++;	
	}
	
	/* Guardamos el n�mero primo, ya que al finalizar el bucle
		se le suma uno siempre al resultado.
	*/
	cout << "El n�mero primo es: " << numero_resultado << endl;
}
