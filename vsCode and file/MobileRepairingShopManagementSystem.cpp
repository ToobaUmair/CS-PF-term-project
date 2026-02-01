#include <iostream>
#include <fstream>
#include <iomanip>
#include <fstream>
using namespace std;

// global variable for autogenrated customer and order id
int customer_id_no = 0;
int order_id_no = 0;

// Functions for Customer Management
void addCustomer(string customerName, string customerCNIC, int numberOfOrder, string phoneModel, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);
void readCustomer(string customerID, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);
void updateCustomer(string customerID, string customerName, string customerCNIC, int numberOfOrder, string phoneModel, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);
void deleteCustomer(string customerID, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);
void viewCustomers(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);

// Functions for Order Management
void addOrder(string customerID, string orderType, string orderConditon, int orderCost, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size);
void readOrder(string customerID, string orderID, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], int size);
void updateOrder(string customerID, string orderID, string orderType, string orderConditon, int orderCost, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], int size);
void deleteOrder(string customerID, string orderID, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size);
void viewOrder(string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], int size);

// Functions for Service Management
void addService(string serviceType, int serviceTime, int serviceCost, string serType[], int serTime[], int serCost[], int size);
void readService(string serviceType, string serType[], int serTime[], int serCost[], int size);
void updateService(string serviceType, int serviceTime, int serviceCost, string serType[], int serTime[], int serCost[], int size);
void deleteService(string serviceType, string serType[], int serTime[], int serCost[], int size);
void viewService(string serType[], int serTime[], int serCost[], int size);

// Functions for Status Tracking
void viewPendingOrder(string ordsIDs[][5], string cusIDs[], string ordsType[][5], string ordsCondition[][5], string status[][5], int size);
void viewDeliveredOrder(string ordsIDs[][5], string cusIDs[], string ordsType[][5], string ordsCondition[][5], string status[][5], int size);
void viewCompletedOrder(string ordsIDs[][5], string cusIDs[], string ordsType[][5], string ordsCondition[][5], string status[][5], int size);
void updateStatus(string customerID, string orderID, string orderStatus, string ordsIDs[][5], string cusIDs[], string status[][5], int size);
void initializeAllVariable(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], string serType[], int serTime[], int serCost[], int size, int serSize);

// Function for data persistent
void writeDataInMastersFile(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], string serType[], int serTime[], int serCost[], int size, int sersize);
void loadAllData(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], string serType[], int serTime[], int serCost[], int size, int sersize);
void loadCustomerData(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);
void loadOrderData(string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size);
void loadServiceData(string serType[], int serTime[], int serCost[], int size);
void writeCustomerData(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size);
void writeOrderData(string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size);
void writeServiceData(string serType[], int serTime[], int serCost[], int size);

// function prototype of validation function with some extra functions : to lower string function, convert string to int type function,
// is Digit function(user Defined) , is int function , is Alpahbet (user defined) , generate order Id and customer ID (auto generated)
// its also include of function to return 1d array from function.
int convertToInt(string num);
bool isAlphabet(char c);
bool isDIGIT(char c);
bool validInt(string num);
string generateCustomerID();
string generateorderID();
string toLwrStr(string X);
bool isValidName(const string &name);
bool isValidCNIC(const string &CNIC);
bool isValidOrderNo(int orderNo);
bool isValidPhonemodel(const string &model);
bool isExistCustomerId(string customerId, string cusIDs[]);
bool isExistOrderId(string orderId, string ordsIDs[][5]);
bool isValidOrderType(string orderType, string serType[]);
bool isValidOrderCondition(string orderCondition);
bool isValidServiceCost(int cost);
bool isValidServiceType(const string &name);
bool isValidServiceTime(int time);
bool isValidOrderCost(int orderCost);
bool isExistServiceType(string serviceType, string serType[]);
bool isValidStatus(string status);
int main()
{

    ifstream fin;
    ofstream fout;
    // Declare all variables
    int option;
    bool flag;
    char operation;
    bool validity = true;
    string username = "uet", password = "2025";
    string customerName, CNIC, PhoneModel, customerID;
    string orderID, orderType, orderCondition, serviceType, orderStatus;
    int serviceTime, serviceCost;
    string cusNames[100], cusCNIC[100], phModel[100], cusIDs[100], serType[25]; // DECLARATION OF CUSTOMERS ARRAYS
    int orderNo[100];
    string ordsType[100][5], ordsCondition[100][5], ordsIDs[100][5], status[100][5]; // DECLATATION OF ORDERS ARRAYS
    int ordsCost[100][5];
    int serTime[25], serCost[25];
    int numberOfOrder, orderCost;
    char ch, isIntType;
    string isintType;

    while (true)
    {   
        cout << "\n\e[96m*** Admin Login Panel ***\e[0m" << endl;
        cout << "Enter the username  : ";
        cin >> username;
        cout << "Enter the password  : ";
        cin >> password;

        if (username == "uet" && password == "2025")
            break;
        else
            cout << "Invalid Id"<< endl;
    }

    initializeAllVariable(cusIDs, cusNames, cusCNIC, phModel, orderNo, ordsIDs, ordsType, ordsCondition, ordsCost, status, serType, serTime, serCost, 100, 25);
    cout << endl;
    cout << "\e[96m*** Note About Previous Data *** \e[0m"<< endl;
    loadAllData(cusIDs, cusNames, cusCNIC, phModel, orderNo, ordsIDs, ordsType, ordsCondition, ordsCost, status, serType, serTime, serCost, 100, 25);
    cout << endl;
    bool exitProgram = false;

    do
    {
        cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl; // coral red
        cout << "\e[96m                 Welcome To Mobile Repairing Shop Management System\e[0m" << endl;                                               // Neon Blue color
        cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
        cout << "Enter \e[93m1\e[0m to Manage customer " << endl; // Yellow color
        cout << "Enter \e[93m2\e[0m to Manage order" << endl;
        cout << "Enter \e[93m3\e[0m to Manage services" << endl;
        cout << "Enter \e[93m4\e[0m to status tracking" << endl;
        cout << "Enter \e[93m0\e[0m to Save data and Exit the program" << endl;
        cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
        cout << endl;

        cout << "\e[38;2;255;138;101m Input the option \e[0m : ";

        cin >> isintType; // to avoid input failure first input in string then convert into integer
        if (validInt(isintType))
            option = convertToInt(isintType);
        cin.ignore();
        flag = false;

        switch (option)
        {
        // Case for customer management
        case 1:

            cout << "The option is   : " << option << endl;

            do
            {
                cout << endl;
                cout << "\n\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "\e[96m Manage Customer \e[0m" << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "Enter \e[93mC\e[0m to Add customer" << endl;
                cout << "Enter \e[93mR\e[0m to read customers " << endl;
                cout << "Enter \e[93mU\e[0m to update cutomers" << endl;
                cout << "Enter \e[93mD\e[0m to delete cutomers" << endl;
                cout << "Enter \e[93mV\e[0m to View all cutomers" << endl;
                cout << "Enter \e[93mE\e[0m go back to the menu " << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << endl;

                cout << "\e[38;2;255;138;101mEnter operation  :\e[0m";
                cin >> operation;
                cin.ignore();

                switch (operation)
                {
                    // for
                case 'C':

                    cout << " The operation is   : " << operation << endl;

                    do
                    {
                        cout << " \e[96m*** Add Customer ***\e[0m" << endl;
                        cout << "Enter customer's name         : ";
                        getline(cin, customerName);
                        cout << "Enter customer's CNIC         : ";
                        cin >> CNIC;
                        cout << "Enter customer's no of order  : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            numberOfOrder = convertToInt(isintType);
                        cin.ignore();
                        cout << "Enter customer's phone detail : ";
                        getline(cin, PhoneModel);
                        validity = (isValidName(customerName) && isValidCNIC(CNIC)) && (isValidOrderNo(numberOfOrder) && isValidPhonemodel(PhoneModel));

                        if (validity)
                        { // VALIDATION
                            addCustomer(customerName, CNIC, numberOfOrder, PhoneModel, cusIDs, cusNames, cusCNIC, phModel, orderNo, 100);
                            cout << "\033[32m The customer's details has been added successfully :) \e[0m" << endl;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;

                    } while (!validity);
                    break;

                case 'R':
                    cout << " The operation is     : " << operation << endl;

                    do
                    {
                        cout << " \e[96m*** read Customer ***\e[0m" << endl;
                        cout << "Enter customer id             : ";
                        cin >> customerID;
                        validity = isExistCustomerId(customerID, cusIDs);
                        if (validity)                                                                   // VALIDATION
                            readCustomer(customerID, cusIDs, cusNames, cusCNIC, phModel, orderNo, 100); // readfunction of customer
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;
                    } while (!validity);
                    break;

                case 'U':

                    cout << " The operation is  : " << operation << endl;

                    do
                    {
                        cout << " \e[96m*** update Customer ***\e[0m" << endl;
                        cout << "Enter customer id             : ";
                        cin >> customerID;
                        cin.ignore();
                        cout << "Enter customer's name         : ";
                        getline(cin, customerName);
                        cout << "Enter customer's CNIC         : ";
                        cin >> CNIC;
                        cout << "Enter customer's no of order  : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer

                        if (validInt(isintType))
                            numberOfOrder = convertToInt(isintType);

                        cin.ignore();
                        cout << "Enter customer's phone detail : ";
                        getline(cin, PhoneModel);
                        validity = (isValidName(customerName) && isValidCNIC(CNIC)) && (isValidOrderNo(numberOfOrder) && isValidPhonemodel(PhoneModel));
                        validity = validity && isExistCustomerId(customerID, cusIDs);

                        if (validity)
                        {                                                                                                                                // VALIDATION
                            updateCustomer(customerID, customerName, CNIC, numberOfOrder, PhoneModel, cusIDs, cusNames, cusCNIC, phModel, orderNo, 100); // update funtion of customer
                            cout << "\033[32m The customer's details has been updated successfully :) \e[0m" << endl;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;
                    } while (!validity);
                    break;
                case 'D':
                    cout << " The operation is   : " << operation << endl;
                    do
                    {
                        cout << " \e[96m*** Delete Customer ***\e[0m" << endl;
                        cout << "Enter customer id             : ";
                        cin >> customerID;
                        validity = isExistCustomerId(customerID, cusIDs);
                        if (validity)
                        { // VAlidATION
                            deleteCustomer(customerID, cusIDs, cusNames, cusCNIC, phModel, orderNo, 100);
                            cout << "\033[32m The customer's details has been deleted successfully. :) \e[0m" << endl;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;
                    } while (!validity);
                    break;

                case 'V':
                    cout << " The operation is   : " << operation << endl;
                    cout << " \e[96m*** View All Customer ***\e[0m" << endl;
                    viewCustomers(cusIDs, cusNames, cusCNIC, phModel, orderNo, 100);

                    break;

                case 'E':
                    cout << " The operation is   : " << operation << endl;
                    writeCustomerData(cusIDs, cusNames, cusCNIC, phModel, orderNo, 100);
                    cout << " \e[96m*** Go back to the menu ***\e[0m" << endl;
                    cout << "\033[32m The customer's details has been deleted successfully :) \e[0m" << endl;
                    cout << "\033[32m Changes has been saved in 'customer data.csv'. :) \e[0m" << endl;
                    cout << "Exit from this menu and going back to main menu " << endl;
                    flag = true;
                    break;

                default:
                    cout << endl;
                    cout << " \033[31m ERROR : \e[0m You have entered WRONG option. ." << endl;
                }
            } while (!flag);
            break;

        // Case for order management
        case 2:
            // order's array variable must be 2d arrays of 5 rows , 100 columns
            do
            {
                cout << endl;
                cout << "The option is   : " << option << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "\e[96m Manage Order \e[0m" << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "Enter \e[93mC\e[0m to Add order " << endl;
                cout << "Enter \e[93mR\e[0m to read order " << endl;
                cout << "Enter \e[93mU\e[0m to update order" << endl;
                cout << "Enter \e[93mD\e[0m to delete order" << endl;
                cout << "Enter \e[93mV\e[0m to View all order" << endl;
                cout << "Enter \e[93mE\e[0m go back to the menu " << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << endl;

                cout << "\e[38;2;255;138;101mEnter operation  :\e[0m";
                cin >> operation;
                switch (operation)
                {
                case 'C':
                    cout << " The operation is   : " << operation << endl;
                    do
                    {
                        cout << " \e[96m*** Add order ***\e[0m" << endl;
                        cout << "Enter Customer's Id           : ";
                        cin >> customerID;
                        cin.ignore();
                        cout << "Enter order type              : ";
                        getline(cin, orderType);
                        cout << "Enter order's Condition       : ";
                        cin >> orderCondition;
                        cout << "Enter order costs             : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            orderCost = convertToInt(isintType);
                        validity = (isExistCustomerId(customerID, cusIDs) && isValidOrderCondition(orderCondition)) && (isValidOrderType(orderType, serType) && isValidOrderCost(orderCost));
                        if (validity)
                        {
                            addOrder(customerID, orderType, orderCondition, orderCost, cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, status, 100);
                            cout << "\033[32m The order's details has been added successfully :) \e[0m" << endl;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;

                    } while (!validity);
                    break;

                case 'R':
                    cout << " The operation is   : " << operation << endl;
                    cout << " \e[96m*** Read order ***\e[0m" << endl;
                    do
                    {
                        cout << "Enter Customer's Id           : ";
                        cin >> customerID;
                        cout << "Enter order's Id              : ";
                        cin >> orderID;
                        validity = isExistOrderId(orderID, ordsIDs) && isExistCustomerId(customerID, cusIDs);
                        if (validity)
                        {
                            readOrder(customerID, orderID, cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, 100);
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;
                    } while (!validity);
                    break;
                case 'U':
                    cout << " The operation is   : " << operation << endl;
                    cout << " \e[96m*** Update order ***\e[0m" << endl;
                    do
                    {
                        cout << "Customer's Id                : ";
                        cin >> customerID;
                        cout << "Enter order's Id             : ";
                        cin >> orderID;
                        cin.ignore();
                        cout << "Order type                   : ";
                        getline(cin, orderType);
                        cout << "Order's Condition            : ";
                        cin >> orderCondition;
                        cout << "Order costs                  : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            orderCost = convertToInt(isintType);
                        validity = (isExistCustomerId(customerID, cusIDs) && isValidOrderCondition(orderCondition)) && (isValidOrderType(orderType, serType) && isValidOrderCost(orderCost));
                        validity = validity && isExistOrderId(orderID, ordsIDs);
                        if (validity)
                        {
                            updateOrder(customerID, orderID, orderType, orderCondition, orderCost, cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, 100);
                            cout << "\033[32m The order's details has been updated successfully :) \e[0m" << endl;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;
                    } while (!validity);
                    break;
                case 'D':
                    cout << " The operation is   : " << operation << endl;
                    cout << " \e[96m*** Delete order ***\e[0m" << endl;
                    do
                    {
                        cout << "Customer's Id                : ";
                        cin >> customerID;
                        cout << "Order's Id                   : ";
                        cin >> orderID;
                        validity = isExistOrderId(orderID, ordsIDs) && isExistCustomerId(customerID, cusIDs);
                        if (validity)
                        {
                            deleteOrder(customerID, orderID, cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, status, 100);
                            cout << "\033[32m The order's details has been deleted successfully :) \e[0m" << endl;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. Again input." << endl;
                    } while (!validity);
                    break;
                case 'V':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** View all Order ***\e[0m" << endl;
                    viewOrder(cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, 100);
                    break;
                case 'E':
                    cout << " The operation is   : " << operation << endl;
                    writeOrderData(cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, status, 100);
                    cout << " \e[96m*** Go back to the menu ***\e[0m" << endl;
                    cout << "\033[32m Changes has been saved in 'order data.csv'. :) \e[0m" << endl;
                    cout << "Exit from this menu and going back to main menu " << endl;

                    flag = true;
                    break;

                default:
                    cout << " \033[31m ERROR : \e[0m You have entered WRONG option." << endl;
                }
            } while (!flag);
            break;

        // Case for service management
        case 3:
            do
            {
                cout << endl;
                cout << "The option is   : " << option << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "\e[96m Manage Service \e[0m" << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "Enter \e[93mC\e[0m to Add service " << endl;
                cout << "Enter \e[93mR\e[0m  to read service " << endl;
                cout << "Enter \e[93mU\e[0m to update service" << endl;
                cout << "Enter \e[93mD\e[0m to delete service" << endl;
                cout << "Enter \e[93mV\e[0m to View all service" << endl;
                cout << "Enter \e[93mE\e[0m to go back to the menu" << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "\e[38;2;255;138;101mEnter operation  :\e[0m";
                cout << endl;

                cin >> operation;
                switch (operation)
                {
                case 'C':
                    cout << " The operation is   : " << operation << endl;
                    do
                    {
                        cout << " \e[96m*** Add service ***\e[0m" << endl;
                        cout << "Enter the service type        : ";
                        cin.ignore();
                        getline(cin, serviceType);
                        cout << "Enter the time required       : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            serviceTime = convertToInt(isintType);
                        cout << "Enter the service costs       : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            serviceCost = convertToInt(isintType);
                        validity = (isValidServiceType(serviceType) && isValidServiceTime(serviceTime)) && isValidServiceCost(serviceCost);
                        if (validity)
                        {
                            addService(serviceType, serviceTime, serviceCost, serType, serTime, serCost, 25);
                            cout << "\033[32m The service's details has been added successfully :) \e[0m" << endl;
                            break;
                        }
                        else
                            cout << "You entered wrong input, please try again " << endl;
                    } while (!validity);
                    break;

                case 'R':
                    cout << " The operation is   : " << operation << endl;
                    cout << " \e[96m*** read service ***\e[0m" << endl;
                    cout << "Enter Service type            : ";
                    cin.ignore();
                    getline(cin, serviceType);
                    validity = isExistServiceType(serviceType, serType);
                    if (validity)
                    {
                        readService(serviceType, serType, serTime, serCost, 25);
                    }
                    else
                        cout << " \033[31m ERROR : \e[0m You have entered wrong input. ." << endl;

                    break;

                case 'U':
                    cout << " The operation is   : " << operation << endl;
                    do
                    {
                        cout << " \e[96m*** Update service ***\e[0m" << endl;
                        cout << "Enter Service type            : ";
                        cin.ignore();
                        getline(cin, serviceType);
                        cout << "Required time in minutes      : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            serviceTime = convertToInt(isintType);
                        cout << "Rervice costs                 : ";
                        cin >> isintType; // to avoid input failure first input in string then convert into integer
                        if (validInt(isintType))
                            serviceCost = convertToInt(isintType);
                        validity = (isValidServiceCost(serviceCost) && isValidServiceTime(serviceTime)) && isExistServiceType(serviceType, serType);
                        if (validity)
                        {
                            updateService(serviceType, serviceTime, serviceCost, serType, serTime, serCost, 25);
                            cout << "\033[32m The service's details has been updated successfully :) \e[0m" << endl;
                            break;
                        }
                        else
                        {
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. ." << endl;
                            break;
                        }
                    } while (!validity);
                    break;

                case 'D':
                    cout << " The operation is   : " << operation << endl;
                    do
                    {
                        cout << " \e[96m*** Delete service ***\e[0m" << endl;
                        cin.ignore();
                        cout << "Enter Service type           : ";
                        getline(cin, serviceType);
                        validity = isExistServiceType(serviceType, serType);
                        if (validity)
                        {
                            deleteService(serviceType, serType, serTime, serCost, 25);
                            cout << "\033[32m The service's details has been deleted successfully :) \e[0m" << endl;
                            break;
                        }
                        else
                            cout << " \033[31m ERROR : \e[0m You have entered wrong input. ." << endl;
                    } while (validity);
                    break;

                case 'V':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** View all Service ***\e[0m" << endl;
                    viewService(serType, serTime, serCost, 100);
                    break;

                case 'E':
                    cout << " The operation is   : " << operation << endl;
                    cout << " \e[96m*** Go back to the menu ***\e[0m" << endl;
                    writeServiceData(serType, serTime, serCost, 25);
                    cout << "\033[32m Changes has been saved in 'service data.csv'. :) \e[0m" << endl;
                    cout << "Exit from this menu and going back to main menu " << endl;
                    flag = true;
                    break;
                default:
                    cout << " \033[31m ERROR : \e[0m You have entered WRONG option. ." << endl;
                }
            } while (!flag);

            break;
            // Case for status tracking
        case 4:

            do
            {
                cout << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "\e[96m Status Tracking\e[0m " << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << "Enter \e[93mP\e[0m to View all pending oders " << endl;
                cout << "Enter \e[93mC\e[0m to View all completed orders " << endl;
                cout << "Enter \e[93mD\e[0m to View all delivered orders" << endl;
                cout << "Enter \e[93mU\e[0m to Update the status  " << endl;
                cout << "Enter \e[93mE\e[0m go back to the menu " << endl;
                cout << "\e[38;2;255;241;118m***************************************************************************************************\e[0m" << endl;
                cout << endl;

                cout << "\e[38;2;255;138;101mEnter operation  :\e[0m";
                cin >> operation;

                switch (operation)
                {

                case 'P':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** View all Pending Order ***\e[0m" << endl;
                    viewPendingOrder(ordsIDs, cusIDs, ordsType, ordsCondition, status, 100);
                    break;

                case 'C':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** View all Completed Order \e[0m*** " << endl;
                    viewCompletedOrder(ordsIDs, cusIDs, ordsType, ordsCondition, status, 100);

                    break;

                case 'D':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** View all Delivered Order ***\e[0m" << endl;
                    viewDeliveredOrder(ordsIDs, cusIDs, ordsType, ordsCondition, status, 100);

                    break;

                case 'U':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** Update the status ***\e[0m" << endl;
                    cout << "Enter the Customer id         : ";
                    cin >> customerID;
                    cout << "Enter the Order id            : ";
                    cin >> orderID;
                    cin.ignore();
                    cout << "Enter the Updated status      : ";
                    getline(cin, orderStatus);
                    validity = (isExistCustomerId(customerID, cusIDs) && isExistOrderId(orderID, ordsIDs)) && isValidStatus(orderStatus);
                    if (validity)
                    {
                        updateStatus(customerID, orderID, orderStatus, ordsIDs, cusIDs, status, 100);
                        cout << "\033[32m The order's status has been updated successfully :) \e[0m" << endl;
                    }
                    else
                        cout << " \033[31m ERROR : \e[0m You have entered wrong input. ." << endl;
                    break;

                case 'E':
                    cout << " The operation is   :" << operation << endl;
                    cout << " \e[96m*** Go back to the menu ***\e[0m" << endl;
                    writeOrderData(cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, status, 100);
                    cout << "Exit from this menu and going back to main menu " << endl;
                    flag = true;
                    break;

                default:
                    cout << " \033[31m ERROR : \e[0m You have entered WRONG option. ." << endl;
                }
            } while (!flag);

            break;

        case 0:
            cout << "You selected option: " << option << endl;
            writeDataInMastersFile(cusIDs, cusNames, cusCNIC, phModel, orderNo, ordsIDs, ordsType, ordsCondition, ordsCost, status, serType, serTime, serCost, 100, 25);
            cout << endl;
            cout << "\e[32m  The data is saved successfully  \e[0m" << endl;
            cout << "\e[32m  Program closed successfully    \e[0m" << endl;
            exitProgram = true;

            break;

        default:
            cout << " \033[31m ERROR : \e[0m You have entered WRONG option." << endl;
            cout << "Displaying Main Menu" << endl;
        }

    } while (!exitProgram);

    return 0;
}
/* the purpose of this function is to avoid case sensitivity
for many string that we have to compare with the other
like Urgent and urgent should be consider same */
string toLwrStr(string X)
{
    string str = X;
    int size = X.length();
    for (int i = 0; i < size; i++)
    {
        if (X[i] >= 'A' && X[i] <= 'Z')
        {
            str[i] = X[i] + 32;
        }
    }
    return str;
}
bool isAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}
bool validInt(string num)
{
    for (char c : num)
        if (!isDIGIT(c))
            return false;
    return true;
}
int convertToInt(string num)
{
    int a = 0;
    for (char c : num)
        a = a * 10 + (c - '0');
    return a;
}
bool isDIGIT(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
// genrate customer Id
string generateCustomerID()
{
    customer_id_no++;
    //  saveLastId();// have to check its logics
    char buf[10];
    sprintf(buf, "CU%03d", customer_id_no);
    return string(buf);
}
//  genrate orderID
string generateorderID()
{
    order_id_no++;
    //  saveLastId();// have to check its logics
    char buf[10];
    sprintf(buf, "OR%03d", order_id_no);
    return string(buf);
}

void initializeAllVariable(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], string serType[], int serTime[], int serCost[], int size, int sersize)
{

    // Initialization of Service's Variable

    for (int i = 0; i < sersize; i++)
    {
        serType[i] = "NV";
        serTime[i] = -1;
        serCost[i] = -1;
    } // Initialization of 2D arrays
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ordsIDs[i][j] = "NV";
            ordsType[i][j] = "NV";
            ordsCondition[i][j] = "NV";
            ordsCost[i][j] = -1;
            status[i][j] = "NV";
        }
    } // this loop initialize all string arrays to NV and integers arrays to -1
    for (int i = 0; i < size; i++)
    {
        cusIDs[i] = "NV";
        orderNo[i] = -1;
        cusNames[i] = "NV";
        cusCNIC[i] = "NV";
        phModel[i] = "NV";
    }
}

void loadAllData(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], string serType[], int serTime[], int serCost[], int size, int sersize)
{
    loadCustomerData(cusIDs, cusNames, cusCNIC, phModel, orderNo, size);
    loadServiceData(serType, serTime, serCost, sersize);
    loadOrderData(cusIDs, ordsIDs, ordsType, ordsCondition, ordsCost, status, size);
}

void addCustomer(string customerName, string customerCNIC, int numberOfOrder, string phoneModel, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cusNames[i] == "NV")
        {
            cusIDs[i] = generateCustomerID();
            cusNames[i] = customerName;
            cusCNIC[i] = customerCNIC;
            orderNo[i] = numberOfOrder;
            phModel[i] = phoneModel;
            cout << "The customer ID is  : " <<"\e[93m"<< cusIDs[i] << "\e[0m"<< endl;
            break;
        }
    }
}

void readCustomer(string customerID, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] == customerID)
        {
            cout << "Customer's name               : " << cusNames[i] << endl;
            cout << "Customer's CNIC               : " << cusCNIC[i] << endl;
            cout << "Customer's no of order        : " << orderNo[i] << endl;
            cout << "Customer's phone detail       : " << phModel[i] << endl;
            break;
        }
    }
}

void updateCustomer(string customerID, string customerName, string customerCNIC, int numberOfOrder, string phoneModel, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] == customerID)
        {
            cusNames[i] = customerName;
            cusCNIC[i] = customerCNIC;
            orderNo[i] = numberOfOrder;
            phModel[i] = phoneModel;
            break;
        }
    }
}

void deleteCustomer(string customerID, string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] == customerID)
        {
            cusNames[i] = "NV";
            cusCNIC[i] = "NV";
            orderNo[i] = 0;
            phModel[i] = "NV";
            break;
        }
    }
}

void viewCustomers(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    cout << "_________________________________________________________________________________________________" << endl;
    cout << setw(15) << left << "Customer Id" << setw(20) << left << "Name" << setw(20) << left << "CNIC" << setw(15) << left << "No. of Order" << setw(15) << left << "Phone Model" << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        //    cout << setw(15)<<left<< cusIDs[i] <<setw(15)<<left<<ordIDs[i]<<setw(20)<<left<<"Order type"<<setw(20)<<left<<"Order Conditon"<<setw(20)<<left<<"Order Cost"<<endl;
        if (cusIDs[i] != "NV" && cusNames[i] != "NV")
            cout << setw(15) << left << cusIDs[i] << setw(20) << left << cusNames[i] << setw(20) << left << cusCNIC[i]
                 << setw(15) << left << orderNo[i] << setw(15) << left << phModel[i] << endl;
    }
    cout << "_________________________________________________________________________________________________" << endl;
}

//  all function of order management system
void addOrder(string customerID, string orderType, string orderConditon, int orderCost, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (customerID == cusIDs[i])
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] == "NV")
                    ordsIDs[i][j] = generateorderID();
                    ordsType[i][j] = orderType;
                    ordsCondition[i][j] = orderConditon;
                    ordsCost[i][j] = orderCost;
                    status[i][j] = "pending";
                    cout << "The order ID is  : " << "\e[93m"<< ordsIDs[i][j] << "\e[0m"<< endl;
                    break;
                
            }
            break;
        }
    }
}

void readOrder(string customerID, string orderID, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (customerID == cusIDs[i])
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] == orderID)
                {
                    cout << "Order type                    : " << ordsType[i][j] << endl;
                    cout << "Order's Condition             : " << ordsCondition[i][j] << endl;
                    cout << "Order costs                   : " << ordsCost[i][j] << endl;
                    break;
                }
            }
            break;
        }
    }
}

void updateOrder(string customerID, string orderID, string orderType, string orderConditon, int orderCost, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (customerID == cusIDs[i])
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] == orderID)
                {
                    ordsType[i][j] = orderType;
                    ordsCondition[i][j] = orderConditon;
                    ordsCost[i][j] = orderCost;
                    break;
                }
            }
            break;
        }
    }
}

void deleteOrder(string customerID, string orderID, string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (customerID == cusIDs[i])
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] == orderID)
                {
                    ordsIDs[i][j] = "NV";
                    ordsType[i][j] = "NV";
                    ordsCondition[i][j] = "NV";
                    ordsCost[i][j] = 0;
                    status[i][j] = "NV";
                    break;
                }
            }
            break;
        }
    }
}

void viewOrder(string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], int size)
{
    cout << "_________________________________________________________________________________________________" << endl;
    cout << setw(15) << left << "Customer Id" << setw(15) << left << "Order Id" << setw(20) << left
         << "Order type" << setw(20) << left << "Order Conditon" << setw(20) << left << "Order Cost" << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] != "NV")
                    cout << setw(15) << left << cusIDs[i] << setw(15) << left << ordsIDs[i][j] << setw(20) << left << ordsType[i][j]
                         << setw(20) << left << ordsCondition[i][j] << setw(20) << left << ordsCost[i][j] << endl;
            }
        }
    }
    cout << "_________________________________________________________________________________________________" << endl;
}

// these function of service management
void addService(string serviceType, int serviceTime, int serviceCost, string serType[], int serTime[], int serCost[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (serType[i] == "NV")
        {
            serType[i] = serviceType;
            serTime[i] = serviceTime;
            serCost[i] = serviceCost;
            break;
        }
    }
    return;
}

void updateService(string serviceType, int serviceTime, int serviceCost, string serType[], int serTime[], int serCost[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (serType[i] == serviceType)
        {
            serTime[i] = serviceTime;
            serCost[i] = serviceCost;
            break;
        }
    }
}

void readService(string serviceType, string serType[], int serTime[], int serCost[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (serType[i] == serviceType)
        {
            cout << "Required time in minutes      : " << serTime[i] << endl;
            cout << "Service costs                 : " << serCost[i] << endl;
            break;
        }
    }
}

void deleteService(string serviceType, string serType[], int serTime[], int serCost[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (serType[i] == serviceType)
        {
            serType[i] = "NV";
            serTime[i] = 0;
            serCost[i] = 0;
            break;
        }
    }
}

void viewService(string serType[], int serTime[], int serCost[], int size)
{
    cout << "_________________________________________________________________________________________________" << endl;
    cout << setw(30) << left << "Service Type" << setw(20) << left << "Required time(min)" << setw(20) << left << "Service cost" << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (serType[i] != "NV" && (serType[i][0] != 'C' && serTime[i] != -1))
        {
            cout << setw(30) << left << serType[i] << setw(20) << left << serTime[i] << setw(20) << left << serCost[i] << endl;
        }
    }
    cout << "_________________________________________________________________________________________________" << endl;
}

// these are functions of status tracking menu
void viewPendingOrder(string ordsIDs[][5], string cusIDs[], string ordsType[][5], string ordsCondition[][5], string status[][5], int size)
{
    cout << "__________________________________________________________________________________________________" << endl;
    cout << setw(15) << left << "Customer Id" << setw(15) << left << "Order Id" << setw(20) << left
         << "Order type" << setw(20) << left << "Order Conditon" << setw(20) << left << "status" << endl;
    cout << "__________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
            {
                if (toLwrStr(status[i][j]) == "pending")
                {
                    cout << setw(15) << left << cusIDs[i] << setw(15) << left << ordsIDs[i][j] << setw(20) << left
                         << ordsType[i][j] << setw(20) << left << ordsCondition[i][j] << setw(20) << left << status[i][j] << endl;
                }
            }
        }
    }
    cout << "__________________________________________________________________________________________________" << endl;
}

void viewCompletedOrder(string ordsIDs[][5], string cusIDs[], string ordsType[][5], string ordsCondition[][5], string status[][5], int size)
{
    cout << "__________________________________________________________________________________________________" << endl;
    cout << setw(15) << left << "Customer Id" << setw(15) << left << "Order Id" << setw(20) << left
         << "Order type" << setw(20) << left << "Order Conditon" << setw(20) << left << "status" << endl;
    cout << "__________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
            {
                if (status[i][j] == "completed" && ordsIDs[i][j] != "NV")
                {
                    cout << setw(15) << left << cusIDs[i] << setw(15) << left << ordsIDs[i][j] << setw(20) << left << ordsType[i][j] << setw(20) << left << ordsCondition[i][j] << setw(20) << left << status[i][j] << endl;
                }
            }
        }
    }
    cout << "__________________________________________________________________________________________________" << endl;
}

void viewDeliveredOrder(string ordsIDs[][5], string cusIDs[], string ordsType[][5], string ordsCondition[][5], string status[][5], int size)
{
    cout << "__________________________________________________________________________________________________" << endl;
    cout << setw(15) << left << "Customer Id" << setw(15) << left << "Order Id" << setw(20) << left << "Order type" << setw(20) << left << "Order Conditon" << setw(20) << left << "status" << endl;
    cout << "__________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
            {
                if (status[i][j] == "delivered")
                {
                    cout << setw(15) << left << cusIDs[i] << setw(15) << left << ordsIDs[i][j] << setw(20) << left
                         << ordsType[i][j] << setw(20) << left << ordsCondition[i][j] << setw(20) << left << status[i][j] << endl;
                }
            }
        }
    }
    cout << "__________________________________________________________________________________________________" << endl;
}

void updateStatus(string customerID, string orderID, string orderStatus, string ordsIDs[][5], string cusIDs[], string status[][5], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (customerID == cusIDs[i])
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] == orderID)
                {
                    status[i][j] = orderStatus;
                    break;
                }
            }
            break;
        }
    }
}
void loadCustomerData(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    ifstream fin;
    char ch;

    fin.open("customer data.csv");
    if (fin)
    {
        fin >> customer_id_no; // to start customer id where left it
        fin.get(ch);

        cout << "Previous customer data is loading...." << endl; // this tells about previous record of data
        for (int i = 0; getline(fin, cusIDs[i], ',') && i < size; i++)
        {
            getline(fin, cusNames[i], ',');
            getline(fin, cusCNIC[i], ',');
            fin >> orderNo[i];
            fin >> ch;
            getline(fin, phModel[i]);
        }

        fin.close();
    }
    else
        cout << "There is no customer records exist.You have to input it." << endl; // this tells about previous record of data
}
// to laod order data is very complex because 1d customer ID array have to map with 2d order's arrays
// this function load all 2d order detail with mapping to customer ID

void loadOrderData(string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size)
{
    ifstream fin;
    char ch;
    fin.open("order data.csv");
    if (fin)
    {
        string cus_ID;      // need this variable we don't need to input customer 'id again, we have already input in costomer management.
        fin >> order_id_no; // for inputting the lastid number to start it from previous most id
        fin.get(ch);
        cout << "Previous order data is loading...." << endl; // this tells about previous record of data
        getline(fin, cus_ID, ',');
        string ID = cus_ID;
        getline(fin, ordsIDs[0][0], ',');
        getline(fin, ordsType[0][0], ',');
        getline(fin, ordsCondition[0][0], ',');
        fin >> ordsCost[0][0] >> ch;
        getline(fin, status[0][0]);
        int j = 1;
        for (int i = 1; getline(fin, cus_ID, ','); )
        {
            
                if (cus_ID == ID)
                {
                    getline(fin, ordsIDs[i][j], ',');
                    getline(fin, ordsType[i][j], ',');
                    getline(fin, ordsCondition[i][j], ',');
                    fin >> ordsCost[i][j] >> ch;
                    getline(fin, status[i][j]);
                    j++;
            
                }
                else
                {
                    ID = cus_ID;
                    getline(fin, ordsIDs[i][0], ',');
                    getline(fin, ordsType[i][0], ',');
                    getline(fin, ordsCondition[i][0], ',');
                    fin >> ordsCost[i][0] >> ch;
                    getline(fin, status[i][0]);                    
                    i++;
                         j = 1;
                }
            
            
        }
        fin.close();
    }
    else
        cout << "There is no order records exist.You have to input it." << endl; // this tells about previous record of data
}

void loadServiceData(string serType[], int serTime[], int serCost[], int size)
{
    ifstream fin;
    char ch;
    fin.open("service data.csv");
    if (fin)
    {
        cout << "Previous service data is loading...." << endl; // this tells about previous record of data
        for (int i = 0; getline(fin, serType[i], ','); i++)
        {
            fin >> serTime[i];
            fin >> ch >> serCost[i];
            fin.get(ch);
        }
        fin.close();
    }
    else
        cout << "There is no service records exist.You have to input it." << endl; // this tells about previous record of data
}

void writeCustomerData(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], int size)
{
    ofstream fout;
    fout.open("customer data.csv");
    fout << customer_id_no << ','; // to keep record of last customer id
    for (int i = 0; i < 100; i++)
        if (cusIDs[i] != "NV" && cusNames[i] != "NV")
        {
            fout << cusIDs[i] << "," << cusNames[i] << "," << cusCNIC[i] << "," << orderNo[i] << "," << phModel[i] << endl;
        }
    fout.close();
}

void writeOrderData(string cusIDs[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], int size)
{
    ofstream fout;
    fout.open("order data.csv");
    fout << order_id_no << ","; // to keep record of last order id
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
                if (ordsIDs[i][j] != "NV")
                    fout << cusIDs[i] << "," << ordsIDs[i][j] << "," << ordsType[i][j] << "," << ordsCondition[i][j] << "," << ordsCost[i][j] << "," << status[i][j] << endl;
        }
    }
    fout.close();
}

void writeServiceData(string serType[], int serTime[], int serCost[], int size)
{
    ofstream fout;
    fout.open("service data.csv");
    for (int i = 0; i < size; i++)
        if (serType[i] != "NV" && (serType[i][0] != 'C' && serTime[i] != -1))
            fout << serType[i] << "," << serTime[i] << "," << serCost[i] << endl;
    fout.close();
}
// this function write all data in .txt files administrator can easily check the changes

void writeDataInMastersFile(string cusIDs[], string cusNames[], string cusCNIC[], string phModel[], int orderNo[], string ordsIDs[][5], string ordsType[][5], string ordsCondition[][5], int ordsCost[][5], string status[][5], string serType[], int serTime[], int serCost[], int size, int sersize)
{

    ofstream fout;
    fout.open("Customer Record.txt");
    fout << "_________________________________________________________________________________________________" << endl;
    fout << setw(15) << left << "Customer Id" << setw(20) << left << "Name" << setw(20) << left << "CNIC" << setw(15) << left << "No. of Order" << setw(15) << left << "Phone Model" << endl;
    fout << "_________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV" && cusNames[i] != "NV")
            fout << setw(15) << left << cusIDs[i] << setw(20) << left << cusNames[i] << setw(20) << left << cusCNIC[i]
                 << setw(15) << left << orderNo[i] << setw(15) << left << phModel[i] << endl;
    }
    fout << "_________________________________________________________________________________________________" << endl;
    fout.close();

    fout.open("Order Record.txt");
    fout << "_________________________________________________________________________________________________" << endl;
    fout << setw(15) << left << "Customer Id" << setw(15) << left << "Order Id" << setw(20) << left
         << "Order type" << setw(20) << left << "Order Conditon" << setw(20) << left << "Order Cost" << endl;
    fout << "_________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
            {
                if (ordsIDs[i][j] != "NV")
                {
                    fout << setw(15) << left << cusIDs[i] << setw(15) << left << ordsIDs[i][j] << setw(20) << left << ordsType[i][j]
                         << setw(20) << left << ordsCondition[i][j] << setw(20) << left << ordsCost[i][j] << endl;
                }
            }
        }
    }
    fout << "_________________________________________________________________________________________________" << endl;
    fout.close();

    fout.open("Service Record.txt");
    fout << "_________________________________________________________________________________________________" << endl;
    fout << setw(30) << left << "Service Type" << setw(20) << left << "Required time(min)" << setw(20) << left << "Service cost" << endl;
    fout << "_________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (serType[i] != "NV"&& serTime[i] != -1)
            fout << setw(30) << left << serType[i] << setw(20) << left << serTime[i] << setw(20) << left << serCost[i] << endl;
    }
    fout << "_________________________________________________________________________________________________" << endl;
    fout.close();
    fout.open("Status Record.txt");
    fout << "__________________________________________________________________________________________________" << endl;
    fout << setw(15) << left << "Customer Id" << setw(15) << left << "Order Id" << setw(20) << left
         << "Order type" << setw(20) << left << "Order Conditon" << setw(20) << left << "status" << endl;
    fout << "__________________________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (cusIDs[i] != "NV")
        {
            for (int j = 0; j < 5; j++)
                if (ordsIDs[i][j] != "NV" && status[i][j] != "NV")
                    fout << setw(15) << left << cusIDs[i] << setw(15) << left << ordsIDs[i][j] << setw(20) << left << ordsType[i][j] << setw(20) << left << ordsCondition[i][j] << setw(20) << left << status[i][j] << endl;
        }
    }
    fout << "__________________________________________________________________________________________________" << endl;
    fout.close();
}
// name validity

bool isValidName(const string &name)
{
    int validity = 0;
    for (char c : name)
    {
        if (!(isAlphabet(c) || c == ' '))
            validity++;
    }
    return (!name.empty() && name.length() <= 50) && validity == 0;
}
// cnic validity
bool isValidCNIC(const string &CNIC)
{
    int validity = 0;
    for (char c : CNIC)
    {
        if (!isDIGIT(c))
            validity++;
    }
    return (CNIC.length() == 13 && validity == 0);
}
// number of order of a customer
bool isValidOrderNo(int orderNo)
{
    return (orderNo >= 1 && orderNo <= 5);
}
// phone model
bool isValidPhonemodel(const string &model)
{
    int validity = 0;
    for (char c : model)
    {
        if (!((isAlphabet(c) || c == ' ') || isDIGIT(c)))
            validity++;
    }
    return (!model.empty() && model.length() <= 50);
}

// Check in existing data
// customer Id
bool isExistCustomerId(string customerId, string cusIDs[])
{
    for (int i = 0; i < 25; i++)
    {
        if (customerId == cusIDs[i])
        {
            return true;
        }
    }
    return false;
}
// OrderID
bool isExistOrderId(string orderId, string ordsIDs[][5])
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (orderId == ordsIDs[i][j])
            {
                return true;
            }
        }
    }
    return false;
}
// check validity of function
bool isValidOrderType(string orderType, string serType[])
{
    for (int i = 0; i < 25; i++)
    {

        if (serType[i] == orderType)
        { // Also add case sensitivety
            return true;
        }
    }
    return false;
}
// order Condition
bool isValidOrderCondition(string orderCondition)
{
    return orderCondition == "normal" || orderCondition == "urgent";
}
// validation applied

bool isValidServiceCost(int cost)
{
    return cost >= 0;
}

// check validity of function
bool isValidServiceType(const string &name)
{
    int validity = 0;
    for (char c : name)
    {
        if (isDIGIT(c))
            validity++;
    }
    return (!name.empty() && name.length() <= 50) && validity == 0;
}

bool isValidServiceTime(int time)
{
    return time > 0;
}

bool isValidOrderCost(int orderCost)
{
    return orderCost >= 0;
}

bool isExistServiceType(string serviceType, string serType[])
{

    for (int i = 0; i < 25; i++)
    {
        if (toLwrStr(serType[i]) == toLwrStr(serviceType))
        {
            return true;
        }
    }
    cout << "Service Not Found " << endl;
    return false;
}

bool isValidStatus(string status)
{
    if ((toLwrStr(status) == "pending" || toLwrStr(status) == "delivered") || toLwrStr(status) == "updated")
        return true;
    else
        return false;
}

/*


********  **   **  ********      ********  **    **  ******
   **     **   **  **            **        ***   **  **   ***
   **     *******  *******       ********  ** ** **  **    **
   **     **   **  **            **        **   ***  **   ***
   **     **   **  ********      ********  **    **  ******


*/