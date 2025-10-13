/*Escreva  um  programa  que  leia  10  números  reais  distintos  e  calcule  o  segundo  maior 
número lido*/

#include <stdio.h>

int main(){
    int n, maior = 0, segundo_maior = 0;
    
    for(int i = 1; i <= 10;i++){
        printf("Digite o numero: ");
        scanf("%d", &n);

        if(n > maior){
            segundo_maior = maior;
            maior = n;
        }
        else if(n > segundo_maior && n < maior){
            segundo_maior = n;
        }
    }

    printf("O segundo maior numero eh: %d\n\n", segundo_maior);

    return 0;
}