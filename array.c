#include<stdio.h>
#include<string.h>

void insert(int array[], int length, int tempArray[], int value, int index){
    int i;
    for(i=0;i<length; i++){
        if(i<index){
            tempArray[i] = array[i];
        }
        else{
            tempArray[i+1] = array[i];
        }
    }
    tempArray[index] = value;
}

int main()
{
    int array[]={90, 70, 50, 80, 60, 85};

// comprimento = tamanho total do array / elemento idividual;    dessa forma podemos mudar o tamanho do array e a variável comprimento vai se adaptar dinamicamente
    int length = sizeof(array) / sizeof(array[0]);
    int i;
    int tempArray[length+1]; //cria um vetor maior que array


    insert(array,length,tempArray,15, 2);

    memcpy(array,tempArray,sizeof(tempArray)); // copia tempArray para array

     for(i=0; i<length+1; i++)
    {
       printf("%d\t", array[i]);
    }
    
    return 0;
}