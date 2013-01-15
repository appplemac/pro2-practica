/** @file World.hpp
    @brief Specification of the "World" class
*/
#ifndef WORLD_HPP
#define WORLD_HPP
#include "Region.hpp"
#include "GrpSpecies.hpp"
#include <vector>
#include "utils.PRO2"
#include "Arbre.hpp"
#include <queue>

/** @class World
 *  @brief Represents the World – the group of Regions.
 */
class World {
private:
    /** @brief The structure of regions.
     */
    Arbre<int> structure;

    /** @brief The regions itself.
     */
    vector<Region> regions;

    /** @brief The species of the world.
     */
    GrpSpecies species;

    /** @brief The function that performs the fight in a region of the world.
     *
     * The functions that performs the fight between species in a certain region
     * of the world.
     *
     * \pre The explicit argument points to a non-empty region.
     * \post The fight in the region 'r' is performed.
     */
    void region_fight(int r);

    /** @brief Function used to determine the path to central region.
     *
     * This function helps us to retrieve the path from the region 'element' to
     * the central plantation by storing it in the 'path' queue.
     *
     * \pre The implicit parameter contains the path from 'element' to the
     * central plantation.
     * \post The path from 'element' to the central region is stored in 'path'.
     */
    bool path_to_central(const int& element, Arbre<int>& tree, queue<int>& path);

    /** @brief Function used to get the subtree of 'tree' with 'element' as root.
      *
      * This function finds the subtree of 'tree', which has 'element' as root
      * and writes this subtree to the explicit parameter 'tree'.
      *
      * \pre True.
      * \post 'tree' contains the 'cut' tree – the subtree with 'element' as a
      * root.
      */
    void cut_tree(int element, Arbre<int>& tree);

    /** @brief Recursive function used to perform the migration to periferics.
     *
     * \pre True.
     * \post The migration of h animals of 'spec_id' species if performed inside
     * the 'tree' of regions.
     */
    void to_periferics(Arbre<int> tree, int h, int spec_id, int g);

public:
    /** @brief Default constructor.
     *
     *   Executed on the creation of the new world.
     *
     *   \pre True.
     *   \post The result is an empty world.
     */
    World() {}

    /** @brief Constructor with the main data structures (the structure tree and the
     * vector of regions) passed as an explicit parameters.
     *
     * \pre True.
     * \post The result is a world with the structure of regions specified in
     * the explicit parameters.
     */
    World(Arbre<int> structure, vector<Region> regions, GrpSpecies species);

    /** @brief Default destructor.
     *
     * Executed when the instance of World gets out of scope.
     *
     * \pre The implicit parameter is a non-empty World instance.
     * \post The implicit parameter is destroyed.
     */
    ~World() {}

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

    /** @brief Change the alimentation preference of one of the species in the world.
     * \pre The animal with the id 'id' is carnivorous.
     * \post The vector of preference for the animal 'id' has been read from stdin.
     */
    void change_prey_preference(int id) {
        species.change_prey_preference(id);
    }
};
#endif
