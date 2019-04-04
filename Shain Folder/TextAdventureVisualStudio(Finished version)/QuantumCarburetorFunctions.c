/**********************************************************
File Name: QuantumCarburetorFunctions.h
by: Shain Allen
last edited: 3/21/2019
brief: this is the Quantum Carburetor that is needed to fix the engine
***********************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BrickFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "QuantumCarburetorFunctions.h" /* Egg_Build */

/* Helper: The action performed when the Quantum Engine is taken. */
void QuantumCarburetor_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("this is indeed the quantum Carburetor that is needed to fix the engine.\n");
}
void QuantumCarburetor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
}

/* Build a "ToolBox" object */
Item* QuantumCarburetor_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("quantum carburetor", "This is the Quantum Carburetor", true, QuantumCarburetor_Use, QuantumCarburetor_Take, NULL);
}