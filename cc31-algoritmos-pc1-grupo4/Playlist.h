#pragma once

#include"Lib.h"

struct Playlist {
	int id;
	string name;
	string author;
	string album;
	Playlist* next;
	Playlist(int _id, string _name, string _author, string _album) {
		id = _id;
		name = _name;
		author = _author;
		album = _album;
		next = nullptr;
	}
};