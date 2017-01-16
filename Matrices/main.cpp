#include "MatricesApp.h"

int main() {
	
	auto app = new MatricesApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}