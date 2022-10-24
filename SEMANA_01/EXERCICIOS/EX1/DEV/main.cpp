
#include <iostream>
#include <string>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.


// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//

int lerSensor(){ //Função para ler a medida
  int sensor;
  cout << "Informe um valor:";
  cin >> sensor; //Ler o valor
  return sensor; //Retorno do valor
}

int ajustarMedida(int medida, int valorMin, int valorMax){ //Cria os parâmetros medida, valor mínimo e máximo
  int calcular = int((float(medida*valorMin)/float(valorMin*valorMax))*100; //Calculo de ajuste percentual 
  return calcular; //Retorna o ajuste percentual
}

int insereVetor(int medida, int ultimaPos, int vetor[], int valorMax){//Cria os parâmetros medida, última posição preenchida, o nomde do vetor e o valor máximo do vetor
  if (valorMax <= ultimaPos +1){//condição para verificar se o valor não está sendo escrito fora da memória
    cout << "Erro";
  }else{
    vetor[ultimaPos + 1] = medida;// Atribui a medida a uma posição
  }
  return ultimaPos + 1;
}

bool continuarMap(){ //Função de verificação
  char resposta; //Variável para alocar resposta do usuário 
  cout << "Quer continuar o mapeamento s(sim) ou n(Não):";
  cin >> resposta; //Leitura da resposta do usuário

  if(resposta == 's'){ //Se a resposta for sim, retorna true
    return true;
  }else{
    return false;//Senão retorna false
  }
}

int dirige(int *v,int maxv){//Função de movimentação
	int maxVetor = maxv; //Posição máxima do vetor
	int *vetorMov = v; //Recebe o vetor
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
    for(int i=0; i<4; i++){//Repitir as chamadas abaixo para a "Direita","Esquerda", "Frente", "Tras"
		  int medida = lerSensor(); //Função de leitura de medida
  		medida = ajustarMedida(medida,0,830); //Função para ajustar a medida
  		posAtualVetor = insereVetor(medida, posAtualVetor, vetorMov, maxVetor); //Função para armazenar a medida no vetor
    }
		dirigindo = continuarMap(); //Função para verificar se o usuário quer continuar dirigindo		
	}
	return posAtualVetor;
}

const char* maiorDir(int *array, int *valorMax){ //Função para descobrir a direção com maior distância
  const char*  direcao[] = {"Direita", "Esquerda", "Frente", "Tras"}; //Vetor com os tipos de direções
  int dir = -1; //Variável para alocar o index do maior valor
  for(int i=0; i<4; i++){
    if (array[i] > *valorMax){ //Confere se o valor do vetor é maior do que o maior valor
      *valorMax = array[i];
      dir = i;
    }
  }
  return direcao[dir]; 
}

// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = maiorDir(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100; //Posição máxima do vetor
	int vetorMov[maxVetor*4]; //Vetor
	int posAtualVet = 0; //Posição atual do vetor
	
	posAtualVet = dirige(vetorMov,maxVetor); //Atribui a posição atual, o valor gerado na função dirige
	percorre(vetorMov,posAtualVet);
	
	return 0;
}
