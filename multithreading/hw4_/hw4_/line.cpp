#include "line.h"

Line::Line(const LineCoords& coords) 
    : Shape(Shape::LINE, coords) {
    // Ћогика инициализации точек уже в базовом классе
}