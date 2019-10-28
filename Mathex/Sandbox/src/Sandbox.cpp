/**
 * Filename		: Sandbox.cpp
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class is used to test the Mathex static maths library.
	 .---.
   .'_:___".
   |__ --==|
   [  ]  :[|
   |__| I=[|
   / / ____|
  |-/.____.'
 /___\ /___\
 */
#include <iostream>
#include "Vectors/Streams/V2Stream.h"
#include "Vectors/Streams/V3Stream.h"

using namespace Mathex;

int main()
{
	try
	{
		const Vector2D v2(1, 2);
		std::cout << v2;

		const Vector3D v3(1,2,3);
		std::cout << v3;
	} 
	catch(...) {}

	return 0;
}