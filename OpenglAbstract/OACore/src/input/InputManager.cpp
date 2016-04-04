#include "ngengine.h"
#include "InputManager.h"

namespace ngengine {
	namespace input {

		InputManager::InputManager()
		{
		}

		void InputManager::setWindow(Window&& parentWindow) {
			window = &parentWindow;

			glfwSetWindowUserPointer(window->getHandler(), this);

			glfwSetKeyCallback(window->getHandler(), keyboardCallback);
			glfwSetCursorPosCallback(window->getHandler(), mouseCallback);
		}

		Pos2D InputManager::getMousePosition()
		{
			return mouse.getMousePosition(window->getHandler());
		}

		Pos2D InputManager::getNormalizedMousePosition()
		{
			return mouse.getNormalizedMousePosition(window->getHandler(), window->getSize());
		}

		KeyState InputManager::getKeyState(int keyIdentifier)
		{
			return keyboard.getKeyState(keyIdentifier);
		}

		void InputManager::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
		{
			InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			inputManager->keyboard.keyboardCallback(key, action);
		}

		void InputManager::mouseCallback(GLFWwindow * window, double x, double y)
		{
			InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			inputManager->mouse.mouseCallback(x, y);
		}

		InputManager::~InputManager()
		{
		}
	}
}