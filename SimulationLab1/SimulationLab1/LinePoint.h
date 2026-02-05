#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class LinePoint
{
public:
	LinePoint(glm::vec3 dir_, glm::vec3 startPt_, glm::vec3 genPt_) : direction(dir_), startingPoint(startPt_), generalPoint(genPt_) {}
	~LinePoint();



private:
	glm::vec3 direction;
	glm::vec3 startingPoint;
	glm::vec3 generalPoint;
};