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
    while (current->light) {
        current = current->next;
        countOp++;
        if (current == first) return 1;
    }

    current->light = true;
    countOp++;

    int len = 1;
    Car* walker = current->next;
    countOp++;

    while (!walker->light) {
        walker = walker->next;
        len++;
        countOp++;
    }

    current->light = false;
    countOp++;

    return len;
}

int Train::getOpCount() {
    return countOp;
}
