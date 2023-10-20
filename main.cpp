#include "CGAME.h"


int main() {
	cout << "HI" << endl;
	CBIRD* bird = new CBIRD;
	CAT* cat = new CAT;
	CMOUSE* mouse = new CMOUSE;
	CTRUCK* truck = new CTRUCK;
	CAR* car = new CAR;
	CTRAIN* train = new CTRAIN;

	//bird->tell();
	////float lastUsed = (float)(clock() - listSound[{name_obj, action}].lastUsed) / CLOCKS_PER_SEC;
	//Sleep(300);
	//cat->tell();
	//Sleep(300);
	//mouse->tell();
	//Sleep(400);
	//truck->tell();
	//Sleep(300);
	//car->tell();
	//Sleep(300);
	//train->tell();
	ConsoleHandle* a = new ConsoleHandle;
	a->fixConsoleWindow();
	return 0;
}