/**
 * Filename		: Vector2DTests.h
 * Name			: Ori Lazar
 * Date			: 28/10/2019
 * Description	: This class contains the unit tests of the Vector2D class.
	 .---.
   .'_:___".
   |__ --==|
   [  ]  :[|
   |__| I=[|
   / / ____|
  |-/.____.'
 /___\ /___\
 */
#include "pch.h"
#include "Vectors/Vector2D.h"

using namespace Mathex;

TEST(Vector_2D_Tests, Constructors)
{
	Vector2D vec2(0,0);
	ASSERT_EQ(vec2.x, 0) << "Default constructor results in wrong x value.";
	ASSERT_EQ(vec2.y, 0) << "Default constructor results in wrong y value.";

	Vector2D vec2b(1,-1);
	ASSERT_EQ(vec2b.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec2b.y, -1) << "Non-Default constructor results in wrong y value.";
}