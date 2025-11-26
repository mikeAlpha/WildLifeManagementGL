#include<IProperty.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class WorldTransform : public IProperty{
    public:
        WorldTransform();
        ~WorldTransform();

        glm::vec3 position, rotation, scale;
}