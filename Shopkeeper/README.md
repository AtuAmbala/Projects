# Shopkeeper Project

[![Watch the video](https://img.youtube.com/vi/AD-u-ohXCgw/maxresdefault.jpg)](https://youtu.be/AD-u-ohXCgw)

## Project Description

The Shopkeeper Project is a Python application designed to help shopkeepers manage their inventory, process orders, and generate receipts for customers. The project leverages object-oriented programming principles to provide a structured and modular approach to handling shop operations.

## Features

- Inventory management: Track stock levels, prices, and reorder levels of items.
- Order processing: Create and manage customer orders.
- Receipt generation: Print and display receipts for customers.
- Graphical User Interface (GUI) for customer receipts.

## Project Structure

### Classes

1. **Stock**: Represents an individual item in the stock.
    - `__init__`: Initializes the stock item with item code, name, price, stock level, and reorder level.
    - `__repr__`: Provides a string representation of the stock item.
    - `reorder_check`: Checks if the stock level is below the reorder level.

2. **Inventory**: Manages the overall inventory of the shop.
    - `__init__`: Reads inventory data from a CSV file.
    - `__repr__`: Provides a string representation of the entire inventory.
    - `retrieve_row`: Retrieves the row index of a specific item in the inventory.
    - `item_info`: Retrieves the information of a specific item in the inventory.

3. **Order**: Represents an individual customer order.
    - `__init__`: Initializes the order with item code, quantity, and links it to the inventory.
    - `__repr__`: Provides a string representation of the order.

4. **Mutiple**: Manages multiple customer orders.
    - `__init__`: Initializes with a list of orders.
    - `__repr__`: Provides a string representation of all orders.
    - `add_order`: Adds a new order to the list.
    - `stock_change`: Updates stock levels after an order.
    - `gather_prices`: Gathers prices from all orders.
    - `calculate_Tprices`: Calculates the total price of all orders.
    - `twoDlists`: Converts a list to a 2D list.
    - `rewrite`: Writes the updated inventory back to a CSV file.
    - `print_receipt`: Prints the receipt for all orders.
    - `return_receipt`: Returns a string representation of the receipt.
    - `user_receipt`: Displays the receipt in a GUI.

### Functions

- `display`: Displays a menu of options for the user.
- `main`: Main user interaction loop, allowing the user to place orders, add orders, view total prices, print receipts, and exit the application.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/shopkeeper-project.git
   ```
2. **Navigate to the project directory:**
   ```bash
   cd shopkeeper-project
   ```
3. **Install the required dependencies:**
   ```bash
   pip install -r requirements.txt
   ```
4. **Run the project:**
   ```bash
   python Final_Project.py
   ```

## Usage

1. **Start the application:**
   ```bash
   python Final_Project.py
   ```
2. **Follow the on-screen instructions to manage inventory, track sales, and handle customer information.**



