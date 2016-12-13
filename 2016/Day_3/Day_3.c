#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int compareInts(const void * a, const void * b){
  int ia = *((int*) a);
  int ib = *((int*) b);
  return (ia > ib) - (ia < ib);
}

bool isTriangle(int a, int b, int c) {
  int sides[3] = {a, b, c};
  qsort(sides, 3, sizeof(int), compareInts);
  return sides[2] < sides[0] + sides[1];
}

int main() {
  printf("Running Day 3 exercise\n");

  size_t maxSize = 2000;
  int col0[maxSize];
  int col1[maxSize];
  int col2[maxSize];

  int c0, c1, c2;
  int counter = 0;
  FILE * fp = fopen("Day_3_input.txt", "r");
  while (fscanf(fp, "%d %d %d", &c0, &c1, &c2) == 3) {
    col0[counter] = c0;
    col1[counter] = c1;
    col2[counter] = c2;
    counter++;
  }
  fclose(fp);

  int numGood = 0;
  for (int i = 0; i < counter; i++) {
    if (isTriangle(col0[i], col1[i], col2[i])) {
      numGood++;
    }
  }
  printf("Out of %d inputs, %d triangles\n", counter, numGood);

  return 0;
}