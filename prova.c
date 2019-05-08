#include <stdio.h>
#include <ctype.h>

#define N 1000


void crip(char [],char []);
void UP(char []);
void elimina(char []);
void adiciona(char[]);

void desloca(char [], int);
int verifica(char,char[]);
void append(char [],char);
void copia(char[],char[]);
int getindex(char);  
int tamanho(char[]); 
void transforma(char[]); //transforma a frase de acordo com a entrada definida
  
int main(){
	char string[N] = {'0'};
	char frase[N] = {'0'};
	
	printf("Digite a frase para ser sua chave\n");
	fgets(string,N,stdin);
	
	printf("\nDigite a frase que sera criptografada\n");
	fgets(frase,N,stdin);
	
	UP(string);
	UP(frase);
	transforma(string);
	transforma(frase);

	elimina(string);
	adiciona(string);
	crip(string,frase);
	printf("%s",frase);
	return 0;
}

void crip(char chave[],char frase[]){ // item 2)
	
	int i = 0;
	int j = 0;
	int tam = 0;
	tam = tamanho(chave);
	while(frase[i] != '\0'){
		j = j + getindex(frase[i]);
		while( j > (tam -1)){
			j = j - tam - 1;
		} 
		frase[i] = chave[j];
		i++;
	}
	
}

void UP(char s[]){ //item a)
	int i = 0;
	while(s[i] != '\0'){
		if(isalpha(s[i])){
			s[i] = toupper(s[i]);
		}
	i++;	 
	}

}

void elimina(char s[]){ //item b)
	char alfa[30] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',',','.',' '};
	char beta[30] = {'0'};
	int b = 1; //indice beta
	int i = 0;
	
	while(s[i] != '\0'){
		if(verifica(s[i],alfa) && !verifica(s[i],beta)){
			beta[b] = s[i];
			b++;
			i++;
		}else{
			desloca(s,i);		
		}
	}
	
}

void adiciona(char s[]){//item c)
	char alfa[30] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',',','.',' '};
	int i = 1;
	while( i<31){
		if(!verifica(alfa[i],s)){
			append(s,alfa[i]);
		}
		i++;
	}
	
}

void desloca(char s[], int i){
	while( s[(i)] != '\0'){
		s[i] = s[(i+1)];
		i++;
	} 
	s[i] = '\0';
}

int verifica(char c,char string[]){
	int b = 0;
	int i = 0;
	while(i<31){
		if(c == string[i]){
			b = 1;
			break;
		}
		i++;
	}
	return b;
}

void append(char s[], char c){
	int i=0;
	while(s[i] != '\0'){
		i++;
	}
	s[i] = c;
	s[(i+1)] = '\0';
}

void copia(char s[], char z[]){
	int i = 0;
	while( z[i] != '\0'){
		s[i] = z[i];
		i++;
	}
	s[i] = '\0';
}

int getindex(char c){
	char alfa[30] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',',','.',' '};
	int i = 1;
	while (i<30){
		if( c == alfa[i]){
			break;
		}
		i++;
	}
	return i;
}

int tamanho(char s[]){
	int i = 0;
	while(s[i] != '\0'){
		i++;
	}
	i = i - 1;
	return i;
}

void transforma(char s[]){
	char alfa[30] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',',','.',' '};
	int i = 0;
	while(s[i] != '\0'){
		if(!verifica(s[i],alfa)){
			desloca(s,i);
		}else{
			i++;
		}
		
	}
}