#ifndef SevenSegment_h
#define SevenSegment_h

#include <Arduino.h>
#include <Thread.h>
#include <ThreadController.h>
#include <StaticThreadController.h>


#define ON true
#define OFF false

class SevenSegment
{

public:
    SevenSegment(int pins[8],int segment_pins_in[4]);
    static void print_number(int number);
private:
    static ThreadController controller;
    static int number_p;
    bool interupt;
    static int a,b,c,d,e,f,g,dp;
    int segment_count;
    int segment_pins[4];
    void initialize();
    void reset_display();
    void print_digit(int digit, int pos);
    void print_decimal();


};

#endif
