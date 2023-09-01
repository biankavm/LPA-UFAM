/*
Laboratório de Programação Avançada - Laboratório 5: Questão 2
Bianka Vasconcelos Maciel - Matrícula: 22153135

Comando de exemplo para rodar o código: 
gcc palavras.c -o palavras -lcrypt
./palavras
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

char caracteres[] = "abc";
int tamanhoMaximo = 3;
char *senhaCriptografada = "$6$7yCakIXevncmT6se$m002Lkf2BK6Qgyhc.c/PxMTvcmBAXYtIo"
 "kUKvWwvB5H5zCt5HhhPOlV8ygebOcSsgNqG74whVwN.8UF9WaGfs/";

// ir mudando cada elemento da string de posição e adicionar essa nova strig em um vetor
// se a string já estiver no vetor, não deve ser adicionada


int verificaSenha(char* senhaTeste, char* senhaCriptografada) {
    char *senhaTesteCriptografada = crypt(senhaTeste, senhaCriptografada);
    return strcmp(senhaTesteCriptografada, senhaCriptografada);
}

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
        if (verificaSenha(pwd, senhaCriptografada) == 0){
            printf("%s --> sim! Senha encontrada!\n", pwd);
            exit(1);
        }
        else{
            printf("%s --> não\n", pwd);
        }
    }
}

int main(){
    int i = 1;
    while(i <= tamanhoMaximo){
        generateAllPasswords("", 0, i);
        i++;
    }
}