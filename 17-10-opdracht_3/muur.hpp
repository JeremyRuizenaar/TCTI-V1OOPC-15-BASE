#ifndef MUUR_HPP
#define MUUR_HPP

#include "window.hpp"
#include "rectangle.hpp"

class muur : public rectangle {
    bool gevuld;
    bool toggle;
    vector start;
    vector end;
public:
    muur(window &w, const vector &start, const vector &end, bool gevuld, vector stuiter,  bool toggle = false);

    void draw();

    void update();
};

#endif