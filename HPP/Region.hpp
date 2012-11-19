/** @file Region.hpp 
 *  @brief Specification of the "Region" class
 */
#ifndef REGION_HPP
#define REGION_HPP
#include <vector>
#include "utils.PRO2"
#include "GrpSpecies.hpp"
#include "Species.hpp"

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

    /** @brief Fight launching operation for the current region.
     *
     * The operation that lets us launch the fight between the species of the
     * current region. During the fight all the species in the region eat till
     * reach of the alimentary minimum or, otherwise, pass away.
     *
     * \pre The implicit parameter is a valid instance of the Region class with
     * a non-empty population vector.
     * \post The fight between species is launched.
     */
    void fight();

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

    /** @brief Population consultory operation.
     *
     * \pre Implicit parameter is an instance of the Region class.
     * \post Implicit parameter's population is returned as a vector of animal
     * id - value pairs.
     */
    vector<int> get_population();
};
#endif
