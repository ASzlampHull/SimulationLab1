#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class SphereLine
{
private:
	glm::vec3 point;
	glm::vec3 direction;
	glm::vec3 sphereCentre;
	float sphereRadius;

public:
	SphereLine(glm::vec3 point_, glm::vec3 direction_, glm::vec3 sphereCentre_, float sphereRadius_)
		: point(point_), direction(direction_), sphereCentre(sphereCentre_), sphereRadius(sphereRadius_) {
	}
	~SphereLine() = default;

	bool DoesLineIntersectSphere() const;
};