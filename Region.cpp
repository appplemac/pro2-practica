#include "Region.hpp"

Region::Region(vector<int> population) {
    this->population = population;
}

void Region::increase_population(int m, int id) {
    population[id-1] += m;
}

void Region::decrease_population(int m, int id) {
    population[id-1] -= m;
}

void Region::print_population() {
    for (int i = 0; i < population.size(); ++i) {
        cout << population[i] << " ";
    }
    cout << endl;
}

int Region::get_population(int id) {
    return population[id-1];
}
