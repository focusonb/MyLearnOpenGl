#include "mouse_click_callback.h"

#include <glfw3.h>
#include <iostream>

#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;


using std::cout;
using std::endl;
//using namespace sh;




void mouseClick_callback(GLFWwindow * window, int button, int xposIn, int yposIn)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		auto start = high_resolution_clock::now();

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		if (handlePos(window, xPos, yPos) == false) {
			return;
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << duration.count() << endl;
	}

}

bool handlePos(GLFWwindow * window, double xPos, double yPos) {
	return true;
}
