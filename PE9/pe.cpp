/* Project Euler Nº9
	
	@ Descripción:
	Calcular tres números, (a, b, c) que cumplan el
	'pythagorean triplet'.
	
	a < b < c
	a^2 + b^2 = c^2
	
	a + b + c = 1000
	
	@ Autor: Alberto Sola
	@ Fecha: 13/10/2014
	@ Versión: 1.0
*/

#include <iostream>
#include <cmath>						// floor(), sqrt()

using namespace std;

/* Función para saber si un número es exacto o no.
	Lo utilizaremos para comprobar si sqrt() devuelve
	un entero, ya que si no se utilizará una aprozimación.
*/
bool esEntero(double numero){
	int numero_aprox_defecto = floor(numero);
	
	if(numero - numero_aprox_defecto == 0){
		return true;	
	}
	
	return false;
}

// Programa principal
int main(){
	const int SUMA_TOTAL = 1000;
	int a = 1,
		 b = 2,
		 suma_abc,
		 producto_abc;	
	
	double c = b;
	
	bool encontrado = false;
	
	while(!encontrado){

		c = sqrt(a*a + b*b);
		suma_abc = a + b + c;
				
		/* Comprobamos que b sea menor que c, y que
			c sea un número exacto (un entero) ya que
			si c no lo es obtendremos una aproximación
			y un resultado incorrecto.
		*/		
		if(b < c && esEntero(c)){
			
			if( suma_abc < SUMA_TOTAL){
				b++;
			}
			else if (suma_abc > SUMA_TOTAL){
				a++;
				b = a + 1;
			}
			else {
				encontrado = true;	
			}
			
		}			
		else if (suma_abc > SUMA_TOTAL){
			a++;
			b = a + 1;
		}
		else{
			b++;
		}
		
	}
	
	producto_abc = a * b * c;
	
	cout << "\n\nLos números son: " << a << " " << b << " " << c << endl;
	cout << "Su suma es: " << suma_abc << endl;
	cout << "Su producto es: " << producto_abc << endl;
	
}	
