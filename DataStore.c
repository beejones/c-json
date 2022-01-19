#include "DataStore.h"

// Create films map
char initFilms[] = " {\
    \"2\": {\"title\": \"the matrix\"}, \
    \"1\": {\"title\": \"pulp fiction\"}, \
    \"3\": {\"title\": \"gremlins\"} \
    }\
";

// Print films map
void print()
{
    struct json_object *parsed_json = json_tokener_parse(initFilms);
    if (parsed_json == NULL) {
        printf("%s -> invalid json\n", initFilms);
        return;
    }
    struct json_object_iterator it = json_object_iter_init_default();
    it = json_object_iter_begin(parsed_json);
    struct json_object_iterator itEnd = json_object_iter_end(parsed_json);

    while (!json_object_iter_equal(&it, &itEnd))
    {
        printf("%s\n", json_object_iter_peek_name(&it));
        printf("%s\n", json_object_to_json_string(json_object_iter_peek_value(&it)));
        json_object_iter_next(&it);
    }
}

void insert(char *key, char *value)
{
    //films.insert(make_pair(key, value));
}

void del(char *key)
{
    //films.erase(key);
}

void update(char *key, char *value)
{
    //films[key] = value;
}
