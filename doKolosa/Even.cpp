//
// Created by Hubert on 12.12.2024.
//

#include "Even.h"

Even::Even(int divider) {
    this->divider=divider;
}

bool Even::operator()(int x) {
if (x%divider == 0) {
    return true;
}
 else {
     return false;
 }
}
