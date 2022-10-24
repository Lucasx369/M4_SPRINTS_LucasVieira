// 1 - Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor

#include <iostream>
#include <string>
using namespace std;

float ajustarMedida(float medida, float valorMin, float valorMax){ //Cria os parâmetros medida, valor mínimo e máximo
  float calcular = ((medida-valorMin)/(valorMax-valorMin))*100; //Calculo de ajuste percentual 
  return calcular; //Retorna o ajuste percentual
}

int main() {
	float resultado = ajustarMedida(78.0, 50.0, 100.0);//Chama a função de ajuste de medida
  cout << "O resultado é: " << resultado;
}