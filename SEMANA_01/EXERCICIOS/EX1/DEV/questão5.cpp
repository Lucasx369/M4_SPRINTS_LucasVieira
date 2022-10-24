// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e retorna verdadeiro ou falso

#include <iostream>
#include <string>
using namespace std;


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

int main() {
	bool mapeamento = continuarMap(); //Chama a função para verificar se o usuário quer continuar o mapeamento
  if(mapeamento == true){
    cout << "Continuar o mapeamento: Sim";
  }else{
    cout << "Continuar o mapeamento: Não";
  }
}
