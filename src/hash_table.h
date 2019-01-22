// Structure to hold a Key-Value pair.
typedef struct {
  char* key;
  char* value;
} ht_item;

typedef struct {
  int count;
  int size;
  ht_item** items;
} ht_hash_table;

// API's exposed by Hash Table
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
void ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);

