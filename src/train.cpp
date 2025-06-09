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

    Car* slow = first;
    Car* fast = first;

    first->light = true;
    countOp++;

    int steps = 0;

    while (true) {
        fast = fast->next;
        countOp++;
        steps++;

        if (fast->light) {
            break;
        }
    }
    
    first->light = false;
    countOp++;

    return steps + 1;
}

int Train::getOpCount() {
    return countOp;
}
