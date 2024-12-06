#ifndef ENUM_H
#define ENUM_H

enum MainMenuOptions
{
    INVENTORY_MANAGEMENT = 1,
    CART_MANAGEMENT,
    BILLING,
    REPORT,
    EXIT
};

enum InventoryMenuOptions
{
    Inventory_AddItem = 1,
    Inventory_DeleteItem,
    Inventory_UpdateItem,
    Inventory_DisplaySummary,
    Inventory_SortByName,
    Inventory_SortByDepartment,
    Inventory_SortByPrice,
    Inventory_GetItemByID,
    Inventory_SaveToFile
} ;

enum CartMenuOptions
{
    Cart_AddItem = 1,
    Cart_DeleteItem,
    Cart_UpdateQuantity,
    Cart_DisplaySummary
};

enum BillingMenuOptions
{
    Calculate_FinalBill = 1,
    Billing_GenerateReceipt
};

enum ReportMenuOptions
{
    Generate_SalesReport = 1,
    Generate_InventoryReport,
    ViewLOWStockAlerts,
    SaveToFile
};

enum returnValue
{
    Failure = 0,
    Success
};


#endif // ENUM_H
