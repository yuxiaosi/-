#ifndef _MORSE_H 
#define _MORSE_H class Morse 
{ 
public:
Morse(int pin);
void dot(); 
void dash();
voidc_space(); 
void w_space(); 
private: 
int _pin; 
int _dottime;
}; 
#endif /_MORSE_H/
