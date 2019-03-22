/******************************************************************************
filename    FlashLightFunctions.c
author		Cody Spring
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "KeyFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void Key_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	if (gameState->currentRoomIndex == 5)
	{
		/*when entering room 2 something happens*/
		printf("You use the keycard on the elevator and it starts to move upwards.\n");

		gameState->currentRoomIndex = 11;
	}
	else
	{
		printf("You have nothing to use this on yet.\n");
	}
}
void Key_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	printf("You have picked up the keycard, which has been scratched many times.\n");
}

/* Build a "exit door" object */
Item* Key_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("keycard", "A small keycard used to unlock something.\n", true, Key_Use, Key_Take, NULL);
}