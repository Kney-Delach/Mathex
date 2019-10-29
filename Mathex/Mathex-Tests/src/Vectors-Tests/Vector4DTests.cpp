/**
 * Filename		: Vector4DTests.h
 * Name			: Ori Lazar
 * Date			: 29/10/2019
 * Description	: This class contains the unit tests of the Vector4D class.
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
#include "Vectors/Vector3D.h"
#include "Vectors/Vector4D.h"

using namespace Mathex;

TEST(Vector_4D_Tests, Constructors)
{
	Vector4D vec4;
	ASSERT_EQ(vec4.x, 0) << "Default constructor results in wrong x value.";
	ASSERT_EQ(vec4.y, 0) << "Default constructor results in wrong y value.";
	ASSERT_EQ(vec4.z, 0) << "Default constructor results in wrong z value.";
	ASSERT_EQ(vec4.w, 0) << "Default constructor results in wrong w value.";

	Vector4D vec4b(1,2,3,4);
	ASSERT_EQ(vec4b.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec4b.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec4b.z, 3) << "Non-Default constructor results in wrong z value.";
	ASSERT_EQ(vec4b.w, 4) << "Non-Default constructor results in wrong w value.";

	Vector4D vec4c(Vector2D(1,2), Vector2D(3, 4));
	ASSERT_EQ(vec4c.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec4c.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec4c.z, 3) << "Non-Default constructor results in wrong z value.";
	ASSERT_EQ(vec4c.w, 4) << "Non-Default constructor results in wrong w value.";

	Vector4D vec4d(Vector3D(1, 2,3), 4);
	ASSERT_EQ(vec4d.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec4d.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec4d.z, 3) << "Non-Default constructor results in wrong z value.";
	ASSERT_EQ(vec4d.w, 4) << "Non-Default constructor results in wrong w value.";

	Vector4D vec4e(4, Vector3D(1, 2, 3));
	ASSERT_EQ(vec4e.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec4e.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec4e.z, 3) << "Non-Default constructor results in wrong z value.";
	ASSERT_EQ(vec4e.w, 4) << "Non-Default constructor results in wrong w value.";
}