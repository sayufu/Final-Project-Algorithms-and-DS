#pragma once

#include"Menu.h"
#include"Controller.h"


/*HIDES CIN*/
void hideInput() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
}


/*REGISTER*/
template<template<class> class var, class T>
void Register(var<T>* controller) {

	string username, password, recov = "";
	pintarlog();
	setposition(1, 0); cout << "Menu de Registro de Usuario MACAMUSIC\n\n";
	setposition(1, 2); cout << "- Tu usuario y password debe contener al menos 3 caracteres\n";
	setposition(1, 4); cout << "- Tus credenciales no pueden coincidir con algun usuario registrado\n\n";

	Console::SetCursorPosition(73, 8); Console::BackgroundColor = ConsoleColor::Gray;
	Console::ForegroundColor = ConsoleColor::Black; cout << "JOIN MACAMUSIC\n\n";
	Console::BackgroundColor = ConsoleColor::DarkGreen;
	Console::SetCursorPosition(67, 15); cout << "Username"; Console::BackgroundColor = ConsoleColor::DarkRed; Console::SetCursorPosition(67, 12); cin >> username;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(55, 30); cout << "Ingrese su mensaje para recuperar password --> "; Console::SetCursorPosition(55, 31); cin >> recov;
	Console::BackgroundColor = ConsoleColor::DarkGreen;
	Console::SetCursorPosition(67, 24); cout << "Password (Input is hidden)"; hideInput(); Console::BackgroundColor = ConsoleColor::DarkRed; Console::SetCursorPosition(67, 21); cin >> password;

	auto user = controller->verifyExistUser(username);

	if (username.size() < 3 || password.size() < 3 || user.exist == true) {
		system("CLS");
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::White;
		setposition(8, 5); cout << "\n\nError al crear usuario:\n";
		setposition(8, 7); cout << "El username ya se encuentra registrado o las credenciales contienen menos de 2 caracteres\n\n";
		system("PAUSE"); system("CLS");
		Register(controller);
	}
	else
	{
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::White;
		controller->push_write_csv_vector(controller->getUsers(), "Dependencies//user_list.csv", username, password, recov, "False");
	}
}


/*LOGIN*/
template<template<class> class var, class T>
void Login(var<T>* controller, int tries) {

	string username, password = "";
	system("CLS");

	if (controller->getUsers()->size() == 0) {
		system("CLS");
		setposition(10, 10); cout << "No hay usuarios registrados, ve a la opcion de Registros en el menu principal\n";
		setposition(10, 12); cout << "Presione una tecla para volver al menu principal.";
	}
	else {
		pintarlog();
		Console::SetCursorPosition(73, 8); Console::BackgroundColor = ConsoleColor::Gray;
		Console::ForegroundColor = ConsoleColor::Black; cout << "LOGIN MACAMUSIC\n\n";
		Console::BackgroundColor = ConsoleColor::DarkGreen;
		Console::SetCursorPosition(67, 15); cout << "Username"; Console::BackgroundColor = ConsoleColor::DarkRed; Console::SetCursorPosition(67, 12); cin >> username;
		Console::BackgroundColor = ConsoleColor::DarkGreen;
		Console::SetCursorPosition(67, 24); cout << "Password (Input is hidden)"; hideInput(); Console::BackgroundColor = ConsoleColor::DarkRed; Console::SetCursorPosition(67, 21); cin >> password;
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::White;
		auto user = controller->verifyExistUser(username);

		if (controller->verifyLogin(username, password) == true) {

			//If user is not banned
			if (controller->getUsers()->at(user.id).data4 == "True") {
				system("CLS");
				Console::SetCursorPosition(73, 8); cout << "\nTu cuenta esta baneada\nSeras redigirido a la pagina principal";
			}
			//Granted logged in
			else {
				system("CLS");
				Console::BackgroundColor = ConsoleColor::Black;
				Console::ForegroundColor = ConsoleColor::White;
				Console::SetCursorPosition(73, 8); cout << "\nLogged in! Presiona una tecla";
				_getch();
				system("CLS");
				UserPanel(username, controller);
			}

		}
		else {
			tries--;
			system("CLS");
			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(73, 8); cout << "Credenciales incorrectos.\nTe quedan " << tries << " intentos.\n";
			if (tries > 0) {
				_getch();
				Login(controller, tries);
			}
		}
	}

}


/*PASSWORD RECOVERY*/
template<template<class> class var, class T>
void RecoverPassword(var<T>* controller, int tries) {

	string username, password, recov = "";

	system("CLS"); cout << "RECUPERAR PASSWORD MACAMUSIC\n\n";
	if (controller->getUsers()->size() == 0) {
		cout << "No hay usuarios registrados, ve a la opcion de Registros en el menu principal\n";
		cout << "Presione una tecla para volver al menu principal.";
	}
	else {
		cout << "Recuerde que necesita su respuesta de recuperacion de password\n";
		cout << "Ingrese su username para recuperar password-> "; cin >> username;

		auto user = controller->verifyExistUser(username);

		if (user.exist == true) {
			cout << "\nSe encontro al usuario " << username << "\n\n";
			cout << "Ingrese su codigo para recuperar la password\nEs la que utilizo para registrarse a Macamusic\n-->";
			cin >> recov;

			//If credentials are correct
			auto verifier = controller->verifyRecov(username, recov);
			//If recover password is correct
			if (verifier.verified == true) {
				cout << "\nSu password es -->" << verifier.data2 << "\n";
			}
			else {
				tries--;
				cout << "Codigo de recuperacion incorrecto." << "\nTe quedan " << tries << " intentos.\n";
				if (tries > 0) {
					_getch();
					RecoverPassword(controller, tries);
				}
			}
		}
		else {
			tries--;
			cout << "\nNo existe el usuario " << username << ".\nTe quedan " << tries << " intentos.\n";
			if (tries > 0) {
				_getch();
				RecoverPassword(controller, tries);
			}
		}
	}
}


/*USER PANEL*/
template<template<class> class var, class T, class U>
void UserPanel(U username, var<T>* controller) {
	char choice = 0;
	string data1, data2, data3;
	string search;
	int option;

	while (true) {
		system("CLS");

		setcolor(15); setposition(42, 1); cout << "MACAMUSIC\nBienvenido/a " << username << "\n\n";
		userMenu();

		do { cout << "Elige una opcion " << "--> "; cin >> choice; } while (choice < 97 || choice>107); system("CLS");

		switch (choice) {
		case 'a':
			cout << "----------------------\n";
			cout << "Canciones (Linked list)\n";
			cout << "----------------------\n";
			cout << "1. Ver canciones\n";
			cout << "2. Reproducir canciones (Busqueda)\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1)
				controller->getSongs()->showAll();
			else {
				cout << "--- REPRODUCTOR MACAMUSIC ---\n";
				cout << "Busca una cancion para reproducir-->"; cin >> search;
				controller->playSong(search);
			}

			break;
		case 'b':
			cout << "----------------------\n";
			cout << "-Playlists (Hash Map)-\n";
			cout << "----------------------\n";
			cout << "1. Ver playlists\n";
			cout << "2. Eliminar un nodo\n";
			cout << "3. Insertar un nodo\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->getPlaylists()->show();
			}
			else if (option == 2) {
				int toDelete;
				cout << "Ingrese nodo a borrar (id of playlist): "; cin >> toDelete;
				controller->getPlaylists()->remove(toDelete);
			}
			else {
				int id;
				cout << "ID: "; cin >> id;
				cout << "Author: "; cin >> data1;
				cout << "Playlist name: "; cin >> data2;
				cout << "Album name: "; cin >> data3;
				controller->getPlaylists()->push(id,data1, data2, data3);
			}

			break;
		case 'c':
			cout << "---------------------\n";
			cout << "-- Podcasts (Tree) --\n";
			cout << "---------------------\n";
			cout << "1. Ver podcasts\n";
			cout << "2. Ingresar nuevo podcast\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->getPodcasts()->showAll();
			}
			else {
				cout << "Name: "; cin >> data1;
				cout << "Genre: "; cin >> data2;
				cout << "Duration: "; cin >> data3;
				controller->getPodcasts()->push(data1, data2, data3);
				cout << "Added\n";
			}

			break;
		case 'd':
			cout << "-------------------------\n";
			cout << "-- Singers (Self List) --\n";
			cout << "-------------------------\n";
			cout << "1. Ver singers\n";
			cout << "2. Buscar singer\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->getSingers()->showAll();
			}
			else {
				cout << "Busqueda-> "; cin >> search;
				controller->getSingers()->search(search);
			}

			break;
		case 'e':
			cout << "---------------------\n";
			cout << "-- Sponsors(Heaps) --\n";
			cout << "---------------------\n";
			cout << "1. Ver sponsors\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->getSponsors()->showAll();
			}

			break;
		case 'f':
			cout << "----------------------\n";
			cout << "-- Awards (XorList) --\n";
			cout << "----------------------\n";
			cout << "1. Ver awards\n";
			cout << "2. Ingresar nuevo award\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->getAwards()->showAll();
			}
			else {
				cout << "Award name: "; cin >> data1;
				cout << "Winner: "; cin >> data2;
				cout << "Year: "; cin >> data3;
				controller->getAwards()->push(data1, data2, data3);
				cout << "Added\n";
			}

			break;
		case 'g':
			cout << "----------------------------\n";
			cout << "-- Podcasters (Count Sort) --\n";
			cout << "----------------------------\n";
			cout << "1. Ver podcasters\n";
			cout << "2. Aplicar Count Sort\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->printVector(controller->getPodcasters());
			}
			else {
				countSort(controller->getPodcasters());
				controller->printVector(controller->getPodcasters());
				cout << "Count Sort aplicado!\n";
			}

			break;
		case 'h':
			cout << "------------------------\n";
			cout << "-- Users (Gnome Sort) --\n";
			cout << "------------------------\n";
			cout << "1. Ver users\n";
			cout << "2. Aplicar Gnome Sort\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->printVector(controller->getUsers());
			}
			else {
				gnomeSort(controller->getUsers());
				controller->printVector(controller->getUsers());
				cout << "Gnome Sort aplicado!\n";
			}

			break;
		case 'i':
			cout << "--------------------------\n";
			cout << "-- Events (Circle Sort) --\n";
			cout << "--------------------------\n";
			cout << "1. Ver events\n";
			cout << "2. Aplicar Circle Sort\n";
			cout << "->"; cin >> option;
			system("CLS");
			if (option == 1) {
				controller->printVector(controller->getEvents());
			}
			else {
				circleSort(controller->getEvents(), 0, controller->getEvents()->size() - 1);
				controller->printVector(controller->getEvents());
				cout << "Circle Sort aplicado!\n";
			}

			break;
		case 'j':
			cout << "Nos vemos pronto! - MACAMUSIC SIEMPRE CONTIGO\n";
			cout << "Logging out de " << username; Sleep(1000); cout << " . "; Sleep(1000); cout << " . "; Sleep(1000); cout << " . "; Sleep(1000);
			cout << "\nLogged out! Presione una tecla para cerrar el aplicativo";
			_getch();
			exit(0);
			break;
		default:
			break;
		}
		cout << "\nPresione una tecla para ir al menu principal\n";
		_getch();
	}

}




/*ADMIN PANEL*/
template<template<class> class var, class T>
void AdminPanel(var<T>* controller) {
	string username, password, tobanUser = "";
	char choice = 0;
	cout << "Admin Login\n";
	cout << "Username -> "; cin >> username;
	cout << "Password ->"; cin >> password;

	system("CLS");
	cout << "Admin Panel\n\n";

	if (controller->LogAdmin(username, password) == true) {

		cout << "Puedes banear un usuario.\nIngrese un username ->";
		cin >> tobanUser;
		auto user = controller->verifyExistUser(tobanUser);

		if (user.exist == true) {
			do {
				system("CLS");
				cout << "Amin Panel\n\nSe encontro el usuario " << tobanUser;
				cout << "\nConfirma banear al usuario " << tobanUser << "? Esto no podra revertirse (y/n):\n";
				cin >> choice;
			} while (choice != 'y' && choice != 'n');

			if (choice == 121) {
				controller->getUsers()->at(user.id).data4 = "True";
				cout << "Usuario " << tobanUser << " baneado, ya no podra loggearse.";
				controller->update_csv_vector(controller->getUsers(), "Dependencies//user_list.csv");
			}
			else
				cout << "De acuerdo, el usuario " << tobanUser << " no ha sido baneado.";
		}
		else
			cout << "No existe el usuario " << tobanUser << ".\nVolveras al menu principal.";
	}
	else
		cout << "Credenciales incorrectos\nVolveras al menu principal.";
}