/* (c) Daniel Levi Guise, 2017. */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world-times-datastructure.h"
#include "world-times.h"

#define SEC_IN_HOUR 3600

#define GET_TIME(time, seconds, diff) ((time) + ((seconds) * (diff)))

int main(void) {
  time_t curr_time = time(NULL);

  /* creates a new city list */
  City_list city_list;
  create_list(&city_list);

  if (curr_time != -1) {
    printf("\nLarge cities in order by population, with local time(hours:minutes:seconds):\n\n");
    
    /* These add_city calls can be edited/removed to change the list */
    add_city(&city_list, "New York", 0);
    add_city(&city_list, "Sao Paulo", 2);
    add_city(&city_list, "Seoul", 14);
    add_city(&city_list, "Mexico City", -1);
    add_city(&city_list, "Osaka", 14);
    add_city(&city_list, "Manila", 13);
    add_city(&city_list, "Jakarta", 12);
    add_city(&city_list, "Lagos", 6);
    add_city(&city_list, "Los Angeles", -3);

    /* Call to print the list */
    print_list(&city_list, curr_time);
  } else {
    printf("Time error: PROGRAM ABORT");
  }
  return 0;
}

/* Method that initializes the city list; always starts with Tokyo,
   the largest city in the world (for parity). */
void create_list(City_list *head) {
  head->largest = malloc(sizeof(City));
  head->largest->name = malloc(sizeof(char)*6); /* 5 + 1 to include NULL terminator */
  strcpy(head->largest->name, "Tokyo");
  head->largest->time_diff = 14; /* Tokyo is 14 hours ahead of us in Maryland */
  head->largest->next = NULL;
}

/* Basic insert method for the city list */
void add_city(City_list *city_list, const char arg_name[], int time_diff) {
  /* Double pointer used to actually affect the list structure */
  City **head = NULL, *city_to_add = NULL;

  head = &(city_list->largest);

  city_to_add = malloc(sizeof(*city_to_add));
  city_to_add->name = malloc(sizeof(strlen(arg_name) + 1));
  strcpy(city_to_add->name, arg_name);
  city_to_add->time_diff = time_diff;
  city_to_add->next = NULL;

  /* Iterates through the list; O(n), but could be ~O(1) if I kept a "current"
     node in my data structure */
  while ((*head)->next != NULL) {
    head = &((*head)->next);
  }
  (*head)->next = city_to_add;
}

/* Method that prints the current contents of the initialized list structure */
void print_list(City_list *city_list, time_t curr_time) {
  City *temp = city_list->largest;
  time_t temp_time;
  char *temp_s;
  char *time_str = malloc(sizeof(char)*9);
  
  while (temp != NULL) {
    /* Gets local time of computer */
    temp_time = GET_TIME(curr_time, SEC_IN_HOUR, temp->time_diff);
    /* Converts local time to string format */
    temp_s = ctime(&temp_time);
    strncpy(time_str, temp_s + 11, 8); /* C doesn't have regex? */
    
    printf("Current time in %s is: %s\n", temp->name, time_str);

    temp = temp->next;
  }
  printf("\n");
}
