/* (c) Daniel Levi Guise, 2017. */

#include "world-times-datastructure.h"

/* Prototypes */
void create_list(City_list *head);
void add_city(City_list *city_list, const char arg_name[], int time_diff);
void print_list(City_list *city_list, time_t curr_time);
