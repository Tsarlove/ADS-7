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

  // Проверка: есть ли уже включённые лампочки
  Car* check = first;
  do {
    if (check->light) {
      int length = 1;
      const Car* temp = check->next;
      countOp++;
      while (temp != check) {
        length++;
        temp = temp->next;
        countOp++;
      }
      return length;
    }
    check = check->next;
    countOp++;
  } while (check != first);

  // Включаем первую лампочку и ищем включённую снова
  Car* current = first;
  current->light = true;
  current = current->next;
  countOp++;

  while (!current->light) {
    current->light = true;
    current = current->next;
    countOp++;
  }

  // Считаем длину круга
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
