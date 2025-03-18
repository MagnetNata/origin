#include "shape.h"

// ��������� ����� �� �������
void Shape::setPoint(int index, const Point& point) {
    if (index >= 0 && index < 8) {
        points[index] = point;
    }
}

// ��������� ����� �� �������
Point Shape::getPoint(int index) const {
    if (index >= 0 && index < 8) {
        return points[index];
    }
    return { 0, 0, 0 }; // ���������� ����� �� ���������
}

// ����� ������
void Shape::shift(int m, int n, int k) {
    for (int i = 0; i < 8; ++i) {
        points[i].x += m;
        points[i].y += n;
        points[i].z += k;
    }
}

// ��������������� �� ��� X
void Shape::scaleX(int a) {
    for (int i = 0; i < 8; ++i) {
        points[i].x *= a;
    }
}

// ��������������� �� ��� Y
void Shape::scaleY(int d) {
    for (int i = 0; i < 8; ++i) {
        points[i].y *= d;
    }
}

// ��������������� �� ��� Z
void Shape::scaleZ(int e) {
    for (int i = 0; i < 8; ++i) {
        points[i].z *= e;
    }
}

// ��������������� ���� ������
void Shape::scale(int s) {
    for (int i = 0; i < 8; ++i) {
        points[i].x /= s;
        points[i].y /= s;
        points[i].z /= s;
    }
}

// ������������
Shape::Shape(Type _type, const LineCoords& coords) : type(_type) {
    setPoint(0, coords.start);
    setPoint(1, coords.end);
    calculateSquare();
    calculateVolume();
}

Shape::Shape(Type _type, const SquareCoords& coords) : type(_type) {
    setPoint(0, coords.p1);
    setPoint(1, coords.p2);
    setPoint(2, coords.p3);
    setPoint(3, coords.p4);
    calculateSquare();
    calculateVolume();
}

Shape::Shape(Type _type, const CubeCoords& coords) : type(_type) {
    for (int i = 0; i < 8; ++i) {
        setPoint(i, coords.p1); // ��������� ����� ����
    }
    calculateSquare();
    calculateVolume();
}

Shape::Shape(Type _type, const CircleParams& params) : type(_type), radius(params.radius) {
    setPoint(0, params.center);
    calculateSquare();
    calculateVolume();
}

Shape::Shape(Type _type, const CylinderParams& params) : type(_type), radius(params.radius), height(params.height) {
    setPoint(0, params.center);
    calculateSquare();
    calculateVolume();
}

void Shape::calculateSquare() {
    // ������� ���������� (����� ���� �������������� � �������� �������)
}

void Shape::calculateVolume() {
    // ������� ���������� (����� ���� �������������� � �������� �������)
}