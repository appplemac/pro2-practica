#include "GrpSpecies.hpp"

GrpSpecies::GrpSpecies(vector<Species> vspecies, vector<int> priority) {
    this->vspecies = vspecies;
    this->priority = priority;
}

int GrpSpecies::priority_id(int count) {
    if (count < priority.size()) return priority[count];
    return -1;
}

int GrpSpecies::priority_size() {
    return priority.size();
}

bool GrpSpecies::is_carnivorous(int id) {
    return vspecies[id-1].is_carnivorous();
}

int GrpSpecies::nutritious_minimum(int id) {
    return vspecies[id-1].nutritious_minimum();
}

int GrpSpecies::nutritious_value(int id) {
    return vspecies[id-1].nutritious_value();
}

void GrpSpecies::change_prey_preference(int id) {
    vspecies[id-1].change_prey_preference();
}

int GrpSpecies::nprey(int id) {
    return vspecies[id-1].nprey();
}

int GrpSpecies::prey_id(int id, int seq) {
    return vspecies[id].prey_id(seq);
}
