#include "Bezier.h"

Bezier::Bezier() {}

Bezier::Bezier(glm::mat4x4 bezierPoints)
{
    this->bezierPoints = bezierPoints;
}

glm::vec3 Bezier::getBezierCurve()
{
    if (this->t > 1.0f) this->growing = false;
    if (this->t < 0.0f) this->growing = true;

    this->t = (this->growing) ? this->t + 0.005f : this->t - 0.005f;

    glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
    glm::vec3 p = parameters * A * glm::transpose(this->bezierPoints);

    return p;
}