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

TEST(Vector_2D_Tests, Clear)
{
	Vector2D vec2(1, 1);
	vec2.Clear();
	ASSERT_EQ(vec2.x, 0) << "Clear function results in wrong x value.";
	ASSERT_EQ(vec2.y, 0) << "Clear function results in wrong y value.";
}

TEST(Vector_2D_Tests, Accessors)
{
	Vector2D vec2(1, 2);
	ASSERT_EQ(vec2[0], 1) << "Index 0 accessor results in wrong accessed index.";
	ASSERT_EQ(vec2[1], 2) << "Index 1 accessor results in wrong accessed index.";
}

TEST(Vector_2D_Tests, Scalar_Multiplication)
{
	Vector2D vec2(1, 1);
	const float scalar = 2;
	vec2 *= scalar; 
	ASSERT_EQ(vec2.x, 2) << "Scalar multiplication results in wrong x value.";
	ASSERT_EQ(vec2.y, 2) << "Scalar multiplication results in wrong y value.";
}

TEST(Vector_2D_Tests, Scalar_Division)
{
	Vector2D vec2(4, 4);
	const float scalar = 2;
	vec2 /= scalar;
	ASSERT_EQ(vec2.x, 2) << "Scalar division results in wrong x value.";
	ASSERT_EQ(vec2.y, 2) << "Scalar division results in wrong y value.";
}

TEST(Vector_2D_Tests, Vector_Addition)
{
	Vector2D vec2(1, 1);
	const Vector2D vec2b(2, 2);
	vec2 += vec2b;
	ASSERT_EQ(vec2.x, 3) << "Vector addition results in wrong x value.";
	ASSERT_EQ(vec2.y, 3) << "Vector addition results in wrong y value.";
}

TEST(Vector_2D_Tests, Vector_Subtraction)
{
	Vector2D vec2(3, 3);
	const Vector2D vec2b(2, 2);
	vec2 -= vec2b;
	ASSERT_EQ(vec2.x, 1) << "Vector subtraction results in wrong x value.";
	ASSERT_EQ(vec2.y, 1) << "Vector subtraction results in wrong y value.";
}