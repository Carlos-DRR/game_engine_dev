#include <iostream>
#include "vector3d.h"

int main(){
    Vector3D vec1(1.0f, 2.0f, 3.0f);
    const Vector3D vec2(4.0f, 5.0f, 6.0f);
    std::cout << "vec1: ";
    std::cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << std::endl;
    std::cout << "vec2: ";
    std::cout << vec2[0] << ", " << vec2[1] << ", " << vec2[2] << std::endl;

    vec1 *= 2;
    std::cout << "após aplicar *=2 no vec1: ";
    std::cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << std::endl;
    vec1 = {2, 2, 2};
    vec1 /=2;
    std::cout << "após aplicar atribuir 2, 2, 2 para vec1 e /=2: ";
    std::cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << std::endl;
    Vector3D vec1Times3 = vec1 * 3;
    std::cout << "vec1Times3: ";
    std::cout << vec1Times3[0] << ", " << vec1Times3[1] << ", " << vec1Times3[2] << std::endl;
    Vector3D vec1Times3DividedBy3 = vec1Times3 / 3;
    std::cout << "vec1Times3DividedBy3: ";
    std::cout << vec1Times3DividedBy3[0] << ", " << vec1Times3DividedBy3[1] << ", " << vec1Times3DividedBy3[2] << std::endl;
    
    Vector3D vecA(1.0f, 1.0f, 1.0f);
    std::cout << "vecA: ";
    std::cout << vecA[0] << ", " << vecA[1] << ", " << vecA[2] << std::endl;
    Vector3D vecANegated = -vecA;
    std::cout << "vecA negated: ";
    std::cout << vecANegated[0] << ", " << vecANegated[1] << ", " << vecANegated[2] << std::endl;

    Vector3D vecB(3, 4, 5);
    std::cout << "vecB magnitude: ";
    std::cout << Magnitude(vecB) << std::endl;
    Vector3D vebNomalized = Normalize(vecB);
    std::cout << "vebNomalized: ";
    std::cout << vebNomalized[0] << ", " << vebNomalized[1] << ", " << vebNomalized[2] << std::endl;

    return 0;
}