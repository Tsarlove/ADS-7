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

// Метод по классическому алгоритму с лампочкой
int Train::getLength() {
    countOp = 0;
    if (!first) return 0;

    Car* current = first;
    while (true) {
        if (!current->light) {
            // Впервые встретили вагон с выключенной лампочкой
            current->light = true;
            countOp++;
            current = current->next;
            countOp++;
        } else {
            // Нашли вагон с включённой лампочкой
            current->light = false;  // сброс
            countOp++;
            int length = 1;
            Car* checker = current->next;
            countOp++;

            while (!checker->light) {
                checker = checker->next;
                countOp++;
                length++;
            }

            // Сброс последней лампы
            checker->light = false;
            countOp++;
            return length;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
