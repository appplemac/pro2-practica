/* vim: set ft=cpp: */
/** @file GrpSpecies.hpp
    @brief Specification of the "GrpSpecies" class
*/
#ifndef GRP_SPECIES_HPP
#define GRP_SPECIES_HPP
#include "utils.PRO2"
#include <vector>
#include "Species.hpp"

/** @class GrpSpecies
 *  @brief Represents the Group of Species – all the species that exist in the World.
*/
class GrpSpecies {
private:
    /** @brief Vector where all the species of the group are stored.
     */
    vector<Species> vspecies;

    /** @brief Vector where the alimentation priority information is stored.
     */
    vector<int> priority;

public:
    /** @brief Default constructor.
     *
     * Creates the empty group of species.
     *
     * \pre True.
     * \post Implicit parameter is an empty instance if the GrpSpecies class.
     */
    GrpSpecies();

    /** @brief Constructor with extended set of settings.
     *
     * Creates the group of species with the vector of Species specified by the
     * first explicit parameter and the priority between those species specified
     * by the second explicit parameter.
     *
     * \pre True.
     * \post The group of species with the member species specified by the
     * explicit parameters is created.
     */
    GrpSpecies(vector<Species> vspecies, vector<int> priority);

    /** @brief Default destructor.
     *
     * Executed when the instance of GrpSpecies gets out of scope.
     *
     * \pre The implicit parameter is a GrpSpecies instance.
     * \post The implicit parameter is destroyed.
     */
    ~Species();

    /** @brief The consultor operation for the priority between species.
     *
     * Allows us to get information about the priority in alimentation of
     * the species of our group.
     *
     * \pre Implicit parameter is a valid group of species. Count is less than
     * the total number of carnivorous species in the region and greater or
     * equal than 0.
     * \post The ID of the animal which has a priority of 'count' in the vector
     * is returned.
     */
    int priority_id(int count);

    /** @brief Returns the size of the priority vector (the number of
     * carnivorous species).
     *
     * \pre The implicit parameter is a valid group of species.
     * \post The size of the priority vector is returned.
     */
    int priority_size();

    /** @brief The member species carnivorousness consultor operation.
     *
     * Allows us to get the information about our species' carnivorousness.
     *
     * \pre The implicit parameter is a valid group of species.
     * \pre The animal with the specified id exists in our group of species.
     * \post The information about the carnivorousness of the specified animal
     * is returned.
     */
    bool is_carnivorous(int id);

     /** @brief Nutritious minimum consultor operation.
     *
     * Allows us to get the nutritious minimum for the member species.
     *
     * \pre The implicit parameter is a valid group of species.
     * \pre The animal with the specified id exists in our group of species.
     * \post The information about the nutritious minimum of the member species
     * is returned.
     */
    int nutritious_minimum(int id);

    /** @brief Nutritious value consultor operation.
     *
     * Allows us to get the nutritious value for the member species.
     *
     * \pre The implicit parameter is a valid group of species.
     * \pre The animal with the specified id exists in our group of species.
     * \post The information about the nutritious value of the member species
     * is returned.
     */
    int nutritious_value(int id);

    /** @brief The operation of change of the prey vector.
     *
     * Allows us to update the prey preference for the the member species.
     *
     * \pre The implicit parameter is a valid group of species.
     * \post The information about the updated prey preference is written to the
     * prey vector of the member species.
     */
    void change_prey_preference(int id);

    /** @brief Returns the number of prey species for a species from the group.
     *
     * The operation that allows us to get the number of prey species for the
     * animals of current group.
     *
     * \pre The id is greater or equal than 0 and less than the number of
     * species of current group.
     * \post The number of prey species for the 'id' species of current group is
     * returned.
     */
    void nprey(int id);

    /** @brief The operation of consulting one of the possible prey species.
     *
     * Allows us to get an id of a species with which we can alimentate current
     * member animal.
     *
     * \pre The implicit parameter is a valid group of species.
     * \post The id of a prey unit, registered in the prey vector of current
     * member species under the prey[seq] is returned if it exists. If the
     * member species' prey[seq] does not exist, -1 is returned.
     */
    int prey_id(int id, int seq);
};
#endif
