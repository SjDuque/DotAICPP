#include "dot.hpp"
#include "raylib.h"

Dot::Dot() {
    curMove = 0;
    pos = VPoint(0.5f, 0.5f);
    status = ALIVE;
    
    for (int i = 0; i < MAX_MOVES; i++) {
        moves.push_back(VELOCITY * VPoint::random());
    }
}

Dot::Dot(const Dot& dot) {
    curMove = 0;
    pos = VPoint(0.5f, 0.5f);
    status = ALIVE;
    
    for (int i = 0; i < MAX_MOVES; i++) {
        moves.push_back(dot.moves[i]);
    }
}

Dot Dot::mutate() const {
    Dot mut(*this);
    
    for (int i = 0; i < moves.size(); i++) {
        mut.moves[i] += (VELOCITY * MUTATION_RATE) * VPoint::random();
        mut.moves[i] *= (VELOCITY / mut.moves[i].mag());
    }
    
    return mut;
}

float Dot::fitness() const {
    if (win()) {
        return 1 + (1.0f/MAX_MOVES)*(MAX_MOVES - curMove);
    }
    return 1.0f/pos.dist(GOAL);
}

bool Dot::alive() const {
    return status==ALIVE;
}

bool Dot::win() const {
    return status==WIN;
}

bool Dot::lose() const{
    return status==LOSE;
}

void Dot::update() {
    if (curMove < moves.size()) {
        pos += moves[curMove++];
        
        if (pos.x < RADIUS || pos.y < RADIUS || pos.x > 1.0f-RADIUS || pos.y > 1.0f-RADIUS) {
            status = LOSE;
        } else if (pos.dist(GOAL) < RADIUS) {
            status = WIN;
        }
    } else {
        status = LOSE;
    }
    
}

void Dot::draw() {
    int size = (GetScreenHeight() > GetScreenWidth()) ? GetScreenWidth() : GetScreenHeight();
    DrawCircle(size*pos.x, size*pos.y, size*RADIUS, RED);
}