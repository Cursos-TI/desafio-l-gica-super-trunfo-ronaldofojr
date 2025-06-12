#include <stdio.h>

// Função para mostrar os dados da carta
void mostrarCarta(char estado, char codigo[], char nome[], int populacao, float area, float pib, int pontosTuristicos) {
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("\n");
}

// Função pra comparar população (quem tem maior vence)
int compararPopulacao(int p1, int p2) {
    if (p1 > p2)
        return 1;
    else if (p1 < p2)
        return 2;
    else
        return 0; // empate
}

// Função pra comparar área (quem tem maior vence)
int compararArea(float a1, float a2) {
    if (a1 > a2)
        return 1;
    else if (a1 < a2)
        return 2;
    else
        return 0;
}

// Função pra comparar PIB (quem tem maior vence)
int compararPIB(float pib1, float pib2) {
    if (pib1 > pib2)
        return 1;
    else if (pib1 < pib2)
        return 2;
    else
        return 0;
}

// Função pra comparar pontos turísticos (quem tem maior vence)
int compararPontos(int pts1, int pts2) {
    if (pts1 > pts2)
        return 1;
    else if (pts1 < pts2)
        return 2;
    else
        return 0;
}

// Função pra comparar densidade populacional (população/área), aqui quem tem menor vence
int compararDensidade(int p1, float a1, int p2, float a2) {
    float d1 = p1 / a1;
    float d2 = p2 / a2;

    if (d1 < d2)
        return 1;
    else if (d1 > d2)
        return 2;
    else
        return 0;
}

int main() {
    // Declaração das variáveis pra armazenar as cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome1[50], nome2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    int opcao, resultado;

    // Leitura da carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%3s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nome1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    printf("\n");

    // Leitura da carta 2
    printf("Cadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código (ex: B02): ");
    scanf("%3s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nome2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    printf("\n");

    // Mostrar as duas cartas depois do cadastro
    printf("Carta 1 cadastrada:\n");
    mostrarCarta(estado1, codigo1, nome1, populacao1, area1, pib1, pontosTuristicos1);

    printf("Carta 2 cadastrada:\n");
    mostrarCarta(estado2, codigo2, nome2, populacao2, area2, pib2, pontosTuristicos2);

    // Agora o menu pra escolher o atributo pra comparar
    printf("Escolha o atributo pra comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    printf("\n");

    // Switch pra tratar cada opção escolhida
    switch (opcao) {
        case 1:
            resultado = compararPopulacao(populacao1, populacao2);
            printf("Comparação por População:\n");
            break;
        case 2:
            resultado = compararArea(area1, area2);
            printf("Comparação por Área:\n");
            break;
        case 3:
            resultado = compararPIB(pib1, pib2);
            printf("Comparação por PIB:\n");
            break;
        case 4:
            resultado = compararPontos(pontosTuristicos1, pontosTuristicos2);
            printf("Comparação por Número de Pontos Turísticos:\n");
            break;
        case 5:
            resultado = compararDensidade(populacao1, area1, populacao2, area2);
            printf("Comparação por Densidade Populacional:\n");
            break;
        default:
            printf("Opção inválida!\n");
            return 1; // sai do programa com erro
    }

    // Mostrar quem venceu
    if (resultado == 1) {
        printf("Carta 1 vence!\n");
    } else if (resultado == 2) {
        printf("Carta 2 vence!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
