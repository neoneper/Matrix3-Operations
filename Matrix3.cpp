#include "Matrix3.h"



Matrix3::Matrix3()
{
	CreateIdentityMatrix();
}
Matrix3::Matrix3(const Matrix3 & mat)
{

	CreateEmptyMatrix();

	for (unsigned row = 0; row < size; row++)
		for (unsigned col = 0; col < size; col++)
			matrix[row][col] = mat(row, col);
}
Matrix3::Matrix3(const vector<vector<float>> mat)
{
	matrix = mat;
}
Matrix3::Matrix3(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22)
{
	CreateEmptyMatrix();
	_a() = a00;
	_b() = a01;
	_c() = a02;
	_d() = a10;
	_e() = a11;
	_f() = a12;
	_g() = a20;
	_h() = a21;
	_i() = a22;
}
Matrix3::~Matrix3()
{

}

bool Matrix3::Invert()
{
	if (ExistInverse() == false)
		return false;

	*this = GetInverse();

	return true;
}
void Matrix3::Transpose()
{

	*this = GetTranspose();
}
float Matrix3::GetDeterminant() const
{
	/*
	Repetindo as duas primeiras colunas e somando a multiplicaçao de cada diagonal.
	Diagonal direita positiva e diagonal esquerda negativa.	*/

	float d1 = _a() * _e() * _i();
	float d2 = _b() * _f() * _g();
	float d3 = _c() * _d() * _h();
	float n1 = _g() * _e() * _c();
	float n2 = _h() * _f() * _a();
	float n3 = _i() * _d() * _b();

	float det = d1 + d2 + d3 - (n1 + n2 + n3);

	return det;
}
Matrix3 Matrix3::GetInverse() const
{
	/*
	Se a determinante da MATRIZ for zero, não existe INVERSA e ela seria considerada
	uma matriz SINGULAR, 
	Fonte KhanAcademy: https://pt.khanacademy.org/math/precalculus/precalc-matrices/intro-to-matrix-inverses/v/singular-matrices
	*/
	//Determinante
	float determinant = GetDeterminant();
	if (determinant == 0.0f)
	{
		Matrix3 zero = Matrix3();
		zero.CreateEmptyMatrix();
		return zero;
	}
	/*
	Ao invez de escalonar a matrix [A] até a forma reduzida onde [A] vira [I]
	Identidade e Identidade vira[ A ]-¹ eu vou utilizar a formula da matriz inversa por cofatores,
	vista em Youtube GUI ROZA :
	https://www.youtube.com/watch?v=s9FCRcvU1qo

	A Formula consist em alguns passos:
	1 - Achar a determinante da matriz |A|
	2 - Criar a matriz de cofatores de [A]
	3 - Transpor a matriz cofatores [A]T
	4 - Dividir os elementos da [A]T pela determinante de |A|
	*/

	
	//Cofatores da matriz
	float cfA = _e() * _i() - _h() *_f();
	float cfB = _d() * _i() - _g() *_f();
	float cfC = _d() * _h() - _g() *_e();
	float cfD = _b() * _i() - _h() *_c();
	float cfE = _a() * _i() - _g() *_c();
	float cfF = _a() * _h() - _g() *_b();
	float cfG = _b() * _f() - _e() *_c();
	float cfH = _a() * _f() - _d() *_c();
	float cfI = _a() * _e() - _d() *_b();

	//Invertendo os sinais das potencias IMPARES
	//Por Algum motivo eu não estou conseguindo fazer modificação direto na linha dos cofatores acima.
	//Mesmo multiplicando por -1, os valroes nao mudam. mas fazendo separadamente como abaixo funciona.
	//(^.~)Paciencia
	cfB *= -1.0f;
	cfD *= -1.0f;
	cfF *= -1.0f;
	cfH *= -1.0f;

	//Nova matriz cofator trasposta
	Matrix3 cofactTransposed = Matrix3(cfA, cfB, cfC, cfD, cfE, cfF, cfG, cfH, cfI);

	cofactTransposed.Transpose();

	//Dividindo matriz transposta cofatorada pela determinante de A
	cofactTransposed /= determinant;

	//Atualizando matriz
	return cofactTransposed;
}
Matrix3 Matrix3::GetTranspose() const
{

	/*
	As linhas da matriz A vão virar as COLUNAS da matriz B.
	*/
	float a = _a();
	float b = _d();
	float c = _g();
	float d = _b();
	float e = _e();
	float f = _h();
	float g = _c();
	float h = _f();
	float i = _i();

	Matrix3 transposed = Matrix3(a, b, c, d, e, f, g, h, i);
	return transposed;

}
bool Matrix3::ExistDeterminant()
{
	return GetDeterminant() > 0.0f || GetDeterminant() <= 0.0f;
}
bool Matrix3::ExistInverse()
{
	/*
	Tendo em mente que se a determinante da MATRIZ for zero, não existe INVERSA e ela seria considerada
	uma matriz SINGULAR. e assim sendo retornará falso com a matriz de referencia zerada.
	Fonte KhanAcademy: https://pt.khanacademy.org/math/precalculus/precalc-matrices/intro-to-matrix-inverses/v/singular-matrices
	*/

	return ExistDeterminant() == true;
}
string Matrix3::ToString()
{
	string tostring = "";

	for (unsigned rows = 0; rows < 3; rows++)
	{
		for (unsigned cols = 0; cols < 3; cols++)
		{
			tostring += "\t" + to_string(matrix[rows][cols]);
		}
		tostring += "\n";
	}
	return tostring;
}

const Matrix3 Matrix3::matrixRotation(const float degrees)
{
	//Circulo completo 2*(degree * PI) / 360;
	float radians = (degrees * PI) / 180;

	//Criando matriz identidade
	Matrix3 rotation = Matrix3();

	/*
	Aplicando rotação sobre o eixo X.
	https://www.youtube.com/watch?v=7TDjvVEAib0
	

	rotation._e() = cos(radians);
	rotation._f() = -sin(radians);
	rotation._g() = sin(radians);
	rotation._i() = cos(radians);
	*/

	//Aplicando rotacao no eixo Z. Tive que ir fazendo testes ate encontrar

	rotation._a() = cos(radians);
	rotation._b() = sin(radians);
	rotation._d() = -sin(radians);
	rotation._e() = cos(radians);

	return rotation;
}

const Matrix3 Matrix3::matrixScale(const float x, const float y)
{
	//Nova matrix idenidade
	Matrix3 scale = Matrix3();

	/*
	Trocando os elementos A e E conforme o PDF.
	*/

	scale._a() = x; 
	scale._e() = y;

	return scale;
}

const Matrix3 Matrix3::matrixTranslate(const float x, const float y)
{
	//Nova matrix idenidade
	Matrix3 translate = Matrix3();
	
	/*Trocando os elementos C e F da matriz e depois Transpondo
	conforme o PDF Pg 24, eu vou acabar modificando os elementos G e H 
	da matriz identidade. Assim sendo vou fazer direto esta operação
	para poupar processo e dedo.
	OBS: Tenha em mente que eu estou transpondo a matriz para trabalhar com o sistema da mao Direita,
	e ele trabalho com matriz linha e não coluna.
	*/

	translate._g() = x; //C Transposto vira G
	translate._h() = y; //F Transposto vira F

	return translate;
}

float & Matrix3::_a() { return (*this)(0, 0); }
float & Matrix3::_b() { return (*this)(0, 1); }
float & Matrix3::_c() { return (*this)(0, 2); }
float & Matrix3::_d() { return (*this)(1, 0); }
float & Matrix3::_e() { return (*this)(1, 1); }
float & Matrix3::_f() { return (*this)(1, 2); }
float & Matrix3::_g() { return (*this)(2, 0); }
float & Matrix3::_h() { return (*this)(2, 1); }
float & Matrix3::_i() { return (*this)(2, 2); }
float  Matrix3::_a() const { return (*this)(0, 0); }
float  Matrix3::_b() const { return (*this)(0, 1); }
float  Matrix3::_c() const { return (*this)(0, 2); }
float  Matrix3::_d() const { return (*this)(1, 0); }
float  Matrix3::_e() const { return (*this)(1, 1); }
float  Matrix3::_f() const { return (*this)(1, 2); }
float  Matrix3::_g() const { return (*this)(2, 0); }
float  Matrix3::_h() const { return (*this)(2, 1); }
float  Matrix3::_i() const { return (*this)(2, 2); }

Matrix3 Matrix3::operator=(const Matrix3 & other) {

	if (&other == this)
		return *this;

	CreateEmptyMatrix();

	for (unsigned row = 0; row < size; row++)
		for (unsigned col = 0; col < size; col++)
			matrix[row][col] = other(row, col);

	return *this;

}
float & Matrix3::operator()(const int row, const int column) { return matrix[row][column]; }
float Matrix3::operator()(const int row, const int column) const { return matrix[row][column]; }

Matrix3 Matrix3::operator+(const Matrix3 & other)
{

	/*Soma de matriz matrix.a = a + other.a;*/

	Matrix3 temp = Matrix3();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) + other(rows, columns);
		}
	}
	return temp;
}
Matrix3 Matrix3::operator+(const float scalar)
{

	/*Soma de matriz matrix.a = a + scalar*/

	Matrix3 temp = Matrix3();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) + scalar;
		}
	}
	return temp;
}
Matrix3 Matrix3::operator-(const Matrix3 & other)
{

	/*Subtração de matriz matrix.a = a - other.a;*/

	Matrix3 temp = Matrix3();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) - other(rows, columns);
		}
	}
	return temp;
}
Matrix3 Matrix3::operator-(const float scalar)
{

	/*Subtração de matriz matrix.a = a - scalar;*/

	Matrix3 temp = Matrix3();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) - scalar;
		}
	}
	return temp;
}
Matrix3 Matrix3::operator*(const Matrix3 & other)
{

	/*Multiplicação de matriz:

	matrix.a = a * other.a + b * other.d + c * B.g;
	-> soma da multiplicação entre Primeira linha com primeira coluna
	-> soma da multiplicação entre Segunda linha x segunda coluna
	-> soma da multiplicação entre Terceira linha x terceira coluna

	*/

	Matrix3 temp = Matrix3();

	for (unsigned row = 0; row < size; row++) {
		for (unsigned col = 0; col < size; col++) {
			for (unsigned next = 0; next < size; next++)
			{
				temp(row, col) += (*this)(row, next) * other(next, col);
			}
		}
	}
	return temp;
}
Matrix3 Matrix3::operator*(const float scalar)
{

	/*Multiplicação de matriz matrix.a = a * scalar*/

	Matrix3 temp = Matrix3();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) * scalar;
		}
	}
	return temp;
}
Matrix3 Matrix3::operator/(const Matrix3 & other)
{

	/*Divisão de matriz matrix.a = a / other.a;*/

	Matrix3 temp = Matrix3();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) / other(rows, columns);
		}
	}
	return temp;
}
Matrix3 Matrix3::operator/(const float scalar)
{

	/*Divisão escalar de matriz matrix.a = a / scalar*/

	Matrix3 temp = Matrix3();
	temp.CreateEmptyMatrix();

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			temp(rows, columns) = (*this)(rows, columns) / scalar;
		}
	}
	return temp;
}

void Matrix3::operator+=(const Matrix3 & other)
{

	/*Soma de matriz this.matrix.a += other.a;*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) += other(rows, columns);
		}
	}

}
void Matrix3::operator+=(const float scalar)
{

	/*Soma de matriz this.matrix.a +=scalar*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) += scalar;
		}
	}

}
void Matrix3::operator-=(const Matrix3 & other)
{

	/*Subtração de matriz this.matrix.a -= other.a;*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) -= other(rows, columns);
		}
	}

}
void Matrix3::operator-=(const float scalar)
{

	/*Subtração de matriz this.matrix.a -= other.a;*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) -= scalar;
		}
	}

}
void Matrix3::operator*=(const Matrix3 & other)
{
	//Multiplicação de matriz this.matrix *= other
	Matrix3 temp = (*this) * other;
	*this = temp;
}
void Matrix3::operator*=(const float scalar)
{

	/*Multiplicação de matriz this.matrix.a *= scalar;*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) *= scalar;
		}
	}

}
void Matrix3::operator/=(const Matrix3 & other)
{

	/*Divisão de matriz this.matrix.a /= other.a;*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) /= other(rows, columns);
		}
	}

}
void Matrix3::operator/=(const float scalar)
{

	/*Divisão escalar de matriz this.matrix.a /= escalar*/

	for (unsigned rows = 0; rows < size; rows++)
	{
		for (unsigned columns = 0; columns < size; columns++)
		{
			(*this)(rows, columns) /= scalar;
		}
	}

}




