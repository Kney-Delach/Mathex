/**
 * Filename		: Vector3DTests.h
 * Name			: Ori Lazar
 * Date			: 29/10/2019
 * Description	: This class contains the unit tests of the Vector3D class.
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

using namespace Mathex;

TEST(Vector_3D_Tests, Constructors)
{
	Vector3D vec3;
	ASSERT_EQ(vec3.x, 0) << "Default constructor results in wrong x value.";
	ASSERT_EQ(vec3.y, 0) << "Default constructor results in wrong y value.";
	ASSERT_EQ(vec3.z, 0) << "Default constructor results in wrong z value.";

	Vector3D vec3b(1, 2,3);
	ASSERT_EQ(vec3b.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec3b.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec3b.z, 3) << "Non-Default constructor results in wrong z value.";

	Vector3D vec3c(3, Vector2D(1,2));
	ASSERT_EQ(vec3c.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec3c.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec3c.z, 3) << "Non-Default constructor results in wrong z value.";

	Vector3D vec3d(Vector2D(1, 2), 3);
	ASSERT_EQ(vec3d.x, 1) << "Non-Default constructor results in wrong x value.";
	ASSERT_EQ(vec3d.y, 2) << "Non-Default constructor results in wrong y value.";
	ASSERT_EQ(vec3d.z, 3) << "Non-Default constructor results in wrong z value.";
}