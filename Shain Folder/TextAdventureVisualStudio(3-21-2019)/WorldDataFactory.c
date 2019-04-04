/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "GameState.h"
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */
#include "MEDKITFunctions.h" /* MEDKIT_Build */
#include "FlashLightFunctions.h" //Fuse_Build



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

Room* Room1_Build_StartArea()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("You wake up in your room on the L. Selene, a space ship headed to colonize a distant galaxy.\nYou notice that the lights are dimmer than usual, and that everything has fallen onto the floor.\nThere are multiple broken fuses and a single unbroken one on the floor along with a flashlight. The door to your room is slightly open and you see that there are no lights on in the hallway.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "door", 3);  /* 1 = the room index this exit connects to */
										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Fuse_Build());

	/* Return the new room */
	return room;
}

Room* Room2_Build_ForwardBay()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

Room* Room3_BuildMainHallway()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* if you are injured when you entered the room you lose some of your health */


	/* Create the room
	include an initial room description */
	room = Room_Create("Standing at the end of the hallway you see the room you started in on your right. \nFarther on your right you see the Workroom \nOn your left you see the Capton's room \nFarther on your right you see the elevator room \nAt the end of the hall you see the air lock \n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "starting room", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */

	/* Return the new room */
	return room;
}
Room* Room4_BuildMedbay()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("The medbay has paper scattered about. Documentation from everyone who was on board and the intended plans of colonization. \nThere is a medkit on the ground\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "door", 3);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "hallway", 3);
										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), MEDKIT_Build());

	/* Return the new room */
	return room;
}

Room* Room5_Build_ElevatorRoom()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

/* TODO REQUIRED: Build room 6 */
Room* Room6_Build_AirLock()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 6. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */

	room = Room_Create("as you enter the airlock you notice the lever is still in a functing state and there is a handle next to it that is also undamaged.\n you see the doors/exits are on the north and south\n");

	/* TODO REQUIRED: Add an Exit "north" to Room 3 and 7 */

	Room_AddRoomExit(room, "north", 3);
	Room_AddRoomExit(room, "south", 7);

	/* TODO BASIC: Add room exit shortcut for "n" */

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */

	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}

Room* Room7_Build_Lounge()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

Room* Room8_Build_CaptainsRoom()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

/* TODO REQUIRED: Build room 9 */
Room* Room9_BuildEngineRoom1()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */

	room = Room_Create("As you enter the right engine room you notice the engine has a broken quantum carborator and the tools to fix it are not in the room\n you will need to go to the forwad bay and pickup the replacement quantum carborator and your tools are in the other engine room\n fixing the engine is of the upmost importance\n");

	/* TODO REQUIRED: Add an Exit to Room 7 */

	Room_AddRoomExit(room, "east", 7);

	Room_AddRoomExitShortcut(room, "e", 7);

	/* TODO REQUIRED: Add a brick to the list of items in the room */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Room10_BuildEngineRoom2()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */

	room = Room_Create("as you enter the right engine you see that the engine is in working order and only has to be turned back on\n you also notice that your tools are in the closet along the far wall\n you will need these to fix the left engine");

	/* TODO REQUIRED: Add an Exit "east" to Room 7 */

	Room_AddRoomExit(room, "west", 7);

	Room_AddRoomExitShortcut(room, "w", 7);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}

Room* Room11_BuildTheBridge()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}


/* TODO ADVANCED: Build room 3 */
/* TODO ADVANCED: Build room 4 */


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 1;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* TODO REQUIRED: add rooms to the world data */
	WorldData_SetRoom(worldData, 1, Room1_Build_StartArea);
	WorldData_SetRoom(worldData, 2, Room2_Build_ForwardBay);
	WorldData_SetRoom(worldData, 3,	Room3_BuildMainHallway);
	WorldData_SetRoom(worldData, 4, Room4_BuildMedbay);
	WorldData_SetRoom(worldData, 5, Room5_Build_ElevatorRoom);
	WorldData_SetRoom(worldData, 6, Room6_Build_AirLock);
	WorldData_SetRoom(worldData, 7, Room7_Build_Lounge);
	WorldData_SetRoom(worldData, 8, Room8_Build_CaptainsRoom);
	WorldData_SetRoom(worldData, 9, Room9_BuildEngineRoom1);
	WorldData_SetRoom(worldData, 10, Room10_BuildEngineRoom2);
	WorldData_SetRoom(worldData, 11, Room11_BuildTheBridge);

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}