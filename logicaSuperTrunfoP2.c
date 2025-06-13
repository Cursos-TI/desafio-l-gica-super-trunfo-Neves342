#include <stdio.h>
//aluna: Yasmin Neves
//Bem vindo(a) ao jogo de Super Trunfo parte 2 ( Desafio de Logica), espero que goste do meu trabalho.

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[30];                  // Estado da cidade
    char codigo[10];                  // Codigo da carta
    char nome_cidade[50];             // Nome da cidade
    int populacao;                    // Populacao da cidade
    float area;                       // Area da cidade em km2
    float pib;                        // PIB da cidade
    int pontos_turisticos;            // Numero de pontos turisticos
    float densidade_populacional;     // Densidade populacional (calculada)
    float pib_per_capita;             // PIB per capita (calculado)
} Carta;

// Funcao auxiliar para calcular densidade populacional e PIB per capita
void calcular_atributos(Carta *carta) {
    // Protege contra divisao por zero
    if (carta->area > 0)
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    else
        carta->densidade_populacional = 0.0f;

    if (carta->populacao > 0)
        carta->pib_per_capita = carta->pib / carta->populacao;
    else
        carta->pib_per_capita = 0.0f;
}

// Funcao para exibir os dados de uma carta
void exibir_carta(Carta carta, int numero) {
    printf("Carta %d - %s (%s):\n", numero, carta.nome_cidade, carta.estado);
    printf("  Populacao: %d\n", carta.populacao);
    printf("  Area: %.2f km2\n", carta.area);
    printf("  PIB: %.2f\n", carta.pib);
    printf("  Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("  PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("\n");
}

// Funcao para retornar o nome do atributo conforme o numero escolhido
const char* nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

// Funcao para obter o valor do atributo escolhido de uma carta
float obter_valor_atributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade_populacional;
        default: return 0.0;
    }
}

// Funcao para exibir o valor do atributo escolhido de uma carta
void exibir_valor_atributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: printf("%d", carta.populacao); break;
        case 2: printf("%.2f km2", carta.area); break;
        case 3: printf("%.2f", carta.pib); break;
        case 4: printf("%d", carta.pontos_turisticos); break;
        case 5: printf("%.2f hab/km2", carta.densidade_populacional); break;
        default: printf("N/A");
    }
}

int main() {
    // Definicao das cartas (pre-cadastradas)
    Carta carta1 = {
        "SP", "001", "Sao Paulo", 12300000, 1521.11f, 750000000000.0f, 10, 0.0f, 0.0f
    };
    Carta carta2 = {
        "RJ", "002", "Rio de Janeiro", 6000000, 1182.30f, 360000000000.0f, 8, 0.0f, 0.0f
    };

    // Calcula os atributos derivados das cartas
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // Exibe as cartas cadastradas
    printf("=== Carta 1 ===\n");
    exibir_carta(carta1, 1);
    printf("=== Carta 2 ===\n");
    exibir_carta(carta2, 2);

    int atributo1 = 0, atributo2 = 0, valido = 0;

    // Menu para escolha do primeiro atributo de comparacao
    do {
        printf("Escolha o PRIMEIRO atributo para comparar:\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Populacional\n");
        printf("Digite o numero da opcao desejada: ");
        if (scanf("%d", &atributo1) != 1) {
            // Limpa o buffer em caso de entrada invalida
            while (getchar() != '\n');
            atributo1 = 0;
        }
        valido = (atributo1 >= 1 && atributo1 <= 5);
        if (!valido) printf("Opcao invalida! Tente novamente.\n\n");
    } while (!valido);

    // Menu para escolha do segundo atributo (nao pode ser igual ao primeiro)
    do {
        printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
        int i;
        for (i = 1; i <= 5; i++) {
            if (i != atributo1) {
                printf("%d - %s\n", i, nome_atributo(i));
            }
        }
        printf("Digite o numero da opcao desejada: ");
        if (scanf("%d", &atributo2) != 1) {
            // Limpa o buffer em caso de entrada invalida
            while (getchar() != '\n');
            atributo2 = 0;
        }
        valido = (atributo2 >= 1 && atributo2 <= 5 && atributo2 != atributo1);
        if (!valido) printf("Opcao invalida! Tente novamente.\n\n");
    } while (!valido);

    printf("\nComparando cartas com os atributos: %s e %s\n\n", nome_atributo(atributo1), nome_atributo(atributo2));

    // Obtem os valores dos atributos escolhidos para cada carta
    float valor1_c1 = obter_valor_atributo(carta1, atributo1);
    float valor1_c2 = obter_valor_atributo(carta2, atributo1);
    float valor2_c1 = obter_valor_atributo(carta1, atributo2);
    float valor2_c2 = obter_valor_atributo(carta2, atributo2);

    int vencedor1 = 0, vencedor2 = 0;

    // Regra: para densidade populacional, o menor vence; para os demais, o maior vence( pesquisei bastante aqui)
    vencedor1 = (atributo1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c2 < valor1_c1 ? 2 : 0))
                                 : (valor1_c1 > valor1_c2 ? 1 : (valor1_c2 > valor1_c1 ? 2 : 0));
    vencedor2 = (atributo2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c2 < valor2_c1 ? 2 : 0))
                                 : (valor2_c1 > valor2_c2 ? 1 : (valor2_c2 > valor2_c1 ? 2 : 0));

    // Exibe os valores e o vencedor de cada atributo
    printf("Atributo 1: %s\n", nome_atributo(atributo1));
    printf("  Carta 1 (%s): ", carta1.nome_cidade); exibir_valor_atributo(carta1, atributo1); printf("\n");
    printf("  Carta 2 (%s): ", carta2.nome_cidade); exibir_valor_atributo(carta2, atributo1); printf("\n");
    printf("  Vencedor: %s\n\n", vencedor1 == 1 ? carta1.nome_cidade : vencedor1 == 2 ? carta2.nome_cidade : "Empate");

    printf("Atributo 2: %s\n", nome_atributo(atributo2));
    printf("  Carta 1 (%s): ", carta1.nome_cidade); exibir_valor_atributo(carta1, atributo2); printf("\n");
    printf("  Carta 2 (%s): ", carta2.nome_cidade); exibir_valor_atributo(carta2, atributo2); printf("\n");
    printf("  Vencedor: %s\n\n", vencedor2 == 1 ? carta1.nome_cidade : vencedor2 == 2 ? carta2.nome_cidade : "Empate");

    // Soma dos valores dos dois atributos para cada carta
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("Soma dos atributos:\n");
    printf("  Carta 1 (%s): %.2f\n", carta1.nome_cidade, soma_c1);
    printf("  Carta 2 (%s): %.2f\n", carta2.nome_cidade, soma_c2);

    // Exibe o resultado final da rodada
    if (soma_c1 > soma_c2) {
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (soma_c2 > soma_c1) {
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    // Limpa o buffer do teclado
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\nPressione ENTER para sair...");
    getchar(); // Aguarda o ENTER do usuario

    return 0;
}
