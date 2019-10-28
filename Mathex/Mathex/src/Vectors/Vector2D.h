/**
 * Filename		: Vector2D.h
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class contains the implementation of a 2D vector. 
     .---.  
   .'_:___".
   |__ --==|
   [  ]  :[|
   |__| I=[|
   / / ____|
  |-/.____.'
 /___\ /___\
 */
#pragma once

namespace Mathex
{
	struct Vector2D
	{
		float x, y;

		Vector2D() : x(0), y(0)
		{
		}

		Vector2D(const float a, const float b)
		{
			x = a;
			y = b;
		}

		void Clear()
		{
			x = 0;
			y = 0;
		}

		// -------------- Accessors -------------- //

		float& operator [](const int i)
		{
			return ((&x)[i]);
		}

		const float& operator [](const int i) const
		{
			return ((&x)[i]);
		}

		// -------------- Mathematical Operations -------------- //

		inline Vector2D& operator *=(const float scalar)
		{
			x *= scalar;
			y *= scalar;
			return (*this);
		}

		inline Vector2D& operator /=(float scalar)
		{
			scalar = 1.f / scalar;
			x *= scalar;
			y *= scalar;
			return (*this);
		}

		inline Vector2D& operator +=(const Vector2D& vector)
		{
			x += vector.x;
			y += vector.y;
			return (*this);
		}

		inline Vector2D& operator -=(const Vector2D& vector)
		{
			x -= vector.x;
			y -= vector.y;
			return (*this);
		}

		inline Vector2D operator +(const Vector2D& vector) const
		{
			return Vector2D(x + vector.x, y + vector.y);
		}

		inline Vector2D operator -(const Vector2D& vector) const 
		{
			return Vector2D(x - vector.x, y - vector.y);
		}
	};
}