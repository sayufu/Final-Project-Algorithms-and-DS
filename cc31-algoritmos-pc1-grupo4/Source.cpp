#include"Controller.h"
int main() 
{
	Console::SetWindowSize(160, 40);
	Controller<string>* controller = new Controller<string>("soyunadmin","123456");
	csvGen generator;
	generator.generate_dataset();
	controller->addAllData();

	Start();
	char option = 0;
	while (true) {
/*Main menu*/
		system("CLS");
		Start2();
		do { setposition(25, 32); setfondo(0); setcolor(15); cout << "--> "; cin >> option; } while (!isdigit(option) || option < 49 || option>53); system("CLS");
		switch (option) {
/*Log in*/
		case '1':
			Login(controller, 3);
			_getch();
			break;
		case '2':
/*Register user*/
			Register(controller);
			_getch();
			break;
/*Get password*/
		case '3':
			RecoverPassword(controller, 3);
			_getch();
			break;
/*Exit program*/
		case '4':
			AdminPanel(controller);
			_getch();
			break;
/*Exit program*/
		case '5':
			exit(0);
			break;
		}
	}
	return 0;
}
