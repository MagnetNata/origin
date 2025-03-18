#include <iostream>
#include "line.h"
#include "square.h"
#include "cube.h"
#include "circle.h"
#include "cylinder.h"
#include "transform.h"

int main() {
    // Создаем структуры для фигур
    LineCoords lineCoords = { {0, 0, 0}, {5, 0, 0} };
    SquareCoords squareCoords = { {0, 0, 0}, {5, 0, 0}, {5, 5, 0}, {0, 5, 0} };
    CubeCoords cubeCoords = { {0, 0, 0}, {5, 0, 0}, {5, 5, 0}, {0, 5, 0},
                             {0, 0, 5}, {5, 0, 5}, {5, 5, 5}, {0, 5, 5} };
    CircleParams circleParams = { {0, 0, 0}, 10 };
    CylinderParams cylinderParams = { {0, 0, 0}, 10, 20 };

    // Создаем фигуры
    Line line(lineCoords);
    Square square(squareCoords);
    Cube cube(cubeCoords);
    Circle circle(circleParams);
    Cylinder cylinder(cylinderParams);

    // Применяем трансформации
    Transform lineTransform(line);
    lineTransform.shift(2, 3, 0); // Сдвигаем линию

    Transform cubeTransform(cube);
    cubeTransform.scale(2); // Масштабируем куб

    // Выводим информацию о фигурах
    std::cout << "Line square: " << line.getSquare() << ", volume: " << line.getVolume() << std::endl;
    std::cout << "Cube square: " << cube.getSquare() << ", volume: " << cube.getVolume() << std::endl;

    return 0;
}