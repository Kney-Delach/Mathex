/**
 * Filename		: Vector3D.h
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class contains the implementation of a 3D vector.
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
	struct Vector3D
	{
		union
		{
			struct
			{
				float x, y, z;
			};
			struct
			{
				float r, g, b;
			};
		};

		Vector3D() : x(0), y(0), z(0) {};

		Vector3D(const float a, const float b, const float c) : x(a), y(b), z(c) {};

		Vector3D(const Vector2D v, const float a) : x(v.x), y(v.y), z(a) {};

		Vector3D(const float a, const Vector2D v) : x(v.x), y(v.y), z(a) {};

		~Vector3D() = default;

		inline void Clear()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		inline void Invert()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		_NODISCARD inline float Length() const
		{
			return sqrt((x * x) + (y * y) + (z * z));
		}

		void Normalize()
		{
			const float length = this->Length();
			if(length != 0)
			{
				x *= length;
				y *= length;
				z *= length;
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

		inline Vector3D Cross(const Vector3D& vector) const
		{
			return Vector3D(y * vector.z - z * vector.y,
				z * vector.x - x * vector.z,
				x * vector.y - y * vector.x);
		}

		_NODISCARD inline float Dot(const Vector3D& vector)
		{
			return (x * vector.x + y * vector.y + z * vector.z);
		}

		// ---------------------------- Operations ---------------------------- //

		inline Vector3D& operator *=(const float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return (*this);
		}

		inline Vector3D& operator /=(float scalar)
		{
			scalar = 1.f / scalar;
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return (*this);
		}

		inline Vector3D& operator +=(const Vector3D& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
			return (*this);
		}

		inline Vector3D& operator -=(const Vector3D& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			return (*this);
		}

		inline Vector3D operator *(const float scalar) const
		{
			return Vector3D(x * scalar, y * scalar, z * scalar);
		}

		inline Vector3D operator *(const Vector3D& vector) const 
		{
			return Vector3D(x * vector.x, y * vector.y, z * vector.z);
		}

		inline Vector3D operator /(const float scalar) const
		{
			return Vector3D(x / scalar, y / scalar, z / scalar);
		}

		inline Vector3D operator /(const Vector3D& vector) const 
		{
			return Vector3D(x / vector.x, y / vector.y, z / vector.z);
		}

		inline Vector3D operator +(const float scalar) const
		{
			return Vector3D(x + scalar, y + scalar, z + scalar);
		}

		inline Vector3D operator +(const Vector3D& vector) const
		{
			return Vector3D(x + vector.x, y + vector.y, z + vector.z);
		}

		inline Vector3D operator -(const float scalar) const
		{
			return Vector3D(x - scalar, y - scalar, z - scalar);
		}

		inline Vector3D operator -(const Vector3D& vector) const
		{
			return Vector3D(x - vector.x, y - vector.y, z - vector.z);
		}

		_NODISCARD inline Vector3D Inverse() const
		{
			return Vector3D(-x, -y, -z);
		}

		inline Vector3D operator -() const
		{
			return Vector3D(-x, -y, -z);
		}

		inline bool	CompareTo(const Vector3D& vector) const
		{
			return (vector.x == x && vector.y == y && vector.z == z) ? true : false;
		}

		inline bool	operator==(const Vector3D& vector) const
		{
			return (vector.x == x && vector.y == y && vector.z == z) ? true : false;
		}

		inline bool	operator!=(const Vector3D& vector) const
		{
			return (vector.x == x && vector.y == y && vector.z == z) ? false : true;
		}
	};
}