# include <stdio.h>

long long a[2][3];

int resi4() {
  a[0][0] = a[0][2] = a[1][0] = a[1][2] = 1;
  return 1;
}

int resi0() {
  if (a[0][0] + a[1][0] == a[0][2] + a[1][2]) return 1;
  return 0;
}

int resi1() {
  int i, j;
  i = 0; j = 0;
  while (i < 2) {
    if (a[i][j] == 0) break;
    j += 2;
    if (j > 2) {
      i++; j = 0;
    }
  }
  if (i >= 2) return 0;
  a[i][j] = a[i][2-j] + a[1-i][2-j] - a[1-i][j];
  if (a[i][j] <= 0) return 0; else return 1;
}

int resi3() {
  int i, j;
  i = 0; j = 0;
  while (i < 2) {
    if (a[i][j] != 0) break;
    j += 2;
    if (j > 2) {
      i++; j = 0;
    }
  }
  if (i >= 2) return 0;
  a[i][2-j] = a[i][j];
  a[1-i][j] = a[1-i][2-j] = 1;
  return 1;
}

int resi2() {
  int i1, j1, i2, j2;
  if ((a[0][0] != 0) && (a[1][0] != 0)) {
    a[0][2] = a[0][0];
    a[1][2] = a[1][0];
    return 1;
  }
  if ((a[0][2] != 0) && (a[1][2] != 0)) {
    a[0][0] = a[0][2];
    a[1][0] = a[1][2];
    return 1;
  }
  if (a[0][0] != 0) {
    i1 = j1 = 0;
  } else {
    i1 = 1; j1 = 0;
  }
  if (a[0][2] != 0) {
    i2 = 0; j2 = 2;
  } else {
    i2 = 1; j2 = 2;
  }
  if (a[i1][j1] >= a[i2][j2]) {
    a[1-i1][j1] = 1;
    a[1-i2][j2] = 1 + a[i1][j1] - a[i2][j2];
    return 1;
  } else {
    a[1-i2][j2] = 1;
    a[1-i1][j1] = 1 + a[i2][j2] - a[i1][j1];
    return 1;
  } 
  return 0;
}

main() {
  int nz;
  int i, j, k;
  for (i = 0; i < 2; i++)
    for (j = 0; j <= 2; j++)
      scanf("%lld", &a[i][j]);
  if (a[0][1] == 0) a[0][1] = 1;
  if (a[1][1] == 0) a[1][1] = 1;
  nz = 0;
  if (a[0][0] == 0) nz++;
  if (a[0][2] == 0) nz++;
  if (a[1][0] == 0) nz++;
  if (a[1][2] == 0) nz++;
  switch (nz) {
    case 0:
      k = resi0();
      break;
    case 1:
      k = resi1();
      break;
    case 2:
      k = resi2();
      break;
    case 3:
      k = resi3();
      break;
    case 4:
      k = resi4();
      break;
  }
  if (k == 1) {
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++) 
        printf("%lld ", a[i][j]);
      printf("\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}

