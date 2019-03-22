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
#include "Room.h"

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void Flashlight_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	int i;
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);
	printf("You have turned on your flashlight.\n");
	if (gameState->currentRoomIndex == 2)
	{
		Room* room;
		/*when entering room 2 something happens*/
		printf("Turning the corner you notice some of the boxes are really messed up and that area is much colder than the rest of the room. Curiosity takes the best of you and you slowly walk to the boxes. The airduct above you was broken and blowing cold air, You dont think much of it untill it starts to creak. The creaking slowly gets louder and almost closer. .....  ");
		gameState->mIsChasing = true;
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);;
		for(i = 1; i < 12; i++)
		{
			room = WorldData_GetRoom(worldData, i);
			if (i == 1)
			{
				Room_SetDescription(room, "You wake up in your room on the L. Selene, a space ship headed to colonize a distant galaxy.\nYou notice that the lights are dimmer than usual, and that everything has fallen onto the floor.\nThere are multiple broken fuses and a single unbroken one on the floor along with a flashlight. The only thing that didn't fall was your prized posession, hang in there kitten poster.\nThe door to your room is slightly open and you see that there are no lights on in the hallway. \nYou're being chased\n");
			}
			else if (i == 2)
			{
				Room_SetDescription(room, "You enter a dark room and can only faintly see boxes filling the room. You attempet to walk further into the room but step on a small gear. This feels like stepping on a lego, but metal, and very cold. You dont dare go any farther without a light. \nYou're being chased\n");
			}
			else if (i == 3)
			{
				Room_SetDescription(room, "Standing at the end of the hallway you see the room you started in on your right. \nFarther on your right you see the Workroom \nOn your left you see the Capton's room \nFarther on your right you see the elevator room \nAt the end of the hall you see the air lock. \nYou're being chased \n");
			}
			else if (i == 4)
			{
				Room_SetDescription(room, "The medbay has paper scattered about. Documentation from everyone who was on board and the intended plans of colonization. \nThere is a medkit on the ground\nYou're being chased");
			}
			else if (i == 5)
			{
				Room_SetDescription(room,
			}
			else if (i == 6)
			{
				Room_SetDescription(room, "as you enter the airlock you notice the lever is still in a functing state and there is a handle next to it that is also undamaged.\n you see the doors/exits are on the north and south\nYou're being chased\n");
			}
			else if (i == 7)
			{
				Room_SetDescription(room, "A fairly large lounge with a set of tables, chairs, and TVs.\nReally just a standard relaxation area. There are three doors in the room, two go to the engine bays and one to the air lock.\nYou're being chased\n");
			}
			else if (i == 8)
			{
				Room_SetDescription(room, 
			}
			else if (i == 9)
			{
				Room_SetDescription(room, "As you enter the right engine room you notice the engine has a broken quantum carborator and the tools to fix it are not in the room\n you will need to go to the forwad bay and pickup the replacement quantum carborator and your tools are in the other engine room\n fixing the engine is of the upmost importance\nYou're being chased\n");
			}
			else if (i == 10)
			{
				Room_SetDescription(room, "as you enter the right engine you see that the engine is in working order and only has to be turned back on\n you also notice that your tools are in the closet along the far wall\n you will need these to fix the left engine\nYou're being chased\n"); "
			}
			else if (i == 11)
			{
					Room_SetDescription(room,
			}
		}

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