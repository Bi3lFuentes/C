#include<stdio.h>
#define TRUE 1
#define FALSE 0

void sort(int array[], int length) //ordena um vetor usando bubble sort 
{
    int i, j;

    for(i=0;i<length-1;i++)
    {
        int swap=FALSE;
        
        for(j=0;j<length-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap=TRUE;
            }
        }
        if(!swap) // se swap == 0 finaliza a funcao
        {
            break;
        }
    }

}

int main(void)
{
    int array[] = {90,60,50,80,70,85,95};
    int length = sizeof(array) / sizeof(array[0]); // define o tamanho do array 

    sort(array,length);

    int i;

    for(i=0;i<length;i++)
    {
        printf("%d, ", array[i]);
    }

    return 0;
}