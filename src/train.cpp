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

  Car* temp = first;
  do {
    temp->light = false;
    temp = temp->next;
    countOp++;
  } while (temp != first);

  Car* current = first;

  while (!current->light) {
    current->light = true;
    current = current->next;
    countOp++;
  }

  int length = 1;
  const Car* marker = current;
  current = current->next;
  countOp++;

  while (current != marker) {
    length++;
    current = current->next;
    countOp++;
  }

  return length;
}

int Train::getOpCount() {
  return countOp;
}
