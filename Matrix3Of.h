#pragma once
#include "Matrix3.h"
#include "ofVec2f.h"
#include "ofMatrix4x4.h"

/// <summary>
/// Matrix3Of é uma extensão para trabalhar com a <see cref="Matrix3"/> e openFrameworks.
/// </summary>
class Matrix3Of
{

public:

	/// <summary>
	/// Escala a matriz identidade utilizando um ofVec2f.
	/// Tenha em mente a matriz retorno <see cref="Matrix3"/> não é acumulada
	/// </summary>
	/// <param name="v">Vetor contendo x e y da escala</param>
	/// <returns>Matrix3 escalada mas não acumulada</returns>
	const static Matrix3 matrixScale(const ofVec2f &v);
	/// <summary>
	/// Move a matriz identidade utilizando um ofVec2f.
	/// Tenha em mente a matriz retorno <see cref="Matrix3"/> não é acumulada
	/// </summary>
	/// <param name="v">Vetor contendo x e y para movimento</param>
	/// <returns>Matrix3 movida mas não acumulada</returns>
	const static Matrix3 matrixTranslate(const ofVec2f &v);
	/// <summary>
	/// Rotaciona a matriz identidade utilizando angulo em degrees.
	/// Tenha em mente a matriz retorno <see cref="Matrix3"/> não é acumulada
	/// </summary>
	/// <param name="degrees">angulo em degrees</param>
	/// <returns>Matrix3 rotacionada</returns>
	const static Matrix3 matrixRotation(const float degrees);
	/// <summary>
	/// Converte um objeto <see cref="Matrix3"/> para uma Matriz4x4 padrão openFrameWorks.
	/// veja <see cref="ofMatrix4x4"/>
	/// </summary>
	/// <param name="matrix3">Matrix3 original para ser modificada em 4x4of</param>
	/// <returns>matriz4x4 openframeOrks</returns>
	const static ofMatrix4x4 ToOfMatrix4(const Matrix3 &matrix3);

	/// <summary>
	/// Multiplica a matriz3 origem por um ofVec2f e retorna o vetor resultante
	/// </summary>
	/// <param name="v">Vetor para multiplicação</param>
	/// <param name="matrix">Matriz3 Origem</param>
	/// <returns>Vetor resultante</returns>
	const static ofVec2f Transform(const ofVec2f &v, const Matrix3 &matrix);
	
};

