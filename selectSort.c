#include<stdio.h>

void sort(int array[], int length)
{
    int minIndex = 0;
    int i, j;

    for(i=0;i<length-1;i++)
    {
        minIndex = i;
        int minValue = array[minIndex];

        for(j=i;j<length-1;j++)
        {
            if(minValue>array[j+1])
            {
                minValue = array[j+1];
            	minIndex = j+1; 
            }
        }
        
        if(i != minIndex)
        {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
        }
    }
}

int main()
{
    int array[]={70,50,80,90,60,40};
    int length = sizeof(array) / sizeof(array[0]);
    sort(array,length);

    int i;
    for(i=0;i<length;i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}