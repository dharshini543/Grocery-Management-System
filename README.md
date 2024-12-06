
# Grocery Management System

The ---Grocery Management System--- is a C-based application designed to help manage a grocery store efficiently. This program allows users to manage inventory, handle customer carts, generate bills, and produce detailed reports for sales and stock analysis.  


## Features
 ###1. User Management
- User login with credentials for secure access.
- Ability to initialize user details.

 ###2. Inventory Management
- Add, delete, and update items in the inventory.
- Display inventory summary.
- Sort inventory by:
  - Name
  - Department
  - Price
- Retrieve inventory details by item ID.

###3. Cart Management
- Add items from inventory to the cart.
- Update quantities of items in the cart.
- Remove items from the cart.
- Display cart summary.

 ###4. Billing
- Calculate the final bill based on cart items.
- Apply discounts and generate a detailed receipt.

###5. Reporting
- Generate sales reports for transactions.
- Generate inventory reports to review stock levels.
- View low-stock alerts for inventory restocking.

---

## File Structure
- **`main.c`**: Entry point of the application.
- **`user.h/user.c`**: Handles user login and authentication.
- **`inventory.h/inventory.c`**: Manages inventory operations.
- **`cart.h/cart.c`**: Manages customer cart operations.
- **`billing.h/billing.c`**: Handles billing and receipt generation.
- **`report.h/report.c`**: Generates sales and inventory reports.
- **`file_operations.h/file_operations.c`**: Handles file read/write operations for persistent data.
- **`enum.h`**: Contains enumerations for menu options and constants.

## How to Run the Project
### Prerequisites
- Install a C compiler (e.g., GCC).
- Clone this repository or download the source code.
- Ensure `Grocery.txt` is present in the working directory.

### Steps to Compile and Run
1. Navigate to the project directory:
   cd GroceryManagement

2.Compile the program
gcc main.c user.c inventory.c cart.c billing.c report.c file_operations.c -o GroceryManager

3.Run the Executable
./GroceryManager

##Creator
Project Developed by https://github.com/dharshini543





