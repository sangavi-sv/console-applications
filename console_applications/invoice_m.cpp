#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer {
private:
    string customerID;
    string customerName;

public:
    Customer(string id, string name) : customerID(id), customerName(name) {}

    string getCustomerID() const { return customerID; }
    string getCustomerName() const { return customerName; }
};

class Item {
private:
    string itemName;
    double itemPrice;
    int quantity;

public:
    Item(string name, double price, int qty) 
        : itemName(name), itemPrice(price), quantity(qty) {}

    string getItemName() const { return itemName; }
    double getItemPrice() const { return itemPrice; }
    int getQuantity() const { return quantity; }

    double getTotalPrice() const { return itemPrice * quantity; }
};

class Invoice {
private:
    string invoiceID;
    string customerID;
    vector<Item> items;

public:
    Invoice(string id, string custID) : invoiceID(id), customerID(custID) {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    string getInvoiceID() const { return invoiceID; }
    string getCustomerID() const { return customerID; }
    
    vector<Item> getItems() const { return items; }

    double getTotalAmount() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getTotalPrice();
        }
        return total;
    }
};

class InvoiceManager {
private:
    vector<Customer> customers;
    vector<Invoice> invoices;

public:
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void addInvoice(const Invoice& invoice) {
        invoices.push_back(invoice);
    }

    void addItemToInvoice(const string& invoiceID, const Item& item) {
        for (auto& invoice : invoices) {
            if (invoice.getInvoiceID() == invoiceID) {
                invoice.addItem(item);
                return;
            }
        }
        cout << "Invoice not found!" << endl;
    }

    void listAllCustomers() const {
        cout << "Customers List:" << endl;
        for (const auto& customer : customers) {
            cout << "ID: " << customer.getCustomerID() 
                 << ", Name: " << customer.getCustomerName() << endl;
        }
    }

    void listAllInvoices() const {
        cout << "Invoices List:" << endl;
        for (const auto& invoice : invoices) {
            cout << "Invoice ID: " << invoice.getInvoiceID() 
                 << ", Customer ID: " << invoice.getCustomerID() 
                 << ", Total Amount: " << invoice.getTotalAmount() << endl;
        }
    }

    void listInvoicesOfCustomer(const string& customerID) const {
        cout << "Invoices for Customer ID: " << customerID << endl;
        for (const auto& invoice : invoices) {
            if (invoice.getCustomerID() == customerID) {
                cout << "Invoice ID: " << invoice.getInvoiceID() 
                     << ", Total Amount: " << invoice.getTotalAmount() << endl;
            }
        }
    }

    void displayInvoiceDetails(const string& invoiceID) const {
        for (const auto& invoice : invoices) {
            if (invoice.getInvoiceID() == invoiceID) {
                cout << "Invoice ID: " << invoice.getInvoiceID() 
                     << ", Customer ID: " << invoice.getCustomerID() << endl;
                cout << "Items:" << endl;
                for (const auto& item : invoice.getItems()) {
                    cout << " - Item Name: " << item.getItemName() 
                         << ", Price: " << item.getItemPrice() 
                         << ", Quantity: " << item.getQuantity() 
                         << ", Total: " << item.getTotalPrice() << endl;
                }
                cout << "Total Amount: " << invoice.getTotalAmount() << endl;
                return;
            }
        }
        cout << "Invoice not found!" << endl;
    }
};

int main() {
    InvoiceManager manager;

    int choice;
    do {
        cout << "\nInvoice Management System" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Add Invoice" << endl;
        cout << "3. Add Items to Invoice" << endl;
        cout << "4. List All Customers" << endl;
        cout << "5. List All Invoices" << endl;
        cout << "6. List Invoices of a Customer" << endl;
        cout << "7. Display Full Details of an Invoice" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string id, name;
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Customer Name: ";
                cin >> name;
                manager.addCustomer(Customer(id, name));
                break;
            }
            case 2: {
                string invoiceID, customerID;
                cout << "Enter Invoice ID: ";
                cin >> invoiceID;
                cout << "Enter Customer ID: ";
                cin >> customerID;
                manager.addInvoice(Invoice(invoiceID, customerID));
                break;
            }
            case 3: {
                string invoiceID, itemName;
                double itemPrice;
                int quantity;
                cout << "Enter Invoice ID: ";
                cin >> invoiceID;
                cout << "Enter Item Name: ";
                cin >> itemName;
                cout << "Enter Item Price: ";
                cin >> itemPrice;
                cout << "Enter Quantity: ";
                cin >> quantity;
                manager.addItemToInvoice(invoiceID, Item(itemName, itemPrice, quantity));
                break;
            }
            case 4:
                manager.listAllCustomers();
                break;
            case 5:
                manager.listAllInvoices();
                break;
            case 6: {
                string customerID;
                cout << "Enter Customer ID: ";
                cin >> customerID;
                manager.listInvoicesOfCustomer(customerID);
                break;
            }
            case 7: {
                string invoiceID;
                cout << "Enter Invoice ID: ";
                cin >> invoiceID;
                manager.displayInvoiceDetails(invoiceID);
                break;
            }
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
