// 3 - Faça uma função que armazena uma medida inteira qualquer em um vetor fornecido. Note que como C não possui vetores nativos da linguagem, lembre-se que você precisa passar o valor máximo do vetor assim como a última posição preenchida Evite também que, por acidente, um valor seja escrito em uma área de memória fora do vetor

#include <iostream>
#include <string>
using namespace std;

int insereVetor(int medida, int ultimaPos, int vetor[], int valorMax){//Cria os parâmetros medida, última posição preenchida, o nomde do vetor e o valor máximo do vetor
  if (valorMax <= ultimaPos+1){//condição para verificar se o valor não está sendo escrito fora da memória
    cout << "Erro";
  }else{
    vetor[ultimaPos + 1] = medida;// Atribui a medida a uma posição
  }
  return ultimaPos + 1;
}

int main() {
  int medida = 1;
  int valorMax = 10;
  int ultimaPos = 5;
  int vetor[valorMax];//Nome do vetor
	int posAtualVetor = insereVetor(medida, ultimaPos, vetor, valorMax); //Chama a função para inserir vetor
  cout << "A posição é: " << posAtualVetor;
}
