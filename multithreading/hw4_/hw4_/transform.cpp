#include "transform.h"

Transform::Transform(Shape& sh) : shape(sh) {}

void Transform::shift(int m, int n, int k) {
    shape.shift(m, n, k);
}

void Transform::scaleX(int a) {
    shape.scaleX(a);
}

void Transform::scaleY(int d) {
    shape.scaleY(d);
}

void Transform::scaleZ(int e) {
    shape.scaleZ(e);
}

void Transform::scale(int s) {
    shape.scale(s);
}