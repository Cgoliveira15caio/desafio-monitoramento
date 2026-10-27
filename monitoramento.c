#include <stdio.h>

int main() {
    float limiteTemperatura;
    float temperatura;
    int acimaDoLimiteConsecutivos = 0;

    printf("=== SISTEMA DE MONITORAMENTO DE TEMPERATURA ===\n\n");

    // Validação do limite de temperatura inicial usando do...while
    do {
        printf("Digite o limite maximo de temperatura permitido (C): ");
        if (scanf("%f", &limiteTemperatura) != 1) {
            printf("Entrada invalida! Por favor, insira um numero valido.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            limiteTemperatura = -999;
        } else if (limiteTemperatura <= 0) {
            printf("Erro: O limite de temperatura deve ser um valor positivo!\n");
        }
    } while (limiteTemperatura <= 0);

    printf("\nLimite definido em: %.2f C\n", limiteTemperatura);
    printf("Iniciando o monitoramento...\n");
    printf("(O sistema encerra se houver 3 leituras consecutivas acima do limite)\n\n");

    // Loop principal de leitura contínua usando while
    while (acimaDoLimiteConsecutivos < 3) {
        printf("Digite a leitura atual de temperatura (C): ");
        
        // Trata valores inválidos / entradas não numéricas
        if (scanf("%f", &temperatura) != 1) {
            printf("[ERRO] Entrada invalida! Tente novamente.\n\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        // Verifica se a temperatura está acima do limite
        if (temperatura > limiteTemperatura) {
            acimaDoLimiteConsecutivos++;
            printf("[ALERTA] Temperatura (%.2f C) acima do limite! (%d/3 consecutivas)\n\n", 
                    temperatura, acimaDoLimiteConsecutivos);
        } else {
            acimaDoLimiteConsecutivos = 0; // Reseta a contagem se for normal ou menor
            printf("[OK] Temperatura (%.2f C) dentro do limite normal.\n\n", temperatura);
        }
    }

    printf("====================================================\n");
    printf("ALERTA CRITICO: 3 temperaturas consecutivas acima do limite!\n");
    printf("Monitoramento encerrado automaticamente por seguranca.\n");
    printf("====================================================\n");

    return 0;
}
