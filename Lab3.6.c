/*Esercizio 6 - Fusione di array ordinati con Bubblesort
Scrivere un programma che:
- chiede due volte all'utente di inserire N valori interi, e li salva in due array di dimensione N;
- ordina quindi ciascun array utilizzando il metodo Bubble Sort;
- effettua la fusione dei due array, in modo che l'array risultante mantenga l'ordinamento;
- stampa il vettore dopo la fusione.
Valutare inoltre la complessità dell'algoritmo di ordinamento contando il numero totale di confronti e il numero
totale di swap eseguiti e stampare questi valori.*/

#include <stdio.h>
#define N 5
void stampa(int K[]){
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", K[i]);
    }
    printf("\n"); 
}
void ordina(int K[]){
    int i, j, flag, temp;
    for (j = 0, flag=1; j < N-1 && flag==1; j++)//Questo ciclo esegue N-1 passate complete degli N numeri
    {
        flag=0; //Azzera le iterazioni fatte
        for (i=0; i<N-1; i++) //Questo ciclo fa passare tutte le coppie fino all'ultima
        {
            if (K[i]>K[i+1])
            {
                temp=K[i+1];
                K[i+1]=K[i];
                K[i]=temp;
                flag=1; //Segna che ha fatto almeno una iterazione
            }           
        }
    }
}

int main(){
    char c;
    int A[N], B[N], F[2*N], i, j, temp, flag=1;
    printf("Inserisci %d valori per l'array A[%d]\n", N, N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Inserisci %d valori per l'array B[%d]\n", N, N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }
    
    ordina(A);
    ordina(B);
    printf("\nOrdinato A[%d]:\n", N);
    stampa(A);
    printf("Ordinato B[%d]:\n", N);
    stampa(B);
    printf("\nPremi un tasto per unirli\n");
    while ((c = getchar()) != '\n' && c != EOF) // Devo rimuovere tutti i \n
        {
        // Rimuove i caratteri dal buffer finché non trovi '\n' o raggiungi EOF
        }
        getchar();

    //Gli array sono ora ordinati, li devo unire mantenendo l'ordine, uso i per A, j per B e temp per F
    i=0;
    j=0;
    temp=0;
    while (i<N && j<N) //Finchè non finisco uno dei due array (devono essere entrambi <N per passare il while)
    {
        if (A[i]<=B[j]) //Scelgo l'elemento minore fra A[i] e B[i]
        {
            F[temp]=A[i]; //E lo assegno all'elemento dell'array F in cui sono
            temp++; //Incremento l'array F
            i++; //E l'array che ho appena utilizzato
        }
        else
        {
            F[temp]=B[j]; //E lo assegno all'elemento dell'array F in cui sono
            temp++; //Incremento l'array F
            j++; //E l'array che ho appena utilizzato
        }        
    }
    while (i<N) //Non ho ancora terminato A
    {
        F[temp]=A[i]; //Riempio F con i restnti elementi di A
        temp++;
        i++;
    }
    while (j<N) //Non ho ancora terminato B
    {
        F[temp]=B[j]; //Riempio F con i restanti elementi di B
        temp++;
        j++;
    }    
    
    //Stampo l'array fusione
    printf("L'array fusione dei due è:\n");
    for (i = 0; i < 2*N; i++)
    {
        printf("%d ", F[i]);
    }
    
}