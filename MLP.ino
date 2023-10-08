byte x1;
byte x2;
byte y;
byte w[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

void setup() {
  // put your setup code here, to run once:
  pinMode(x1, INPUT);
  pinMode(x2, INPUT);
  pinMode(y, OUTPUT);
}

void loop() {
    byte x1_ = digitalRead(x1);
    byte x2_ = digitalRead(x2);

    byte out_;
    byte x1_2, x2_2;

    x1_2 = w[0] * x1 + w[1] * x2 + w[2];
    x2_2 = w[3] * x1 + w[4] * x2 + w[5];

    if (x1_2 > 0) x1_2 = 1; else x1_2 = -1;
    if (x2_2 > 0) x2_2 = 1; else x2_2 = -1;

    out_ = w[6] * x1_2 + w[7] * x2_2 + w[8]; 
    if (out_ >= 0) {
      digitalWrite(y, 1);
    } else {
      digitalWrite(y, 0);
    }


}
