/******************************************************************************
filename    BrickFunctions.c
author      Matthew Picioccio and modified and changed by Ofer Krupka
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "keycard".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "KeycardFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the keycard is taken. */
void Keycard_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the keycard might be used, whenever it is picked up. */
	printf("This keycard is probebly used to open or to enable something.\n");
}


/* Helper: The action performed when the keycard is used. */
void Keycard_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* keycard; /* The keycard in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the keycard out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the keycard - inform the user of the problem and take no action */
		printf("You must have the keycard before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 5/*Elevator*/)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the keycard here.\n");
		return;
	}

	/*check if the keycard is in the elevator's keycard reader*/
	if (GameFlags_IsInList(gameState->gameFlags, "keycardInElevatorScored"))
	{
		/* the player already used the keycard - inform the user of the problem and take no action */
		printf("You already put the keycard in the keycard reader, the elevator is enabled.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the keycard in the player's inventory - it should be there, since we are in the Inventory context */
		keycard = ItemList_FindItem(gameState->inventory, "keycard");

		/* Remove the keycard from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, keycard);

		/* Tell the user what they did */
		printf("You put the keycard in the keycard ready, now you can use the elevator\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 5);
		
		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "Welcome to the elevator, your keycard is in the keycard reader and the elevator is enabled.\n south - bridge [2nd floor]\n west - main hallway [1st floor]\n\n");
		
		/* Update the room exits */
		Room_AddRoomExit(room, "south", 11/*Bridge*/);
		Room_AddRoomExitShortcut(room, "s", 11);

		/* Add keycard to the current room */
		*roomItemsPtr = ItemList_Add(*roomItemsPtr, Keycard_Build());

		/* update the game flags */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "keycardInElevatorScored");
	}
}


/* Build a "keycard" object */
Item* Keycard_Build()
{
	/* Create a "keycard" item, using the functions defined in this file */
	return Item_Create("keycard", "White keycard with a spaceship icon", true, Keycard_Use, Keycard_Take, NULL);
}