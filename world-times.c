/* (c) Daniel Levi Guise, 2017. */

/* TODO: 
   -fix time zone issue
   -fix printing issue (weird symbol?)
   -add more methods? (OPTIONAL)
*/

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

  City_list city_list;
  create_list(&city_list);

  if (curr_time != -1) {
    printf("Large cities ranked by population with current time.");

    /* These add_city calls can be edited/removed to change the list */
    add_city(&city_list, "New York, US", 0);
    add_city(&city_list, "Sao Paulo, Brazil", 2);
    add_city(&city_list, "Seoul, South Korea", 14);
    add_city(&city_list, "Mexico City, Mexico", -1);
    add_city(&city_list, "Osaka, Japan", 14);
    add_city(&city_list, "Manila, Philippines", 13);
    add_city(&city_list, "Jakarta, Indonesia", 12);
    add_city(&city_list, "Lagos, Nigera", 6);
    add_city(&city_list, "Los Angeles, US", -3);
    
    print_list(&city_list, curr_time);
  } else {
    printf("Time error: PROGRAM ABORT");
  }
  return 0;
}

/* Always starts with Tokyo, the largest city in the world */
void create_list(City_list *head) {
  head->largest = malloc(sizeof(head->largest));
  head->largest->name = malloc(sizeof(char)*6);
  strcpy(head->largest->name, "Tokyo");
  head->largest->time_diff = 14;
  head->largest->name = NULL;
}

/* Basic insert method for the city list */
void add_city(City_list *city_list, const char arg_name[], int time_diff) {
  City **head = NULL, *city_to_add = NULL;

  head = &(city_list->largest);

  city_to_add = malloc(sizeof(*city_to_add));
  city_to_add->name = malloc(sizeof(strlen(arg_name) + 1));
  city_to_add->name = strcpy(city_to_add->name, arg_name);
  city_to_add->next = NULL;

  while ((*head)->next != NULL) {
    head = &((*head)->next);
  }
  (*head)->next = city_to_add;
}

void print_list(City_list *city_list, time_t curr_time) {
  City *temp = city_list->largest;
  
  while (temp != NULL) { 

    /* need to convert time zones */
    printf("Current time in %s is: %s", temp->name, ctime(&curr_time));

    temp = temp->next;
  }
}
