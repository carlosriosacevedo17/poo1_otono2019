#include <stdio.h>

#define allahuakbar 5 //Es una constante

void SelectionSort(int *array, int n) {
  int x, y, min, tmp;
  for(x = 0; x < n; x++) {
    min = x;
    for(y = x + 1; y < n; y++) {
      if(array[min] > array[y]) {
        min = y;
      }
    }
    tmp = array[min];
    array[min] = array[x];
    array[x] = tmp;
  }
}

void Shell(int *array, int n) {
   // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = array[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) 
                array[j] = array[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            array[j] = temp; 
        } 
    } 
}

void IBinaria(int *array, int n) {
  int x,y,m,tmp,izq,der;
  for(x = 1; x < n; x++) {
    tmp = array[x];
    izq = 0;
    der = x - 1;
    while (izq <= der) {
      m = (izq + der) / 2;
      if(tmp < array[m]) {
        der = m - 1;
      } else {
        izq = m + 1;
      }
    }
    y = x - 1;
    while (y >= izq) {
      array[y + 1] = array[y];
      y = y - 1;
    }
    array[izq] = tmp;
  }
}

void IDirecta(int *array, int n) {
  int x,val,y;
  for(x = 1; x < n; x++) {
    val = array[x];
    y = x - 1;
    while (y >= 0 && array[y] > val) {
      array[y + 1] = array[y];
      y--;
    }
    array[y + 1] = val;
  }
}

void QuickSort(int *array, int inicio, int final) {
  int i = inicio, f = final, tmp;
  int x = array[(inicio + final) / 2];
  do {
    while(array[i] < x && f <= final) {
      i++;
    }
    while(x < array[f] && f > inicio) {
      f--;
    }
    if(i <= f) {
      tmp = array[i];
      array[i] = array[f];
      array[f] = tmp;
      i++; f--;
    }
  } while(i <= f);

  if(inicio < f) {
    QuickSort(array,inicio,f);
  }

  if(i < final){
    QuickSort(array,i,final);
  }

}

void Burbuja(int *array, int n) {
  int x,y,tmp;
  for(x = 1; x < n; x++) {
    for(y = 0; y < n - x; y++) {
      if(array[y] > array[y + 1]) {
        tmp = array[y];
        array[y] = array[y + 1];
        array[y + 1] = tmp;
      }
    }
  }
}

void Print(char *function,int *array, int n) {
  int x;
  printf("%s:",function);
  for(x = 0; x < n; x++) {
    printf(" %i",array[x]);
  }
  printf("\n");
}

int main() {

  int vector[allahuakbar] = {12,34,54,2,3};

  SelectionSort(vector,allahuakbar);
  Print("SelectionSort",vector,allahuakbar);

  Shell(vector,allahuakbar);
  Print("Shell",vector,allahuakbar);

  IBinaria(vector,allahuakbar);
  Print("Isercion Binaria",vector,allahuakbar);

  IDirecta(vector,allahuakbar);
  Print("Isercion Directa",vector,allahuakbar);

  QuickSort(vector,0,allahuakbar - 1); // allahuakbar - 1: resto 1 porque es la posición inicial menos la final POSICIÓN NO CANTIDAD DE ELEMENTOS
  Print("QuickSort",vector,allahuakbar);

  Burbuja(vector,allahuakbar);
  Print("Burbuja",vector,allahuakbar);

  //system("PAUSE"); DESCOMENTAR SI SE CIERRA LA VENTANA

  return 1;
}
