#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void fillRotationMatrix(float angle, float arr[2][2]) {
  float c = cos(angle);
  float s = sin(angle);
  arr[0][0] = c;
  arr[0][1] = s;
  arr[1][0] = -s;
  arr[1][1] = c;
}

void updateDirection(int direction[2], char turnDirection) {
  float m[2][2];
  if (turnDirection == 'L') {
    fillRotationMatrix(-M_PI/2., m);
  } else if (turnDirection == 'R') {
    fillRotationMatrix(M_PI/2., m);
  }
  int oldDirection[2];
  memcpy(oldDirection, direction, 2 * sizeof(int));
  for (int i = 0; i < 2; i++) {
    int sum = 0;
    for (int j = 0; j < 2; j++) {
      sum += (int) (m[i][j] * oldDirection[j]);
    }
    direction[i] = sum;
  }
}

void updatePosition(int position[2], int direction[2], int stepSize) {
  for (int i = 0; i < 2; i++) {
    position[i] += stepSize * direction[i];
  }
}

int calcVectorDisplacement(int vec[2]) {
  int sum = 0;
  for (int i = 0; i < 2; i++) {
    sum += abs(vec[i]);
  }
  return sum;
}

int main() {
  printf("Running Day 1 exercise (part 1)\n");

  char PROBLEM_INPUT[] = "L4, L1, R4, R1, R1, L3, R5, L5, L2, L3, R2, R1, L4, R5, R4, L2, R1, R3, L5, R1, L3, L2, R5, L4, L5, R1, R2, L1, R5, L3, R2, R2, L1, R5, R2, L1, L1, R2, L1, R1, L2, L2, R4, R3, R2, L3, L188, L3, R2, R54, R1, R1, L2, L4, L3, L2, R3, L1, L1, R3, R5, L1, R5, L1, L1, R2, R4, R4, L5, L4, L1, R2, R4, R5, L2, L3, R5, L5, R1, R5, L2, R4, L2, L1, R4, R3, R4, L4, R3, L4, R78, R2, L3, R188, R2, R3, L2, R2, R3, R1, R5, R1, L1, L1, R4, R2, R1, R5, L1, R4, L4, R2, R5, L2, L5, R4, L3, L2, R1, R1, L5, L4, R1, L5, L1, L5, L1, L4, L3, L5, R4, R5, R2, L5, R5, R5, R4, R2, L1, L2, R3, R5, R5, R5, L2, L1, R4, R3, R1, L4, L2, L3, R2, L3, L5, L2, L2, L1, L2, R5, L2, L2, L3, L1, R1, L4, R2, L4, R3, R5, R3, R4, R1, R5, L3, L5, L5, L3, L2, L1, R3, L4, R3, R2, L1, R3, R1, L2, R4, L3, L3, L3, L1, L2";

  size_t maxSize = 500;
  char * split[maxSize];
  char splitString[] = ", ";

  for (int i = 0; i < maxSize; i++) {
    if (i == 0) {
      split[i] = strtok(PROBLEM_INPUT, splitString);
    } else {
      split[i] = strtok(NULL, splitString);
      if (split[i] == NULL)
        break;
    }
  }

  int POSITION[2] = {0, 0};
  int DIRECTION[2] = {0, 1};

  for (int i = 0; i < maxSize; i++) {
    char * stepStr = split[i];
    if (stepStr == NULL)
      break;

    // printf(">>> Item #%d is %s\n", i, stepStr);
    // printf("Starting position: [%d][%d]\n", POSITION[0], POSITION[1]);
    char turnDirection = stepStr[0];
    stepStr++;
    int stepSize = atoi(stepStr);

    // printf("Setting turnDirection %c\n", turnDirection);
    // printf("Setting length %d\n", stepSize);
    updateDirection(DIRECTION, turnDirection);
    // printf("New direction: [%d][%d]\n", DIRECTION[0], DIRECTION[1]);
    updatePosition(POSITION, DIRECTION, stepSize);
    // printf("New position: [%d][%d]\n", POSITION[0], POSITION[1]);
  }

  printf("Final position: [%d][%d]\n", POSITION[0], POSITION[1]);
  int dist = calcVectorDisplacement(POSITION);
  printf("Distance: %d\n", dist);
  return 0;
}