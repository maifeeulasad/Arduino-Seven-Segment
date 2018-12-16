#include <SevenSegment.h>

int pins[] = {9, 8, 7, 6, 5, 4, 3, 2};
int seg[] = {13,12,11,10};

SevenSegment sevenSegment(pins, seg);


void setup() {
  /*
  for (int i = 0; i < 9999; i++) {

    sevenSegment.print_decimal(i);


    delay(250);
  }
  */
//delay(2000);

/*
  for(int i=0;i<4;i++){
    for(int j=0;j<10;j++){
      sevenSegment.print_digit(j,seg[i]);
      delay(1000);
    }
    
  }
  */


  
  

  //delay(4000);
  //sevenSegment.interupt=true;

sevenSegment.print_decimal(1250);

}

void loop() {
//sevenSegment.print_decimal(1250);

}
