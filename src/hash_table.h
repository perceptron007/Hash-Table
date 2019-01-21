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