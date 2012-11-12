class Species {
private:
    bool carnivorous;
    int nutritious_minimum;
    int nutritious_value;
    int npres;
    vector<int> pres;

public:
    bool is_carnivorous();
    int nutritious_minimum();
    int nutritious_value();

