#include "Controller.h"

int Controller::width = 800;
int Controller::height = 600;

/// <summary>
/// Class constructor taking one argument pointer to Camera class
/// </summary>
Controller::Controller(Camera* camera)
{
	this->camera = camera;
}

static void window_size_callback(GLFWwindow* window, int width, int height) {
	Controller::width = width;
	Controller::height = height;
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

/// <summary>
/// Method checkInput is called in main loop, handle user input and sends info to camera
/// </summary>
void Controller::checkInput()
{
	WindowInitializer *windowInitializer = WindowInitializer::getInstance();
	GLFWwindow *window = windowInitializer->getWindow();

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera->position += camera->speed * camera->orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera->position += camera->speed * -glm::normalize(glm::cross(camera->orientation, camera->up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera->position += camera->speed * -camera->orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera->position += camera->speed * glm::normalize(glm::cross(camera->orientation, camera->up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		camera->position += camera->speed * camera->up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		camera->position += camera->speed * -camera->up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		camera->speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		camera->speed = 0.1f;
	}

	glfwSetWindowSizeCallback(window, window_size_callback);

	camera->width = Controller::width;
	camera->height = Controller::height;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (camera->firstClick)
		{
			glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
			camera->firstClick = false;
		}

		double mouseX;
		double mouseY;

		glfwGetCursorPos(window, &mouseX, &mouseY);
		float rotX = camera->sensitivity * (float)(mouseY - (camera->height / 2)) / camera->height;
		float rotY = camera->sensitivity * (float)(mouseX - (camera->width / 2)) / camera->width;

		glm::vec3 newOrientation = glm::rotate(camera->orientation, glm::radians(-rotX), glm::normalize(glm::cross(camera->orientation, camera->up)));

		if (abs(glm::angle(newOrientation, camera->up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			camera->orientation = newOrientation;
		}

		camera->orientation = glm::rotate(camera->orientation, glm::radians(-rotY), camera->up);

		glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		camera->firstClick = true;
	}
}