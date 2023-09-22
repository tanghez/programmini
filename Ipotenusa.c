//includere libreria generale per printf e scanf
#include <stdio.h>
//inludere libreria radice quadrata
#include <math.h>
int main ()
{
  //dichiarare variabili locali
  int cateto1 = 0, cateto2 = 0;
  double ipotenusa = 0.0;
  //chiedere al cateto il primo cateto
  printf("inserire primo cateto: \n");
  //acquisire il primo cateto
  scanf("%d", &cateto1);
  //printf("il cateto inserito è: %d\n", cateto1);
  printf("inserire secondo cateto: \n");
  //acquisire il secondo cateto
  scanf("%d", &cateto2);
  //calcolare iootenusa
  int somma_quadrati = (cateto1*cateto1)+(cateto2*cateto2);
  ipotenusa = sqrt(somma_quadrati);
  //stampare ipotenusa
  printf("l'ipotenusa vale: %lf\n", ipotenusa);
}
