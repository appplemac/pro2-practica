/** @file GrpSpecies.cpp
 * @brief Implementation of the GrpSpecies class.
 */
#include "GrpSpecies.hpp"

GrpSpecies::GrpSpecies(vector<Species> vspecies, vector<int> priority) {
    this->vspecies = vspecies;
    this->priority = priority;
}

int GrpSpecies::priority_id(int count) {
    return priority[count];
}

int GrpSpecies::priority_size() {
    return priority.size();
}

bool GrpSpecies::is_carnivorous(int id) {
    // Here, and in some other functions, we substract 1 to the id since the
    // position of the species 1 in the vector is actually 0.
    return vspecies[id-1].is_carnivorous();
}

int GrpSpecies::get_nutritious_minimum(int id) {
    return vspecies[id-1].get_nutritious_minimum();
}

int GrpSpecies::get_nutritious_value(int id) {
    return vspecies[id-1].get_nutritious_value();
}

void GrpSpecies::change_prey_preference(int id) {
    vspecies[id-1].change_prey_preference();
}

int GrpSpecies::get_nprey(int id) {
    return vspecies[id-1].get_nprey();
}

int GrpSpecies::prey_id(int id, int seq) {
    return vspecies[id-1].prey_id(seq);
}
