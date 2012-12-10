/** @file pro2.cpp
 * @brief The main program for the PRedatOr2 project.
 */
#include "World.hpp"

/** @brief Function used to perform the input of the tree stucture.
 *
 * \pre The tree 'a' is empty.
 * \post The tree 'a' contains the structure read from stdin.
 */
void read_tree(Arbre<int>& a, int marca) {
    // Available in the files for the practice classes.
    // Changed the formatting a little.
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

/** @brief Main function used to call the necessary actions.
 * \pre True.
 * \post The action required by the user is performed.
 */
int main() {
    int n, c;
    // Read the total number of species and the number of carnivorous species.
    cin >> n >> c;
    vector<Species> vspecies (n);
    // Read all the species.
    for (int i = 0; i < n; ++i) {
        int va, np, cm;
        bool carn = false;
        // Read the nutritios value and the number of prey animals.
        cin >> va >> np;
        vector<int> prey (np);
        if (np > 0) carn = true;
        // Read the prey vector.
        for (int j = 0; j < np; ++j) {
            cin >> prey[j];
        }
        if (carn) cin >> cm;
        else cm = 0;
        // Finally, create the species object and put to the vector.
        Species current_species(carn, cm, va, np, prey);
        vspecies[i] = current_species;
    }
    vector<int> priority (c);
    // Read the alimentation priority vector.
    for (int k = 0; k < c; ++k) {
        cin >> priority[k];
    }
    // Declare the GrpSpecies object.
    GrpSpecies species(vspecies, priority);
    int nr;
    // Read the number of regions.
    cin >> nr;
    vector<Region> regions (nr);
    Arbre<int> structure;
    // Read the structure of the regions to the tree 'structure'
    read_tree(structure, 0);
    for (int l = 0; l < nr; ++l) {
        // Read the population for every region.
        vector<int> population(n);
        for (int m = 0; m < n; ++m) {
            cin >> population[m];
        }
        // Create region object and put it to the regions vector.
        Region current_region(population);
        regions[l] = current_region;
    }
    // FInally, mount the World object.
    World world(structure, regions, species);

    int option;
    while (cin >> option and option != -6) {
        if (option == -1) world.fight();
        else if (option == -2) {
             int type, origin, id, num, g;
             cin >> type >> origin >> id >> num >> g;
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
            world.change_prey_preference(id);
        }
        else if (option == -5) {
            world.print_population();
            cout << endl;
        }
    }
}
