//
// Created by Hubert on 28.10.2024.
//

#include "CompareByNumberCitizens.h"

#include "City.h"

bool CompareByNumberCitizens::operator()(City &c1, City &c2) {
    return c1.get_citizens().size()<c2.get_citizens().size();
}
