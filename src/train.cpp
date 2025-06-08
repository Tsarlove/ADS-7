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

    if (!current->light) {
        current->light = true;
        countOp++;
    }

    while (true) {
        current = current->next;
        countOp++;

        if (!current->light) {
            current->light = true;
            countOp++;
        } else {
            break;
        }
    }

    int length = 1;
    Car* temp = current->next;
    countOp++;

    while (temp != current) {
        length++;
        temp = temp->next;
        countOp++;
    }

    temp = current;
    do {
        temp->light = false;
        countOp++;
        temp = temp->next;
        countOp++;
    } while (temp != current);

    return length;
}

int Train::getOpCount() {
    return countOp;
}
