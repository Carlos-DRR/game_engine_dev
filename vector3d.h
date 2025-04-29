#include <math.h>

struct Vector3D{
    float x, y, z;
    Vector3D() = default;
    Vector3D(float a, float b, float c): x(a), y(b), z(c){};
    /*
        Operador de índice para acesso aos membros como array.
        Assume que x, y, z estão alocados sequencialmente na memória (o que é verdade para uma struct desse exemplo).
        Não verifica limites (i deve ser 0, 1 ou 2).
        
        Explicação do return:
        - &x obtém o endereço do primeiro membro: float x;
        - Adiciona i para acessar os membros subsequentes: &x + 1 -> é o float y, &x + 2 é o float z
        - (&x)[i] é equivalente a *(&x + i) (aritmética de ponteiros)
        - Retorna por referência (float&) e não cópia
    */
    float& operator[](int i){
        return ((&x)[i]); // ou *(&x + i)
    }

    /*
        Versão const do operador de índice, para uso em objetos const.
        
        Diferenças:
        - Retorna const float& (referência constante, não permite modificação)
        - A função é marcada como const (read-only) (pode ser chamada em objetos const)
        
        Casos de uso:
            Vector3D v1; v1[0] = 1.0f; // usa versão não-const
            const Vector3D v2; float f = v2[0]; // usa versão const
    */
    const float& operator[](int i ) const{
        return *(&x + i);
    }
    /*
        Operação de multiplicação por escalar retornando o próprio vetor: *=
    */
    Vector3D& operator*=(float scalar){
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }
    /*
        Operação de divisão por escalar retornando o próprio vetor: *=
    */
    Vector3D& operator/=(float scalar){
        scalar = 1.0f/scalar;
        return operator*=(scalar);
    }
};

/*
    Função que recebe um vetor e multiplica ele por um escalar, retornando um novo vetor.
*/
inline Vector3D operator*(const Vector3D &vector, float scalar){
    return Vector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

/*
    Função que recebe um vetor e divide ele por um escalar, retornando um novo vetor.
*/
inline Vector3D operator/(const Vector3D &vector, float scalar){
    return operator*(vector, 1.0f/scalar);
}

/*
    Função que recebe um vetor e nega ele, retornando um novo vetor.
*/
inline Vector3D operator-(const Vector3D &vector){
    return Vector3D(-vector.x, -vector.y, -vector.z);
}
/*
    Função que calcula a magnitude de um vetor, usando teorema de pitágoras
*/
inline float Magnitude(const Vector3D &vector){
    return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}
/*
    Função que normaliza o vetor, divide cada componente pela magnitude
*/
inline Vector3D Normalize(const Vector3D &vector){
    return vector / Magnitude(vector);
}