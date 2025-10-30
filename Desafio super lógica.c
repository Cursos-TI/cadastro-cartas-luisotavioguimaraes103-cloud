#include <stdio.h>

/// Estrutura representando uma carta
struct Carta {
    int ataque;
    int defesa;
    int velocidade;
};

int main() {
    struct Carta carta1, carta2;
    int opcao, atributo1, atributo2;

    printf("=== COMPARADOR DE CARTAS ===\n\n");

    // Entrada de dados para as duas cartas
    printf("Digite os atributos da Carta 1 (ataque, defesa, velocidade): ");
    scanf("%d %d %d", &carta1.ataque, &carta1.defesa, &carta1.velocidade);

    printf("Digite os atributos da Carta 2 (ataque, defesa, velocidade): ");
    scanf("%d %d %d", &carta2.ataque, &carta2.defesa, &carta2.velocidade);

    // MENU PRINCIPAL
    printf("\nEscolha a etapa de comparação:\n");
    printf("1 - Etapa 1: Comparação simples (if / if-else)\n");
    printf("2 - Etapa 2: Comparação múltipla (switch / if encadeado)\n");
    printf("3 - Etapa 3: Comparação avançada (operador ternário)\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    // ==================== ETAPA 1 ====================
    case 1: {
        int escolha;
        printf("\nEscolha um atributo para comparar:\n");
        printf("1 - Ataque\n2 - Defesa\n3 - Velocidade\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            if (carta1.ataque > carta2.ataque)
                printf("Carta 1 venceu com maior ATAQUE!\n");
            else if (carta2.ataque > carta1.ataque)
                printf("Carta 2 venceu com maior ATAQUE!\n");
            else
                printf("Empate em ATAQUE!\n");
        } else if (escolha == 2) {
            if (carta1.defesa > carta2.defesa)
                printf("Carta 1 venceu com maior DEFESA!\n");
            else if (carta2.defesa > carta1.defesa)
                printf("Carta 2 venceu com maior DEFESA!\n");
            else
                printf("Empate em DEFESA!\n");
        } else if (escolha == 3) {
            if (carta1.velocidade > carta2.velocidade)
                printf("Carta 1 venceu com maior VELOCIDADE!\n");
            else if (carta2.velocidade > carta1.velocidade)
                printf("Carta 2 venceu com maior VELOCIDADE!\n");
            else
                printf("Empate em VELOCIDADE!\n");
        } else {
            printf("Opção inválida!\n");
        }
        break;
    }

    // ==================== ETAPA 2 ====================
    case 2: {
        int escolha;
        printf("\nEscolha o atributo principal:\n");
        printf("1 - Ataque\n2 - Defesa\n3 - Velocidade\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            if (carta1.ataque > carta2.ataque && carta1.defesa > carta2.defesa)
                printf("Carta 1 venceu! Tem ATAQUE e DEFESA maiores.\n");
            else if (carta2.ataque > carta1.ataque && carta2.velocidade > carta1.velocidade)
                printf("Carta 2 venceu! Tem ATAQUE e VELOCIDADE maiores.\n");
            else if (carta1.ataque == carta2.ataque)
                printf("Empate no ATAQUE!\n");
            else
                printf("Difícil decidir! As cartas têm pontos fortes diferentes.\n");
            break;

        case 2:
            if (carta1.defesa > carta2.defesa && carta1.velocidade > carta2.velocidade)
                printf("Carta 1 venceu! DEFESA e VELOCIDADE superiores.\n");
            else if (carta2.defesa > carta1.defesa && carta2.ataque > carta1.ataque)
                printf("Carta 2 venceu! DEFESA e ATAQUE superiores.\n");
            else
                printf("Empate técnico em DEFESA!\n");
            break;

        case 3:
            if (carta1.velocidade > carta2.velocidade)
                printf("Carta 1 venceu! É mais rápida.\n");
            else if (carta2.velocidade > carta1.velocidade)
                printf("Carta 2 venceu! É mais rápida.\n");
            else
                printf("Empate em VELOCIDADE!\n");
            break;

        default:
            printf("Opção inválida!\n");
        }
        break;
    }

    // ==================== ETAPA 3 ====================
    case 3: {
        printf("\nEscolha dois atributos para comparar (1 = Ataque, 2 = Defesa, 3 = Velocidade)\n");
        printf("Atributo 1: ");
        scanf("%d", &atributo1);
        printf("Atributo 2: ");
        scanf("%d", &atributo2);

        int soma1 = 0, soma2 = 0;

        // Soma dos atributos escolhidos para cada carta
        soma1 += (atributo1 == 1 ? carta1.ataque : (atributo1 == 2 ? carta1.defesa : carta1.velocidade));
        soma1 += (atributo2 == 1 ? carta1.ataque : (atributo2 == 2 ? carta1.defesa : carta1.velocidade));

        soma2 += (atributo1 == 1 ? carta2.ataque : (atributo1 == 2 ? carta2.defesa : carta2.velocidade));
        soma2 += (atributo2 == 1 ? carta2.ataque : (atributo2 == 2 ? carta2.defesa : carta2.velocidade));

        printf("\n--- RESULTADOS ---\n");
        printf("Carta 1 -> Ataque: %d | Defesa: %d | Velocidade: %d\n", carta1.ataque, carta1.defesa, carta1.velocidade);
        printf("Carta 2 -> Ataque: %d | Defesa: %d | Velocidade: %d\n", carta2.ataque, carta2.defesa, carta2.velocidade);

        printf("\nAtributos escolhidos: %d e %d\n", atributo1, atributo2);

        // Operador ternário para determinar o vencedor
        (soma1 > soma2) ? printf("Carta 1 venceu!\n") :
        (soma2 > soma1) ? printf("Carta 2 venceu!\n") :
        printf("Empate!\n");
        break;
    }

    default:
        printf("Opção inválida!\n");
    }

    printf("\n=== Fim do programa ===\n");
    return 0;
}