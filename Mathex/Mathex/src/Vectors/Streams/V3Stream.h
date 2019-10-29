/**
 * Filename		: V3Stream.h
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class contains the implementation of a 3D vector stream override,
 *                this is located here as to make the Vector3D header as light as possible.
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
#include "Vectors/Vector3D.h"

namespace Mathex
{
	inline std::ostream& operator <<(std::ostream& out, const Vector3D& vector)
	{
		out << "3D Vector ( " << vector.x << " , " << vector.y << " , " << vector.z << " )\n";
		return out;
	}
}