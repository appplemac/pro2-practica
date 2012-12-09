#include "Species.hpp"

Species::Species(bool carnivorous, int nutritious_minimum, int nutritious_value, int nprey, vector<int> prey) {
    this->carnivorous = carnivorous;
    this->nutritious_minimum = nutritious_minimum;
    this->nutritious_value = nutritious_value;
    this->nprey = nprey;
    this->prey = prey;
}

bool Species::is_carnivorous() {
    return carnivorous;
}

int Species::nutritious_minimum() {
    return nutritious_minimum;
}

int Species::nutritious_value() {
    return nutritious_value;
}

void Species::change_prey_preference() {
    int vsize;
    cin >> vsize;
    vector<int> new_prey;
    for (int i = 0; i < vsize; ++i) {
        cin >> vsize[i];
    }
    this->nprey = vsize;
    this->prey = new_prey;
}

int Species::prey_id(int seq) {
    if (seq > nprey-1) return -1;
    return this->prey[seq];
}

int Species::nprey() {
    return nprey;
}
