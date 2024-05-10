#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int contadorCarros = 0;
pthread_mutex_t cruzamento;
const char* sinal = "horizontal";

typedef struct {
    int carro_id; 
    const char* rua;
    int direcao; // 1 reto, 2 virar
    int ladoRua; // 1 esquerda, 2 direita
} Carro;

void visualizarDireitaReto(int isVertical) {
    contadorCarros++;
    char rua[10]; 

    for (int c = 0; c < 5; c++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5];
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + c, carro, strlen(carro));

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               |    | %c  |\n", rua[0]);
        printf("               +---------+\n");
        printf("               |    | %c  |\n", rua[1]);
        printf("      --+--+---+\033[32m---------\033[39m+---+--+--\n");
        printf("rua 4   _C _%2d \033[31m|\033[39m      %c  |   _  _      rua 2\n", contadorCarros + 1,rua[2]);  
        printf("               \033[31m|\033[39m      %c  |          \n", rua[3]);
        printf("      --+--+---+---------+---+--+--\n");
        printf("               |    | %c  |\n", rua[4]);
        printf("               +---------+\n");
        printf("               |    | %c  |\n", rua[5]);
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }


    contadorCarros++;

    for (int i = 0; i < 5; i++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5]; 
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + i, carro, strlen(carro));  

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("      --+--+---+\033[31m---------\033[39m+---+--+--\n");
        printf("rua 4   _%c _  %c\033[32m|\033[39m %c    %c  |  %c_ %c_      rua 2\n", rua[0], rua[1], rua[2], rua[3], rua[4], rua[5]);  
        printf("               \033[32m|\033[39m         |         \n");
        printf("      --+--+---+---------+---+--+--\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }
}


void visualizarDireitaVirando(int isVertical) {
    contadorCarros++;
    char rua[10]; 

    for (int c = 0; c < 5; c++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5];
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + c, carro, strlen(carro));

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               |    | %c  |\n", rua[0]);
        printf("               +---------+\n");
        printf("               |    | %c  |\n", rua[1]);
        printf("      --+--+---+\033[32m---------\033[39m+---+--+--\n");
        printf("rua 4   _C _%2d \033[31m|\033[39m      %c  |  %c_ %c_      rua 2\n", contadorCarros + 1,rua[2], rua[3], rua[4]);  
        printf("               \033[31m|\033[39m         |         \n");
        printf("      --+--+---+---------+---+--+--\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }

    contadorCarros++;

    for (int i = 0; i < 5; i++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5]; 
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + i, carro, strlen(carro));  

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("      --+--+---+\033[31m---------\033[39m+---+--+--\n");
        printf("rua 4   _%c _  %c\033[32m|\033[39m     %c   |   _  _      rua 2\n", rua[0], rua[1], rua[2]);        
        printf("               \033[32m|\033[39m      %c  |         \n", rua[3]);
        printf("      --+--+---+---------+---+--+--\n");
        printf("               |    | %c  |\n", rua[4]);
        printf("               +---------+\n");
        printf("               |    | %c  |\n",rua[5]);
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }
}

void visualizarEsquerdaReto(int isVertical) {
    contadorCarros++;
    char rua[10]; 

    for (int c = 0; c < 5; c++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5];
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + c, carro, strlen(carro));

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               | %c  |    |\n", rua[0]);
        printf("               +---------+\n");
        printf("               | %c  |    |\n", rua[1]);
        printf("      --+--+---+\033[32m---------\033[39m+---+--+--\n");
        printf("rua 4   _  _   \033[31m|\033[39m %c       |   _  _      rua 2\n", rua[2]);  
        printf("         C  %2d \033[31m|\033[39m %c       |          \n", contadorCarros + 1,rua[3]);
        printf("      --+--+---+---------+---+--+--\n");
        printf("               | %c  |    |\n", rua[4]);
        printf("               +---------+\n");
        printf("               | %c  |    |\n", rua[5]);
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }

    contadorCarros++;

    for (int i = 0; i < 5; i++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5]; 
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + i, carro, strlen(carro));  

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("      --+--+---+\033[31m---------\033[39m+---+--+--\n");
        printf("rua 4   _  _   \033[32m|\033[39m         |   _  _      rua 2\n");
        printf("         %c    %c\033[32m|\033[39m %c   %c   |  %c   \n", rua[0],rua[1],rua[2], rua[3], rua[4]);
        printf("      --+--+---+---------+---+--+--\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }
}

void visualizarEsquerdaVirando(int isVertical) {
    contadorCarros++;
    char rua[10]; 

    for (int c = 0; c < 5; c++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5];
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + c, carro, strlen(carro));

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               | %c  |    |\n", rua[0]);
        printf("               +---------+\n");
        printf("               | %c  |    |\n", rua[1]);
        printf("      --+--+---+\033[32m---------\033[39m+---+--+--\n");
        printf("rua 4   _C _%2d \033[31m|\033[39m %c   %c   |%c  _%c _      rua 2\n",contadorCarros + 1, rua[2], rua[3], rua[4], rua[5]);  
        printf("               \033[31m|\033[39m         |          \n");
        printf("      --+--+---+---------+---+--+--\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");
        
        usleep(299000);
        system("clear");
    }

    contadorCarros++;

    for (int i = 0; i < 5; i++) {
        memset(rua, ' ', sizeof(rua));
        rua[sizeof(rua) - 1] = '\0'; 

        char carro[5]; 
        sprintf(carro, "C%d", contadorCarros);
        strncpy(rua + i, carro, strlen(carro));  

        printf("\n\n");
        printf("                 rua 1\n");
        printf("               +         +\n");
        printf("               |    |    |\n");
        printf("               +---------+\n");
        printf("               |    |    |\n");
        printf("      --+--+---+\033[31m---------\033[39m+---+--+--\n");
        printf("rua 4   _%c _ %c \033[32m|\033[39m %c       |   _  _      rua 2\n", rua[0], rua[1], rua[2]);           
        printf("               \033[32m|\033[39m %c       |         \n",rua[3]);
        printf("      --+--+---+---------+---+--+--\n");
        printf("               | %c  |    |\n", rua[4]);
        printf("               +---------+\n");
        printf("               | %c  |    |\n",rua[5]);
        printf("               +         +\n");
        printf("                 rua 3\n\n\n");

        usleep(299000);
        system("clear");
    }
}

void* cruzarCruzamento(void* arg) {
    Carro* carro = (Carro*)arg;
    pthread_mutex_lock(&cruzamento);

    for(int i = 0; i < 3; i++) {
        if (i == 0) {
            visualizarDireitaReto(carro->ladoRua == 1 ? 1 : 0);
        } else if (i == 1) {
            visualizarDireitaVirando(carro->ladoRua == 1 ? 1 : 0);
        } else if (i == 2) {
            visualizarEsquerdaReto(carro->ladoRua == 1 ? 1 : 0);
        } else {
            visualizarEsquerdaVirando(carro->ladoRua == 1 ? 1 : 0);
        }
    }

    pthread_mutex_unlock(&cruzamento);
    free(carro);
    return NULL;
}

int main() {
    pthread_mutex_init(&cruzamento, NULL);
    srand(time(NULL));

    while (1) {
        int num_carros_horizontal = rand() % 9 + 2;
        int num_carros_vertical = rand() % 9 + 2;
        int num_carros_total = num_carros_horizontal + num_carros_vertical;

        Carro* carros[num_carros_total];
        pthread_t threads[num_carros_total];

        int index = 0;
        int direcao;
        int faixa;
        for (int i = 0; i < num_carros_horizontal; i++) {
            carros[index] = (Carro*)malloc(sizeof(Carro));
            carros[index]->carro_id = index + 1;
            carros[index]->rua = "horizontal";
            direcao = rand() % 2 + 1;
            carros[index]->direcao = direcao;
            if(direcao == 2){ // Vai virar, 2 possibilidades de faixa
                faixa = rand() % 2 + 1;
                carros[index]->ladoRua = faixa; // 1 esquerda, 2 direita
            }
            index++;
        }

        for (int i = 0; i < num_carros_vertical; i++) {
            carros[index] = (Carro*)malloc(sizeof(Carro));
            carros[index]->carro_id = index + 1;
            carros[index]->rua = "vertical";
            direcao = rand() % 2 + 1;
            carros[index]->direcao = direcao;
            faixa = rand() % 2 + 1;
            carros[index]->ladoRua = faixa; // 1 esquerda, 2 direita
            index++;
        }

        for (int i = 0; i < num_carros_total; i++) {
            pthread_create(&threads[i], NULL, cruzarCruzamento, (void*)carros[i]);
        }

        for (int i = 0; i < num_carros_total; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    pthread_mutex_destroy(&cruzamento);
    return 0;
}
