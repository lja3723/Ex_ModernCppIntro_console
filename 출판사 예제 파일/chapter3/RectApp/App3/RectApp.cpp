#include "RectApp.h"
#include "Rect.h"

RectApp::RectApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}
// 응용 과제 3
void RectApp::mouseDown(int x, int y)
{
	if (rectCount == 0) {
		rects[rectCount] = std::make_unique<Rect>(x, y, x + 70, y + 50);
		++rectCount;
	}
	else {
		if (rectCount < MAX_RECTS) {
			if (rects[rectCount - 1]->includes(x, y)) {
				rects[rectCount] = std::make_unique<Rect>(x, y, x + 70, y + 50);
				rectCount = rectCount + 1;
			}
		}
	}
	clearAndUpdate();
}

void RectApp::paint()
{
	// 응용 과제 3
	for (auto it = rects.begin(); it != rects.end(); ++it)
		(*it)->draw(*this);
}

int mainLAF()
{
	RectApp theApp(TEXT("RECTANGLES"), 750, 500, 150, 150);
	theApp.run();

	return 0;
}