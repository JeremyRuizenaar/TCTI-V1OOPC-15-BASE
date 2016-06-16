#include "muur.hpp"

muur::muur(window &w, const vector &start, const vector &end, bool gevuld, bool toggle) :
        rectangle(w, start, end),
        start(start),
        end(end),
        gevuld(gevuld),
        toggle(toggle){

}

void muur::draw() {
    rectangle::draw();

    if (gevuld) {
        for (vector temp = start; temp.y < end.y; temp.y++) {
            temp.x = start.x;
            for (; temp.x < end.x; temp.x++) {
                w.draw(temp);
            }
        }
    }
}

void muur::update() {
    if(toggle){
        gevuld = !gevuld;
    }
}




