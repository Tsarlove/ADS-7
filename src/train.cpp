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
  Car* current = first;

  current->light = true;
  int length = 0;
  current = current->next;
  countOp++;

  while (!current->light) {
    length++;
    current = current->next;
    countOp++;
  }

  return length + 1;
}


int Train::getOpCount() {
  return countOp;
}
