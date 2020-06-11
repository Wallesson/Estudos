#include <stdio.h>
#include <stdlib.h>

void Soma(int v[], int num[], int i){
	for(int p = 0; p<i; p++){
		int aux = v[p];
		num[aux]++;
	}
}

int main (){
	int val;
	int num[61];
	char va_2[20]="";
	int v1[2800], v2[2800], v3[2800], v4[2800], v5[2800], v6[2800];
	FILE *arq_1;
	char buf[BUFSIZ];
	arq_1 = fopen("Resultados.txt", "r");
	int i =0;
	if(arq_1 == NULL){printf("Erro ao Ler o Arquivo!!!\n");}
	 
	while(fgets(buf, BUFSIZ, arq_1)!= NULL){
		fscanf(arq_1,"%d %s %d %d %d %d %d %d[^\n]",&val, va_2, &v1[i], &v2[i], &v3[i], &v4[i], &v5[i], &v6[i]);
		i++;
	}
	for(int j =0; j<61; j++){
		num[j] = 0;
	}

	Soma(v1, num,i);
	Soma(v2, num,i);
	Soma(v3, num,i);
	Soma(v4, num,i);
	Soma(v5, num,i);
	Soma(v6, num,i);

	for(int j =1; j<61; j++){
		printf("-> %d saiu  foi : %d\n",j,num[j]);
	}
	int maiores[6]={0,0,0,0,0,0};
	for(int k = 0; k < 6; k++){
		for(int t = 0; t<61;t++){
			int aux = 0;
			if(t>aux){
				maiores[k] = num[t];
			}
		}
		int aux = maiores[k];
		num[aux] = 0;
	}
	printf("Os Seis Numeros que mais sairam foram:\n");
	for(int k = 0; k < 6; k++){
		printf(" %d\n ", maiores[k]);
		
	}	
	fclose(arq_1);
	return 0;
}
