#include "Matrix3Of.h"



const Matrix3 Matrix3Of::matrixScale(const ofVec2f &v)
{
	return Matrix3::matrixScale(v.x, v.y);
}

const Matrix3 Matrix3Of::matrixTranslate(const ofVec2f &v)
{
	return Matrix3::matrixTranslate(v.x, v.y);
}

const Matrix3 Matrix3Of::matrixRotation(const float degrees)
{
	return Matrix3::matrixRotation(degrees);
}

const ofMatrix4x4 Matrix3Of::ToOfMatrix4(const Matrix3 &matrix3)
{
	float a = matrix3._a();
	float b = matrix3._b();
	float c = matrix3._c();
	float d = matrix3._d();
	float e = matrix3._e();
	float f = matrix3._f();
	float g = matrix3._g();
	float h = matrix3._h();
	float i = matrix3._i();

	ofMatrix4x4 matrix4 = ofMatrix4x4(a,b,0,c,d,e,0,f,0,0,1,0,g,h,0,i);
	

	return matrix4;
}



const ofVec2f Matrix3Of::Transform(const ofVec2f &v, const Matrix3 &matrix)
{
	/*Não tecenho certeza se isto esta fucionando corretamente.
	O Algoritmo funciona da seguinte maneira.
	Produto das linhas da Matriz por Colunas da Matriz Vetor.
	POREM meu Vetor é de 2 Elementso e minha matriz é de 3 Linhas. Assim sendo eu nao sei
	se devo considerar na multiplicação de linhas o ultimo elemento de cada linha multiplicando 1 ou
	se devo ignorar.
	Tambem não sei se devo ignorar a ultima linha da matriz, uma vez que meu vetor e X e Y, esta ultima linha
	ficaria sem utiliade no vetor. (X.X) BUMP
	*/

	float a, b, c, d, e, f, x, y;
	a = matrix._a();	
	b = matrix._b();	
	c = matrix._c();	
	d = matrix._d();	
	e = matrix._e();	
	f = matrix._f(); 
	x = v.x; 
	y = v.y;

	ofVec2f result = ofVec2f().zero();

	result.x = a*x + b*y + c* 1.0f;
	result.y = d*x + e*y + f* 1.0f;

	return result;
}
