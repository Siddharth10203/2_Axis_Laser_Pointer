int x = 0;
int y = 0;

#define HT 600
#define LT 400

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = incdec(analogRead(A0),x);
  y = incdec(analogRead(A1),y);
  
  if (analogRead(A2)==0 && analogRead(A1) > LT && analogRead(A0)>LT){
    x=0;
    y=0;
  }

  Serial.print(x);
  Serial.print("   ");
  Serial.print(analogRead(A2));
  Serial.print("   ");
  Serial.println(y);
}

int incdec(double a, int b){
  if(a > HT)
    b++;
  else if(a < LT)
    b--;
  return b;
}

