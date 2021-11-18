#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    struct dados{
        char nome[15];
        char sobrenome[15];
        char end[26];
        int nmrCasa;
    }data;

    FILE *arq;
    int id;

    if ((arq = fopen("fixo.dad", "rb")) == NULL){
        printf("Não foi possivel abrir o arquivo!");
        getche();
		return 0;
    }

    while (fread(&data, sizeof(data), 1, arq)){
        printf("Nome: %s\n", data.nome);
        printf("Sobrenome: %s\n", data.sobrenome);
        printf("Endereco: %s\n", data.end);
        printf("Numero da casa: %d\n\n\n", data.nmrCasa);
        
    }
    
    printf("Qual registro deseja acessar? ");
    scanf(" %d", &id);
    
    rewind(arq);
    
    fseek(arq, (id - 1) * sizeof(data), 0);
    
	printf("Registro de Posicao %d\n", id);
	fread(&data, sizeof(data), 1, arq);
	printf("Nome: %s\n", data.nome);
	printf("Sobrenome: %s\n", data.sobrenome);
    printf("Endereco: %s\n", data.end);
    printf("Numero da casa: %d\n", data.nmrCasa);
	
    fclose(arq);
}