#pragma once
#include "shape.h"

class Transform
{
public:
    Transform(Shape& sh); // Принимаем Shape по ссылке
    void shift(int m, int n, int k);
    void scaleX(int a);
    void scaleY(int d);
    void scaleZ(int e);
    void scale(int s);

private:
    Shape& shape; // Используем ссылку на Shape
};