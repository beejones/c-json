#include "DataStore.h"

// Create films map
char initFilms[] = " {\
    \"2\": {\"title\": \"the matrix\"}, \
    \"1\": {\"title\": \"pulp fiction\"}, \
    \"3\": {\"title\": \"gremlins\"} \
    }\
";

static struct json_object *films = NULL;

int mapInit()
{
    films = json_tokener_parse(initFilms);
    return 1;
}


// Print films map
void mapPrint()
{
    if (films == NULL) 
    {
        printf("Run mapInit() first\n");
        return;
    }

    struct json_object_iterator it = json_object_iter_init_default();
    it = json_object_iter_begin(films);
    struct json_object_iterator itEnd = json_object_iter_end(films);

    printf("------------------------------------\n");

    while (!json_object_iter_equal(&it, &itEnd))
    {
        printf("%s: ", json_object_iter_peek_name(&it));
        printf("%s\n", json_object_to_json_string(json_object_iter_peek_value(&it)));
        json_object_iter_next(&it);
    }
}

// Insert element into map
void mapInsert(const char *key, const char *value)
{
   if (films == NULL) 
    {
        printf("Run mapInit() first\n");
        return;
    }

    auto obj = json_tokener_parse(value);
    if (obj == NULL) 
    {
        printf("%s is no valid json\n", value);
        return;
    }
    json_object_object_add(films, key, obj);
}

void mapDeleteItem(const char *key)
{
   if (films == NULL) 
    {
        printf("Run mapInit() first\n");
        return;
    }
    json_object_object_del(films, key);
}

void mapUpdate(const char *key, const char *value)
{
  mapInsert(key, value);
}
