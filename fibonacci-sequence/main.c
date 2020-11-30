#include<stdio.h>
#include<stdlib.h>

int main() {
    int n = 0;

    printf("Quanti numeri della sequenza di Fibonaccio vuoi vedere?\n");

    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &n);
        if(n <= 2 || n >= 47) 
        {
            printf("\nIl numero inserito non è valido!\n");
        }
    } 
    while (n <= 2 || n >= 47);

    long arr[n + 3];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    printf("Calcolo la sequenza...\n");
    for(int i = 3; i < n; i++) {
        arr[i] = (arr[i - 1]) + (arr[i - 2]);
    }

    printf("Ecco il risultato:\n");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}