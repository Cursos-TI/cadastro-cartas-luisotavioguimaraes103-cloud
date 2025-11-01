#include <stdio.h>

// Função recursiva para simular o movimento da Rainha (horizontal + vertical + diagonal)
void moverRainhaRecursivo(int x, int y, int limite, int passo) {
    if (passo > limite) return;
    printf("Rainha move para: (%d, %d)\n", x + passo, y);
    printf("Rainha move para: (%d, %d)\n", x, y + passo);
    printf("Rainha move para: (%d, %d)\n", x + passo, y + passo);
    moverRainhaRecursivo(x, y, limite, passo + 1);
}

int main() {
    int i, j;

    printf("=== Simulação de Movimentos de Xadrez (MateCheck) ===\n\n");

    // 1️⃣ Movimento da TORRE – usando for (horizontal e vertical)
    printf("Movimento da TORRE:\n");
    for (i = 1; i <= 8; i++) {
        printf("Torre move para: (%d, 1)\n", i); // horizontal
    }
    printf("\n");

    // 2️⃣ Movimento do BISPO – usando while (diagonal)
    printf("Movimento do BISPO:\n");
    i = 1;
    while (i <= 8) {
        printf("Bispo move para: (%d, %d)\n", i, i);
        i++;
    }
    printf("\n");

    // 3️⃣ Movimento da RAINHA – usando do-while + recursividade
    printf("Movimento da RAINHA:\n");
    i = 1;
    do {
        printf("Rainha move para: (%d, %d)\n", i, 1); // linha inicial
        i++;
    } while (i <= 3);
    printf("Movimentos avançados (recursivos):\n");
    moverRainhaRecursivo(1, 1, 3, 1);
    printf("\n");

    // 4️⃣ Movimento do CAVALO – loops aninhados
    printf("Movimento do CAVALO:\n");
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int nx = 4 + dx[i];
            int ny = 4 + dy[i];
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
                printf("Cavalo move para: (%d, %d)\n", nx, ny);
            }
        }
    }

    printf("\n=== Fim da Simulação ===\n");
    return 0;
}