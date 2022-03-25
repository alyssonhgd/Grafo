#include<iostream>
#include<string>
#include<list>
#include<string>
#include<stdlib.h>
#include<unordered_map>
#include<queue>
#include<array>
#define INFINITO 9999; //Definição de uma variavel para guardar um valor exorbitante

using namespace std;

//Main do programa
int main(int argc, char* argv[])
{
	bool visitados[7]; //Vetor para guardar os vertices que já foram visitados
	bool naoVisitados[7]; //Vetor para guardar os vertices que não forma visitados
	string verticeAtual; //Vertice do tipo string para guardar o vertice que esta sendo analisado
	unordered_map < string, list< pair<int, int > > > pontosParadaAdjacentes(7); //cria um maplist onde serao inseridos os vertices com um par de inteiros que representará a ligação com outro vertice e o peso dessa ligação(aresta)
	int distancia[7]; //Vetor que irá guardar as distancias do verticeatual para seus adjacentes
	int origem = 1; //o vertice de inicio que será o primeiro a ser analisado
	int distanciaTotal = 0; //essa variavel será a que irá receber a soma das menores distancias já percorridas anteriores ao vertice que esta sendo analisado
	int menorPeso = INFINITO; //Variavel que irá guardar o menor peso encontrado dentre os vertices adjacentes ao vertice analisado
	bool atualiza = false; //variavel de controle para zerar o vetor de distancias e indicar que o vertice a ser analisado irá mudar



	//Inicializa todos as distancais em infinito "9999"
	for (int i = 0; i < 7; i++)
		distancia[i] = INFINITO;
	//Pega o vetor de naoVisitados e inicializa-o setando true para todos os vertices, pois ng foi visitado ainda
	for (int i = 0; i < 7; i++)
		naoVisitados[i] = true;
	////seta todos os vertices da variavel visitados como false
	for (int i = 0; i < 7; i++)
		visitados[i] = false;

	//Insere os vertices no no map da seguinte maneira
  //vertice "0" -> vertice "2" essa ligação com peso 1

	pontosParadaAdjacentes["0"].push_front(make_pair(2, 1));
	pontosParadaAdjacentes["2"].push_front(make_pair(1, 3));
	pontosParadaAdjacentes["0"].push_front(make_pair(1, 10));
	pontosParadaAdjacentes["1"].push_back(make_pair(3, 4));
	pontosParadaAdjacentes["3"].push_front(make_pair(4, 10));
	pontosParadaAdjacentes["3"].push_front(make_pair(5, 3));
	pontosParadaAdjacentes["5"].push_front(make_pair(4, 2));
	pontosParadaAdjacentes["4"].push_front(make_pair(6, 15));


	//Inicializa o algoritmo setando a distancia do vertice origem para ele mesmo com 0
	distancia[origem] = 0;
	string aux = to_string(origem);
	verticeAtual = "0";


//Realiza a passagem por todos os vertices para que todos os vertices sejam analisados, pegando sempre o menor caminho até o vertice analisado.

	for (auto& value : pontosParadaAdjacentes) { 
		string vertice = value.first; //string que pega o vertice do map
		list< pair<int, int> > verticesAdjacentes = value.second; //lista que recebe os valroes da lista de adjacencia do vertice do map
		list< pair<int, int> >::iterator itr = verticesAdjacentes.begin(); //lista com iterator para acessar e percorrer, quando preciso, os valores da lista de adjacencia


		//percorre a lista de vertices adjacentes verificando sempre atravs do vetor de verticesnaovisitados se o vertice já foi analisado ou nao, se nao foi ele seta o peso da ligação(aresta) + o valor da distancia total para chegar ate ali e vai colocando os valores  no vetor de distancias 

		while (itr != verticesAdjacentes.end()) {
			if (naoVisitados[(*itr).first] == true)
			{

				distancia[(*itr).first] = ((*itr).second + distanciaTotal);
        //toda vez que ele coloca o somatorio da distancia ate aqui no vetor de distancia, ele ja verifica se esse valor é o valor de menor peso para chegar ate ao vertice, caso a resposta seja sim ele ja atualiza a variavel verticeAtual como a que tem o menorPeso dentro do vetor de distancias do vertice adjacente 
				if (distancia[(*itr).first] < menorPeso && naoVisitados[(*itr).first] == true)
				{
					menorPeso = distancia[(*itr).first];
					verticeAtual = to_string((*itr).first);
				}
        //seta variavel atualiza como true,
				atualiza = true;
			}
			++itr; //passa para o proximo vertice adjacente do vertice do map atual
		}
    //dentro dessa condição são setados a distanciatotal para chegar ate o verticeatual
    //seta o menorpeso como infinito novamente
    //seta o vetor de Naovisitados como false(ou seja, esse ja foi visitado e nao devera ser analisado novamente)
    //reinicia o vetor de distancias todos os valores como infinito, pois será verificado o proximo vertice do map
		if (atualiza == true)
		{
			distanciaTotal = menorPeso;
			menorPeso = INFINITO;
			int valor = stoi(verticeAtual);
			naoVisitados[valor] = false;
			atualiza = false;
			for (int i = 0; i < 7; i++)
				distancia[i] = INFINITO;
		}
	}
	cout << distanciaTotal;
	return 0;
};
