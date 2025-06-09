#include <stdio.h>

 int main({
    printf("Desafio Super Trunfo\n")
 }
// Estrutura que representa uma carta do Super Trunfo, usando o typedef struct
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

// Função para calcular densidade populacional e PIB per capita
void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta, dei uma bugada, mas consegui
void exibir_carta(Carta carta, int numero) {
    printf("Carta %d - %s (%s):\n", numero, carta.nome_cidade, carta.estado);
    printf("  População: %d\n", carta.populacao);
    printf("  Área: %.2f km2\n", carta.area);
    printf("  PIB: %.2f\n", carta.pib);
    printf("  Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("  PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("\n");
}

int main() {
    // =========================
    // Definição da Carta 1
    // =========================
    Carta carta1 = {
        "SP",           // Estado
        "001",          // Código
        "São Paulo",    // Nome da cidade
        12300000,       // População
        1521.11,        // Área
        750000000000.0, // PIB
        10              // Pontos turísticos
    };

    // Calcula atributos derivados da carta 1
    calcular_atributos(&carta1);

    // Exibe a carta 1
    printf("=== Carta 1 ===\n");
    exibir_carta(carta1, 1);

printf("\n");

    // =========================
    // Definição da Carta 2
    // =========================
    Carta carta2 = {
        "RJ",               // Estado
        "002",              // Código
        "Rio de Janeiro",   // Nome da cidade
        6000000,            // População
        1182.30,            // Área
        360000000000.0,     // PIB
        8                   // Pontos turísticos
    };

    printf("\n");
    
    // Calcula atributos derivados da carta 2
    calcular_atributos(&carta2);

    // Exibe a carta 2
    printf("=== Carta 2 ===\n");
    exibir_carta(carta2, 2);

    // =========================
    // Comparação das cartas
    // =========================
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);

    // Lógica de comparação
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
