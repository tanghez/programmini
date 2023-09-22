#include <stdio.h>
#include <stdbool.h>
int main() {
    int lato1 = 0, lato2 = 0, lato3 = 0;
    //todo acquisire di i lati del triangolo
    printf("scrivere primo lato\n");
    scanf("%d", &lato1);
    printf("scrivere secondo lato\n");
    scanf("%d", &lato2);
    printf("scrivere terzo lato\n");
    scanf("%d", &lato3)
    //todo verificare la condizione di triangolarità Or logico || Not logico
    //lato1 < lato2 + lato3 per tutti i lati
    //lato2 < lato1 + lato3
    //lato3 < lato2 + lato1
    bool triangolo_valido = lato1 < lato2 + lato3 &&
                            lato2 < lato1 + lato3 &&
                            lato3 < lato2 + lato1;
    //todo se la condizione non è valida stampare errore e uscire
    if (!triangolo_valido){        //è vero solo quando il triangolo non è valido
        printf("Errore, i lati inseriti non formano un triangolo\n");
        return -1; // lo considero un errore
    }
    printf("I lati inseriti formano un triangolo valido");
  
    //todo controllo equilatero + stampa risultato
    bool triangolo_valido = lato1 == lato2 && lato2 == lato3;
    if (triangolo_equilatero) {
      printf("Il triangolo è equilatero!\n");
      return 0;
    }
  
    //todo controllo isoscele + stampa risultato
    if (lato1 == lato2 || lato2 == lato3 || lato3 == lato1) {
      printf("Il triangolo è isoscele");
      return 0;
    }

    //todo controllo scaleno (menglio metterle nell'ordine giusto + stampa risultato
    printf("Il triangolo è scaleno"); //se ha superato le altre opzioni è sicuramente scaleno
    return 0;
}
