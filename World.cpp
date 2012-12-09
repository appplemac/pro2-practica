#include "World.hpp"
#include "Species.hpp"
#include "GrpSpecies.hpp"

void World::region_fight(int r) {
    for (int i = 0; i < species.priority_size(); ++i) {
        int species_id = species.priority_id(i);
        int count = regions[r-1].get_population(species_id);
        while (count > 0) {
            int remaining = species.get_nutritious_minimum(species_id);
            for (int j = 0; j < species.get_nprey(species_id); ++j) {
                int current_prey_id = species.prey_id(species_id, j);
                while (remaining > 0 and regions[r-1].get_population(current_prey_id) > 0) {
                    remaining -= species.get_nutritious_value(current_prey_id);
                    cout << "decreasing population of species" << current_prey_id;
                    regions[r-1].decrease_population(1, current_prey_id);
                }
            }
            if (remaining > 0) regions[r-1].decrease_population(1, species_id);
            --count;
        }
    }
}

bool World::path_to_central(const int& element, Arbre<int>& tree, queue<int>& path) {
    if (tree.arrel() == element) {
        return true;
    }
    Arbre<int> right;
    Arbre<int> left;
    tree.fills(left, right);
    if (not left.es_buit() and path_to_central(element, left, path)) {
        path.push(tree.arrel());
        return true;
    }
    else if (not right.es_buit() and path_to_central(element, right, path)) {
        path.push(tree.arrel());
        return true;
    }
    else return false;
}

void World::cut_tree(int element, Arbre<int>& tree) {
    if (tree.es_buit()) return;
    if (tree.arrel() == element) return;
    Arbre<int> left, right;
    tree.fills(left, right);
    cut_tree(element, left);
    if (not left.es_buit()) tree = left;
    cut_tree(element, right);
    tree = right;
}

void World::to_periferics(Arbre<int> tree, int h, int spec_id, int g) {
    if (h < g) return;
    int root = tree.arrel();
    Arbre<int> left, right;
    tree.fills(left, right);
    if (left.es_buit() and right.es_buit()) return;
    int q = h/2;
    bool one = (left.es_buit() or right.es_buit());
    if (one) {
        regions[root-1].decrease_population((h-q), spec_id);
        if (not left.es_buit()) {
            regions[left.arrel()-1].increase_population((h-q), spec_id);
            to_periferics(left, (h-q), spec_id, g);
        }
        else {
            regions[right.arrel()-1].increase_population((h-q), spec_id);
            to_periferics(right, (h-q), spec_id, g);
        }
    }
    else {
        regions[root-1].decrease_population(h, spec_id);
        regions[right.arrel()-1].increase_population(h, spec_id);
        to_periferics(right, h, spec_id, g);
        regions[left.arrel()-1].increase_population((h-q), spec_id);
        to_periferics(left, (h-q), spec_id, g);
    }
}

World::World(Arbre<int> structure, vector<Region> regions, GrpSpecies species) {
    this->structure = structure;
    this->regions = regions;
    this->species = species;
}

void World::fight() {
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
    path_to_central(r, tree, path);
    int current_region = r;
    int next_region = path.front();
    path.pop();
    regions[current_region-1].decrease_population(h, spec_id);
    regions[next_region-1].increase_population(h, spec_id);
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
    to_periferics(tree, h, spec_id, g);
}

void World::increase_population(int reg_id, int m, int spec_id) {
    regions[reg_id-1].increase_population(m, spec_id);
}
