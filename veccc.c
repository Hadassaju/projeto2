char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void int2string(unsigned short int num, char *str) {
  unsigned short int i = 0;
  unsigned short int is_negative = 0;

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
  unsigned short int j;
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
  for (unsigned short int i = 0; str[i] != '\0'; i++)
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

void uart_send_integer(unsigned short int num)
{
  char str[20];
  int2string(num, str);
  uart_send_string(str);
}

void print_array(unsigned short int *vector, unsigned short int size)
{
	for (unsigned short int i = 0; i < size; i++) {
    uart_send_integer(vector[i]);
		uart_send_string(" ");
  }
}

void sort_array(unsigned short int *vector, unsigned short int n)
{
	unsigned short int i, j, aux;
	for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - 1 - i; j++) {
          if (vector[j] > vector[j + 1]) {
              aux = vector[j];
              vector[j] = vector[j + 1];
              vector[j + 1] = aux;							
          }
      }
  }
	print_array(vector,n);

}

int main()
{

	unsigned short int vector[] = {6, 25, 15, 5, 1, 40, 55};
  unsigned short int n = sizeof(vector)/sizeof(vector[0]);

  uart_send_string("\n\nOrdenador de Vetor\n");
	
	sort_array(vector, n);
	uart_send_string("\n");

	print_array(vector, n);

  return 0;
}

