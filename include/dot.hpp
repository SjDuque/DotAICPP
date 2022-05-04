#ifndef DOT_HPP
#define DOT_HPP

#include "vpoint.hpp"

const float MUTATION_RATE = 0.5;
const float VELOCITY = 0.05;
const float RADIUS = 0.01;
const float MAX_MOVES = 100;
const VPoint GOAL(0.1, 0.5);

class Dot {
    private:
    
    enum DotStatus {
    ALIVE,
    WIN,
    LOSE
    };
    
    VPoint pos;
    std::vector<VPoint> moves;
    DotStatus status;
    
    int curMove;
    
    public:
    
    Dot();
    
    Dot(const Dot& dot);
    
    Dot mutate() const;
    
    void update();
    void draw();
    
    float x() const;
    float y() const;
    float fitness() const;
    
    bool alive() const;
    bool win() const;
    bool lose()  const;
};

#endif