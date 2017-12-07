//
//  linked-list.c
//  linked-list
//
//  Created by Shana Moore on 12/6/17.
//  Copyright © 2017 Shana Moore. All rights reserved.
/* 1. Create a C program that implements
 a Linked List of at 4 structs w the following: 
 Model, Price, Miles, pointer.
 2. Remember to use the strcpy function
 from the string.h library to copy any
 strings into fields of the structure.
 3. Load the nodes with values from the
 keyboard. (loading the actual nodes can
 be with code or interactively).
 4. Link the nodes together and provide a
 function to “traverse” the list and printing
 the contents of the nodes on the
 screen.
 5. Create a function to find the average
 price of all cars and the total miles driven
 in all cars.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declare struct
typedef struct node_s {
    char model[10];
    double price;
    double miles;
    struct node_s *next;
} node_t;

// prototype functions
void print_list(node_t *head_p);
void print_stats(node_t *head_p);

int main(void) {
    // declare variables with appropriate data type
    node_t *car1_p, *car2_p, *car3_p, *car4_p;
    
    // allocate and intialize data components of 4 nodes
    car1_p = (node_t *)malloc(sizeof(node_t));
    strcpy(car1_p->model, "56 Ford");
    car1_p->price = 500;
    car1_p->miles = 23000;
    
    car2_p = (node_t *)malloc(sizeof(node_t));
    strcpy(car2_p->model, "64 Impala");
    car2_p->price = 1800;
    car2_p->miles = 12000;
    
    car3_p = (node_t *)malloc(sizeof(node_t));
    strcpy(car3_p->model, "57 Ford");
    car3_p->price = 1400;
    car3_p->miles = 22000;
    
    car4_p = (node_t *)malloc(sizeof(node_t));
    strcpy(car4_p->model, "65 Galaxy");
    car4_p->price = 2600;
    car4_p->miles = 48000;
    
    // connect nodes
    car1_p->next = car2_p;
    car2_p->next = car3_p;
    car3_p->next = car4_p;
    car4_p->next = NULL;
    
    // output to screen
    print_list(car1_p);
    print_stats(car1_p);
    
    return 0;
}

void print_list(node_t *headp){
    if(headp == NULL){
        printf("\n");
    } else {
        printf("Car: %s, Price: %.2lf, I drove it: %.0lf\n", headp->model, headp->price, headp->miles);
        print_list(headp->next);
    }
}

void print_stats(node_t *headp){
    int total_miles = 0;
    double avg_price = 0;
    
    if(headp == NULL){
        printf("\n");
    }
    
    while (headp != NULL){
        total_miles += headp->miles;
        avg_price += headp->price;
        headp = headp->next;
    }
    
    avg_price = avg_price / 4;
    printf("The Total Miles: %.0d\nThe average price was: %.2lf\n", total_miles, avg_price);
}
