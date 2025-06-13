#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[30];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Funcao para calcular densidade populacional e PIB per capita
void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Funcao para exibir os dados de uma carta
void exibir_carta(Carta carta, int numero) {
    printf("Carta %d - %s (%s):\n", numero, carta.nome_cidade, carta.estado);
    printf("  Populacao: %d\n", carta.populacao);
    printf("  Área: %.2f km2\n", carta.area);
    printf("  PIB: %.2f\n", carta.pib);
    printf("  Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("  PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("\n");
}

int main() {
    // Definicao das cartas
    Carta carta1 = {
        "SP", "001", "Sao Paulo", 12300000, 1521.11, 750000000000.0, 10
    };
    Carta carta2 = {
        "RJ", "002", "Rio de Janeiro", 6000000, 1182.30, 360000000000.0, 8
    };

    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    printf("=== Carta 1 ===\n");
    exibir_carta(carta1, 1);
    printf("=== Carta 2 ===\n");
    exibir_carta(carta2, 2);

    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Digite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    printf("\n");

    //Menu interativo usando a estrutura switch de cada caracteristicas da carta de comparação
    switch (opcao) {
        case 1:
            printf("Comparacao de cartas (Atributo: Populacao):\n\n");
            printf("Carta 1 - %s: %d\n", carta1.nome_cidade, carta1.populacao);
            printf("Carta 2 - %s: %d\n", carta2.nome_cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
        case 2:
            printf("Comparacao de cartas (Atributo: Area):\n\n");
            printf("Carta 1 - %s: %.2f km2\n", carta1.nome_cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km2\n", carta2.nome_cidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.area > carta1.area) {
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
        case 3:
            printf("Comparacao de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: %.2f\n", carta1.nome_cidade, carta1.pib);
            printf("Carta 2 - %s: %.2f\n", carta2.nome_cidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
        case 4:
            printf("Comparacao de cartas (Atributo: Pontos Turisticos):\n\n");
            printf("Carta 1 - %s: %d\n", carta1.nome_cidade, carta1.pontos_turisticos);
            printf("Carta 2 - %s: %d\n", carta2.nome_cidade, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
        case 5:
            printf("Comparacao de cartas (Atributo: Densidade Populacional):\n\n");
            printf("Carta 1 - %s: %.2f hab/km2\n", carta1.nome_cidade, carta1.densidade_populacional);
            printf("Carta 2 - %s: %.2f hab/km2\n", carta2.nome_cidade, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
        default:
            printf("Opcao invalida! Por favor, escolha um numero de 1 a 5.\n");
    }

    getchar(); // Aguarda a entrada do usuario 
    getchar();

    return 0;
}

