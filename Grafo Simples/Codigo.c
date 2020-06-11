#include <stdio.h>
#include <stdlib.h>

int main (){
	char v1[3];
	char v2[3];
	int m[3][3];
	
	FILE *arq;
	char buf[BUFSIZ];
	arq = fopen("entrada.txt", "r");
	int i =0;
	if(arq == NULL){printf("Erro ao Ler o Arquivo!!!\n");}
	printf("Arestas do Grafo:\n");
	while(fgets(buf, BUFSIZ, arq)!= NULL){
		fscanf(arq,"%c %c[^\n]",&v1[i], &v2[i]);
		printf("%c %c\n", v1[i], v2[i]);
		i++;
	}
	
	
	for(int j = 0; j <3; j++){
		for(int k = 0; k <3; k++){
			m[j][k]= 0;
		}
	}

	for(int j = 0; j <3; j++){
		if(v1[j] == 'a' && v2[j] == 'a'){m[0][0]=1;}
		else if((v1[j] == 'a' && v2[j] == 'b')|| (v1[j] == 'b' && v2[j] == 'a')){
			m[0][1]=1;
			m[1][0]=1;
		}
		else if((v1[j] == 'a' && v2[j] == 'c')||(v1[j] == 'c' && v2[j] == 'a')){
			m[0][2]=1;
			m[2][0]=1;
		}
		
		else if(v1[j] == 'b' && v2[j] == 'b'){m[1][1]=1;}
		else if((v1[j] == 'b' && v2[j] == 'c')||(v1[j] == 'c' && v2[j] == 'b')){
			m[1][2]=1;
			m[2][1]=1;
		}
		else if(v1[j] == 'c' && v2[j] == 'c'){m[2][2]=1;}
	}
	printf("Matriz de adjacencias:\n");
	for(int j = 0; j <3; j++){
		printf("%d %d %d\n",m[j][0],m[j][1],m[j][2]);
	}
	//S = [(b,a), (b,c), (a,c), (c,c) ] = [(1,0),(1,2),(0,2),(2,2)]
	int a[4];
	for(int k = 0; k<4; k++){a[k]= 0;}
	if(m[1][0] == 1){
		a[0] = 1;
	}
	if(m[1][2] == 1){
		a[1] = 1;
	}
	if(m[0][2] == 1){
		a[2] = 1;
	}
	if(m[2][2] == 1){
		a[3] = 1;
	}
	printf("SAIDA\n");	
	for(int k = 0; k<4; k++){printf("%d ",a[k]);}
	fclose(arq);
	return 0;
	}

