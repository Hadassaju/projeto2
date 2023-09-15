#include <stdio.h> // Para as funções de entrada e saída padrão

char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void int_to_string(unsigned short num, char str[]) {
  // ... (código da função int_to_string igual ao seu exemplo)
}

void uart_send_string(char *str) {
  // ... (código da função uart_send_string igual ao seu exemplo)
}

void uart_send_integer(unsigned short num) {
  // ... (código da função uart_send_integer igual ao seu exemplo)
}

void sum_array(unsigned short *array, unsigned short size) {
  unsigned int sum = 0;

  for (unsigned short i = 0; i < size; i++) {
    sum += array[i];
  }

  char sum_str[20];
  int_to_string(sum, sum_str);

  uart_send_string("Soma dos elementos do vetor: ");
  uart_send_string(sum_str);
  uart_send_string("\n");
}

int main() {
  unsigned short array[] = {7, 2, 9, 4, 8, 15, 1};
  unsigned short size = sizeof(array) / sizeof(array[0]);

  uart_send_string("\n\nSoma dos Elementos de um Vetor\n");

  sum_array(array, size);

  uart_send_string("\nFim.");

  return 0;
}
