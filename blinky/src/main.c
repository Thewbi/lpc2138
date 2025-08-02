#include "LPC213x.h"

void
delay(int d)
{     
  for(; d; --d);
}

static void
cycle(int n)
{
  int m = 0;
  for (; n; m++, n--)
    {
      IO0CLR = 0x80000000;
      delay(m);
      IO0SET = 0x80000000;
      delay(n);
    }

  for (; m; m--, n++)
    {
      IO0CLR = 0x80000000;
      delay(m);
      IO0SET = 0x80000000;
      delay(n);
    }
}

static int on_off = 0;

static void
toggle()
{
  if (on_off) {
      IO0CLR = 0x80000000;
  } else {
    IO0SET = 0x80000000;
  }

  on_off = 1 - on_off;
      
}

int
main(void)
{

// Pins auf UART Funktion schalten  
//  PINSEL0 = (PINSEL0 & 0xfffffff0) | 0x00000005;
  
  //
  //// PLL einstellen  
  //PLLCFG = (4-1)|((2-1)<<5); // M=4 und P=2 (Multiplikatoren von 0 sind nicht erlaubt)
  //PLLCON = 0x01; // PLL aktivieren
 
  //PLLFEED = 0xAA;  //PLL Feed-Sequenz
  //PLLFEED = 0x55;
  //while ( !( PLLSTAT & (1<<10) ) ); // Auf PLOCK warten
  //

//PCONP |= PCONP_PCUART0;

//PINSEL0 = (PINSEL0 & 0xfffffffc) | 0x00000001; // TX only

//U0LCR = 0x83;	// 8 bits, no Parity, 1 Stop bit, DLAB = 1
//U0DLL = UART0_DIV_LOW;
//U0DLM = UART0_DIV_HIGH;

//U0DLL = 0x20;                // PCLK = CCLK @ 58,9225 MHz
//  U0DLM = 0x00;                // divider is 32; desired baud rate = 115200, real baud rate 115083

//U0DLL = 0x10; 
//U0DLM = 0x00; 

//U0LCR = 0x03;  // DLAB = 0
//U0IER = 0x00;  // No interrupts
//U0FCR = 0x01;  // Use FIFO
//U0TER = 0x80;  // Transmitter enabled

  IO0DIR |= 0x80000000;
  IO0SET = 0x80000000;
  while (1)
    {
      //cycle(1000);
      //cycle(2000);

      toggle();

      delay(200000);

      //my_putchar('a');
    }
  return 0;
}