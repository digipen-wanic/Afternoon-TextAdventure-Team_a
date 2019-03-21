/******************************************************************************
filename    FlashLightFunctions.c
author		Cody Spring
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "FuseFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void Fuse_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);
	printf("You have turned on your flashlight.\n");
	if (gameState->currentRoomIndex == 2)
	{
		//when entering room 2 something happens
		printf("");
	}
}
void Fuse_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	printf("You have picked up the fuse, which has a faint glow to it.\n");
}

/* Build a "exit door" object */
Item* Fuse_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("fuse", "An unbroken fuse.\n", true, Fuse_Use, Fuse_Take, NULL);
}