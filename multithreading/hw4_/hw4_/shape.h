#pragma once
#include <string>
#include <cmath>
#include <initializer_list>

// Структуры для хранения данных фигур
struct Point {
    int x, y, z;
};

struct LineCoords {
    Point start;
    Point end;
};

struct SquareCoords {
    Point p1, p2, p3, p4;
};

struct CubeCoords {
    Point p1, p2, p3, p4, p5, p6, p7, p8;
};

struct CircleParams {
    Point center;
    double radius;
};

struct CylinderParams {
    Point center;
    double radius;
    double height;
};

class Shape
{
public:
    enum Type {
        LINE,
        SQR,
        CUBE,
        CIRCLE,
        CYLINDER
    };

    Shape() = default;
    Shape(Type type, const LineCoords& coords);
    Shape(Type type, const SquareCoords& coords);
    Shape(Type type, const CubeCoords& coords);
    Shape(Type type, const CircleParams& params);
    Shape(Type type, const CylinderParams& params);

    Type getType() const { return type; }
    double getSquare() const { return square; }
    double getVolume() const { return volume; }

    // Методы для трансформаций
    void shift(int m, int n, int k);
    void scaleX(int a);
    void scaleY(int d);
    void scaleZ(int e);
    void scale(int s);

protected:
    Type type;
    double square = 0;
    double volume = 0;
    double radius = 0;
    double height = 0;

    Point points[8]; // Максимум 8 точек для куба

    // Методы для доступа к точкам
    void setPoint(int index, const Point& point);
    Point getPoint(int index) const;

    virtual void calculateSquare();
    virtual void calculateVolume();
};