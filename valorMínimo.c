#include<stdio.h>

int valorMinimo(int vetor[], int length){
    int i;
    int minIndex = 0;

    for(i=1;i<length;i++)
    {
        if(vetor[minIndex]>vetor[i])
        {
            minIndex=i;
        }
    }
    return vetor[minIndex];
}

int main(){

    int vetor[]={5,15,20,2,40,50};

    int length = sizeof(vetor) / sizeof(vetor[0]); 

    int minValue = valorMinimo(vetor, length);

    printf("%d", minValue);

  return 0;  
}