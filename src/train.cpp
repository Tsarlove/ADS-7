// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  countOp = 0;
  if (!first) return 0;

  Car* current = first;
  while (!current->light) {
    current->light = true;
    current = current->next;
    countOp++;
  }

  Car* marker = current;
  int minSteps = 0;
  current = current->next;
  countOp++;

  while (current != marker) {
    if (!current->light) {
      current->light = true;
      Car* temp = current->next;
      int steps = 1;
      countOp++;
      while (!temp->light) {
        temp->light = true;
        temp = temp->next;
        steps++;
        countOp++;
      }
      if (minSteps == 0 || steps < minSteps) {
        minSteps = steps;
      }
    }
    current = current->next;
    countOp++;
  }
  return minSteps + 1;
}

int Train::getOpCount() {
  return countOp;
}
