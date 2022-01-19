#include "DataStore.h"

// Create films map
std::map<char *, json> films{{"2", {"title", "the matrix"}}, {"1", {"title", "pulp fiction"}}, {"3", {"title", "gremlins"}}};
//json j_films(films);

extern "C"
{

    // Print films map
    void print()
    {
        std::cout << "----------------------------\n";
        for (auto it = films.begin(); it != films.end(); ++it)
        {
            std::cout << it->first << " : " << it->second << "\n";
        }
    }

    void insert(char *key, json value)
    {
        films.insert(make_pair(key, value));
    }

    void del(char *key)
    {
        films.erase(key);
    }

    void update(char *key, json value)
    {
        films[key] = value;
    }

    json search(char *key)
    {
        return films[key];
    }
}