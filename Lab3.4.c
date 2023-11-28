/*Esercizio 4 – Copia dispari v. 2.0
Modificare il programma dell’esercizio precedente in modo che la matrice Mat1 di interi NxN (sempre con N
costante opportunamente definita) venga letta da un file di testo chiamato 'matrice.txt' scritto in formato
CSV (Comma Separated Values):
1,2,3
4,5,6
7,8,9
Il programma, prima di procedere con la copia degli elementi dispari, verifica che la matrice definita nel file
abbia le dimensioni richieste. Se la matrice non è di dimensioni NxN allora deve comparire un messaggio di
errore a video e il programma viene terminato.
Se la matrice contenuta nel file ha le dimensioni e il formato corretti, procedere come nel precedente esercizio,
stampare a video la matrice di partenza Mat1 e scrivere in un file di testo 'matrice_dispari.txt' la nuova
matrice Mat2, rispettando il formato riportato sopra.*/
#include <stdio.h>
#define N 6
void modifica(int K[][N], int B[][N], int dimensione){ // dall'esercizio Lab3.3
    int m, n, mB=0, nB=0;
    for (m = 0; m < dimensione; m++)
    {
        for (n = 0; n < dimensione; n++)
        {
            if (K[m][n] % 2 == 1) //se è dispari lo copio in B
            {
                B[mB][nB]=K[m][n];
                nB++; //e mi sposto nella casella più a dx di B
                if (nB==dimensione) //se sono arrivato a riempire tutta la prima riga di B passo a quella dopo
                {
                    nB=0;
                    mB++;
                }
            }
        }       
    }
    //aggiungo gli zeri necessari
    for (; mB < dimensione; mB++)
    {
        for (; nB < dimensione; nB++)
        {
            B[mB][nB]=0;
        }
        nB=0;
    }
}
void stampa(int K[][N], int righe_max, int colonne_max){
    int m, n;
    for (m = 0; m < righe_max; m++)
    {
        for (n = 0; n < colonne_max; n++)
        {
            printf("%d ", K[m][n]);
        }
        printf("\n"); 
    }
    printf("\n");
}
int main(){
    int i=0, j=0, righe=0, colonne=0, flag=0, A[N][N], B[N][N];
    char carattere;
    FILE *fp;
    fp=fopen("matrici.txt", "r");
    if (fp==NULL)
    {
        printf(" <<< ERRORE: Apertura file >>>\n");
        return -1;
    }
    else printf("<< File aperto >>\n");

    printf("<< Analisi file >>\n");
    while (fscanf(fp, "%d%c", &A[righe][j], &carattere)!=EOF)
    {
        if (flag==0) // Sono alla prima riga
        {
            if (carattere!='\n') // Non sono alla fine della riga
            {
                j++;
                colonne++;
            }
            else // Sono alla fine della riga
            {
                flag=1;
                colonne++;
                j=0;
                righe++;
            }
        }
        else // Sono a una riga successiva alla prima
        {
            if (carattere!='\n') // Non sono alla fine della riga
            {
                j++;
            }
            else // Sono alla fine della riga
            {
                j=0;
                righe++;
            }   
        }      
    }
    righe++; // Aggiungo la riga finale
    fclose(fp);
    printf("<< File chiuso >>\n");

    printf("<< Matrice trovata [%d x %d]: >>\n\n", righe, colonne);
    stampa(A, righe, colonne);

    if (righe!=colonne || righe>=N || colonne>=N) // La matrice deve essere quadrata e minore di NxN
    {
        printf(" <<< ERRORE: Matrice non quadrata o oltre il buffer >>>\n");
        return 1;
    }
    
    printf("Matrice [%d x %d] modificata:\n\n", righe, colonne);
    modifica(A, B, righe);
    stampa(B, righe, colonne);

    fp=fopen("matrici_dispari.txt", "a");
    printf("<< File aperto >>\n");
    // Stampa la matrice su file
    printf("<< Salvataggio matrice >>\n");
    fprintf(fp, "\n");
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            fprintf(fp,"%d", B[i][j]);
            if (j==colonne-1) // Va a capo quando finisce una riga
            {
                fprintf(fp, "\n");
            }
            else fprintf(fp, ","); // Oppure stampa una virgola
        } 
    }
    printf("<< Matrice salvata >>\n");
    fclose(fp);
    return 0;
}