int inp[7][7];
int kernel[2][3][3] = {{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}};
const int s = 7;
int r;

int conv3x3(int inp[3][3], int kernel[3][3]) {
  int res = 0;
    for (int k = 0; k < 3; k++) {
      for (int l = 0; l < 3; l++) {
        res += kernel[k][l] * inp[k][l];
      }
    }
  return res;
}

int convolutionalNN(int size, int inp[s][s], int kernel[s / 2][3][3]) {
  // int t[size][size] = inp;
  int size_ = size - 2;
  int fResult;
  for (int i = 0; i < size/2; i++) {
    int t[size_][size_];
    for (int j = 0; j < size_; j++) {
      for (int k = 0; k < size_; k++) {
        int tt[3][3];
        for (int l = 0; l < 3; l++) {
          for (int m = 0; m < 3; m++) {
            tt[l][m] = inp[j + l][k + m];
          }
        }
        int res = conv3x3(tt, kernel[i]);
        t[j][k] = res;
      }
    }
    fResult = t[0][0];
  }
  return fResult;
}

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
  int res = convolutionalNN(7, inp, kernel);
}
