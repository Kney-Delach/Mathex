/**
 * Filename		: V2Stream.h
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class contains the implementation of a 2D vector stream override, 
 *                this is located here as to make the Vector2D header as light as possible.
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
#include <ostream>
#include "Vectors/Vector2D.h"

namespace Mathex
{
	inline std::ostream& operator <<(std::ostream& out, const Vector2D& vector)
	{
		out << "Vector2D(" << vector.x << "," << vector.y << ")\n";
		return out;
	}
}