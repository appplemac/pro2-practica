/* vim: set ft=cpp : */
/** @file Region.hpp
 *  @brief Specification of the "Region" class
 */
#ifndef REGION_HPP
#define REGION_HPP
#include <vector>
#include "utils.PRO2"
#include "GrpSpecies.hpp"

/** @class Region
*   @brief Represents the Region - a territory where different species live.
*/
class Region {
private:
    /* Population in the region is saved as the vector 'animal id - value'
     */
    vector<int> population;

public:
    /** @brief Default constructor.
     *
     * Creates the empty region.
     *
     * \pre True.
     * \post Implicit parameter is an empty instance if the Region class.
     */
    Region();

    /** @brief The constructor which provides the non-empty population vector on
     * creation.
     *
     * Creates the region with some population of different species in it.
     *
     * \pre The explicit parameter is a valid vector 'animal id - population'.
     * \post The implicit parameter is a valid region with the population
     * specified the the first explicit parameter.
     */
    Region(vector<int> population);

    /** @brief Default destructor.
     *
     * Executed when the instance of Region gets out of scope.
     *
     * \pre The implicit parameter is a Region instance.
     * \post The implicit parameter is destroyed.
     */
    ~Region();

    /** @brief Increases the population of certain species in current region.
     *
     * \pre Implicit parameter is an instance of the Region class.
     * \post Implicit parameter's "id" species population is increased by m.
     */
    void increase_population(int m, int id);

    /** @brief Decreases the population of certain species in current region.
     *
     * \pre Implicit parameter is an instance of the Region class.
     * \post Implicit parameter's "id" species population is decreased by m.
     */
    void decrease_population(int m, int id);

    /** @brief Prints the region's population to stdout.
     *
     * \pre Implicit parameter is a non-empty instance of the Region class.
     * \post Implicit parameter's population is written to the standard output.
     */
    void print_population();

    /** @brief Returns the population of a certain species in the current region.
     *
     * \pre Implicit parameter is a non-empty instance of the Region class.
     * \post The population of the species with the id equal to 'id' is
     * returned.
     */
    int get_population(int id);
};
#endif
