#pragma once

#include"Functions.h"
#include"Node.h"
#include"List.h"
#include"forVector.h"
#include"heaps.h"
#include"Admin.h"
#include"Xorlist.h"
#include"selfList.h"
#include"Tree.h"
#include"hashMap.h"
#include"countSort.h"
#include"circleSort.h"
#include"gnomeSort.h"
#include"datasetGen.h"
#include"Playlist.h"
#include"structheap.h"

template<class T>
class Controller {
private:
	Admin<T>* admin;
	List<T>* songs;
	Xorlist<T>* awards;
	heaps<T>* sponsors;
	selfList<T>* singers;
	hashMap<Playlist>* playlists;
	Tree<T>* podcasts;
	vector<forVector<T>>* users;
	vector<forVector<T>>* podcasters;
	vector<forVector<T>>* events;
public:

	Controller(T aUsername, T aPassword) {
		admin = new Admin<T>(aUsername, aPassword);
		songs = new List<T>("Dependencies//songs.csv");
		awards = new Xorlist<T>("Dependencies//awards.csv");
		sponsors = new heaps<T>("Dependencies//sponsors.csv");
		singers = new selfList<T>("Dependencies//singers.csv");
		//playlists = new hashMap<T>("Dependencies//spotify_dataset.csv"); //1 million data
		playlists = new hashMap<Playlist>("Dependencies//generated_data_set.csv");
		podcasts = new Tree<T>("Dependencies//podcast.csv");
		users = new vector<forVector<T>>();
		podcasters = new vector<forVector<T>>();
		events = new vector<forVector<T>>();
	}
	~Controller() {}



	template<template<class> class var, class T>
	void read_csv_hash(var<T>* p) {
		string filename = p->getCSV();
		ifstream inputFile;
		string line = "";

		inputFile.open(filename);
		if (inputFile.is_open()) {
			cout << "Currently reading " << filename << ". . .\n";
			while (getline(inputFile, line)) {
				string data1, data2, data3, data4;
				stringstream inputString(line);

				getline(inputString, data1, ',');
				getline(inputString, data2, ',');
				getline(inputString, data3, ',');
				getline(inputString, data4, ',');
				p->push(stoi(data1), data2, data3,data4);
			}
			cout << "Done reading " << filename << "\n";
		}
		else {
			cout << "Error: " << filename << "\n";
			_getch();
			exit(0);
		}

		inputFile.close();
	}

	template<template<class> class var, class T>
	void read_csv_other(var<T>* p) {
		string filename = p->getCSV();
		ifstream inputFile;
		string line = "";

		inputFile.open(filename);
		if (inputFile.is_open()) {
			cout << "Currently reading " << filename << ". . .\n";
			while (getline(inputFile, line)) {
				string data1, data2, data3;
				stringstream inputString(line);

				getline(inputString, data1, ',');
				getline(inputString, data2, ',');
				getline(inputString, data3, ',');
				p->push(data1, data2, data3);
			}
			cout << "Done reading " << filename << "\n";
		}
		else {
			cout << "Error: " << filename << "\n";
			_getch();
			exit(0);
		}

		inputFile.close();
	}

	template<template<class> class var, class T>
	void push_write_csv_other(var<T>* p, string filename, T data1, T data2, T data3) {
		string filename = p->getCSV();
		p->push(data1, data2, data3);

		ofstream file;
		file.open(filename, ofstream::app);
		if (file.is_open()) {
			file << data1 << "," << data2 << "," << data3 << "\n";
		}
		file.close();
	}

/*READ WRITE CSV FOR VECTORS*/
	void read_csv_vector(vector<forVector<string>>* p, string filename) {
		ifstream inputFile;
		string line = "";

		inputFile.open(filename);
		if (inputFile.is_open()) {
			cout << "Currently reading " << filename << ". . .\n";
			while (getline(inputFile, line)) {
				string data1, data2, data3, data4;
				stringstream inputString(line);

				getline(inputString, data1, ',');
				getline(inputString, data2, ',');
				getline(inputString, data3, ',');
				getline(inputString, data4, ',');
				p->push_back(forVector<T>(data1, data2, data3, data4));
			}
			cout << "Done reading " << filename << "\n";
		}
		else {
			cout << "Error: " << filename << "\n";
			_getch();
			exit(0);
		}

		inputFile.close();
	}

	void update_csv_vector(vector<forVector<string>>* p, string filename) {
		string data1, data2, data3, data4 = "";
		ofstream file;
		file.open(filename);
		if (file.is_open()) {
			for (uint i = 0; i < p->size(); i++) {
				file << users->at(i).data1 << "," << users->at(i).data2 << "," << users->at(i).data3 << "," << users->at(i).data4 << "\n";
			}
			file.close();
		}
	}

	void push_write_csv_vector(vector<forVector<string>>* p, string filename, T data1, T data2, T data3, T data4) {
		p->push_back(forVector<T>(data1, data2, data3, data4));

		ofstream file;
		file.open(filename, ofstream::app);
		if (file.is_open()) {
			file << data1 << "," << data2 << "," << data3 << "," << data4 << "\n";
			file.close();
		}
		file.close();
		cout << "\n" << data1 << " agregado!\n";
	}

	void addAllData() {
		cout << "Reading files, this may take a while . . . \n\n";

		read_csv_other(songs); // Linked list singer song genre
		read_csv_other(awards); // Xorlist award winner year
		//read_csv_other(sponsors); // Heaps name typeofcompany country
		read_csv_other(singers); // selfList name bestsong yearborn
		read_csv_other(podcasts); // Tree name genre duration
		read_csv_hash(playlists); //Author Name Album
		read_csv_vector(users, "Dependencies//user_list.csv"); // Vector username password recovery isBanned
		read_csv_vector(podcasters, "Dependencies//podcasters.csv"); // Vector name job yearborn country
		read_csv_vector(events, "Dependencies//events.csv"); // Vector Title Location Date Webpage
		cout << "\nAll datasets read successfully\n";
		system("PAUSE");
		system("CLS");
	}

	void printVector(vector<forVector<T>>* toPrint) {
		for (int i = 0; i < toPrint->size(); i++) {
			cout << "[" << toPrint->at(i).data1 << "," << toPrint->at(i).data2 << "," << toPrint->at(i).data3 << "," << toPrint->at(i).data4 << "]\n";
		}
	}


/*SEARCH*/
	void playSong(string song) {
		auto Song = songs->getNode(song);

		if (Song.data1 != "") {
			cout << "\nReproduciendo " << Song.data1 << "\nDe: " << Song.data2 << "\nGenero: " << Song.data3 << "\n...\n";
		}
		else
			cout << "La cancion " << song << " no existe\n";
	}

/*User login functions*/
	auto verifyExistUser(T data1) {
		struct Userdata {
			bool exist;
			uint id;
		};

		for (uint i = 0; i < users->size(); i++) {
			if (users->at(i).data1 == data1) {
				return Userdata{ true, i };
			}
		}
	}

	bool verifyLogin(T data1, T data2) {
		for (uint i = 0; i < users->size(); i++) {
			if (users->at(i).data1 == data1 && users->at(i).data2 == data2) {
				return true;
			}
		}
	}

	auto verifyRecov(T data1, T data3) {
		struct Credentials {
			bool verified;
			T data2;
		};

		for (uint i = 0; i < users->size(); i++) {
			if (users->at(i).data1 == data1 && users->at(i).data3 == data3) {
				return Credentials{ true , users->at(i).data2 };
			}
		}
	}

/*Admin Panel*/
	bool LogAdmin(T data1, T data2) {
		if (admin->getUsername() == data1 && admin->getPassword() == data2)
			return true;
	}

	Admin<T>* getAdmin() { return admin; }
	List<T>* getSongs() { return songs; }
	Xorlist<T>* getAwards() { return awards; }
	heaps<T>* getSponsors() { return sponsors; }
	selfList<T>* getSingers() { return singers; }
	hashMap<Playlist>* getPlaylists() { return playlists; }
	Tree<T>* getPodcasts() { return podcasts; }
	vector<forVector<T>>* getUsers() { return users; }
	vector<forVector<T>>* getPodcasters() { return podcasters; }
	vector<forVector<T>>* getEvents() { return events; }
};