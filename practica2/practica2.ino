int main (void){
  DDRB = 255; // configuracion de los puertos B como de salida
  DDRD = 0x8; // configuracion de los puertos D como de salida
  TCCR0A = 0b00000000; // salidas modo de operacion
  TCCR0B = 0b00000111; // Modo de operacion (3), fuente de reloj
  TCCR2A = 0b00110011; // para el timer 2A para la velocidad mas rapida 
  TCCR2B = 0b00000111; // para el timer 2B es el divisor mas grande 
  while(1){
    PORTB = TCNT0;
  }
  return 0;
}
// 11 fast PWM  se lleva al maximo para que sea lo mas lenta posible
// 00000111 para el timer 2 es el divisor mas grande posible