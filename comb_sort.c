#include <stdio.h>
#include <stdlib.h>
#define TAM 1000
#define true 1
#define false 0

void mostrar(int * vetor){
	int i = 0;
	
	for(i = 0; i < TAM; i++){
		printf("%d ", vetor[i]);
	}
	
	printf("%\n");
}

int * gerarVetor(int vetor[]){
	int i;

	srand((unsigned)time(0));
    int maior = 10000;
    int menor = 1;
    int aleatorio = 0;

	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%(maior-menor+1) + menor;
	}

	return vetor;
}


int calcularGap(int gap){
	gap = gap / 1.3; //Fator de encolhimento
	if(gap < 1) return 1; //Caso a divis�o do gap pelo fator de encolhimento seja menor que um, ent�o o gap ser� 1(distancia de um elemento)
	
	return gap;
}

void trocarLugares(int * primeiro, int * segundo){ //Utilizo o conceito de ponteiro para realizar a troca dos valores
	int auxiliar = 0;
	auxiliar = *primeiro; //Coloco o valor do primeiro na vari�vel auxiliar
	*primeiro = *segundo; //atribuio o valor do segundo no primeiro
	*segundo = auxiliar; //atribuio o valor do auxiliar ao segundo
}

void combSort(int * vetor, int tamanho){
	int i = 0;
	int gap = tamanho; //Inicializo o gap com o tamanho do vetor;
	//O gap � o espa�o entre o elemento de referencia e o elemento que irei compara-lo
	//em algoritmos como o bubble sort esse gap � igual a 1(vizinho com vizinho).
	//No comb sort esse espa�o � calculado baseado em um fator de encolhimento que por conven��o e simula��es � igual a 1,3
	
	int houveTrocaDeLugares; //vari�vel flag, que ir� monitorar se houve ou n�o troca de lugares entre os elementos
	
	do{
		gap = calcularGap(gap); //Calculo o valor do gap a cada itera��o
		houveTrocaDeLugares = false; //Defino o valor da flag como falso, se houverem trocas se tornar� verdadeiro
		
		for(i = 0; i < tamanho - gap; i++){ //Percorro o vetor utilizando o gap como referencia
			
			if ( vetor[i] > vetor[i + gap] ){ //Comparo cada elemento com o elemento com 'gap' posi��es ao lado
				trocarLugares(&vetor[i], &vetor[i + gap]); //Caso seja maior, fa�o a troca dos elementos
                houveTrocaDeLugares = true; //e a flag vir� true
            }
            
		}
	}while(gap != 1 || houveTrocaDeLugares == true); 
	//Tudo isso ser� executado enquanto o gap (distancia) for diferente de 1 e n�o houver tido troca de lugares na itera��o
	//Quanto mais itera��es forem executadas, menor ser� o gap, at� o ponto que ele ser� igual a 1
	//nesse momento ainda podem haver elementos desordenados, por isso o vetor s� estar� completamente
	//ordenado quando al�m de o gap ser igual a 1, n�o houver tido nenhuma troca de lugar na itera��o.
}



void main(){
	//int vetor[TAM] = {3,2,1,5,4,9,7,8,6,0};
	int vetor[TAM];
	combSort(gerarVetor(vetor), TAM);
	
	mostrar(vetor);
}
