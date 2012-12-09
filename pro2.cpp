/** @file pro2.cpp
 * @brief The main program for the PRedatOr2 project,
 */
#include "World.hpp"
#include "Arbre.hpp"

void read_tree(Arbre<int>& a, int marca) {
    Arbre<int> a1;
    Arbre<int> a2;
    int x;
    cin >> x;
    if (x != marca) {
        read_tree(a1, marca);
        read_tree(a2, marca);
        a.plantar(x,a1,a2);
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<Species> vspecies (n);
    for (int i = 0; i < n; ++i) {
        int va, np, cm;
        bool carn = false;
        cin >> va >> np;
        vector<int> prey (np);
        if (np > 0) carn = true;
        for (int j = 0; j < np; ++j) {
            cin >> prey[j];
        }
        if (carn) cin >> cm;
        else cm = 0;
        vspecies[i] = Species::Species(carn, cm, va, np, prey);
    }
    vector<int> priority (c);
    for (int k = 0; k < c; ++k) {
        cin >> priority[k];
    }
    GrpSpecies::GrpSpecies species(vspecies, priority);
    int nr;
    cin >> nr;
    vector<Region> regions (nr);
    Arbre<int> structure;
    read_tree(structure, 0);
    for (int l = 0; l < nr; ++l) {
        vector<int> population(n);
        for (int m = 0; m < n; ++m) {
            cin >> population[m];
        }
        Region current_region(population);
        regions[l] = current_region;
    }
    World world(structure, regions, species);

    int option;
    while (cin >> option and option != -6) {
        if (option == -1) world.fight();
        else if (option == -2) {
             int type, origin, id, num, g;
             cin >> type;
             if (type == 1) world.migrate_periferic(origin, num, id, g);
             else if (type == 2) world.migrate_central(origin, num, id, g);
        }
        else if (option == -3) {
            int reg_id, num, spec_id;
            cin >> num >> spec_id >> reg_id;
            world.increase_population(reg_id, num, spec_id);
        }
        else if (option == -4) {
            int id;
            cin >> id;
            species.change_prey_preference(id);
        }
        else if (option == -5) {
            world.print_population();
        }
    }
}
