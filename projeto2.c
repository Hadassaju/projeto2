#include <stdio.h>

int main() {
    // Declaração de variáveis
    float tensao, corrente, resistencia;

    // Solicitar ao usuário que insira a corrente e a resistência
    printf("Digite a corrente (em Amperes): ");
    scanf("%f", &corrente);

    printf("Digite a resistência (em Ohms): ");
    scanf("%f", &resistencia);

    // Calcular a tensão usando a fórmula de Ohm
    tensao = corrente * resistencia;

    // Exibir o resultado
    printf("A tensão é %.2f Volts\n", tensao);

    return 0;
}
