#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

//using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

struct Person;

struct MovieCard
{
	std::string Title;
	std::string Country;
	std::string Date;
	std::string Studio;
	std::string Screenwriter;
	std::string Director;
	std::string Producer;
	std::vector<Person> TopCast;
};

struct Person
{
	std::string Star;
	std::string Character;
};

void addEntry(ordered_json& j);
void to_json(ordered_json& j, const Person& person);
void to_json(ordered_json& j, const MovieCard& movie);
void writeToFile(ordered_json& j);
void readFromFile(ordered_json& j);

void printMovieCard(const MovieCard& movie);

int main()
{
	std::cout << "Task 1.\n";

	ordered_json j;	

	addEntry(j);
	
	writeToFile(j);

	return 0;
}

void addEntry(ordered_json& j)
{
	MovieCard movie;
	Person person;
	
	std::cout << "Please input movie title\n";
	getline(std::cin, movie.Title);
	
	std::cout << "Please input movie country\n";
	getline(std::cin, movie.Country);
	
	std::cout << "Please input movie date\n";
	getline(std::cin, movie.Date);
		
	std::cout << "Please input movie studio\n";
	getline(std::cin, movie.Studio);
	
	std::cout << "Please input screenwriter of the movie\n";
	getline(std::cin, movie.Screenwriter);
	
	std::cout << "Please input director of the movie\n";
	getline(std::cin, movie.Director);
	
	std::cout << "Please input producer of the movie\n";
	getline(std::cin, movie.Producer);
	
	std::string line{};

	do
	{
		std::cout << "Please input actor of the movie\n";
		getline(std::cin, person.Star);		

		std::cout << "Please input role\n";
		getline(std::cin, person.Character);		

		movie.TopCast.push_back(person);		

		std::cout << "Do you want add a star (y/n)?\n";
		std::cin >> line;

		std::cin.ignore();

	} while (line != "n");
	
	//printMovieCard(movie); // uncomment for debug

	to_json(j, movie);
	
}

void to_json(ordered_json& j, const Person& person)
{
	j = ordered_json
	{
		{"Star", person.Star},
		{"Character", person.Character}
	};
}

void to_json(ordered_json& j, const MovieCard& movie)
{
	j = ordered_json
	{
		{"Title", movie.Title},
		{"Country", movie.Country},
		{"Date", movie.Date},
		{"Studio", movie.Studio},
		{"Screenwriter", movie.Screenwriter},
		{"Director", movie.Director},
		{"Producer", movie.Producer},
		{"TopCast", movie.TopCast}
	};
}

void writeToFile(ordered_json& j)
{
	std::ofstream out("base.json");

	if (out.is_open())
	{
		out << j;
	}

	out.close();
}

void readFromFile(ordered_json& j)
{
	std::ifstream in("base.json");

	if (in.is_open())
	{
		in >> j;
	}

	in.close();
}

void printMovieCard(const MovieCard& movie)
{
	std::cout << "The Movie Card:\n";
	std::cout << "===============\n";
	std::cout << "Title: " << movie.Title << '\n';
	std::cout << "Country: " << movie.Country << '\n';
	std::cout << "Date: " << movie.Date << '\n';
	std::cout << "Studio: " << movie.Studio << '\n';
	std::cout << "Screenwriter: " << movie.Screenwriter << '\n';
	std::cout << "Director : " << movie.Director << '\n';
	std::cout << "Producer : " << movie.Producer << '\n';
	std::cout << "TopCast :\n";

	for (const auto& it : movie.TopCast)
	{
		std::cout << "\t" << it.Star << " (" << it.Character << ")\n";
	}
	
	std::cout << '\n';
}

