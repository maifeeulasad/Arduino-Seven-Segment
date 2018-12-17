
#include <Arduino.h>
#include "SevenSegment.h"

SevenSegment::SevenSegment(int pins[8],int segment_pins_in[4])
{

    controller=ThreadController();

    interupt=false;


    a=pins[0];
    b=pins[1];
    c=pins[2];
    d=pins[3];
    e=pins[4];
    f=pins[5];
    g=pins[6];
    dp=pins[7];


    segment_count=4;

    for(int i=0; i<segment_count; i++)
    {
        segment_pins[i]=segment_pins_in[i];
    }

    initialize();

}


void SevenSegment::initialize()
{
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(dp, OUTPUT);


    for (int i = 0; i < segment_count; i++)
    {
        pinMode(segment_pins[i], OUTPUT);

    }


}


void SevenSegment::reset_display()
{


    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, HIGH);
}

void SevenSegment::print_decimal()
{

    //while(interupt==false)
    while(true)
    {
        for (int i = 0; i < segment_count; i++)
        {
            print_digit(number_p % 10, segment_pins[i]);
            number_p = number_p / 10;
            delay(5);
        }
    }



    reset_display();

    for (int i = 0; i < segment_count; i++)
    {

        pinMode(segment_pins[i], LOW);

    }




}



void SevenSegment::print_digit(int digit, int pos)
{
    digit=digit%10;
    reset_display();
    for (int i = 0; i < segment_count; i++)
    {
        if (segment_pins[i] == pos)
        {
            pinMode(segment_pins[i], HIGH);
        }
        else
        {
            pinMode(segment_pins[i], LOW);
        }
    }
    if (digit != 1 && digit != 4)
        digitalWrite(a, LOW);
    if (digit != 5 && digit != 6)
        digitalWrite(b, LOW);
    if (digit != 2)
        digitalWrite(c, LOW);
    if (digit != 1 && digit != 4 && digit != 7)
        digitalWrite(d, LOW);
    if (digit == 2 || digit == 6 || digit == 8 || digit == 0)
        digitalWrite(e, LOW);
    if (digit != 1 && digit != 2 && digit != 3 && digit != 7)
        digitalWrite(f, LOW);
    if (digit != 0 && digit != 1 && digit != 7)
        digitalWrite(g, LOW);


}

void SevenSegment::print_number(int number)
{

    Thread* myThread = new Thread();


    if(controller.size(false)==0)
    {

        controller.add(myThread);
    }
    else
    {
        controller.clear();
        controller.add(myThread);
    }

    number_p=number;

    myThread->onRun(print_decimal);

    myThread->run();


}
