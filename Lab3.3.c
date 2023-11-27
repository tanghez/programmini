/*Esercizio 3 – Copia dispari
Scrivere un programma che, data una matrice Mat1 di interi NxN, con N costante opportunamente definita,
copia i soli elementi dispari in una nuova matrice Mat2 della stessa dimensione, senza lasciare posizioni vuote
intermedie. */

#include <stdio.h>
#define N 3
void stampa(int K[][N]){
    int m, n;
    for (m = 0; m < N; m++)
    {
        for (n = 0; n < N; n++)
        {
            printf("%d ", K[m][n]);
        }
        printf("\n"); 
    }
}
int main(){
    char c;
    int A[N][N], B[N][N], m, n, mB=0, nB=0;
    printf("Inserisci i valori della prima matrice %d x %d\n", N, N);
    for (m = 0; m < N; m++)
    {
        printf("Inserisci la %d^ riga\n", m+1);
        for (n = 0; n < N; n++)
        {
            scanf("%d", &A[m][n]);
        }     
    }
    printf("\nLa matrice inserita è:\n");
    stampa(A);
    //calcolo matrice modificata
    for (m = 0; m < N; m++)
    {
        for (n = 0; n < N; n++)
        {
            if (A[m][n] % 2 == 1) //se è dispari lo copio in B
            {
                B[mB][nB]=A[m][n];
                nB++; //e mi sposto nella casella più a dx di B
                if (nB==N) //se sono arrivato a riempire tutta la prima riga di B passo a quella dopo
                {
                    nB=0;
                    mB++;
                }
            }
        }       
    }
    //aggiungo gli zeri necessari
    for (; mB < N; mB++)
    {
        for (; nB < N; nB++)
        {
            B[mB][nB]=0;
        }
        nB=0;
    }
    printf("\nPremi un tasto per calcolare la matrice modificata");
    while ((c=getchar())!='\n' && c!=EOF)
    {
        //tolgo tutti gli \n dal buffer
    }
    getchar();
    
    printf("La matrice modificata è:\n");    
    stampa(B);
    return 0;
}