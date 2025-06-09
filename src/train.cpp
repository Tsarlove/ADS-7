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

    Car* cur = first;
    int len = 1;

    cur->light = true;
    cur = cur->next;
    countOp++;

    while (!cur->light) {
        cur = cur->next;
        len++;
        countOp++;
    }

    return len;
}

int Train::getOpCount() {
    return countOp;
}
