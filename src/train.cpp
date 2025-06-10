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
    Car* cur = first;
    countOp = 0;

    // 1. Включаем лампочку в текущем вагоне
    if (!cur->light) {
        cur->light = true;
        countOp++;
    }

    // 2. Идем направо, пока не встретим вагон с включённой лампочкой
    int steps = 1;
    cur = cur->next;
    countOp++;

    while (!cur->light) {
        cur = cur->next;
        steps++;
        countOp++;
    }

    // 3. Выключаем лампочку в этом вагоне, чтобы избежать зацикливания
    cur->light = false;
    countOp++;

    // 4. Возвращаемся налево столько же шагов
    for (int i = 0; i < steps; ++i) {
        cur = cur->prev;
        countOp++;
    }

    // 5. Если лампочка в изначальном вагоне всё ещё включена — возвращаем длину
    if (cur->light) {
        return steps;
    }

    // 6. Иначе — повторяем с большим шагом
    return getLength();  // Рекурсивный вызов до нахождения длины
}


int Train::getOpCount() {
    return countOp;
}
