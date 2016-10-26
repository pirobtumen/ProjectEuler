/*
	PROJECT EULER - 16

	Calcular la suma de los dígitos del número
	2^1000.

	Alberto Sola

*/

#include <iostream>
#include "BigNumber/BigNumber.hpp"

int main(){
	// Esstablecemos la potencia que queremos calcular
	const int POTENCIA = 1000;

	BigNumber numero;

	// Inicializamos el número en la base
	std::string i_numero = "2";
	numero.AddNumero( i_numero );

	// Elevamos a dicha potencia
	for( int i = 1; i < POTENCIA; i++ ){
		numero = numero * 2;
	}

	// Mostramos el resultado
	std::cout << "Resultado: " << numero << "   " << numero.GetSum() << std::endl;

}