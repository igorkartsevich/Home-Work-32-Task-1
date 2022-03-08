#include <iostream>
#include <fstream>
#include "Home-Work-32-Task-1.h"
#include "nlohmann/json.hpp"

struct Film
{
	std::string name;
	std::string country;
	int year;
	std::string producer;
	std::string director;
	std::string writer;
	std::string maleStar;
	std::string femaleStar;
	int duration_min;
	int boxOffice_world;
};

int main()
{
	nlohmann::json filmWrite = {
		{ "Name: ", "Terminator 2" },
		{ "Country: ", "USA" },
		{ "Year: ", 1994 },
		{ "Producer: ", "Stefany Ostin, James Cameron" },
		{ "Director: ", "James Cameron" },
		{ "Writer: ", "James Cameron, William Wisher" },
		{ "Male Star: ", "Arnold Schwarzenegger" },
		{ "Female Star: ", "Linda Hamilton" },
		{ "Duration: ", 137 },
		{ "Box office: ", 516950043 }
	};

	std::ofstream FileWrite("record.json");
	if (FileWrite.is_open()) {
		FileWrite << filmWrite;
	}
	FileWrite.close();

	std::ifstream FileRead("record.json");
	nlohmann::json filmRead;
	if (FileRead.is_open()) {
		FileRead >> filmRead;
	}
	FileRead.close();

	Film film;
	film.name = filmRead["Name: "];
	film.country = filmRead["Country: "];
	film.year = filmRead["Year: "];
	film.producer = filmRead["Producer: "];
	film.director = filmRead["Director: "];
	film.writer = filmRead["Writer: "];
	film.maleStar = filmRead["Male Star: "];
	film.femaleStar = filmRead["Female Star: "];
	film.duration_min = filmRead["Duration: "];
	film.boxOffice_world = filmRead["Box office: "];

	std::cout << film.name << " " << film.country << " " << film.year << std::endl << film.producer << " " << film.director << " " << film.writer << std::endl << film.maleStar << " " << 
		film.femaleStar << std::endl << film.duration_min << " " << film.boxOffice_world << std::endl;

	return 0;
}
