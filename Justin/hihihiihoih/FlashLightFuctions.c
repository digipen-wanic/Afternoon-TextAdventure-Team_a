/******************************************************************************
filename    FlashLightFunctions.c
author		Cody Spring
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "FlashLightFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void Flashlight_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);
	printf("You have turned on your flashlight.\n");
	if (gameState->currentRoomIndex == 2)
	{
		/*when entering room 2 something happens*/
		printf("Turning the corner you notice some of the boxes are really messed up and that area is much colder than the rest of the room.\n Curiosity takes the best of you and you slowly walk to the boxes. \n The airduct above you was broken and blowing cold air, You dont think much of it untill it starts to creak. \n The creaking slowly gets louder. \n You point the flashlight up just intime to see a burgundy colered creature fall from the vent and land behind boxes. \n Your heart beats harder and harder in your chest as you crouch down to hide. \n You cant stay here and must go to the deck to call for help. \n You manage to sneak closer to the door but the creature is just to the left of it, you are going to have to run for the door.\n ");
	}
}
void Flashlight_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	printf("You have picked up the flashlight.\n");
}

/* Build a "exit door" object */
Item* Flashlight_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("flashlight", "An old flashlight.\n", true, Flashlight_Use, Flashlight_Take, NULL);
}