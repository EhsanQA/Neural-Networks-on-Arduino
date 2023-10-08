int n = 3;
int padding = 2;
int inp[7][7];
int kernel[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
int w[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
int b = 5;
int y[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int r;
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
  pinMode(r, OUTPUT);

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
      y[i][j] = res;
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result += y[i][j] * w[i][j];
    }
  }
  result += b;
  if (result > 0) result = 1; else result = -1;
  digitalWrite(r, result);
}
