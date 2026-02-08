#include "pch.h"
#include "../SimulationLab1/Sphere.h"
#include "../SimulationLab1/LinePoint.h"
#include "../SimulationLab1/SphereLine.h"
#include "../SimulationLab1/PointToPlane.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#pragma region Q1 Sphere-Sphere Collision Tests

TEST(SphereSphereCollision, NoIntersectionCentreAtOrigin) {
	Sphere sphereA(glm::vec3(0, 0, 0), 1);
	Sphere sphereB(glm::vec3(5, 0, 0), 1);

	EXPECT_FALSE(sphereA.Intersects(sphereB));
}

TEST(SphereSphereCollision, NoIntersectionOffsetOrigin) {
	Sphere sphereA(glm::vec3(3, 3, 3), 2);
	Sphere sphereB(glm::vec3(10, 10, 10), 2);

	EXPECT_FALSE(sphereA.Intersects(sphereB));
}

TEST(SphereSphereCollision, IntersectionCentreAtOrigin) {
	Sphere sphereA(glm::vec3(0, 0, 0), 2);
	Sphere sphereB(glm::vec3(2, 0, 0), 2);

	EXPECT_TRUE(sphereA.Intersects(sphereB));
}

TEST(SphereSphereCollision, IntersectionOffsetOrigin) {
	Sphere sphereA(glm::vec3(5, 5, 5), 3);
	Sphere sphereB(glm::vec3(8, 5, 5), 3);

	EXPECT_TRUE(sphereA.Intersects(sphereB));
}

TEST(SphereSphereCollision, ContainedCentreAtOrigin) {
	Sphere sphereA(glm::vec3(0, 0, 0), 3);
	Sphere sphereB(glm::vec3(1, 0, 0), 1);

	EXPECT_TRUE(sphereA.Intersects(sphereB));
}

TEST(SphereSphereCollision, ContainedOffsetOrigin) {
	Sphere sphereA(glm::vec3(6, 6, 6), 5);
	Sphere sphereB(glm::vec3(7, 6, 6), 2);

	EXPECT_TRUE(sphereA.Intersects(sphereB));
}

#pragma endregion

#pragma region Q2 Closest Distance from a Point to a Line

TEST(ClosestDistanceToLine, ClosePointOnLine) {
	LinePoint linePoint(glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), glm::vec3(2, 3, 4));
	EXPECT_FLOAT_EQ(linePoint.ClosetDistanceToLine(), 1.41f);
}

TEST(ClosestDistanceToLine, GenIsOnLine) {
	LinePoint linePoint(glm::vec3(1, 2, 3), glm::vec3(0, 0, 0), glm::vec3(3, 6, 9));
	EXPECT_FLOAT_EQ(linePoint.ClosetDistanceToLine(), 0.0f);
}

TEST(ClosestDistanceToLine, VertLineCase) {
	LinePoint linePoint(glm::vec3(0, 0, 1), glm::vec3(2, 2, 0), glm::vec3(4, 5, 3));
	EXPECT_FLOAT_EQ(linePoint.ClosetDistanceToLine(), 3.61f);
}

TEST(ClosestDistanceToLine, HoriLineCase) {
	LinePoint linePoint(glm::vec3(1, 0, 0), glm::vec3(0, 0, 0), glm::vec3(3, 4, 5));
	EXPECT_FLOAT_EQ(linePoint.ClosetDistanceToLine(), 6.40f);
}

TEST(ClosestDistanceToLine, DiagLineCase) {
	LinePoint linePoint(glm::vec3(1, -1, 1), glm::vec3(1, 1, 1), glm::vec3(2, 5, 3));
	EXPECT_FLOAT_EQ(linePoint.ClosetDistanceToLine(), 4.55f);
}


#pragma endregion

#pragma region Q3 Sphere Line Intersection Test

TEST(SphereLineIntersection, NoIntersection) {
	SphereLine sphereLine(glm::vec3(5, 5, 5), glm::vec3(1, 0, 0), glm::vec3(0, 0, 0), 3);
	EXPECT_FALSE(sphereLine.DoesLineIntersectSphere());
}

TEST(SphereLineIntersection, PassThroughAtCentre) {
	SphereLine sphereLine(glm::vec3(10, 0, 0), glm::vec3(-1, 0, 0), glm::vec3(10, 0, 0), 5);
	EXPECT_TRUE(sphereLine.DoesLineIntersectSphere());
}

TEST(SphereLineIntersection, PassThroughInsideSphere) {
	SphereLine sphereLine(glm::vec3(3, 2, 2), glm::vec3(1, 0, 0), glm::vec3(2, 2, 2), 5);
	EXPECT_TRUE(sphereLine.DoesLineIntersectSphere());
}

TEST(SphereLineIntersection, PassThroughCentreSphere) {
	SphereLine sphereLine(glm::vec3(-5, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0, 0, 0), 3);
	EXPECT_TRUE(sphereLine.DoesLineIntersectSphere());
}

#pragma endregion

#pragma region Q4 Closest Distance from a Point to a Plane

TEST(ClosestDistanceToPlane, ClosePointOnPlane) {
	PointToPlane pointToPlane(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(2, 3, 5));
	EXPECT_FLOAT_EQ(pointToPlane.ClosetDistanceToPlane(), 5.0f);
}

#pragma endregion