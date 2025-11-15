#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// --- Constantes Globais ---
//
#define TAMANHO_TABULEIRO 10
//
#define TAMANHO_NAVIO 3
//
#define TAMANHO_HABILIDADE 5 // Usando 5x5 como exemplo razoável [cite: 635]

// --- Protótipos das Funções ---

void inicializar_tabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

void exibir_tabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

void posicionar_navios(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

void criar_matriz_habilidade(int matriz_hab[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tipo);

void aplicar_habilidade(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                           int matriz_hab[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                           int origem_l, int origem_c);
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

 int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    // 1. Definição do Tabuleiro
    inicializar_tabuleiro(tabuleiro);
    // 2. Exibição do Tabuleiro
    posicionar_navios(tabuleiro);

    criar_matriz_habilidade(habilidade_cone, 1);     // 1 = Cone [cite: 631]
    criar_matriz_habilidade(habilidade_cruz, 2);     // 2 = Cruz [cite: 633]
    criar_matriz_habilidade(habilidade_octaedro, 3); // 3 = Octaedro [cite: 634]

    // Aplicando Cone na posição (2, 5)
    aplicar_habilidade(tabuleiro, habilidade_cone, 2, 5);

    // Aplicando Cruz na posição (7, 7)
    aplicar_habilidade(tabuleiro, habilidade_cruz, 7, 7);

    // Aplicando Octaedro na posição (4, 4) (sobrepondo um navio diagonal)
    aplicar_habilidade(tabuleiro, habilidade_octaedro, 4, 4);

    printf("### ⚓ Tabuleiro Final da Batalha Naval ⚓ ###\n");
    printf("Legenda: 0=Água | 3=Navio | 5=Área de Habilidade\n\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}


// --- Funções ---

void inicializar_tabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Loop aninhado para percorrer a matriz [cite: 256]
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tab[i][j] = 0; // 0 representa água [cite: 251]
        }
    }
}

void exibir_tabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime cabeçalho das colunas para facilitar visualização
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }

printf("\n--|--------------------\n");

for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); // Imprime cabeçalho da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da célula (0, 3 ou 5)
            //
            printf("%d ", tab[i][j]);
        }
        printf("\n"); // Pula para a próxima linha
    }
}

void posicionar_navios(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // (Coordenadas e tamanhos fixos) [cite: 272, 273, 449]
    // Navio Horizontal (Tamanho 3) [cite: 254]
    tab[1][1] = 3;
    tab[1][2] = 3;
    tab[1][3] = 3;
    // Navio Vertical (Tamanho 3) [cite: 254]
    tab[3][0] = 3;
    tab[4][0] = 3;
    tab[5][0] = 3;
    // Navio Diagonal (Subindo-Esquerda) (Tamanho 3) [cite: 429]
    tab[3][3] = 3;
    tab[4][4] = 3;
    tab[5][5] = 3;
    // Navio Diagonal (Subindo-Direita) (Tamanho 3) [cite: 429]
    tab[8][1] = 3;
    tab[7][2] = 3;
    tab[6][3] = 3;

}

void criar_matriz_habilidade(int matriz_hab[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tipo) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz_hab[i][j] = 0;
        }
    }
// 2. Define a área afetada (1) usando loops aninhados e condicionais [cite: 647, 667]
    //
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz 5x5 é [2][2]    

    switch (tipo) {
        case 1: // Cone (Origem no topo [0][centro], expandindo para baixo) [cite: 631]
            //
            // Lógica baseada nos exemplos de saída [cite: 650-652]
            for (int i = 0; i < 3; i++) { // Apenas as 3 primeiras linhas
                for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
                    // Condicional: abs(j - centro) <= i
                    if (abs(j - centro) <= i) {
                        matriz_hab[i][j] = 1; // 1 = afetado [cite: 635]
                    }
                }
            }
            break;

        case 2: // Cruz (Origem no centro) [cite: 633]
            //
            for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
                for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
                    // Condicional: (linha == centro) OU (coluna == centro)
                    if (i == centro || j == centro) {
                        matriz_hab[i][j] = 1;
                    }
                }
            }
         
            break;

        case 3: // Octaedro (Losango / Diamante) (Origem no centro) [cite: 634]
            //
            for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
                for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
                    // Condicional: Distância de Manhattan do centro <= centro
                    if (abs(i - centro) + abs(j - centro) <= centro) {
                        matriz_hab[i][j] = 1;
                    }
                }
            }
            break;
    }
}

void aplicar_habilidade(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                          int matriz_hab[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                          int origem_l, int origem_c) {


       int centro_hab = TAMANHO_HABILIDADE / 2; // (ex: 2)
       for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // 1. Verifica se esta parte da habilidade está ativa (== 1)
            //
            if (matriz_hab[i][j] == 1) {
                
                // 2. Calcula o offset do centro da habilidade
                int offset_l = i - centro_hab; // de -2 a +2
                int offset_c = j - centro_hab; // de -2 a +2

                // 3. Calcula a coordenada alvo no tabuleiro principal 10x10
                //
                int l_tab = origem_l + offset_l;
                int c_tab = origem_c + offset_c;

                // 4. Condicional de Validação de Limites
                // Garante que a área de efeito permaneça dentro dos limites do tabuleiro [cite: 648]
                //
                if (l_tab >= 0 && l_tab < TAMANHO_TABULEIRO && 
                    c_tab >= 0 && c_tab < TAMANHO_TABULEIRO) {
                    
                    // 5. Aplica a Habilidade (Valor 5)
                    // Somente se a posição for Água (0)
                    //
                    if (tab[l_tab][c_tab] == 0) {
                        tab[l_tab][c_tab] = 5; // [cite: 641, 646]
                    }
                }
            }
        }
    }                     
}