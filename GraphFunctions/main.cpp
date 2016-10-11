#include "GraphFunctionsApp.h"

int main() {
	
	auto app = new GraphFunctionsApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}