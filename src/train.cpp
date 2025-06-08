// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool /*light*/) {
    Car* newCar = new Car{false, nullptr, nullptr};
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

    first->light = true;
    countOp++;

    Car* current = first->next;
    int len = 1;
    countOp++;

    while (true) {
        countOp++;
        if (current->light)
            break;

        current = current->next;
        len++;
        countOp++;
    }

    first->light = false;
    countOp++;

    return len;
}

int Train::getOpCount() {
    return countOp;
}
