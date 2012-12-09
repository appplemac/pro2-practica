/** @file Species.hpp
    @brief Specification of the "Species" class
*/
#ifndef SPECIES_HPP
#define SPECIES_HPP
#include "utils.PRO2"
#include <vector>

/** @class Species
 * @brief Represents a base unit of the population – a Species.
 */
class Species {
private:
    bool carnivorous;
    int nutritious_minimum;
    int nutritious_value;
    int nprey;
    vector<int> prey;

public:
    /** @brief Default constructor.
     *
     * Creates the empty species.
     *
     * \pre True.
     * \post Implicit parameter is an empty instance if the Species class.
     */
    Species() {}

    /** @brief Constructor with extended set of settings.
     *
     * Creates the species with the specified values of carnivorousness,
     * nutritious minimum, nutritious value, number of possible prey species and
     * the vector of these prey species.
     *
     * \pre All the parameters have valid values.
     * \post The species with all the necessary information is created.
     */
    Species(bool carnivorous, int nutritious_minimum, int nutritious_value, int nprey, vector<int> prey);

    /** @brief Default destructor.
     *
     * Executed when the instance of Species gets out of scope.
     *
     * \pre The implicit parameter is a non-empty Species instance.
     * \post The implicit parameter is destroyed.
     */
    ~Species() {}

    /** @brief Carnivorousness consultor operation.
     *
     * Allows us to determine whether the species is carnivorous.
     *
     * \pre The implicit parameter is a valid instance of Species class.
     * \post The information about carnivorousness of the implicit parameter is
     * returned.
     */
    bool is_carnivorous();

    /** @brief Nutritious minimum consultor operation.
     *
     * Allows us to get the nutritious minimum for current species.
     *
     * \pre The implicit parameter is a valid instance of Species class.
     * \post The information about the nutritious minimum of the implicit
     * parameter is returned.
     */
    int get_nutritious_minimum();

    /** @brief Nutritious value consultor operation.
     *
     * Allows us to get the nutritious value for current species.
     *
     * \pre The implicit parameter is a valid instance of Species class.
     * \post The information about the nutritious value of the implicit
     * parameter is returned.
     */
    int get_nutritious_value();

    /** @brief The operation of change of the prey vector.
     *
     * Allows us to update the prey preference for the current species
     *
     * \pre The implicit parameter is a valid instance of Species class.
     * \post The information about the updated prey preference is written to the
     * prey vector of the implicit parameter.
     */
    void change_prey_preference();

    /** @brief The operation of consulting one of the possible prey species.
     *
     * Allows us to get an id of a species with which we can alimentate current
     * animal.
     *
     * \pre The implicit parameter is a valid instance of Species class.
     * \post The id of a prey unit, registered in the prey vector of current
     * species under the prey[seq] is returned if it exists. If the prey[seq]
     * does not exist, -1 is returned.
     */
    int prey_id(int seq);

    /** @brief The operation of consulting the number of the prey animals.
     * \pre The implicit parameter is a valid instance of Species class.
     * \post The number of prey animals for current species is returned.
     */
    int get_nprey();
};
#endif
