#ifndef Blink_h
#define Blink_h

#include <Arduino.h>


#define ON true
#define OFF false

class SevenSegment
{
public:

    bool interupt;

    int a,b,c,d,e,f,g,dp;
    int segment_count;
    int segment_pins[4];
    SevenSegment(int pins[8],int segment_pins_in[4]);
    void print_digit(int digit, int pos);
    void print_decimal(int decimal);
    void initialize();
    void reset_display();


};

#endif
