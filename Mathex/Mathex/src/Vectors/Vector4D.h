/**
 * Filename		: Vector4D.h
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class contains the implementation of a 4D vector.
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
	struct Vector4D
	{
		union
		{
			struct
			{
				float x, y, z, w;
			};
			struct
			{
				float r, g, b, a;
			};
		};

		Vector4D() : x(0), y(0), z(0), w(0) {};

		Vector4D(const float a, const float b, const float c, const float d) : x(a), y(b), z(c), w(d) {};

		Vector4D(const Vector2D v1, const Vector2D v2) : x(v1.x), y(v1.y), z(v2.x), w(v2.y) {};

		Vector4D(const Vector3D v3, const float a) : x(v3.x), y(v3.y), z(v3.z), w(a) {};

		Vector4D(const float a, const Vector3D v3) : x(v3.x), y(v3.y), z(v3.z), w(a) {};

		~Vector4D() = default;

		inline void Clear()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		inline void Invert()
		{
			x = -x;
			y = -y;
			z = -z;
			w = -w;
		}

		_NODISCARD inline float Length() const
		{
			return sqrt((x * x) + (y * y) + (z * z) + (w * w));
		}

		void Normalize()
		{
			const float length = this->Length();
			if (length != 0)
			{
				x /= length;
				y /= length;
				z /= length;
				w /= length;
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

		// ---------------------------- Operations ---------------------------- //

		inline Vector4D& operator *=(const float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return (*this);
		}

		inline Vector4D& operator /=(float scalar)
		{
			scalar = 1.f / scalar;
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return (*this);
		}

		inline Vector4D& operator +=(const Vector4D& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
			w += vector.w;
			return (*this);
		}

		inline Vector4D& operator -=(const Vector4D& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			w -= vector.w;
			return (*this);
		}

		inline Vector4D operator *(const float scalar) const
		{
			return Vector4D(x * scalar, y * scalar, z * scalar, w * scalar);
		}

		inline Vector4D operator *(const Vector4D& vector) const
		{
			return Vector4D(x * vector.x, y * vector.y, z * vector.z, w * vector.w);
		}

		inline Vector4D operator /(const float scalar) const
		{
			return Vector4D(x / scalar, y / scalar, z / scalar, w / scalar);
		}

		inline Vector4D operator /(const Vector4D& vector) const
		{
			return Vector4D(x / vector.x, y / vector.y, z / vector.z, w / vector.w);
		}

		inline Vector4D operator +(const float scalar) const
		{
			return Vector4D(x + scalar, y + scalar, z + scalar, w + scalar);
		}

		inline Vector4D operator +(const Vector4D& vector) const
		{
			return Vector4D(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
		}

		inline Vector4D operator -(const float scalar) const
		{
			return Vector4D(x - scalar, y - scalar, z - scalar, w - scalar);
		}

		inline Vector4D operator -(const Vector4D& vector) const
		{
			return Vector4D(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
		}

		_NODISCARD inline Vector4D Inverse() const
		{
			return Vector4D(-x, -y, -z, -w);
		}

		inline Vector4D operator -() const
		{
			return Vector4D(-x, -y, -z, -w);
		}

		inline bool	CompareTo(const Vector4D& vector) const
		{
			return (vector.x == x && vector.y == y && vector.z == z && vector.w == w) ? true : false;
		}

		inline bool	operator==(const Vector4D& vector) const
		{
			return (vector.x == x && vector.y == y && vector.z == z && vector.w == w) ? true : false;
		}

		inline bool	operator!=(const Vector4D& vector) const
		{
			return (vector.x == x && vector.y == y && vector.z == z && vector.w == w) ? false : true;
		}
	};
}