#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int valor;
    printf("1 - Pedra\n 2 - Papel\n 3 - Tesoura");
    printf("\n Escolha um valor:");
    scanf("%d", &valor);

    switch(valor)
	{
		case 1:
			printf("Jogador escolheu PEDRA\n");
		break;
		
		case 2:
			printf("Jogador escolheu PAPEL\n");
		break;
		
		case 3:
			printf("Jogador escolheu TESOURA\n");
		break;
		
		default:
			printf("Opcao invalida\n");
	}

    srand(time(NULL));
    int computador=("%d", rand()%3 + 1);

    switch(computador)
    {
        case 1:
            printf("O computador escolheu PEDRA");
        break;

         case 2:
            printf("O computador escolheu PAPEL");
        break;

         case 3:
            printf("O computador escolheu TESOURA");
        break;
    }

    if(valor==computador)
    {
        printf("\nEMPATE");
    }

    else if((valor==1 && computador==3) || (valor==2 && computador==1) || (valor==3 && computador==2))
    {
        printf("\nJOGADOR VENCEU");
    }

    else
    {
        printf("\nCOMPUTADOR VENCEU");
    }



    return 0;
}