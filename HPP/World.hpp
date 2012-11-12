/** @file World.hpp
    @brief Specification of the "World" class
*/
#ifndef WORLD_HPP
#define WORLD_HPP
#include "utils.PRO2"
#include "Region.hpp"

/** @class World
    @brief Represents the World – the group of Regions.
*/

class World {
private:
    Arbol<Region> regions;

public:
/** @brief Default constructor.

    Executed on the creation of the new world.

    \pre True.
    \post The result is an empty world.
*/
    World();

    /** @brief Default destructor.
     *
     * Executed when the instance of World gets out of scope.
     *
     * \pre The implicit parameter is a non-empty World instance.
     * \post The implicit parameter is destroyed.
     */
    ~World();

    /** @brief Write the information on the world to stdout.
     * \pre True.
     * \post The information from the implicit parameters is written to stdout.
     */
    void write();

    /** @brief Fire up the fight between the species in the world.
     * \pre The implicit parameter is a World instance.
     * \post The fight between species is launched in every region of the world.
     */
    void fight!();

    /** @brief Print the information about the population of the world.
     * \pre The implicit parameter is a World instance.
     * \post The information about the population of the implicit parameter is written to stdout.
     */
    void get_population();
};
#endif
