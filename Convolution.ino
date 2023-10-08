int n = 3;
int padding = 2;
int inp[7][7];
int kernel[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
int y[3][3];
void setup() {
  // put your setup code here, to run once:
  pinMode(inp[2][2], INPUT);
  pinMode(inp[2][3], INPUT);
  pinMode(inp[2][4], INPUT);
  pinMode(inp[3][2], INPUT);
  pinMode(inp[3][3], INPUT);
  pinMode(inp[3][4], INPUT);
  pinMode(inp[4][2], INPUT);
  pinMode(inp[4][3], INPUT);
  pinMode(inp[4][4], INPUT);
  pinMode(y[0][0], OUTPUT);
  pinMode(y[0][1], OUTPUT);
  pinMode(y[0][2], OUTPUT);
  pinMode(y[1][0], OUTPUT);
  pinMode(y[1][1], OUTPUT);
  pinMode(y[1][2], OUTPUT);
  pinMode(y[2][0], OUTPUT);
  pinMode(y[2][1], OUTPUT);
  pinMode(y[2][2], OUTPUT);

}
void loop() {  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; i++) {
      int res = 0;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          res += kernel[i + k][j + l] * inp[i + k][j + l];
        }
      }
      if (res > 0) res = 1; else res = -1;
      digitalWrite(y[i][j], res);
    }
  }
}
