#include "Mesh.h"
#include <numbers>
#include <vector>

Mesh* CreateCircle(float radius = 0.5f, int segments = 64) {
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0);

	for (int i = 0; i <= segments; i++) {
		float angle = (2 * 3.14159265358979323846f * i) / segments;
		float x = radius * cos(angle);
		float y = radius * sin(angle);

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(0);
	}

	for (int i = 1; i <= segments; i++) {
		indices.push_back(0);
		indices.push_back(i);
		indices.push_back(i + 1);
	}
	
	return new Mesh(vertices.data(), static_cast<unsigned int>(vertices.size()), indices.data(), static_cast<unsigned int>(indices.size()));
}