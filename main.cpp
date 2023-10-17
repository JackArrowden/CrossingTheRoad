#include "CBIRD.h"
#include "Cat.h"
#include "CMOUSE.h"

int main() {
	cout << "HI" << endl;
	CBIRD* bird = new CBIRD;
	CAT* cat = new CAT;
	CMOUSE* mouse = new CMOUSE;
	bird->tell();
	//float lastUsed = (float)(clock() - listSound[{name_obj, action}].lastUsed) / CLOCKS_PER_SEC;
	Sleep(1000);
	cat->tell();
	Sleep(1000);
	mouse->tell();
	return 0;
}