#include "victim.hpp"

victim::victim(window &w, const vector &start, const vector &end) :
        drawable(w, start, end - start, vector(-1, -1)) { }

void victim::interact(drawable &other) {
    if (this != &other) {
        if (overlaps(other)) {
            location+=vector(1,1);
            size-=vector(2,2);

        }
    }
}

void victim::draw() {
    vector x = vector(size.x, 0);
    vector y = vector(0, size.y);
    drawLine(location, location + x);
    drawLine(location, location + y);
    drawLine(location + x, location + size);
    drawLine(location + y, location + size);

}

void victim::drawLine(vector start, vector stop) {
    int dx = abs(stop.x - start.x), sx = start.x < stop.x ? 1 : -1;
    int dy = abs(stop.y - start.y), sy = start.y < stop.y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    for (; ;) {
        w.draw(start);
        if (start == stop) break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dy) {
            err += dx;
            start.y += sy;
        }
    }
}


