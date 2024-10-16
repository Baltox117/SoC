#define FOSC 16000000
//Clock Spee 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void USART_Init(unsigned int ubrr){
  // Set baud rate
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char) ubrr;
  DDRD |= (1 << PD1);
  // Enable receiver and transmitter
  UCSR0B = (1 << TXEN0);
  // Set frame format : 8data, 2stop bit
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

void USART_Transmit(unsigned char data){
  // wait for empty transmit buffer
  while (!(UCSR0A & (1 << UDRE0)));
  // put data into buffer, sends the data
  UDR0 = data;
}

int main (void){
  USART_Init(MYUBRR);
  unsigned char character = 'Z';
  while (1) {
        USART_Transmit(character); // Envía el carácter
        _delay_ms(1000);           // Retraso para permitir ver el dato en el osciloscopio
    }
}