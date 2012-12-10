/** @file Species.cpp
 * @brief Implementation of the Species class.
 */
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

int Species::get_nutritious_minimum() {
    return nutritious_minimum;
}

int Species::get_nutritious_value() {
    return nutritious_value;
}

void Species::change_prey_preference() {
    int vsize;
    cin >> vsize;
    vector<int> new_prey(vsize);
    for (int i = 0; i < vsize; ++i) {
        cin >> new_prey[i];
    }
    this->prey = new_prey;
    this->nprey = new_prey.size();
}

int Species::prey_id(int seq) {
    // The function used to dispatch the prey animal ids. Written this way for
    // more modularity.
    return this->prey[seq];
}

int Species::get_nprey() {
    return nprey;
}
