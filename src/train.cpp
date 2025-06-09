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
    while (cur->light) {
        cur = cur->next;
        countOp++;
        if (cur == first)
            return 1;
    }

    cur->light = true;
    countOp++;

    int len = 1;
    Car* tmp = cur->next;
    countOp++;

    while (!tmp->light) {
        tmp = tmp->next;
        len++;
        countOp++;
    }

    cur->light = false;
    countOp++;

    return len;
}

int Train::getOpCount() {
    return countOp;
}
