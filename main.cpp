#include "accountsDatabase.h"
#include "functionalUI.h"

int main()
{
	AccountsDatabase db;
	FunctionalUI ui(db);
	ui.run();
	return 0;
}
