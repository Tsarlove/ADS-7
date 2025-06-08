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
    int steps = 1;

    while (true) {
        if (current->light) {
            return steps;
        }

        current->light = true;
        countOp++;

        for (int i = 0; i < steps; i++) {
            current = current->next;
            countOp++;
        }

        steps++;
    }
}

int Train::getOpCount() {
    return countOp;
}
