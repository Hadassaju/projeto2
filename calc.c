char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void int_to_string(unsigned short num, char str[]) {
  unsigned short i = 0;
  unsigned short is_negative = 0;

  // Trata o caso especial de zero
  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return;
  }

  // Trata números negativos
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }

  // Cria a string reversa dos dígitos
  while (num > 0) {
    str[i++] = (num % 10) + '0';
    num /= 10;
  }

  // Adiciona o sinal de negativo, se necessário
  if (is_negative) {
    str[i++] = '-';
  }

  // Inverte a string
  unsigned short j;
  for (j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  // Adiciona o caractere nulo para terminar a string
  str[i] = '\0';
}

void uart_send_string(char *str)
{
  for (unsigned short i = 0; str[i] != '\0'; i++)
  {
    while ((*iostatus & 0x20) != 0x20)
      ;
    *iodata = str[i];
  }
	
	// Adiciona o caractere nulo para terminar a string
  while ((*iostatus & 0x20) != 0x20)
    ;
  *iodata = '\0';
}

void uart_send_integer(unsigned short num)
{
  char str[20];
  int_to_string(num, str);
  uart_send_string(str);
}

int main()
{

    unsigned short array[] = {5, 2, 7, 2, 8, 4, 9};
    unsigned short size = sizeof(array) / sizeof(array[0]);

    unsigned short soma = 0;
    
    uart_send_string("\n\nSomar os elementos de um vetor \n");
    uart_send_string("\n\nVetor: \n");
    for (unsigned short i = 0; i < size; i++)
    {
        uart_send_integer(array[i]);
        soma = soma + array[i];
	
        if (i == (size -1)) {
		uart_send_string("\n\nResultado: \n");
	        uart_send_integer(soma);
	    }
    }
    uart_send_string("\n\nFim! \n");

    return 0;
}

