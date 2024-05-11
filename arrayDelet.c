#include<stdio.h>
#include<string.h>

int main(){

    int array[]={90, 70, 50, 80, 60, 85};
    int length = sizeof(array) / sizeof(array[0]);
    int tempArray[length-1];

    printf("Digite o index para ser deletado:");
    int index;
    scanf("%d",&index);

    int i;
    for(i=0;i<length;i++)
    {
        if(i<index)
        {
            tempArray[i]=array[i];
        }
        if(i>index)
        {
            tempArray[i-1]=array[i];
        }
    }

    memcpy(array, tempArray,sizeof(tempArray));

    for(i=0;i<length-1;i++)
    {
        printf("%d\t",array[i]);
    }

    return 0;
}