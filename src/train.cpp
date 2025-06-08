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
        if (current == first) {
            // All lights are on, turn one off to start
            current->light = false;
        }
    }
    current->light = true;
    countOp++;
    Car* marker = current;
    
    int len = 1;
    current = current->next;
    countOp++;
    
    while (current != marker) {
        len++;
        current = current->next;
        countOp++;
    }
    
    // Reset the marker light
    marker->light = false;
    
    return len;
}

int Train::getOpCount() {
    return countOp;
}
