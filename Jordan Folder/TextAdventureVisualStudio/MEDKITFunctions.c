/******************************************************************************
filename    ExitDoorFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "MEDKITFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;

/* Jordan */

/* Helper: The action performed when the exit door is used. */
void MEDKIT_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);
	if (gameState->isInjured == true)
	{
		printf("You have healed yourself");
		gameState->isInjured = false;
	}

}

void MEDKIT_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);


}

/* Build a "exit door" object */
Item* MEDKIT_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("MEDKIT", "You see a medkit with some bandages inside. Could come in handy in a pinch\n", false, MEDKIT_Use, MEDKIT_Take, NULL);
}