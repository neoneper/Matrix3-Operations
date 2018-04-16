#pragma once
#include <vector> //C++ Vector class
#include <string>

using  namespace std; //Add standard library

# define PI 3.14159265358979323846 

/// <summary>
/// Operações com matrizes de ordem 3.
/// </summary>
class Matrix3
{

private:

	/// <summary>
	/// Matriz[3][3]
	/// </summary>
	vector<vector<float>> matrix{ vector<float>{0} };

	/// <summary>
	/// Tamanho fixo da matriz
	/// </summary>
	const unsigned int size = 3;

	/// <summary>
	/// atualiza os valores da matrix para zero
	/// </summary>
	void CreateEmptyMatrix()
	{
		vector<vector<float> > idty(3, vector<float>(3, 0));
		matrix = idty;
	}
	/// <summary>
	/// Atualiza os valores da matriz para uma matriz identidade, cujo os valores
	/// da diagonal principal são 1
	/// </summary>
	void CreateIdentityMatrix()
	{
		CreateEmptyMatrix();
		vector<vector<float> > identity(3, vector<float>(3, 0));
		for (unsigned i = 0; i < 3; i++)
			matrix[i][i] = 1;
	}

public:

	//Construtores Overloading
	Matrix3();
	Matrix3(const Matrix3 &mat);
	Matrix3(const vector<vector<float>> mat);
	Matrix3(float a00, float a01, float a02,
		float a10, float a11, float a12,
		float a20, float a21, float a22);
	//Destrutor
	~Matrix3();

	//Estaticos para rotação , escala e transformação
	/// <summary>
	/// Gera uma nova matriz de Rotação não acumulada.
	/// </summary>
	/// <param name="angle">Degrees para rotação</param>
	/// <returns>Matriz não acumulada de rotação</returns>
	const static Matrix3 matrixRotation(const float angle);
	/// <summary>
	/// Gera uma nova matriz de Escala não acumluada
	/// </summary>
	/// <param name="x">Escala em X</param>
	/// <param name="y">Escala em Y</param>
	/// <returns></returns>
	const static Matrix3 matrixScale(const float x, const float y);
	/// <summary>
	/// Gera uma nova matriz de Translação não acumulada
	/// </summary>
	/// <param name="x">Posição X</param>
	/// <param name="y">Posição Y</param>
	/// <returns></returns>
	const static Matrix3 matrixTranslate(const float x, const float y);

	//Metodos de atribuição Permição de escrita
	/// <summary>
	/// Permite o acesso e moificação ao elemento 1,1 desta matriz
	/// </summary>
	/// <returns>referencia ao element 1,1 da matriz</returns>
	float& _a();
	float _a() const;
	/// <summary>
	/// Permite o acesso e moificação ao elemento 1,2 desta matriz
	/// </summary>
	/// <returns>referencia ao element 1,2 da matriz</returns>
	float& _b();
	float _b() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 1,3 desta matriz
	/// </summary>
	/// <returns>referencia ao element 1,3 da matriz</returns>
	float& _c();
	float _c() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 2,1 desta matriz
	/// </summary>
	/// <returns>referencia ao element 2,1 da matriz</returns>
	float& _d();
	float _d() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 2,2 desta matriz
	/// </summary>
	/// <returns>referencia ao element 2,2 da matriz</returns>
	float& _e();
	float _e() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 2,3 desta matriz
	/// </summary>
	/// <returns>referencia ao element 2,3 da matriz</returns>
	float& _f();
	float _f() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 3,1 desta matriz
	/// </summary>
	/// <returns>referencia ao element 3,1 da matriz</returns>
	float& _g();
	float _g() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 3,2 desta matriz
	/// </summary>
	/// <returns>referencia ao element 3,2 da matriz</returns>
	float& _h();
	float _h() const;

	/// <summary>
	/// Permite o acesso e moificação ao elemento 3,3 desta matriz
	/// </summary>
	/// <returns>referencia ao element 3,3 da matriz</returns>
	float& _i();
	float _i() const;
	
	/// <summary>
	/// Valor do produto das diaonais principais - diagonais secundaria. 
	/// Veja também <seealso cref="ExistDeterminant()"/> caso só deseje saber se esta matriz
	/// possui uma determinante diferente de zero.
	/// </summary>
	/// <returns>Valor da determinante</returns>
	float GetDeterminant()const;

	/// <summary>
	/// Avalia e retorna a matriz inversa desta matriz. 
	/// Caso esta matriz não seja inversivel, uma matriz zero sera retornada.
	/// <seealso cref="ExistInverse()"/> para saber se esta matriz pode ser Invertida ou não
	/// </summary>
	/// <returns>Matriz invertida ou zero se não for permitido</returns>
	Matrix3 GetInverse()const;
	/// <summary>
	/// Retorna a matriz transposta desta matriz. 
	/// </summary>
	/// <returns>Matriz transposta</returns>
	Matrix3 GetTranspose()const;

	/// <summary>
	/// Valor do produto das diaonais principais - diagonais secundaria. 
	/// Retorna falso se a determinante for igual a zero.
	/// </summary>
	/// <returns>Falso se a determinante for igual a zero</returns>
	bool ExistDeterminant();

	/// <summary>
	/// Uma matriz que pode ser inversa é aquela cujo o determinante é diferente de zero.
	/// veja também <seealso cref="ExistDeterminant()"/>, para verificar se a matriz possui determinante
	/// </summary>
	/// <returns>Verdadeiro se esta matriz é uma matriz inversivel e falso caso contrario</returns>
	bool ExistInverse();

	/// <summary>
	/// Se a matriz atual for uma matriz inversivel ela sera atualizada para uma matriz invertida.
	/// Verdadeiro sera rotornado caso a operação tenha ocorrido com sucesso e falso sera retornado
	/// caso a matriz não seja inversivel. 
	/// Tenha em mente que uma matriz inversivel é aquela cuja a determinante <see cref="GetDeterminant()"/>
	/// é diferente de zero.
	/// Caso não seja possivel fazer a inversão, nenhuma modificação sera feita na matriz original.
	/// </summary>
	/// <returns>Falso se a matrz origem não for uma matriz inversivel.</returns>
	bool Invert();
	/// <summary>
	/// Atualiza a matriz para uma matriz transposta cuja as linhas viram colunas.
	/// </summary>
	void Transpose();

	//Operadores de atribuicao
	Matrix3 operator=(const Matrix3& other);
	//Operadores de acesso
	float& operator() (const int row, const int column);     //Escrita
	float operator() (const int row, const int column)const; //Leitura

	//Operações matrizes x matrizes 
	Matrix3 operator+(const Matrix3& other);
	Matrix3 operator-(const Matrix3& other);
	Matrix3 operator*(const Matrix3& other);
	Matrix3 operator/(const Matrix3& other);
	//Operações matrizes x matrizes atribuicao
	void operator+=(const Matrix3& other);
	void operator-=(const Matrix3& other);
	void operator*=(const Matrix3& other);
	void operator/=(const Matrix3& other);
	//Operações matrizes x escalar
	Matrix3 operator+(const float scalar);
	Matrix3 operator-(const float scalar);
	Matrix3 operator*(const float scalar);
	Matrix3 operator/(const float scalar);
	//Operações matrizes x escalar atribuicao
	void operator+=(const float scalar);
	void operator-=(const float scalar);
	void operator*=(const float scalar);
	void operator/=(const float scalar);

	//Operações matrizes x vetores

	string ToString();

};

