/*
 * Menu.c
 *
 *  Created on: 4 oct. 2016
 *      Author: Julien
 */

#include "Menu.h"
#include "string.h"
#include "stdio.h"

typedef struct Menu_item_s
{
	char name[MENU_MAX_ITEM_NAME_SIZE];
	func_ptr func;

} Menu_item;

static Menu_item menu_items[MENU_MAX_ITEM_COUNT];

static uint8_t menu_item_count = 0;

void Menu_init(const char* menu_title)
{
	strcpy(menu_items[0].name, menu_title);
	menu_items[0].func = NULL;
	menu_item_count++;
}

void Menu_add_item(const char* item_name, func_ptr function)
{
	strcpy(menu_items[menu_item_count].name, item_name);
	menu_items[menu_item_count].func = function;
	menu_item_count++;
}

void Menu_print(void)
{
	//puts("\033[2J");
	//puts("\033[0;0H");

	printf("%s\n\r", menu_items[0].name);

	for(int i = 1 ; i < menu_item_count ; i++)
	{
		printf("%d : %s\n\r", i, menu_items[i].name);
	}

	puts("?\n\r");
}

void Menu_choose(uint8_t item_number)
{
	if(item_number >= menu_item_count || item_number == 0)
		return;

	if(menu_items[item_number].func != NULL)
		menu_items[item_number].func();
}
