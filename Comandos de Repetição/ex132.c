#include <stdio.h>

int main(){
    int n;

    printf("Informe o numero: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int esp = 0; esp < 1 + i; esp++){
            printf(" ");
        }
        for(int ast = 0; ast < n - i; ast++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}