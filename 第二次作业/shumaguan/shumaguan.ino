void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(2,OUTPUT);

  Serial.begin(9600);
}
int input;
int i=0;
int letter[10][4]={
  {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},
  {0,1,0,1},v{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}
};

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    input=Serial.read();
    input = input-46;

    for(i=0;i<4;i++)
    {
      digitalWrite(5-i,letter[input][i]);
    }
    delay(1000);
  }
  
 }
