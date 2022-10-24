// 2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor

#include <iostream>
#include <string>
using namespace std;


int lerSensor(){ //Função para ler o sensor
  int sensor; //Declaração da variável sensor
  cout << "Informe um valor:";
  cin >> sensor; //Leitura do valor variável sensor
  return sensor; //Retorno do valor
}

int main() {
	int valorMedida = lerSensor(); //Chama a função de leitura do sensor
  cout << "O valor é: " << valorMedida;
}