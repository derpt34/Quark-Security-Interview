#ifndef CITY_LIST
#define CITY_LIST

typedef struct city {
  char *name;
  int time_diff;
  struct city *next;
} City;

typedef struct {
  City *largest; /* head node */
} City_list;

#endif
