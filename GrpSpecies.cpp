#include "GrpSpecies.hpp"

GrpSpecies::GrpSpecies(vector<Species> vspecies) {
    this->vspecies = vspecies;
}

bool GrpSpecies::is_carnivorous(int id) {
    return this->vspecies[id].is_carnivorous();
}

int GrpSpecies::nutritious_minimum(int id) {
    return this->vspecies[id].nutritious_minimum();
}

int GrpSpecies::nutritious_value(int id) {
    return this->vspecies[id].nutritious_value();
}

void GrpSpecies::change_prey_preference(int id) {
    this->vspecies[id].change_prey_preference();
}

int GrpSpecies::prey_id(int id, int seq) {
    return this->vspecies[id].prey_id(seq);
}
