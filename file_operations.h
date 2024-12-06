#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "inventory.h"
#include"report.h"

int saveDataToFile(const Inventory *inventory, const Report *report, const char *filename);
int loadDataFromFile(Inventory *inventory, Report *report, const char *filename);

#endif // FILE_OPERATIONS_H

