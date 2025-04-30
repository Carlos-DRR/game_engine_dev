#include "vector3d.h"

#ifndef MATRIX3D_H
#define MATRIX3D_H


/*
    A presente definição de matriz e suas operações consideram a convenção column-major order.
    Isso siginifca que os elementos da matriz serão armazenados e interpertados sequencialmente
    a cada coluna. Sendo assim, interprentado as posições dos elementos de uma matriz 3x3, teríamos:
    
    0 3 6
    1 4 7 
    2 5 8

    Além disso, cada coluna vai equivaler a um Vector3D pois assume-se o Vector3D como vetor coluna (column vector)
    ou seja, se o Vector3D fosse colocado em representação de matriz ele seria:
    
    Vector3D A =

        |x|
        |y|
        |z|
*/

struct Matrix3D{
    private:
        float n[3][3];
    public:
        Matrix3D() = default;
        /*
            Recebe como parâmetro valores na convenção usual de matriz, linha x coluna.
            Armazena na matriz considerando a conveção column-major order, logo, a primeira
            linha informada nos argumentos é a primeira coluna, e assim por diante.

            Os índices dos elementos serão, portanto, intepretados 
            j, i ao invés de i, j como convencionalmente.
        */
        Matrix3D
        ( 
            float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22
        )
        {
            
            n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;//coluna 0
            n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;//coluna 1
            n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;//coluna 2
        }
        /*
            Constrói uma matriz 3x3 a partir de três vetores coluna (A, B, C).
            Os valores são copiados para a matriz na ordem column-major:
            - Coluna 0: componentes (x, y, z) do vetor A.
            - Coluna 1: componentes (x, y, z) do vetor B.
            - Coluna 2: componentes (x, y, z) do vetor C.
        */
        Matrix3D(const Vector3D& A, const Vector3D& B, const Vector3D& C){
            n[0][0] = A.x; n[0][1] = A.y; n[0][2] = A.z;
            n[1][0] = B.x; n[1][1] = B.y; n[1][2] = B.z;
            n[2][0] = C.x; n[2][1] = C.y; n[2][2] = C.z;
        }

        /*  recebe o índice na convenção normal linha x coluna mas retorna coluna x linha */
        float& operator()(int i, int j){
            return n[j][i];
        }

        /*  
            Mesma coisa que o outro mas esse é para read-only, para quando a estrutura de matriz
            for constante.
        */
        const float& operator()(int i, int j) const{
            return n[j][i];
        }

        /*
            Retorna a coluna j da matriz como um Vector3D.
            O acesso é feito via reinterpretação de memória (reinterpret_cast), que é segura porque:
            - O layout de n[j] (float[3]) é idêntico ao de Vector3D (três floats consecutivos: x, y, z).
            - Não há padding ou alinhamento extra em Vector3D.
            
            Observação: Não há verificação de limites. `j` deve ser 0, 1 ou 2.
        */
        Vector3D& operator[](int j){
            return *reinterpret_cast<Vector3D*>(n[j]);
        }
        /*
            Fazendo sobrecarga para método read-only para quando a struct da matriz
            for constante.
        */
        const Vector3D& operator[](int j) const{
            return *reinterpret_cast<const Vector3D*>(n[j]);
        }
};

#endif