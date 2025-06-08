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

  // Проверка: может быть, уже есть включённая лампочка
  Car* current = first;
  do {
    if (current->light) break;
    current = current->next;
    countOp++;
  } while (current != first);

  // Если лампочки уже были включены, просто обходим поезд
  if (current->light) {
    int length = 1;
    Car* temp = current->next;
    countOp++;
    while (temp != current) {
      length++;
      temp = temp->next;
      countOp++;
    }
    return length;
  }

  // Алгоритм: включаем первую лампочку и ищем её снова
  current = first;
  current->light = true;
  current = current->next;
  countOp++;

  while (!current->light) {
    current->light = true;
    current = current->next;
    countOp++;
  }

  // Считаем количество вагонов, пока не вернёмся к первой включённой лампочке
  int length = 1;
  Car* marker = current;
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
