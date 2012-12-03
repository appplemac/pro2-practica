#include "Region.hpp"

Region::Region(vector<int> population) {
    this->population = population;
}

void Region::fight() {
}

void Region::increase_population(int m, int id) {
    this->population[id] += m;
}

void Region::decrease_population(int m, int id) {
    this->population[id] -= m;
}

vector<int> Region::get_population() {
    return this->population;
}
