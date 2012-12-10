/** @file Region.cpp
 * @brief Implementation of the Region class.
 */
#include "Region.hpp"

Region::Region(std::vector<int> population) {
    this->population = population;
}

void Region::increase_population(int m, int id) {
    // Same thing as in the GrpRegions - we substract 1 to the id because the
    // position of the animal with an id 1 is actually 0 in the vector.
    population[id-1] += m;
}

void Region::decrease_population(int m, int id) {
    population[id-1] -= m;
}

void Region::print_population() {
    for (int i = 0; i < population.size(); ++i) {
        std::cout << population[i] << " ";
    }
    std::cout << std::endl;
}

int Region::get_population(int id) {
    return population[id-1];
}
