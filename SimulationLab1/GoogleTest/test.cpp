#include "pch.h"
#include "../SimulationLab1/Sphere.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(SphereSphereCollision, NoIntersectionCentreAtOrigin) {
	Sphere sphereA(glm::vec3(0, 0, 0), 1);
	Sphere sphereB(glm::vec3(5, 0, 0), 1);

	EXPECT_FALSE(sphereA.Intersects(sphereB));
}