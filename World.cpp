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

void World::migrate_central(int r, int h, int spec_id) {
    
}

void World::migrate_periferic(Region r, int h, int spec_id) {
}
