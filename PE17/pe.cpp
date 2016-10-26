/*
	Project Euler - 17
		

	Calcula la suma de ĺas letras de los números
	desde el 1 hasta el 1000 sin contar los
	espacios o los guiones.

	Alberto Sola - 2015
*/

#include <iostream>
#include <fstream>
#include "BigNumber/BigNumber.hpp"
#include <ctime>


const int UNIDADES[] = {3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
const int DECENAS[]	 = {3,6,6,5,5,5,7,6,6};
const int CENTENA = 7;
const int AND = 3;
const int MILLAR = 11;

int Centenas( const BigNumber & numero ){
	/*
		Calcula la suma de letras de las centenas.
	*/
	int letras = 0;
	int digitos = numero.TotalUtilizados();

	// Comprueba si hay centenas
	if( digitos == 3 ){
		// Suma numero + 'hundred'
		letras += UNIDADES[numero.GetDigito( 2 ) - 1] + CENTENA;

		// Suma 'and' si acaba en '00'
		if( !(numero.GetDigito(1) == 0 and numero.GetDigito(0) == 0) ){
			letras += AND;
		}

	}

	return letras;
}

int Decenas( const BigNumber & numero ){
	/*
		Calcula la suma de las centenas a partir
		de 20.
	*/
	int letras = 0;
	int digitos = numero.TotalUtilizados();

	// Comprueba si hay decenas
	if( digitos >= 2 ){

		// Compruebasi es mayor que 10
		if( numero.GetDigito(1) > 1 ){
			letras += DECENAS[ numero.GetDigito( 1 ) - 1 ];
		}

	}

	return letras;
}

int Unidades( const BigNumber & numero ){
	/*
		Calcula l suma de las unidades y de los números
		especiales.
		Es decir, del 1 al 19.
	*/
	int letras = 0;

	int digito = numero.GetDigito(0);

	int total = numero.TotalUtilizados();

	if( total > 1 and numero.GetDigito(1) == 1 ){
		digito += 10;
	}

	if( digito != 0 ){
		letras += UNIDADES[digito - 1];
	}

	//std::cout << "Unidades: " << digito << std::endl;
	//std::cout << "Suma: " << letras << std::endl;

	return letras;
}

int CuentaLetras( const BigNumber & numero ){
	/*
		Calcula la suma de las letras de un número.
	*/
	int letras = 0;

	letras += Unidades( numero );
	letras += Decenas( numero );
	letras += Centenas( numero );

	return letras;
}

int SumaLetras(){
	/*
		Calculala suma de letras de de los números
		en el rango:

		[1, 1000]
	*/
	int suma = 0;

	BigNumber numero;
	numero.AddNumero("1");

	//std::ofstream file;
	//file.open("numeros.txt");

	// Recorremos los números
	for( int i = 0; i < 999; i++ ){

		//std::cout << numero << " - " << CuentaLetras( numero ) << std::endl;
		//file << CuentaLetras( numero ) << std::endl;

		// Calculamos la suma
		suma += CuentaLetras( numero );

		// Incrementamos el número en uno
		numero.Incremento();

	}
	
	// Le sumamos el millar
	suma += MILLAR;

	return suma;
	
}

int main(){

	std::clock_t begin = clock();
	int suma = SumaLetras();
  	std::clock_t end = clock();


	std::cout << "La suma de los números es: " << suma << std::endl;
	std::cout << "El tiempo de ejecución es: " << double(end - begin) / CLOCKS_PER_SEC << std::endl;


}