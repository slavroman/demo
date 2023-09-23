#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using ordered_json = nlohmann::ordered_json;

struct PersonInfo
{
	std::string name;
	std::string surname;
	std::string character;
};

struct MovieInfo
{
	std::string title;
	std::string country;
	std::string date;
	std::string studio;
	std::string writtenBy;
	std::string directedBy;
	std::string producer;
	std::vector<PersonInfo> topCast;
};

class MovieCard
{
public:
	MovieCard();
	~MovieCard();

	void addEntry();
	void printMovieCard();
	void setMovieInfo(const MovieInfo& obj);
	MovieInfo getMovieInfo();

private:
	PersonInfo person;
	MovieInfo movie;
};

MovieCard::MovieCard()
{
}

MovieCard::~MovieCard()
{
}

void MovieCard::addEntry()
{
	std::cout << "Please input movie title\n";
	getline(std::cin, movie.title);

	std::cout << "Please input movie country\n";
	getline(std::cin, movie.country);

	std::cout << "Please input movie date\n";
	getline(std::cin, movie.date);

	std::cout << "Please input movie studio\n";
	getline(std::cin, movie.studio);

	std::cout << "Please input \"written by\" of the movie\n";
	getline(std::cin, movie.writtenBy);

	std::cout << "Please input director of the movie\n";
	getline(std::cin, movie.directedBy);

	std::cout << "Please input producer of the movie\n";
	getline(std::cin, movie.producer);

	std::string line{};

	do
	{
		std::cout << "Please input actor's name and family\n";
		std::cin >> person.name >> person.surname;

		std::cin.ignore();

		std::cout << "Please input character\n";
		getline(std::cin, person.character);

		movie.topCast.push_back(person);

		std::cout << "Want to add another person (y/n)?\n";
		std::cin >> line;

		std::cin.ignore();

	} while (line != "n");
}

void MovieCard::printMovieCard()
{
	std::cout << "\t\t+---------------------+\n"
		      << "\t\t| The Movie Card Info |\n"
		      << "\t\t+---------------------+\n";
	std::cout << "       Title:\t" << movie.title << '\n';
	std::cout << "     Country:\t" << movie.country << '\n';
	std::cout << "        Date:\t" << movie.date << '\n';
	std::cout << "      Studio:\t" << movie.studio << '\n';
	std::cout << "  Written by:\t" << movie.writtenBy << '\n';
	std::cout << "Directed by :\t" << movie.directedBy << '\n';
	std::cout << "   Producer :\t" << movie.producer << '\n';
	std::cout << "\t\tTop cast:\n";

	for (const auto& it : movie.topCast)
	{
		std::cout << "\t" << it.name << ' ' << it.surname << " (" << it.character << ")\n";
	}

	std::cout << '\n';
}

void MovieCard::setMovieInfo(const MovieInfo& obj)
{
	movie.title = obj.title;
	movie.country = obj.country;
	movie.date = obj.date;
	movie.studio = obj.studio;
	movie.writtenBy = obj.writtenBy;
	movie.directedBy = obj.directedBy;
	movie.producer = obj.producer;

	for (const auto& it : obj.topCast)
	{
		movie.topCast.push_back(it);
	}
}

MovieInfo MovieCard::getMovieInfo()
{
	return movie;
}

void to_json(ordered_json& j, const PersonInfo& person);
void to_json(ordered_json& j, const MovieInfo& movie);
void from_json(const ordered_json& j, PersonInfo& person);
void from_json(const ordered_json& j, MovieInfo& movie);
void saveToFile(ordered_json& j);
void readFromFile(ordered_json& j);
void searchInJson(ordered_json& j);
void printMovieCardJson(ordered_json& j);

int main()
{
	std::cout << "Task 2.\n";	

	ordered_json databaseJson;

	std::string line{};
	int select = -1;

	while (select)
	{
		std::cout << "\nWhat do you want to do?\n"
			      << "1 - Add movie\n"
			      << "2 - Save file\n"
			      << "3 - Open file\n"
			      << "4 - Search actor\n"
				  << "5 - Print json\n"
			      << "0 - Exit\n\n";

		std::cin >> select;

		switch (select)
		{
		case 1:
			do
			{
				MovieCard movieCard;

				movieCard.addEntry();

				ordered_json obj = movieCard.getMovieInfo();

				databaseJson.push_back(obj);

				std::cout << "Would you like add another movie (y/n)?\n";
				std::cin >> line;

				std::cin.ignore();

			} while (line != "n");
			break;
		case 2:
			saveToFile(databaseJson);
			break;
		case 3:
			readFromFile(databaseJson);
			break;
		case 4:
			searchInJson(databaseJson);
			break;
		case 5:
			printMovieCardJson(databaseJson);
			break;
		}

	}	

	/*std::vector<MovieCard> database;
		
	for (auto& it : databaseJson)
	{		
		auto tempMovieInfo = it.get<MovieInfo>();

		MovieCard tempMovieCard;

		tempMovieCard.setMovieInfo(tempMovieInfo);

		database.push_back(tempMovieCard);
	}*/
	
	//print use class MovieCard
	/*for (auto& val : database)
	{
		val.printMovieCard();
	}*/
	
	return 0;
}

void to_json(ordered_json& j, const PersonInfo& person)
{
	j = ordered_json
	{
		{"name", person.name},
		{"surname", person.surname},
		{"character", person.character}
	};
}

void to_json(ordered_json& j, const MovieInfo& movie)
{
	j = ordered_json
	{
		{"title", movie.title},
		{"country", movie.country},
		{"date", movie.date},
		{"studio", movie.studio},
		{"written_by", movie.writtenBy},
		{"directed_by", movie.directedBy},
		{"producer", movie.producer},
		{"top_cast", movie.topCast}
	};
}

void from_json(const ordered_json& j, PersonInfo& person)
{
	j.at("name").get_to(person.name);
	j.at("surname").get_to(person.surname);
	j.at("character").get_to(person.character);

}

void from_json(const ordered_json& j, MovieInfo& movie)
{
	j.at("title").get_to(movie.title);
	j.at("country").get_to(movie.country);
	j.at("date").get_to(movie.date);
	j.at("studio").get_to(movie.studio);
	j.at("written_by").get_to(movie.writtenBy);
	j.at("directed_by").get_to(movie.directedBy);
	j.at("producer").get_to(movie.producer);
	j.at("top_cast").get_to(movie.topCast);
}

void saveToFile(ordered_json& j)
{
	std::ofstream out("moviedb.json", std::ios::app);

	if (out.is_open())
	{
		out << std::setw(4) << j << std::endl;

		out.close();
	}
	else
	{
		std::cout << "Error save file!\n";
	}	
}

void readFromFile(ordered_json& j)
{
	std::ifstream in("moviedb.json");

	if (in.is_open())
	{
		in >> j;

		in.close();
	}
	else
	{
		std::cout << "Error open file!\n";
	}	
}

void searchInJson(ordered_json& j)
{
	ordered_json resultJson{};	
	std::string actor{};

	std::cout << "Please enter actor's name or surname for search:\n";
	std::cin >> actor;

	for (const auto& obj : j)
	{
		for (const auto& elem : obj["top_cast"])
		{
			if (elem["name"] == actor || elem["surname"] == actor)
			{				
				std::string name = elem["name"].get<std::string>();
				std::string surname = elem["surname"].get<std::string>();
				std::string character = elem["character"].get<std::string>();
				std::string title = obj["title"].get<std::string>();

				std::string resultStar = name + ' ' + surname;
				std::string resultMovieAndCharacter = title + " (" + character + ')';

				if (resultJson.contains("star"))
				{
					resultJson["movies"].push_back(resultMovieAndCharacter);
				}
				else
				{
					resultJson["star"] = resultStar;
					resultJson["movies"].push_back(resultMovieAndCharacter);
				}				

				/*std::cout << elem["name"] << " " << elem["surname"] << '\n'
							<< obj["title"] << " (" << elem["character"] << ") << "\n";*/								
			}			
		}
	}

	(resultJson.empty()) ? std::cout << "Actor not found!\n" : std::cout << resultJson.dump(4) << '\n';	
}

void printMovieCardJson(ordered_json& j)
{
	for (auto& valJson : j)
	{
		std::cout << "\t\t+---------------------+\n"
				  << "\t\t| The Movie Card Info |\n"
				  << "\t\t+---------------------+\n"
			      << valJson.dump(4) << "\n";
	}
}
