#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};
#endif /*_MORSE_H*/
Morse::Morse(int _pin)
{

    pinMode(_pin, OUTPUT);

    _codePin = _pin;

}


void Morse::dot()

{

    digitalWrite(_codePin, HIGH);

    delay(250);

    digitalWrite(_codePin, LOW);

    delay(250);

}


void Morse::dash()

{

    digitalWrite(_codePin, HIGH);

    delay(1000);

    digitalWrite(_codePin, LOW);

    delay(250);

}
void Morse::transfor(char _code)
{
  switch (_code) 
  {
        case 'a':
            dot();
            dash();
            break;
        case 'b':
            dash();
            dot();
            dot();
            dot();
            break;
        case 'c':
            dash();
            dot();
            dash();
            dot()
            break;
        case 'd':
            dash();
            dot();
            dot();
            break;
        case 'e':
            dot();
            break;
        case 'f':
            dot();
            dot();
            dash();
            dot();
            break;
        case 'g':
            dash();
            dash();
            dot();
            break;
        case 'h':
            dot();
            dot();
            dot();
            dot();
            break;
        case 'i':
            dot();
            dot();
            break;
        case 'j':
            dot();
            dash();
            dash();
            dash();
            break;
        case 'k':
            dash();
            dot();
            dash();
            break;
        case 'l':
            dot();
            dash();
            dot();
            dot();
            break;
        case 'm':
            dash();
            dash();
            break;
        case 'n':
            dash();
            dot();
            break;
        case 'o':
            dash();
            dash();
            dash();
            break;
        case 'p':
            dot();
            dash();
            dash();
            dot();
            break;
        case 'q':
            dash();
            dash();
            dot();
            dash();
            break;
        case 'r':
            dot();
            dash();
            dot();
            break;
        case 's':
            dot();
            dot();
            dot();
            break;
        case 't':
            dash();
            break;
        case 'u':
            dot();
            dot();
            dash();
            break;
        case 'v':
            dot();
            dot();
            dot();
            dash();
            break;
        case 'w':
            dot();
            dash();
            dash();
            break;
        case 'x':
            dash();
            dot();
            dot();
            dash();
            break;
        case 'y':
            dash();
            dot();
            dash();
            dash();
            break;
        case 'z':
            dash();
            dash();
            dot();
            dot();
            break;}
}
Morse morse(13);
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String str = "";  
  String morse_s = "";  
  int i, t , temp = 0;
  int n = 0;  
  while (Serial.available() > 0)
  {
    temp = 1;  
    str += char(Serial.read());  
    delay(2);  
    n++;
  }

  if (temp)
  {
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        if (str[i] >= 97 && str[i] <= 122)
        {
          morse_s += char(MORSE[int(str[i] - 97)][t]);
        }
      }
      morse_s += ' ';
    }
    Serial.println(morse_s);  
    for (i = 0; morse_s[i]!='\0' ; i++)
    {
      if (morse_s[i] == '.')morse.dot();
      else if (morse_s[i] == '-')morse.dash();
      else if (morse_s[i] == ' ')morse.w_space();
      if (morse_s[i] != ' ' && str[i] != '*')morse.c_space();
    }
    Serial.println("发送完毕");
    delay(2);
  }
}
