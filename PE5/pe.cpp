/* Project Euler Nº5
	
	Calcular el número más pequeño divisible
	entre los números del 1 al 20.
	
*/

#include <iostream>

using namespace std;

int main(){
	const int RANGO_MENOR_DIVISOR = 2;
	const int RANGO_MAYOR_DIVISOR = 20;
	
	int numero_divisible = RANGO_MAYOR_DIVISOR;
	
	bool numero_encontrado = false;
	
	while(!numero_encontrado){
		
		for(int i = RANGO_MENOR_DIVISOR; i <= RANGO_MAYOR_DIVISOR; i++){
			
			if(numero_divisible % i != 0){
				numero_divisible++;
				i = RANGO_MAYOR_DIVISOR + 1;			// Salimos del for asignando a i un número mayor del rango.
			}
			else if(i == 20){
				numero_encontrado = true;
			}
		}
		
	}
	
	cout << "El número es: " << numero_divisible;
}
