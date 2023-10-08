int x1;
int x2;
int w1 = 2;
int w2 = 2;
int b = -2;
int y;



void setup() {
  // put your setup code here, to run once:
  pinMode(x1, INPUT);
  pinMode(x2, INPUT);
  pinMode(y, OUTPUT);
}

void loop() {
    int x1_ = digitalRead(x1);
    int x2_ = digitalRead(x2);

    int out_ = 0;
    out_ = w1 * x1_ + w2 * x2_ + b;
    if (out_ >= 0) {
      digitalWrite(y, 1);
    } else {
      digitalWrite(y, 0);
    }


}
