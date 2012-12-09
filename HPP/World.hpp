/** @file World.hpp
    @brief Specification of the "World" class
*/
#ifndef WORLD_HPP
#define WORLD_HPP
#include "utils.PRO2"
#include "Region.hpp"
#include "Arbre.hpp"

/** @class World
 *  @brief Represents the World – the group of Regions.
 */
class World {
private:
    Arbre<int> structure;
    vector<Region> regions;
    GrpSpecies species;

    void region_fight(int r);
    void path_to_central(const int& element, Arbre<int>& tree, queue<int>& path);
    void cut_tree(int element, Arbre<int>& tree);
    void to_periferics(Arbre<int> tree, int h, int spec_id, int g);

public:
    /** @brief Default constructor.
     *
     *   Executed on the creation of the new world.
     *
     *   \pre True.
     *   \post The result is an empty world.
     */
    World();

    /** @brief Constructor with the main data structures (the structure tree and the
     * vector of regions) passed as an explicit parameters.
     *
     * \pre True.
     * \post The result is a world with the structure of regions specified in
     * the explicit parameters.
     */
    World(Arbre<int> structure, vector<Region> regions);

    /** @brief Default destructor.
     *
     * Executed when the instance of World gets out of scope.
     *
     * \pre The implicit parameter is a non-empty World instance.
     * \post The implicit parameter is destroyed.
     */
    ~World();

    /** @brief Fire up the fight between the species in the world.
     * \pre The implicit parameter is a World instance.
     * \post The fight between species is launched in every region of the world.
     */
    void fight();

    /** @brief Print the information about the population of the world.
     * \pre The implicit parameter is a World instance.
     * \post The information about the population of the implicit parameter is written to stdout.
     */
    void print_population();

    /** @brief Perform a migration to the direction of the central plantation.
     * \pre The implicit parameter is a non-empty World instance.
     * \post The migration of h individuums of spec_id species originating in
     * the region r in the direction of the central plantation is performed in the implicit parameter.
     */
    void migrate_central(int r, int h, int spec_id, int g);

    /** @brief Perform a migration to the direction of the perifery.
     * \pre The implicit parameter is a non-empty World instance.
     * \post The migration of h individuums of spec_id species originating in
     * the region r in the direction of the perifery is performed in the implicit parameter.
     */
    void migrate_periferic(int r, int h, int spec_id, int g);

    /** @brief Increase the population of a certain species in a certain region.
     * \pre The implicit parameter is a non-empty World instance.
     * \post The population of the species 'spec_id' in the region 'reg_id' is
     * increased by 'm'.
     */
    void increase_population(int reg_id, int m, int spec_id);
};
#endif
