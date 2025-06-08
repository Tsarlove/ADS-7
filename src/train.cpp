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
        if (!current->light) {
            current->light = true;
            countOp++;
            current = current->next;
            countOp++;
        } else {
            // found a lit car, turn it off and count steps
            current->light = false;
            countOp++;
            Car* counter = current->next;
            countOp++;
            int steps = 1;

            while (!counter->light) {
                counter = counter->next;
                countOp++;
                steps++;
            }

            // restore lights off
            counter->light = false;
            countOp++;
            return steps;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
