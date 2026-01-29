#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Sphere
{
private:
	glm::vec3 position;
	float radius;

public:
	Sphere(glm::vec3 pos_, float rad_) : position(pos_), radius(rad_) {}
	~Sphere() = default;

	bool Intersects(const Sphere& other) const;
};
