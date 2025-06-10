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
    while (true) {
        current->light = true;
        countOp++;

        int steps = 0;
        Car* checker = current->next;
        countOp++;

        while (!checker->light) {
            checker = checker->next;
            steps++;
            countOp++;
        }

        if (checker == current) {
            current->light = false;
            countOp++;
            return steps + 1;
        }

        checker->light = false;
        countOp++;

        current = current->next;
        countOp++;
    }
}

int Train::getOpCount() {
    return countOp;
}
