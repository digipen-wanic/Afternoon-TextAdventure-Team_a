/**********************************************************
File Name: ToolBoxFunctions.h
by: Shain Allen
last edited: 3/21/2019
brief: this is the ToolBox that is needed to fix the engine
***********************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BrickFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "ToolBoxFunctions.h" /* Egg_Build */
#include "QuantumCarburetorFunctions.h"

/* Helper: The action performed when the ToolBox is taken. */
void ToolBox_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("The ToolBox is as heavy as ever, and still has everything in it that an enginer of your caliper would need.\n");
}

void ToolBox_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);
	Item* qCarb;
	qCarb = ItemList_FindItem(gameState->inventory, "quantum carburetor");
	if (gameState->currentRoomIndex == 9 && qCarb != NULL)
	{
		gameState->engineWorking = true;
		printf("the quantum engine is now fully functional");

		ItemList_Remove(gameState->inventory, qCarb);
	}
	else
	{
		printf("you don't have the needed pieces to fix the quantum engine");
	}
}

/* Build a "ToolBox" object */
Item* ToolBox_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("tool box", "this is your trusty bright green ToolBox filled with all the quantum tools", true, ToolBox_Use, ToolBox_Take, NULL);
}