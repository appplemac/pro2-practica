#include "Region.hpp"

Region::Region(vector<int> population) {
    this->population = population;
}

void Region::fight() {
    for (int i = 0; i < species.quantity(); ++i) {
        int species_id = species.priority_id[i];
        int count = population[species_id];
        while (count > 0) {
            int remaining = species.nutritious_minimum(species_id);
            for (int j = 0; j < species.nprey(species_id); ++j) {
                int current_prey_id = species.prey_id(species_id, j);
                while (remaining > 0 and population[current_prey_id] > 0) {
                    remaining -= species.nutritious_value(current_prey_id);
                    --population[current_prey_id];
                }
            }
            if (remaining > 0) --population[spec_id];
            --count;
        }
    }
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
