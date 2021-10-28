#include "arvore.h"

int main(){
  int n, op, x;
  //arvore *a = criar();

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &op);
    if(op == 1 || op == 2 || op == 3)
      scanf("%d", &x);
    
    switch(op){
      case 1:
        //inserir(a, x);
        break;

      case 2:
        //sucessor(a, x);
        break;

      case 3:
        //predecessor(a, x);
        break;

      case 4:
        //maximo(a);
        break;

      case 5:
        //minimo(a);
        break;

      case 6:
        //pre_ordem(a);
        break;

      case 7:
        //em_ordem(a);
        break;

      case 8:
        //pos_ordem(a);
        break;
    }
  }

  //liberar(a);

  return 0;
}
