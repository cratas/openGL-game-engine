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

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			if (camera->leftClick)
			{
				camera->leftClick = false;

				GLbyte color[4];
				GLfloat depth;
				GLuint index;

				double mouseX;
				double mouseY;

				glfwGetCursorPos(window, &mouseX, &mouseY);

				int newy = Controller::height - mouseY;

				glReadPixels(mouseX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
				glReadPixels(mouseX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
				glReadPixels(mouseX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);


				//Mùžeme nastavit vybrané tìleso scena->setSelect(index-1);

				//Mùžeme vypoèíst pozici v globálním souøadném systému.  
				glm::vec3 screenX = glm::vec3(mouseX, newy, depth);

				glm::vec4 viewPort = glm::vec4(0, 0, Controller::width, Controller::height);
				glm::vec3 pos = glm::unProject(screenX, camera->getView(), camera->getProjection(), viewPort);

				if (index == 0)
				{
					ObjectManager::getInstance()->createTextureObject(ShaderManager::getInstance()->createTextureShader(camera)
						, "Textures/tree.obj", TextureManager::getInstance()->getTexture(3), true);
					ObjectManager::getInstance()->getObject(ObjectManager::getInstance()->getCount() - 1)->getTransformations()->translate(pos.x, pos.y, pos.z);
					ObjectManager::getInstance()->getObject(ObjectManager::getInstance()->getCount() - 1)->getTransformations()->scale(0.4, 0.4, 0.4);

				}

				printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, % f, stencil index % u\n", mouseX, mouseY, color[0], color[1], color[2], color[3], depth, index);

				ObjectManager::getInstance()->removeObject(index);

				printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
			}
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			camera->leftClick = true;
			camera->firstClick = true;
		}
	} 
	
}