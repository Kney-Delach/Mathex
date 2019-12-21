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

		Vector2D() : x(0), y(0) {}

		Vector2D(const float a, const float b) : x(a), y(b) {}

		~Vector2D() = default;

		inline void Clear()
		{
			x = 0;
			y = 0;
		}

		inline void Invert()
		{
			x = -x;
			y = -y;
		}

		_NODISCARD inline float Length() const
		{
			return sqrt((x * x) + (y * y));
		}

		void Normalize()
		{
			const float length = this->Length();
			if (length != 0)
			{
				x /= length;
				y /= length;
			}
		}

		// ---------------------------- Accessors ---------------------------- //

		inline float& operator [](const int i)
		{
			return ((&x)[i]);
		}

		inline const float& operator [](const int i) const
		{
			return ((&x)[i]);
		}

		// ---------------------------- Multiplication ---------------------------- //

		_NODISCARD inline float Dot(const Vector2D& vector)
		{
			return (x * vector.x + y * vector.y);
		}

		// ---------------------------- Operations ---------------------------- //

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

		inline Vector2D operator *(const float scalar) const
		{
			return Vector2D(x * scalar, y * scalar);
		}

		inline Vector2D operator *(const Vector2D& vector) const
		{
			return Vector2D(x * vector.x, y * vector.y);
		}

		inline Vector2D operator /(const float scalar) const
		{
			return Vector2D(x / scalar ,y / scalar);
		}

		inline Vector2D operator /(const Vector2D& vector) const
		{
			return Vector2D(x / vector.x, y / vector.y);
		}

		inline Vector2D operator +(const float scalar) const
		{
			return Vector2D(x + scalar, y + scalar);
		}

		inline Vector2D operator +(const Vector2D& vector) const
		{
			return Vector2D(x + vector.x, y + vector.y);
		}

		inline Vector2D operator -(const float scalar) const
		{
			return Vector2D(x - scalar, y - scalar);
		}

		inline Vector2D operator -(const Vector2D& vector) const 
		{
			return Vector2D(x - vector.x, y - vector.y);
		}

		_NODISCARD inline Vector2D Inverse() const
		{
			return Vector2D(-x, -y);
		}

		inline Vector2D operator -() const 
		{
			return Vector2D(-x, -y);
		}

		inline bool	CompareTo(const Vector2D& vector) const
		{
			return (vector.x == x && vector.y == y) ? true : false;
		}

		inline bool	operator==(const Vector2D& vector) const
		{
			return (vector.x == x && vector.y == y) ? true : false;
		}

		inline bool	operator!=(const Vector2D& vector) const
		{
			return (vector.x == x && vector.y == y ) ? false : true;
		}
	};
}