#include "Bezier.h"

Bezier::Bezier(){}

glm::vec3 Bezier::getBezierCurve()
{
    glm::mat4x3 B = glm::mat4x3(glm::vec3(-7, 0, 0),
        glm::vec3(-12, 0, 23),
        glm::vec3(12, 0, 23),
        glm::vec3(10, 0, 0));

    if (this->t > 1.0f) this->growing = false;
    if (this->t < 0.0f) this->growing = true;

    if (this->growing)
    {
        this->t += 0.005f;
    }
    else
    {
        this->t -= 0.005f;
    }


    glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);

    glm::vec3 p = parameters * A * glm::transpose(B);

    return p;
}