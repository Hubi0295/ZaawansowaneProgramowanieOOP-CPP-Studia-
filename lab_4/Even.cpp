//
// Created by Hubert on 25.10.2024.
//

#include "Even.h"
Even::Even(int divider) {
    this->divider = divider;
}
bool Even::operator()(int x) {
    return x%divider ==0;
}