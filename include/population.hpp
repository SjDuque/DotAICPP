#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "dot.hpp"

const int POPULATION_SIZE = 1000;

class Population {
    
    private:
    
    std::vector<Dot> pop;
    bool active;
    
    public:
    
    Population();
    Population(const Population& pop);
    Population(const std::vector<Dot>& parent);

    
    bool alive() const;
    void draw();
    void update();
    
    float sumFitness() const;
    Population naturalSelection() const;
};

#endif