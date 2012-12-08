#include "World.hpp"

World::World(vector<Region> regions) {
    this->regions = regions;
}

void World::fight() {
    for (int i = 0; i < regions.size(); ++i) {
        regions[i].fight();
    }
}

void World::get_population() {
}

bool World::path_to_central(const int& element, Arbre<int>& tree, queue<int>& path) {
    if (tree.arrel() == element) {
        return true;
    }
    Arbre<int> right;
    Arbre<int> left;
    tree.fills(left, right);
    if (not left.es_buit() and path_search(element, left, path)) {
            path.push(tree.arrel());
            return true;
        }
    }
    else if (not right.es_buit() and path_search(element, right, path)) {
            path.push(tree.arrel());
            return true;
        }
    }
    else return false;
}

void World::migrate_central(int r, int h, int spec_id, int g) {
    queue<int> path;
    Arbre<int> tree(structure);
    path_search(r, tree, path);
    int current_region = r;
    int next_region = path.front();
    path.pop();
    regions[current_region].decrease_population(h, spec_id);
    regions[next_region].increase_population(h, spec_id);
    while (not path.empty() and h >= g) {
        current_region = next_region;
        next_region = path.front();
        path.pop();
        q = h - h/2;
        regions[current_region].decrease_population(q, spec_id);
        regions[next_region].increase_population(q, spec_id);
        h = q;
    }
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
    if (left.is_buit() and right.es_buit()) return;
    q = h/2;
    bool one = (left.es_buit() or right.es_buit());
    if (one) {
        regions[root].decrease_population((h-q), spec_id);
        if (not left.es_buit()) {
            regions[left.arrel()].increase_population((h-q), spec_id);
            to_periferics(left, (h-q), spec_id, g);
        }
        else {
            regions[right.arrel()].increase_population((h-q), spec_id);
            to_periferics(right, (h-q), spec_id, g);
        }
    }
    else {
        regions[root].decrease_population(h, spec_id);
        regions[right.arrel()].increase_population(h, spec_id);
        to_periferics(right, h, spec_id, g);
        regions[left.arrel()].increase_population((h-q), spec_id);
        to_periferics(left, (h-q), spec_id, g);
    }
}

void World::migrate_periferic(int r, int h, int spec_id, int g) {
    Arbre<int> tree(structure);
    cut_tree(r, tree);
    to_periferics(tree, h, spec_id, g);
}
