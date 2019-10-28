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

using namespace Mathex;

int main()
{
	try
	{
		const Vector2D v;
		std::cout << v;
	} 
	catch(...) {}

	return 0;
}