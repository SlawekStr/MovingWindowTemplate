#include "MovingWindow.h"

int main()
{
	MovingWindow window(1920, 1080, "Moving window template", 144);
	window.run();

	return 0;
}