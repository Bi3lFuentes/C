#include<stdio.h>

void reverse(int array[], int length)
{
    int middle = length/2;
    int i;
    for(i=0;i<=middle;i++)
    {
        int temp = array[length-i-1];
        array[length-i-1] = array[i];
        array[i] = temp;

    }

}

int main()
{
    int scores[] = {40,50,60,70,80,90,100};

    int length = sizeof(scores) / sizeof(scores[0]);
printf("%d", length);
    reverse(scores,length);

    int i;

    for(i=0;i<length;i++)
    {
        printf("%d ", scores[i]);
    }

    return 0;
}