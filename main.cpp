#include <iostream> 
#include <string>
#include "store.h"
#include "Aisle.h"
#include "Item.h"
#include "food.h"
#include "drink.h"
#include <vector>

using namespace std;

//store declaration
store superStore = store("SuperStore Market", 5);


int main() {
	superStore.getMenuChoice();
}