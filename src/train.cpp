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

    // Стратегия: пройти поезд и включить лампочку в каждом вагоне
    Car* car = first;
    do {
        if (!car->light) {
            car->light = true;
            countOp++;
        }
        car = car->next;
        countOp++;
    } while (car != first);

    // Считаем количество включённых лампочек
    int len = 0;
    car = first;
    do {
        if (car->light) {
            len++;
        }
        car = car->next;
    } while (car != first);

    return len;
}

int Train::getOpCount() {
    return countOp;
}
