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

  while (true) {
    countOp++;
    if (!current->light) {
      current->light = true;
      current = current->next;
    } else {
      current->light = false;
      int count = 1;
      current = current->next;
      while (!current->light) {
        count++;
        countOp++;
        current = current->next;
      }
      return count;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
