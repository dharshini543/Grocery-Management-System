#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"
#include "enum.h"

int saveDataToFile(const Inventory *inventory, const Report *report, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error: Could not open file %s for writing.\n", filename);
        return Failure;
    }

    fprintf(file, "Inventory\n");
    InventoryItem *tempInventory = inventory->head;
    while (tempInventory != NULL)
    {
        fprintf(file, "%d|%s|%s|%.2f|%.2f|%s|%s\n",
                tempInventory->itemID, tempInventory->name, tempInventory->brand,
                tempInventory->price, tempInventory->quantity,
                tempInventory->department, tempInventory->expiryDate);
        tempInventory = tempInventory->next;
    }
    fprintf(file, "EndInventory\n");

    fprintf(file, "Report\n");
    ReportItem *tempReport = report->head;
    while (tempReport != NULL)
    {
        fprintf(file, "%d|%.2f\n", tempReport->itemID, tempReport->quantity);
        tempReport = tempReport->next;
    }
    fprintf(file, "EndReport\n");

    fclose(file);
    printf("Data successfully saved to %s.\n", filename);
    return Success;
}

int loadDataFromFile(Inventory *inventory, Report *report, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s for reading.\n", filename);
        return Failure;
    }

    char line[256];
    enum { NONE, INVENTORY, REPORT } section = NONE;

    while (fgets(line, sizeof(line), file))
    {
        if (strcmp(line, "Inventory\n") == 0)
        {
            section = INVENTORY;
            continue;
        }
        else if (strcmp(line, "EndInventory\n") == 0)
        {
            section = NONE;
            continue;
        }
        else if (strcmp(line, "Report\n") == 0)
        {
            section = REPORT;
            continue;
        }
        else if (strcmp(line, "EndReport\n") == 0)
        {
            section = NONE;
            continue;
        }

        if (section == INVENTORY)
        {
            InventoryItem *newitem = (InventoryItem *)malloc(sizeof(InventoryItem));
            if (newitem == NULL)
            {
                printf("Memory allocation failed.\n");
                fclose(file);
                return Failure;
            }

            sscanf(line, "%d|%[^|]|%[^|]|%f|%f|%[^|]|%s",
                   &newitem->itemID, newitem->name, newitem->brand,
                   &newitem->price, &newitem->quantity,
                   newitem->department, newitem->expiryDate);

            newitem->next = NULL;

            if (inventory->head == NULL)
            {
                inventory->head = newitem;
            }
            else
            {
                InventoryItem *temp = inventory->head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newitem;
            }

            inventory->itemCount++;
        }
        else if (section == REPORT)
        {
            ReportItem *newitem = (ReportItem *)malloc(sizeof(ReportItem));
            if (newitem == NULL)
            {
                printf("Memory allocation failed.\n");
                fclose(file);
                return Failure;
            }

            sscanf(line, "%d|%f", &newitem->itemID, &newitem->quantity);

            newitem->next = NULL;

            if (report->head == NULL)
            {
                report->head = newitem;
            }
            else
            {
                ReportItem *temp = report->head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newitem;
            }
        }
    }

    fclose(file);
    printf("Data successfully loaded from %s.\n", filename);
    return Success;
}
