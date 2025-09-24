#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 100 // limite máximo de cartas

// Estrutura que representa uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    Carta cartas[MAX_CARTAS];
    int qtdCartas, i;

    // ==========================
    // CADASTRO DAS CARTAS
    // ==========================
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &qtdCartas);

    if (qtdCartas > MAX_CARTAS) {
        printf("Numero maximo de cartas permitido: %d\n", MAX_CARTAS);
        return 1;
    }

    for (i = 0; i < qtdCartas; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        printf("Estado: ");
        scanf("%s", cartas[i].estado);

        printf("Codigo da carta: ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("Populacao: ");
        scanf("%d", &cartas[i].populacao);

        printf("Area (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhoes): ");
        scanf("%f", &cartas[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Calcula atributos derivados
        cartas[i].densidadePopulacional = cartas[i].populacao / cartas[i].area;
        cartas[i].pibPerCapita = cartas[i].pib / cartas[i].populacao;
    }

    // ==========================
    // ESCOLHA DAS CARTAS PARA DUELO
    // ==========================
    int c1, c2;
    printf("\nEscolha as cartas para comparar (1 a %d):\n", qtdCartas);
    printf("Numero da primeira carta: ");
    scanf("%d", &c1);
    printf("Numero da segunda carta: ");
    scanf("%d", &c2);

    // Ajusta índice para array (começa em 0)
    c1--; 
    c2--;

    if (c1 < 0 || c1 >= qtdCartas || c2 < 0 || c2 >= qtdCartas || c1 == c2) {
        printf("Escolha invalida de cartas!\n");
        return 1;
    }

    // ==========================
    // ESCOLHA DO ATRIBUTO
    // ==========================
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional (menor vence)\n");
    printf("5 - PIB per capita\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    printf("\n");

    // ==========================
    // COMPARAÇÃO DAS CARTAS
    // ==========================
    Carta carta1 = cartas[c1];
    Carta carta2 = cartas[c2];

    switch(opcao) {
        case 1: // População
            printf("Comparacao (Atributo: Populacao)\n\n");
            printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d habitantes\n\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Comparacao (Atributo: Area)\n\n");
            printf("Carta 1 - %s (%s): %.2f km²\n", carta1.nomeCidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km²\n\n", carta2.nomeCidade, carta2.estado, carta2.area);

            if (carta1.area > carta2.area)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Comparacao (Atributo: PIB)\n\n");
            printf("Carta 1 - %s (%s): %.2f bilhoes\n", carta1.nomeCidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f bilhoes\n\n", carta2.nomeCidade, carta2.estado, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Densidade Populacional (menor vence)
            printf("Comparacao (Atributo: Densidade Populacional)\n\n");
            printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
            printf("Carta 2 - %s (%s): %.2f hab/km²\n\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);

            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // PIB per capita
            printf("Comparacao (Atributo: PIB per capita)\n\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
            printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

            if (carta1.pibPerCapita > carta2.pibPerCapita)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            else if (carta2.pibPerCapita > carta1.pibPerCapita)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}