/*
	Alberto Sola
*/

#include <iostream>
#include "BigNumber/BigNumber.hpp"

int main(){
	const int FACTORIAL = 20;

	BigNumber numero;
	std::string i_numero = "1";

	numero.AddNumero( i_numero );

	for( int i = 1; i <= FACTORIAL; i++ ){
		numero = numero * i;
		//std::cout << numero << " - " << i << std::endl;
	}

	std::cout << "Resultado: " << numero << "   " << numero.GetSum() << std::endl;


}
