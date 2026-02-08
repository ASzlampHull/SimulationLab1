#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <cmath>

class PointToPlane
{
private:
	glm::vec3 startingPoint;
	glm::vec3 normalizedDirection;
	glm::vec3 generalPoint;
public:
	PointToPlane(glm::vec3 startingPoint_, glm::vec3 direction_, glm::vec3 generalPoint_)
		: startingPoint(startingPoint_), normalizedDirection(glm::normalize(direction_)), generalPoint(generalPoint_) {
	}
	~PointToPlane() = default;
	float ClosetDistanceToPlane();
};