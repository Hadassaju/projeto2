#include <stdio.h>

int main() {
    // Defina o vetor com os elementos desejados
    int vetor[] = {10, 20, 30, 40, 50}; // Exemplo de vetor com 5 elementos

    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Calcula o tamanho do vetor

    int soma = 0;

    // Calcula a soma dos elementos do vetor
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    // Exibe o resultado da soma
    printf("A soma dos elementos do vetor é: %d\n", soma);

    return 0; // Programa encerrado com sucesso
}
