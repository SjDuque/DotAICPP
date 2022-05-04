#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "dot.hpp"

const int POPULATION_SIZE = 10000;

class Population {
    
    private:
    
    std::vector<Dot> pop;
    bool active;
    
    public:
    
    Population();
    
    bool alive() const;
    void draw();
    void update();
    
    float sumFitness() const;
    void naturalSelection();
};

#endif