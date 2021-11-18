#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int pegaCampo(FILE *arq, char *campo);

int main(){

	char nome[15], sobrenome[15], end[26], nrmCasa[4];
	char campo[60], registro[60];
	int tamCampo, aux = 0, id;
	
	FILE *arq;
	
	if ((arq = fopen("campo_var_reg_fixo.dad","rb")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo");
		getche();
		return 0;
	}
	
	tamCampo = pegaCampo(arq, campo);
	
	while (tamCampo > 0)
    {    
		printf("Nome: %s\n", campo);
		tamCampo = pegaCampo(arq,campo);       
        printf("Sobrenome: %s\n", campo);
        tamCampo = pegaCampo(arq,campo);       
        printf("Endereco: %s\n", campo);
         tamCampo = pegaCampo(arq,campo);       
        printf("Numero da casa: %s\n\n\n", campo);   
    	 aux++;
    	fseek(arq, aux * sizeof(registro) , 0);
    	tamCampo = pegaCampo(arq, campo);
    } 
	 
	printf("Qual registro deseja acessar? ");
    scanf(" %d", &id);
    
    rewind(arq);
    
    fseek(arq, (id - 1) * sizeof(registro), 0);
    printf("Registro de Posicao %d\n", id);
    
    tamCampo = pegaCampo(arq, campo);
    
    printf("Nome: %s\n", campo);
	tamCampo = pegaCampo(arq,campo);       
    printf("Sobrenome: %s\n", campo);
    tamCampo = pegaCampo(arq,campo);       
    printf("Endereco: %s\n", campo);
    tamCampo = pegaCampo(arq,campo);       
	printf("Numero da casa: %s\n\n\n", campo);   
	
	
	fclose(arq);
}


int pegaCampo(FILE *arq, char *campo)
{
    char ch;
    int i=0, aux = 0;

    campo[i] = '\0';
     
    while (fread(&ch,sizeof(char),1,arq))
    {
           if (ch == '|'){
           	  break;
           	  aux++;
		   }
           else campo[i] = ch;
           
           i++;
    }
     
     campo[i] = '\0';
     
     return strlen(campo);
}       