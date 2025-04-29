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

};