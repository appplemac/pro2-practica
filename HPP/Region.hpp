class Region {
private:
    vector<Species> vspecies;

public:
    /** @brief Default constructor.
     *
     * Creates the empty region.
     * \pre True.
     * \post Implicit parameter is an empty instance if the Region class.
     */
    Region();

    ~Region();

    /** @brief Increases the population of certain species in a certain region.
     *
     * \pre Implicit parameter is an instance of the Region class.
     * \post Implicit parameter's population is increased by m.
     */
    void increase_population(int m);

    void decrease_population(int m);

    vector<pair<int>> get_population();

    void fight();
};
