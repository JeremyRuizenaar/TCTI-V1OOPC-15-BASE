#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "window.hpp"
#include "rectangle.hpp"

class victim : public drawable{
    void drawLine(vector start, vector stop);
public:
    victim(window &w, const vector &start, const vector &end);
    void draw() override ;
    void interact(drawable &other) override;

};


#endif //VICTIM_HPP