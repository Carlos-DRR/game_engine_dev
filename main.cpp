#include <iostream>
#include "matrix3d.h"

int main(){
    /*
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

    Vector3D A (1, 2, 3);
    Vector3D B (4, 5, 6);
    Vector3D aPlusB = A + B;
    std::cout << "aPlusB: " << std::endl;
    std::cout << aPlusB[0] << ", " << aPlusB[1] << ", " << aPlusB[2] << std::endl;

    Vector3D C (1, 2, 3);
    Vector3D D (4, 5, 6);
    Vector3D cMinusD = C - D;
    std::cout << "cMinusD: " << std::endl;
    std::cout << cMinusD[0] << ", " << cMinusD[1] << ", " << cMinusD[2] << std::endl;

    Vector3D s (1.0f, 1.0f, 1.0f);
    D += s;
    std::cout << "D after += (1, 1, 1): " << std::endl;
    std::cout << D[0] << ", " << D[1] << ", " << D[2] << std::endl;
    D -= s;
    std::cout << "D after -= (1, 1, 1): " << std::endl;
    std::cout << D[0] << ", " << D[1] << ", " << D[2] << std::endl;*/

    Vector3D v1(1.0f, 2.0f, 3.0f);
    Vector3D v2(4.0f, 5.0f, 6.0f);
    Vector3D v3(7.0f, 8.0f, 9.0f);
    Matrix3D matriz {v1, v2, v3};

    Vector3D a = matriz[0];
    Vector3D b = matriz[1];
    Vector3D c = matriz[2];
    std::cout << "Valor do vetor a retornado como vector column" << std::endl;
    std::cout << a.x <<", " << a.y << ", " << a.z << std::endl;
    std::cout << "Valor do vetor b retornado como vector column" << std::endl;
    std::cout << b.x <<", " << b.y << ", " << b.z << std::endl;
    std::cout << "Valor do vetor c retornado como vector column" << std::endl;
    std::cout << c.x <<", " << c.y << ", " << c.z << std::endl;
    return 0;
}