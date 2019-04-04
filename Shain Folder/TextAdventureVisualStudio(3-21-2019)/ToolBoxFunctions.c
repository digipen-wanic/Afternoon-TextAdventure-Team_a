/**********************************************************
File Name: ToolBoxFunctions.h
by: Shain Allen
last edited: 3/21/2019
brief: this is the toolbox that is needed to fix the engine
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

/* Helper: The action performed when the Toolbox is taken. */
void Toolbox_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("The toolbox is as light as ever and still has everthing in it that an enginer of your caliper would need.\n");
}
void Toolbox_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if (gameState->currentRoomIndex == 9)
	{
		gameState->engineWorking = true;
	}
	else
	{

	}
}

/* Build a "ToolBox" object */
Item* ToolBox_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("ToolBox", "this is your trusty bright green toolbox filled with all the quantum tools", true, Toolbox_Use, Toolbox_Take, NULL);
}