/*
Laboratório de Programação Avançada - Laboratório 5: Questão 1
Bianka Vasconcelos Maciel - Matrícula: 22153135

Comando de exemplo para rodar o código: 
gcc palavras.c -o palavras
./palavras
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

char caracteres[] = "abc";
int tamanhoMaximo = 3;

// ir mudando cada elemento da string de posição e adicionar essa nova strig em um vetor
// se a string já estiver no vetor, não deve ser adicionada

void generateAllPasswords(char pwd[], int pos, int siz){
    if (pos < siz){
        for(int i = 0; i < strlen(caracteres); i++){
            char *novaString = malloc(strlen(pwd) + 1);
            sprintf(novaString, "%s%c", pwd, caracteres[i]);
            generateAllPasswords(novaString, pos + 1, siz);
        continue;
        }
    }
    else{
        printf("%s\n", pwd);
    }
}

int main(){
    int i = 1;
    while(i <= tamanhoMaximo){
        generateAllPasswords("", 0, i);
        i++;
    }


}