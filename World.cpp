/** @file World.cpp
 * @brief Implementation of the World class.
 */
#include "World.hpp"

void World::region_fight(int r) {
    for (int i = 0; i < species.priority_size(); ++i) {
        // Get the next species which has the higher priority.
        int species_id = species.priority_id(i);
        int count = regions[r-1].get_population(species_id);
        while (count > 0) {
            // Find out how much calories will current animal require.
            int remaining = species.get_nutritious_minimum(species_id);
            for (int j = 0; j < species.get_nprey(species_id); ++j) {
                // Get the next available prey animal id.
                int current_prey_id = species.prey_id(species_id, j);
                while (remaining > 0 and regions[r-1].get_population(current_prey_id) > 0) {
                    // Lunch!
                    remaining -= species.get_nutritious_value(current_prey_id);
                    regions[r-1].decrease_population(1, current_prey_id);
                }
            }
            // No food - no sense to live.
            if (remaining > 0) regions[r-1].decrease_population(1, species_id);
            --count;
        }
    }
}

bool World::path_to_central(const int& element, Arbre<int>& tree, queue<int>& path) {
    // A nice function that helps us to find the path animals will follow when
    // migrating from periferic region to the central one.
    // element stands for the name of the region we will be starting the
    // migration from.
    int root = tree.arrel();
    if (root == element) {
        return true;
    }
    Arbre<int> right;
    Arbre<int> left;
    tree.fills(left, right);
    if (not left.es_buit() and path_to_central(element, left, path)) {
        // If we enter here, the regions stands on the way from the periferic
        // region to the central one.
        path.push(root);
        return true;
    }
    else if (not right.es_buit() and path_to_central(element, right, path)) {
        // The same as above.
        path.push(root);
        return true;
    }
    else return false;
}

void World::cut_tree(int element, Arbre<int>& tree) {
    // The function that lets us get the subtree that will be affected by the
    // migration.
    if (tree.es_buit()) return;
    if (tree.arrel() == element) return;
    Arbre<int> left, right;
    tree.fills(left, right);
    cut_tree(element, left);
    // Found the necessary subtree in the left tree.
    if (not left.es_buit()) tree = left;
    // Found the necessary subtree in the right tree.
    else {
        cut_tree(element, right);
        tree = right;
    }
}

void World::to_periferics(Arbre<int> tree, int h, int spec_id, int g) {
    // The function that performs the migration to the periferic regions.
    if (h < g) return;
    int root = tree.arrel();
    Arbre<int> left, right;
    tree.fills(left, right);
    if (left.es_buit() and right.es_buit()) return;
    // We use this boolean value because we need to know if there is one
    // adjacent region or there are two.
    bool one = (left.es_buit() or right.es_buit());
    if (one) {
        // Migrate h-h/2 animals to the adjacent region.
        regions[root-1].decrease_population(h-h/2, spec_id);
        if (not left.es_buit()) {
            regions[left.arrel()-1].increase_population((h-h/2), spec_id);
            to_periferics(left, (h-h/2), spec_id, g);
        }
        else {
            regions[right.arrel()-1].increase_population((h-h/2), spec_id);
            to_periferics(right, (h-h/2), spec_id, g);
        }
    }
    else {
        // Migrate the animals as indicated in the migration policy.
        regions[root-1].decrease_population(h, spec_id);
        regions[right.arrel()-1].increase_population(h/2, spec_id);
        to_periferics(right, h/2, spec_id, g);
        regions[left.arrel()-1].increase_population((h-h/2), spec_id);
        to_periferics(left, (h-h/2), spec_id, g);
    }
}

World::World(Arbre<int> structure, vector<Region> regions, GrpSpecies species) {
    this->structure = structure;
    this->regions = regions;
    this->species = species;
}

void World::fight() {
    // Method that dispatches the fight across all the regions.
    for (int i = 1; i <= regions.size(); ++i) {
        region_fight(i);
    }
}

void World::print_population() {
    for (int i = 0; i < regions.size(); ++i) {
        regions[i].print_population();
    }
}

void World::migrate_central(int r, int h, int spec_id, int g) {
    queue<int> path;
    Arbre<int> tree(structure);
    // Find the path from the origin region to the top.
    path_to_central(r, tree, path);
    int current_region = r;
    int next_region = path.front();
    path.pop();
    // Do the first migration, which doesn't depend on g factor.
    regions[current_region-1].decrease_population(h, spec_id);
    regions[next_region-1].increase_population(h, spec_id);
    // Perform all the rest of migrations until we reach the top or until g is
    // greater than h.
    while (not path.empty() and h >= g) {
        current_region = next_region;
        next_region = path.front();
        path.pop();
        int q = h - h/2;
        regions[current_region-1].decrease_population(q, spec_id);
        regions[next_region-1].increase_population(q, spec_id);
        h = q;
    }
}

void World::migrate_periferic(int r, int h, int spec_id, int g) {
    Arbre<int> tree(structure);
    cut_tree(r, tree);
    Arbre<int> left, right;
    int root = tree.arrel();
    tree.fills(left, right);
    int q = h/2;
    bool one = (left.es_buit() or right.es_buit());
    regions[root-1].decrease_population(h, spec_id);
    // As long as the conditions for the first migration step are a little
    // different than for the rest of the steps, we have to perform the first
    // migration inside of the dispatcher function.
    if (one) {
        if (not left.es_buit()) {
            regions[left.arrel()-1].increase_population(h, spec_id);
            // And now we call the function that will do the rest of the
            // migration for us.
            to_periferics(left, h, spec_id, g);
        }
        else {
            regions[right.arrel()-1].increase_population(h,spec_id);
            to_periferics(right, h, spec_id, g);
        }
    }
    else {
        regions[left.arrel()-1].increase_population((h-q), spec_id);
        regions[right.arrel()-1].increase_population(q, spec_id);
        to_periferics(left, (h-q), spec_id, g);
        to_periferics(right, q, spec_id, g);
    }
}

void World::increase_population(int reg_id, int m, int spec_id) {
    regions[reg_id-1].increase_population(m, spec_id);
}
