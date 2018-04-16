#pragma once
#include <vector> //C++ Vector class
#include <string>

using  namespace std; //Add standard library

# define PI 3.14159265358979323846 

/// <summary>
/// Opera��es com matrizes de ordem 3.
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
	/// da diagonal principal s�o 1
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

	//Estaticos para rota��o , escala e transforma��o
	/// <summary>
	/// Gera uma nova matriz de Rota��o n�o acumulada.
	/// </summary>
	/// <param name="angle">Degrees para rota��o</param>
	/// <returns>Matriz n�o acumulada de rota��o</returns>
	const static Matrix3 matrixRotation(const float angle);
	/// <summary>
	/// Gera uma nova matriz de Escala n�o acumluada
	/// </summary>
	/// <param name="x">Escala em X</param>
	/// <param name="y">Escala em Y</param>
	/// <returns></returns>
	const static Matrix3 matrixScale(const float x, const float y);
	/// <summary>
	/// Gera uma nova matriz de Transla��o n�o acumulada
	/// </summary>
	/// <param name="x">Posi��o X</param>
	/// <param name="y">Posi��o Y</param>
	/// <returns></returns>
	const static Matrix3 matrixTranslate(const float x, const float y);

	//Metodos de atribui��o Permi��o de escrita
	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 1,1 desta matriz
	/// </summary>
	/// <returns>referencia ao element 1,1 da matriz</returns>
	float& _a();
	float _a() const;
	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 1,2 desta matriz
	/// </summary>
	/// <returns>referencia ao element 1,2 da matriz</returns>
	float& _b();
	float _b() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 1,3 desta matriz
	/// </summary>
	/// <returns>referencia ao element 1,3 da matriz</returns>
	float& _c();
	float _c() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 2,1 desta matriz
	/// </summary>
	/// <returns>referencia ao element 2,1 da matriz</returns>
	float& _d();
	float _d() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 2,2 desta matriz
	/// </summary>
	/// <returns>referencia ao element 2,2 da matriz</returns>
	float& _e();
	float _e() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 2,3 desta matriz
	/// </summary>
	/// <returns>referencia ao element 2,3 da matriz</returns>
	float& _f();
	float _f() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 3,1 desta matriz
	/// </summary>
	/// <returns>referencia ao element 3,1 da matriz</returns>
	float& _g();
	float _g() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 3,2 desta matriz
	/// </summary>
	/// <returns>referencia ao element 3,2 da matriz</returns>
	float& _h();
	float _h() const;

	/// <summary>
	/// Permite o acesso e moifica��o ao elemento 3,3 desta matriz
	/// </summary>
	/// <returns>referencia ao element 3,3 da matriz</returns>
	float& _i();
	float _i() const;
	
	/// <summary>
	/// Valor do produto das diaonais principais - diagonais secundaria. 
	/// Veja tamb�m <seealso cref="ExistDeterminant()"/> caso s� deseje saber se esta matriz
	/// possui uma determinante diferente de zero.
	/// </summary>
	/// <returns>Valor da determinante</returns>
	float GetDeterminant()const;

	/// <summary>
	/// Avalia e retorna a matriz inversa desta matriz. 
	/// Caso esta matriz n�o seja inversivel, uma matriz zero sera retornada.
	/// <seealso cref="ExistInverse()"/> para saber se esta matriz pode ser Invertida ou n�o
	/// </summary>
	/// <returns>Matriz invertida ou zero se n�o for permitido</returns>
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
	/// Uma matriz que pode ser inversa � aquela cujo o determinante � diferente de zero.
	/// veja tamb�m <seealso cref="ExistDeterminant()"/>, para verificar se a matriz possui determinante
	/// </summary>
	/// <returns>Verdadeiro se esta matriz � uma matriz inversivel e falso caso contrario</returns>
	bool ExistInverse();

	/// <summary>
	/// Se a matriz atual for uma matriz inversivel ela sera atualizada para uma matriz invertida.
	/// Verdadeiro sera rotornado caso a opera��o tenha ocorrido com sucesso e falso sera retornado
	/// caso a matriz n�o seja inversivel. 
	/// Tenha em mente que uma matriz inversivel � aquela cuja a determinante <see cref="GetDeterminant()"/>
	/// � diferente de zero.
	/// Caso n�o seja possivel fazer a invers�o, nenhuma modifica��o sera feita na matriz original.
	/// </summary>
	/// <returns>Falso se a matrz origem n�o for uma matriz inversivel.</returns>
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

	//Opera��es matrizes x matrizes 
	Matrix3 operator+(const Matrix3& other);
	Matrix3 operator-(const Matrix3& other);
	Matrix3 operator*(const Matrix3& other);
	Matrix3 operator/(const Matrix3& other);
	//Opera��es matrizes x matrizes atribuicao
	void operator+=(const Matrix3& other);
	void operator-=(const Matrix3& other);
	void operator*=(const Matrix3& other);
	void operator/=(const Matrix3& other);
	//Opera��es matrizes x escalar
	Matrix3 operator+(const float scalar);
	Matrix3 operator-(const float scalar);
	Matrix3 operator*(const float scalar);
	Matrix3 operator/(const float scalar);
	//Opera��es matrizes x escalar atribuicao
	void operator+=(const float scalar);
	void operator-=(const float scalar);
	void operator*=(const float scalar);
	void operator/=(const float scalar);

	//Opera��es matrizes x vetores

	string ToString();

};

