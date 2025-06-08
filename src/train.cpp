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
  int steps = 0;

  while (!current->light) {
    current->light = true;
    current = current->next;
    steps++;
    countOp++;
  }

  Car* marker = current;
  current = current->next;
  countOp++;
  int len = 1;

  while (!current->light) {
    current = current->next;
    len++;
    countOp++;
  }

  // Turn off lights on the way back to clean up
  current = marker->next;
  while (current != marker) {
    current->light = false;
    current = current->next;
  }

  return len;
}

int Train::getOpCount() {
  return countOp;
}
