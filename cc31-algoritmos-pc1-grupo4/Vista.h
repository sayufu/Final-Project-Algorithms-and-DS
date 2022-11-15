#pragma once

#include "Lib.h"

class Vista {
private:
	int logear[25][39] = 
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} 
	};
public:
	Vista() {}
	~Vista(){}

	void Start();
	void Start2();
	void pintarlog();
	void userMenu();
};

void Vista:: Start() {
	cout << "BIENVENIDO A MACAMUSIC\n\n";
	cout << "Integrantes\n- Cotaquispe, Christian\n- Fu Ye, Liliana\n-Vicente Ramos, William\n";
	cout << "\nPresione cualquier tecla para iniciar\n";
	_getch();
}

void Vista:: Start2() {
	setcolor(15); setposition(42, 1); cout << "@@@@@@\tMENU MACAMUSIC\t@@@@@@@\n\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(9); setposition(23 + j, 2 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(9); setposition(64 + j, 3 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(9); setposition(65 + j, 4 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(9); setposition(64 + j, 5 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(9); setposition(23 + j, 6 + i); cout << "*";
		}
	}
	setposition(25, 5); cout << "1. Login";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(12); setposition(23 + j, 8 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(12); setposition(64 + j, 9 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(12); setposition(65 + j, 10 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(12); setposition(64 + j, 11 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(12); setposition(23 + j, 12 + i); cout << "*";
		}

	}
	setposition(25, 11); cout << "2. Register\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(10); setposition(23 + j, 14 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(10); setposition(64 + j, 15 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(10); setposition(65 + j, 16 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(10); setposition(64 + j, 17 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(10); setposition(23 + j, 18 + i); cout << "*";
		}

	}
	setposition(25, 17); cout << "3. Recuperar password\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(14); setposition(23 + j, 20 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(14); setposition(64 + j, 21 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(14); setposition(65 + j, 22 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(14); setposition(64 + j, 23 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(14); setposition(23 + j, 24 + i); cout << "*";
		}

	}
	setposition(25, 23); cout << "4. Admin panel\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(8); setposition(23 + j, 26 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(8); setposition(64 + j, 27 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(8); setposition(65 + j, 28 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(8); setposition(64 + j, 29 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(8); setposition(23 + j, 30 + i); cout << "*";
		}

	}
	setposition(25, 29); cout << "5. Salir\n";

	int x, y;
	x = 97; y = 6;
	setfondo(12);
	setposition(x, y); cout << " "; y++;
	setposition(x, y); cout << " "; y++;
	setposition(92, 8); cout << " ";
	setposition(96, 8); cout << " ";
	setposition(97, 8); cout << " ";
	setposition(102, 8); cout << " ";
	setposition(92, 9); cout << " ";
	setposition(96, 9); cout << " ";
	setposition(97, 9); cout << " ";
	setposition(102, 9); cout << " ";
	setposition(106, 9); cout << " ";
	setposition(114, 9); cout << " ";

	for (int i = 1; i < 11; i++) {
		Console::SetCursorPosition(116 + i, 9); cout << " ";
	}
	for (int i = 1; i < 11; i++) {
		Console::SetCursorPosition(128 + i, 9); cout << " ";
	}

	setposition(92, 10); cout << " ";
	setposition(96, 10); cout << " ";
	setposition(97, 10); cout << " ";
	setposition(98, 10); cout << " ";
	setposition(102, 10); cout << " ";
	setposition(106, 10); cout << " ";
	setposition(114, 10); cout << " ";
	setposition(117, 10); cout << " ";
	setposition(126, 10); cout << " ";
	setposition(129, 10); cout << " ";

	setposition(91, 11); cout << " ";
	setposition(92, 11); cout << " ";
	setposition(97, 11); cout << " ";
	setposition(98, 11); cout << " ";
	setposition(102, 11); cout << " ";
	setposition(103, 11); cout << " ";
	setposition(106, 11); cout << " ";
	setposition(114, 11); cout << " ";
	setposition(117, 11); cout << " ";
	setposition(126, 11); cout << " ";
	setposition(129, 11); cout << " ";

	setposition(91, 12); cout << " ";
	setposition(92, 12); cout << " ";
	setposition(97, 12); cout << " ";
	setposition(98, 12); cout << " ";
	setposition(102, 12); cout << " ";
	setposition(103, 12); cout << " ";
	setposition(106, 12); cout << " ";
	setposition(114, 12); cout << " ";
	setposition(117, 12); cout << " ";
	setposition(126, 12); cout << " ";
	setposition(129, 12); cout << " ";

	setposition(91, 13); cout << " ";
	setposition(92, 13); cout << " ";
	setposition(96, 13); cout << " ";
	setposition(97, 13); cout << " ";
	setposition(103, 13); cout << " ";
	setposition(106, 13); cout << " ";
	setposition(114, 13); cout << " ";
	for (int i = 1; i < 11; i++) {
		setposition(116 + i, 13); cout << " ";
	}
	setposition(129, 13); cout << " ";
	setposition(91, 14); cout << " ";
	setposition(92, 14); cout << " ";
	setposition(96, 14); cout << " ";
	setposition(97, 14); cout << " ";
	setposition(102, 14); cout << " ";
	setposition(103, 14); cout << " ";
	setposition(106, 14); cout << " ";
	setposition(114, 14); cout << " ";
	setposition(117, 14); cout << " ";
	setposition(129, 14); cout << " ";

	setposition(92, 15); cout << " ";
	setposition(93, 15); cout << " ";
	setposition(96, 15); cout << " ";
	setposition(97, 15); cout << " ";
	setposition(95, 15); cout << " ";
	setposition(101, 15); cout << " ";
	setposition(102, 15); cout << " ";
	setposition(103, 15); cout << " ";
	setposition(106, 15); cout << " ";
	setposition(114, 15); cout << " ";
	setposition(117, 15); cout << " ";
	setposition(129, 15); cout << " ";

	setposition(92, 16); cout << " ";
	setposition(93, 16); cout << " ";
	setposition(96, 16); cout << " ";
	setposition(97, 16); cout << " ";
	setposition(98, 16); cout << " ";
	setposition(101, 16); cout << " ";
	setposition(102, 16); cout << " ";
	setposition(103, 16); cout << " ";
	setposition(106, 16); cout << " ";
	setposition(114, 16); cout << " ";
	setposition(117, 16); cout << " ";
	setposition(129, 16); cout << " ";

	for (int i = 0; i < 9; i++) {
		setposition(93 + i, 17); cout << " ";
	}
	setposition(106, 17); cout << " ";
	setposition(114, 17); cout << " ";
	setposition(117, 17); cout << " ";
	setposition(129, 17); cout << " ";
	for (int i = 0; i < 9; i++) {
		setposition(93 + i, 18); cout << " ";
	}
	for (int i = 1; i <= 9; i++) {
		setposition(105 + i, 18); cout << " ";
	}
	setposition(117, 18); cout << " ";
	for (int i = 1; i <= 10; i++) {
		setposition(128 + i, 18); cout << " ";
	}
}

void Vista:: pintarlog() {
	char pen = 219;
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 39; c++) {
			Console::SetCursorPosition(60 + c, 6 + f);
			if (logear[f][c] == 1) {
				Console::ForegroundColor = ConsoleColor::Gray;
				cout << pen;
			}
			if (logear[f][c] == 0) {
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << pen;
			}
			if (logear[f][c] == 2) {
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cout << pen;
			}
			if (logear[f][c] == 3) {
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				cout << pen;
			}


		}
	}
}

void Vista::userMenu() {
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(9); setposition(23 + j, 2 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(9); setposition(64 + j, 3 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(9); setposition(65 + j, 4 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(9); setposition(64 + j, 5 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(9); setposition(23 + j, 6 + i); cout << "*";
		}
	}

	setposition(25, 5); cout << "1. Reproducir musica\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(12); setposition(23 + j, 8 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(12); setposition(64 + j, 9 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(12); setposition(65 + j, 10 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(12); setposition(64 + j, 11 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(12); setposition(23 + j, 12 + i); cout << "*";
		}

	}
	setposition(25, 11); cout << "2. Ver canciones\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(10); setposition(23 + j, 14 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(10); setposition(64 + j, 15 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(10); setposition(65 + j, 16 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(10); setposition(64 + j, 17 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(10); setposition(23 + j, 18 + i); cout << "*";
		}

	}
	setposition(25, 17); cout << "3. Ver playslists\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(14); setposition(23 + j, 20 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(14); setposition(64 + j, 21 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(14); setposition(65 + j, 22 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(14); setposition(64 + j, 23 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(14); setposition(23 + j, 24 + i); cout << "*";
		}

	}
	setposition(25, 23); cout << "4. Ver podcasts\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(8); setposition(23 + j, 26 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(8); setposition(64 + j, 27 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(8); setposition(65 + j, 28 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(8); setposition(64 + j, 29 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(8); setposition(23 + j, 30 + i); cout << "*";
		}

	}
	setposition(25, 29); cout << "5. Ver cantantes\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(11); setposition(83 + j, 2 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(11); setposition(124 + j, 3 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(11); setposition(125 + j, 4 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(11); setposition(124 + j, 5 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(11); setposition(83 + j, 6 + i); cout << "*";
		}
	}
	setposition(85, 5); cout << "6. Ver Eventos\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(6); setposition(83 + j, 8 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(6); setposition(124 + j, 9 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(6); setposition(125 + j, 10 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(6); setposition(124 + j, 11 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(6); setposition(83 + j, 12 + i); cout << "*";
		}

	}
	setposition(85, 11); cout << "7. Algunas aplicaciones lambdas\n";
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(2); setposition(83 + j, 14 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(2); setposition(124 + j, 15 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(2); setposition(125 + j, 16 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 10; j++) {
			setcolor(2); setposition(124 + j, 17 + i); cout << "*";
		}
	}
	for (int i = 1; i <= 1; i++) {
		for (int j = 1; j <= 50; j++) {
			setcolor(2); setposition(83 + j, 18 + i); cout << "*";
		}

	}
	setposition(85, 17); cout << "8. Log out\n";
}