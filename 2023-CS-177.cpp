#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <windows.h>
#include <regex> //Including the regex library for pattern matching in validations

using namespace std;

void header();
void loginHeader();
void ArtistHeader();
void CustomerHeader();
void ManagerHeader();
void clearScreen();
int loginMenu();
int Customermenu();
int Managermenu();
int Artistmenu();
void showMenuForRole(string role, int catalogSize, string usernames[], string catalog[], int &userCount, int Paintingsprices[], int preBookings[], int wishlist[], int orderHistory[], string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize, string feedbacks[], int &feedbackCount, string fanMeetDates[], string fanMeetVenues[], int fanMeetDurations[], int fanMeetAttendees[], int &fanMeetSize);
string signIn(string name, string password, string usernames[], string passwords[], string roles[], int userCount);
bool signUp(string name, string password, string role, string usernames[], string passwords[], string roles[], int &userCount, int userLimit);
void Catalog(string catalog[], int catalogSize);
void displayPricing(string catalog[], int Paintingsprices[], int catalogSize);
void order(int choice, int quantity, int preBookings[], string catalog[], int Paintingsprices[], int orderHistory[], int catalogSize);
float calculateTotal(int choice, int quantity, int Paintingsprices[]);
void viewAllProductsData(int catalogSize, string catalog[], int Paintingsprices[], int preBookings[]);
bool preBooking(int choice, int quantity, int preBookings[], string catalog[]);
void ManagerInterfaceFunctionality(int catalogSize, string catalog[], int &userCount, int Paintingsprices[], int preBookings[], string usernames[], int wishlist[], int orderHistory[], string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize, string feedbacks[], int &feedbackCount);
void CustomerInterfaceFunctionality(int catalogSize, string catalog[], int Paintingsprices[], int preBookings[], int wishlist[], int orderHistory[], string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize, string feedbacks[], int &feedbackCount);
void ArtistInterfaceFunctionality(int catalogSize, string catalog[], string feedbacks[], int &feedbackCount, string fanMeetDates[], string fanMeetVenues[], int fanMeetDurations[], int fanMeetAttendees[], int &fanMeetSize, string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize);
void viewWishlist(int wishlist[], string catalog[], int catalogSize);
void addToWishlist(int choice, int quantity, int wishlist[], string catalog[]);
void addToOrderHistory(int preBookings[], string catalog[], int quantity, int orderHistory[], int catalogSize);
void displayBookingsRecord(string catalog[], int preBookings[], int catalogSize);
void applyDiscount(int Paintingsprices[], int catalogSize, double discountPercentage);
void displayUserData(string usernames[], int userCount);
void addItem(string catalog[], int catalogPrices[], int &catalogSize);
void removeItem(int index, string catalog[], int catalogPrices[], int &catalogSize);
int accessCatalog(string catalog[], int catalogPrices[], int catalogSize);
void addExhibition(string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int &exhibitionSize);
void displayExhibition(string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize);
void giveFeedback(string feedbacks[], int &feedbackCount);
void seeCustomerFeedback(string feedbacks[], int feedbackCount);
int searchPainting(string catalog[], int catalogPrices[], int &catalogSize);
void holdFanMeet(string fanMeetDates[], string fanMeetVenues[], int fanMeetDurations[], int fanMeetAttendees[], int &fanMeetSize);
bool isValidUsername(string username);
bool isValidPassword(string password);

int main()
{
  const int catalogSize = 8;
  string catalog[catalogSize] = {"Winters", "StarryNight", "Memory", "Scream", "Guernica", "Lost", "Venus", "Watch"};
  int Paintingsprices[catalogSize] = {860, 1000, 5000, 1200, 1855, 12999, 1999, 6000};
  int preBookings[catalogSize] = {0};
  const int wishlistSize = 8;
  int wishlist[catalogSize] = {0};
  const int orderHistorySize = catalogSize;
  int orderHistory[orderHistorySize] = {0};
  string exhibitionNames[5];
  string exhibitionDates[5];
  string exhibitionTimes[5];
  string specialGuests[5];
  int exhibitionSize = 0;
  string customerNames[5];
  string feedbacks[5];
  int feedbackCount = 0;
  int MAX_PAINTINGS = 20;
  string artistNames[MAX_PAINTINGS];
  int fanMeetDurations[MAX_PAINTINGS];
  string fanMeetDates[MAX_PAINTINGS];
  string fanMeetVenues[MAX_PAINTINGS];
  int fanMeetAttendees[MAX_PAINTINGS];
  int fanMeetSize = 5;
  const int userLimit = 10;
  string usernames[userLimit];
  string passwords[userLimit];
  string roles[userLimit];
  int userCount = 0;
  char choice;

  while (choice != '3')
  {
    system("cls");
    header();
    loginHeader();
    choice = loginMenu();

    switch (choice)
    {
    case '1':
    {
      string name;
      string password;
      string role;
      bool usernameExists;
      do
      {
        j:usernameExists = false;
        cout << "Please Enter the username: ";
        cin >> name;
        if (!isValidUsername(name))
        {
          cout << "Invalid username. Please enter a username that is at least 6 characters long and contains only letters and numbers." << endl;
          goto j;
        }
        else
        {
          for (int i = 0; i < userCount; i++)
          {
            if (usernames[i] == name)
            {
              cout << "This Username already exists. Please choose a different username.\n";
              usernameExists = true;
              break;
            }
          }
        }
      } while (usernameExists);
      cout << "Please Enter the password: ";
      cin >> password;
      t: if (!isValidPassword(password))
      {
        cout << "Invalid password. Please enter a password that is at least 8 characters long and contains at least one uppercase letter, one lowercase letter, and one number." << endl;
        goto t;
      }
      else
      {
        bool validInput = false;
        while (!validInput)
        {
          cout << "Enter your Role (Manager/Customer/Artist): ";
          cin >> role;
          if (role == "Manager" || role == "manager" || role == "Customer" || role == "customer" || role == "Artist" || role == "artist")
          {
            validInput = true;
          }
          else
          {
            cout << "Invalid role entered. Please enter a valid role (Manager/Customer/Artist).\n";
          }
        }
        bool isValid = signUp(name, password, role, usernames, passwords, roles, userCount, userLimit);
        if (isValid)
        {
          cout << "Sign Up successful!\n";
        }
        else
        {
          cout << "SignUp not Successful!!\n";
        }
      }
      break;
    }
    case '2':
    {
      string name;
      string password;
      string role;
      cout << "Enter your Name: ";
      cin >> name;
      cout << "Enter your Password: ";
      cin >> password;
      role = signIn(name, password, usernames, passwords, roles, userCount);
      clearScreen();
      header();
      showMenuForRole(role, catalogSize, usernames, catalog, userCount, Paintingsprices, preBookings, wishlist, orderHistory, exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize, feedbacks, feedbackCount, fanMeetDates, fanMeetVenues, fanMeetDurations, fanMeetAttendees, fanMeetSize);
      break;
    }
    case '3':
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
    clearScreen();
  }
  return 0;
}

int loginMenu()
{
  cout << "1. Sign Up\n";
  cout << "2. Sign In\n";
  cout << "3. Exit\n";
  cout << "Enter your choice: ";
  char choice;
  cin >> choice;
  return choice;
}

bool isValidUsername(string username)
{
  if (username.length() < 6)
  {
    return false;
  }

  for (int i = 0; i < username.length(); i++)
  {
    if (!isalnum(username[i])) // alphanumeric
    {
      return false;
    }
  }
  return true;
}

bool isValidPassword(string password)
{
  bool hasUppercase = false;
  bool hasLowercase = false;
  bool hasNumber = false;

  if (password.length() < 8)
  {
    return false;
  }

  for (int i = 0; i < password.length(); i++)
  {
    if (isupper(password[i]))
    {
      hasUppercase = true;
    }
    else if (islower(password[i]))
    {
      hasLowercase = true;
    }
    else if (isdigit(password[i]))
    {
      hasNumber = true;
    }
  }

  return hasUppercase && hasLowercase && hasNumber;
}

string signIn(string name, string password, string usernames[], string passwords[], string roles[], int usersCount)
{
  for (int i = 0; i < usersCount; i++)
  {
    if (usernames[i] == name && passwords[i] == password)
    {
      string role = roles[i];
      return role;
    }
  }
  return "Sign In failed. Invalid username or password.";
}

bool signUp(string name, string password, string role, string usernames[], string passwords[], string roles[], int &usersCount, int userLimit)
{
  bool isPresent = false;

  for (int i = 0; i < usersCount; i++)
  {
    if (usernames[i] == name && passwords[i] == password)
    {
      isPresent = true;
      break;
    }
  }

  if (isPresent == true)
  {
    return false;
  }
  else if (usersCount < userLimit)
  {
    usernames[usersCount] = name;
    passwords[usersCount] = password;
    roles[usersCount] = role;
    usersCount++;
    return true;
  }
  else
  {
    return false;
  }
}

void header() // function for header
{
  HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hconsole, 11);
  cout << "************************************************************************************************************************************************************************\n";
  cout << "*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n";
  SetConsoleTextAttribute(hconsole, 8);
  cout << "                _        _                     _               _ _                                                                               _                  \n";
  SetConsoleTextAttribute(hconsole, 13);
  cout << "               /_\\  _ __| |_    __ _ _ __   __| |   __ _  __ _| | | ___ _ __ _   _   _ __ ___   __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_                \n";
  SetConsoleTextAttribute(hconsole, 4);
  cout << "              //_ \\| '__| __|  / _` | '_ \\ / _` |  / _` |/ _` | | |/ _ | '__| | | | | '_ ` _ \\ / _` | '_ \\ / _` |/ _` |/ _ | '_ ` _ \\ / _ | '_ \\| __|               \n";
  SetConsoleTextAttribute(hconsole, 3);
  cout << "             /  _  | |  | |_  | (_| | | | | (_| | | (_| | (_| | | |  __| |  | |_| | | | | | | | (_| | | | | (_| | (_| |  __| | | | | |  __| | | | |                 \n";
  SetConsoleTextAttribute(hconsole, 2);
  cout << "             \\_/ \\_|_|   \\__|  \\__,_|_| |_|\\__,_|  \\__, |\\__,_|_|_|\\___|_|   \\__, | |_| |_| |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|\n";
  SetConsoleTextAttribute(hconsole, 6);
  cout << "                                                    |___/                     |___/                               |___/                                               \n";
  SetConsoleTextAttribute(hconsole, 11);
  cout << "*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n";
  cout << "************************************************************************************************************************************************************************\n";
}

void loginHeader() // login menu header printing
{
  HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hconsole, 13);
  cout << "                                                                                                                                                                        \n";
  cout << "                                                                                                                                                                        \n";
  cout << "*                                                                         LOGIN MENU                                                                                   *\n";
  cout << "                                                                                                                                                                        \n";
  cout << "*-----------------------------------------------------------((((((((((((((----------))))))))))))))---------------------------------------------------------------------*\n";
}

void ArtistHeader() // artist menu header printing
{
  HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hconsole, 2);
  cout << "                                                                                                                                                                        \n";
  cout << "                                                                                                                                                                        \n";
  cout << "*                                                                         ARTIST MENU                                                                                  *\n";
  cout << "                                                                                                                                                                        \n";
  cout << "*-----------------------------------------------------------((((((((((((((----------))))))))))))))---------------------------------------------------------------------*\n";
}

void CustomerHeader() // customer menu header printing
{
  HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hconsole, 12);
  cout << "                                                                                                                                                                        \n";
  cout << "                                                                                                                                                                        \n";
  cout << "*                                                                       CUSTOMER MENU                                                                                  *\n";
  cout << "                                                                                                                                                                        \n";
  cout << "*-----------------------------------------------------------((((((((((((((----------))))))))))))))---------------------------------------------------------------------*\n";
}

void ManagerHeader() // manager menu header printing
{
  HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hconsole, 6);
  cout << "                                                                                                                                                                        \n";
  cout << "                                                                                                                                                                        \n";
  cout << "*                                                                        MANAGER MENU                                                                                  *\n";
  cout << "                                                                                                                                                                        \n";
  cout << "*-----------------------------------------------------------((((((((((((((----------))))))))))))))---------------------------------------------------------------------*\n";
}

int Artistmenu() // function for Artist menu
{
  int option;
  cout << "Hello artist! Please select one of the following options:\n";
  cout << "1. Exhibitions Available\n";
  cout << "2. Hold a fan meet\n";
  cout << "3. Display User Feedback\n";
  cout << "4. Exit\n";
  cout << "Your option: ";
  cin >> option;
  return option;
}

int Customermenu() // function for Customer menu
{
  int option;
  cout << "Select one of the following options:\n";
  cout << " 1. Catalog\n";
  cout << " 2. Pricing\n";
  cout << " 3. Place an Order \n";
  cout << " 4. View All Products Data\n";
  cout << " 5. Pre-Booking\n";
  cout << " 6. Add item to wishlist\n";
  cout << " 7. View Wishlist\n";
  cout << " 8. Display Exhibition\n";
  cout << " 9. Give Feedback\n";
  cout << " 10. Exit\n";
  cout << " Your option: ";
  cin >> option;
  return option;
}

int Managermenu() // function for Manager menu
{
  int option;
  cout << "Select one of the following options:\n";
  cout << " 1. Access all items in the catalog.\n";
  cout << " 2. Remove item.\n";
  cout << " 3. Add item.\n";
  cout << " 4. All users data.\n";
  cout << " 5. Discount application.\n";
  cout << " 6. Pre-bookings Record.\n";
  cout << " 7. Add Exhibition\n";
  cout << " 8. Display Exhibition\n";
  cout << " 9. Display User Feedback\n";
  cout << " 10. Search a Record\n";
  cout << " 11. Exit\n";
  cout << " Your option: ";
  cin >> option;
  return option;
}

void showMenuForRole(string role, int catalogSize, string usernames[], string catalog[], int &userCount, int Paintingsprices[], int preBookings[], int wishlist[], int orderHistory[], string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize, string feedbacks[], int &feedbackCount, string fanMeetDates[], string fanMeetVenues[], int fanMeetDurations[], int fanMeetAttendees[], int &fanMeetSize)
{
  if (role == "Manager" || role == "manager")
  {
    ManagerHeader();
    ManagerInterfaceFunctionality(catalogSize, catalog, userCount, Paintingsprices, preBookings, usernames, wishlist, orderHistory, exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize, feedbacks, feedbackCount);
  }
  else if (role == "Customer" || role == "customer")
  {
    CustomerHeader();
    CustomerInterfaceFunctionality(catalogSize, catalog, Paintingsprices, preBookings, wishlist, orderHistory, exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize, feedbacks, feedbackCount);
  }
  else if (role == "Artist" || role == "artist")
  {
    ArtistHeader();
    ArtistInterfaceFunctionality(catalogSize, catalog, feedbacks, feedbackCount, fanMeetDates, fanMeetVenues, fanMeetDurations, fanMeetAttendees, fanMeetSize, exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize);
  }
  else
  {
    cout << "Error!! your role, password, or username does not match. Retry!" << endl;
  }
}

void clearScreen()
{
  cout << "Press any key to continue: ";
  getch();
  system("cls");
}

void Catalog(string catalog[], int catalogSize)
{
  for (int i = 0; i < catalogSize; i++)
  {
    cout << i + 1 << ". " << catalog[i] << endl;
  }
}

void displayPricing(string catalog[], int Paintingsprices[], int catalogSize)
{
  for (int i = 0; i < catalogSize; i++)
  {
    cout << i + 1 << ". " << catalog[i] << ": $" << Paintingsprices[i] << endl;
  }
}

void order(int choice, int quantity, int preBookings[], string catalog[], int Paintingsprices[], int orderHistory[], int catalogSize)
{
  // Checking if the requested quantity is available
  if (preBookings[choice - 1] < 8)
  {
    preBookings[choice - 1]++;
    cout << "Bill generated for " << catalog[choice - 1] << " - $" << Paintingsprices[choice - 1] << endl;
  }
  else
  {
    cout << "Sorry, all copies of this painting have been pre-booked. Cannot make a bill.\n";
  }
  // Updating pre-booked quantity
  preBookings[choice - 1] -= quantity;

  cout << "Your order:\n";
  cout << "Painting: " << catalog[choice - 1] << endl;
  cout << "Quantity: " << quantity << endl;
  cout << "Total Price after tax: $" << calculateTotal(choice, quantity, Paintingsprices) << endl;
  addToOrderHistory(preBookings, catalog, quantity, orderHistory, catalogSize);
}

float calculateTotal(int choice, int quantity, int Paintingsprices[])
{
  float total = (Paintingsprices[choice - 1] * quantity * (0.05));
  return total;
}

void viewAllProductsData(int catalogSize, string catalog[], int Paintingsprices[], int preBookings[])
{
  cout << left << setw(20) << "Painting" << setw(15) << "Price" << setw(15) << "Pre-Booked" << endl;

  for (int i = 0; i < catalogSize; i++)
  {
    cout << setw(20) << catalog[i] << "$" << setw(14) << Paintingsprices[i] << setw(14) << preBookings[i] << endl;
  }
}

bool preBooking(int choice, int quantity, int preBookings[], string catalog[])
{
  // Input Validation
  if (choice < 1 || choice > 8 || quantity < 0)
  {
    cout << "Invalid input parameters.\n";
    return false;
  }

  // Check if there are available copies for pre-booking
  if (preBookings[choice - 1] + quantity <= 2)
  {
    preBookings[choice - 1] += quantity;
    cout << "Pre-booking successful for " << catalog[choice - 1] << ". Thank you!\n";
    return true;
  }
  else
  {
    cout << "Pre-booking failed. Maximum pre-booking limit reached for " << catalog[choice - 1] << ".\n";
    return false;
  }
}

void viewWishlist(int wishlist[], string catalog[], int catalogSize)
{
  cout << "****Wishlist****\n";
  for (int i = 0; i < catalogSize; i++)
  {
    if (wishlist[i] > 0)
    {
      cout << "Painting: " << catalog[i] << setw(20) << " Quantity: " << wishlist[i] << endl;
    }
  }
}

void addToWishlist(int choice, int quantity, int wishlist[], string catalog[])
{
  wishlist[choice - 1] += quantity;
  cout << "Added to wishlist: " << catalog[choice - 1] << setw(20) << " Quantity: " << quantity << endl;
}

void addToOrderHistory(int preBookings[], string catalog[], int quantity, int orderHistory[], int catalogSize)
{
  for (int i = 0; i < catalogSize; i++)
  {
    if (preBookings[i] >= quantity)
    {
      orderHistory[i] += quantity;
      preBookings[i] -= quantity;
    }
  }
  cout << "Order placed successfully!\n";
}

void CustomerInterfaceFunctionality(int catalogSize, string catalog[], int Paintingsprices[], int preBookings[], int wishlist[], int orderHistory[], string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize, string feedbacks[], int &feedbackCount)
{
  int customerChoice;
  while (customerChoice != 7)
  {
    system("cls");
  c:
    header();
    CustomerHeader();
    customerChoice = Customermenu();
    switch (customerChoice)
    {
    case 1:
    {
      cout << "Available Paintings in the Catalog:\n";
      Catalog(catalog, catalogSize);
    }
    break;
    case 2:
    {
      cout << "Pricing of Paintings:\n";
      displayPricing(catalog, Paintingsprices, catalogSize);
    }
    break;
    case 3:
    {
      int choice;
      int quantity;
      cout << "Available Paintings in the Catalog:\n";
      Catalog(catalog, catalogSize);

      cout << "Select a painting to purchase (1-8): ";
      cin >> choice;
      cout << "Enter the quantity: ";
      cin >> quantity;
      if (quantity < 1 || quantity > 8)
      {
        cout << "Invalid quantity.\n";
        return;
      }
      order(choice, quantity, preBookings, catalog, Paintingsprices, orderHistory, catalogSize);
    }
    break;
    case 4:
      viewAllProductsData(catalogSize, catalog, Paintingsprices, preBookings);
      break;
    case 5:
    {
      int choice;
      int quantity;
      cout << "Available Paintings in the Catalog:\n";
      Catalog(catalog, catalogSize);

      cout << "Select a painting to pre-book (1-8): ";
      cin >> choice;
      if (choice < 1 || choice > 8)
      {
        cout << "Invalid choice.\n";
        return;
      }
      cout << "Enter the quantity to pre-book: ";
      cin >> quantity;
      if (quantity < 1 || quantity > 8)
      {
        cout << "Invalid quantity.\n";
        return;
      }
      if (preBooking(choice, quantity, preBookings, catalog) == 0)
      {
        cout << "Sorry, all copies of this painting have been pre-booked. Cannot pre-book more.\n";
      }
    }
    break;
    case 6:
    {
      int choice;
      int quantity;
      cout << "Available Paintings in the Catalog:\n";
      Catalog(catalog, catalogSize);

      cout << "Select a painting to add to the wishlist (1-8): ";
      cin >> choice;
      if (choice < 1 || choice > 8)
      {
        cout << "Invalid choice.\n";
        return;
      }
      cout << "Enter the quantity: ";
      cin >> quantity;
      if (quantity < 1 || quantity > 8)
      {
        cout << "Invalid quantity.\n";
        return;
      }
      addToWishlist(choice, quantity, wishlist, catalog);
    }
    break;
    case 7:
      viewWishlist(wishlist, catalog, catalogSize);
      break;
    case 8: // see Exhibition.
      displayExhibition(exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize);
      break;
    case 9:
    {
      giveFeedback(feedbacks, feedbackCount);
    }
    break;
    case 10:
      cout << "Exiting Customer menu.\n";
      return;
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
    clearScreen();
    goto c;
  }
}

void giveFeedback(string feedbacks[], int &feedbackCount)
{
  // Check if there is space for a new feedback
  if (feedbackCount < 5)
  {
    cout << "Enter your feedback: ";
    cin.ignore(); // Clear the buffer
    getline(cin, feedbacks[feedbackCount]);

    feedbackCount++;

    cout << "Feedback submitted successfully!\n";
  }
  else
  {
    cout << "Cannot accept more feedback. Maximum limit reached.\n";
  }
}

void addExhibition(string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int &exhibitionSize)
{
  // Check if there is space for a new exhibition
  if (exhibitionSize < 5)
  {
    cout << "Enter the details for the new exhibition:\n";

    cout << "Exhibition Name: ";
    getline(cin, exhibitionNames[exhibitionSize]);

    // Geting and validating exhibition date
    regex datePattern("^(0[1-9]|1[0-9]|2[0-9]|3[01])-(0[1-9]|1[0-2])-([2][3-5])$");
    string dateInput;

    do
    {
      cout << "Date (dd-mm-yy): ";
      getline(cin, dateInput);
      if (!regex_match(dateInput, datePattern))
      {
        cout << "Invalid date format! Please enter in dd-mm-yy format, with year between 23 and 25.\n";
      }
    } while (!regex_match(dateInput, datePattern));

    exhibitionDates[exhibitionSize] = dateInput;

    // Getting and validating exhibition time
    regex timePattern("^(1[0-2]|0[1-9]):(00|15|30|45) (am|pm)$");
    string timeInput;
    do
    {
      cout << "Time (hh:mm am/pm): ";
      getline(cin, timeInput);
      if (!regex_match(timeInput, timePattern))
      {
        cout << "Invalid time format! Please enter in hh:mm am/pm format.\n";
      }
    } while (!regex_match(timeInput, timePattern));

    exhibitionTimes[exhibitionSize] = timeInput;

    // Get special guest
    cout << "Special Guest: ";
    getline(cin, specialGuests[exhibitionSize]);
    exhibitionSize++;
    cout << "Exhibition added successfully!\n";
  }
  else
  {
    cout << "Cannot add more exhibitions. Maximum limit reached.\n";
  }
}

// Function to display exhibition details
void displayExhibition(string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize)
{
  // Check if there are any exhibitions to display
  if (exhibitionSize == 0)
  {
    cout << "No exhibitions available.\n";
    return;
  }
  cout << "Exhibition Details:\n";
  for (int i = 0; i < exhibitionSize; ++i)
  {
    cout << "Exhibition " << i + 1 << ":\n";
    cout << "Name: " << exhibitionNames[i] << endl;
    cout << "Date: " << exhibitionDates[i] << endl;
    cout << "Time: " << exhibitionTimes[i] << endl;
    cout << "Special Guest: " << specialGuests[i] << endl;
    cout << "-------------------------\n";
  }
}

int accessCatalog(string catalog[], int catalogPrices[], int catalogSize)
{
  cout << "Catalog Items:\n";
  cout << setw(10) << "Item ID" << setw(20) << "Item Name" << setw(20) << "Price" << endl;
  cout << "---------------------------------------------------" << endl;

  for (int i = 0; i < catalogSize; ++i)
  {
    cout << setw(10) << left << i + 1 << setw(20) << left << catalog[i] << setw(15) << right << "$" << catalogPrices[i] << endl;
  }
  cout << endl;
  return 0;
}

void removeItem(int index, string catalog[], int catalogPrices[], int &catalogSize)
{
  if (index >= 1 && index <= catalogSize)
  {
    for (int i = index - 1; i < catalogSize - 1; ++i)
    {
      catalog[i] = catalog[i + 1];
      catalogPrices[i] = catalogPrices[i + 1];
    }
    catalogSize--;
    cout << "Item removed successfully.\n";
  }
  else
  {
    cout << "Invalid index.\n";
  }
}

void addItem(string catalog[], int catalogPrices[], int &catalogSize)
{
  if (catalogSize < 8)
  {
    cout << "Enter item name: ";
    cin.ignore(); // To clear the buffer
    getline(cin, catalog[catalogSize]);
    cout << "Enter item price: $";
    cin >> catalogPrices[catalogSize];
    catalogSize++;
    cout << "Item added successfully.\n";
  }
  else
  {
    cout << "Catalog is full. Cannot add more items.\n";
  }
}

void displayUserData(string usernames[], int userCount)
{
  cout << "User Data:\n";
  cout << setw(10) << "User ID" << setw(20) << "Username" << endl;
  cout << "---------------------------------------" << endl;

  for (int i = 0; i < userCount; ++i)
  {
    cout << setw(10) << left << i + 1 << setw(45) << left << usernames[i] << endl;
  }

  cout << endl;
}

void applyDiscount(int Paintingsprices[], int catalogSize, double discountPercentage)
{
  if (discountPercentage >= 0 && discountPercentage <= 100)
  {
    for (int i = 0; i < catalogSize; ++i)
    {
      Paintingsprices[i] *= (1.0 - discountPercentage / 100.0);
    }
    cout << "Discount applied.\n";
  }
  else
  {
    cout << "Invalid discount percentage. Please enter a value between 0 and 100.\n";
  }
}

void displayBookingsRecord(string catalog[], int preBookings[], int catalogSize)
{
  cout << "Bookings Record:\n";
  cout << setw(10) << "Item ID" << setw(20) << "Item Name" << setw(20) << "Quantity" << endl;
  cout << "-------------------------------------------" << endl;

  for (int i = 0; i < catalogSize; ++i)
  {
    if (preBookings[i] > 0)
    {
      cout << setw(10) << left << i + 1 << setw(20) << left << catalog[i] << setw(8) << right << preBookings[i] << endl;
    }
  }
  cout << endl;
}

void seeCustomerFeedback(string feedbacks[], int feedbackCount)
{
  if (feedbackCount == 0)
  {
    cout << "No feedbacks available.\n";
    return;
  }
  cout << "Customer Feedbacks:\n";
  for (int i = 0; i < feedbackCount; ++i)
  {
    cout << "Feedback " << i + 1 << ":\n";
    cout << feedbacks[i] << endl;
    cout << "-------------------------\n";
  }
}

int searchPainting(string catalog[], int catalogPrices[], int &catalogSize)
{
  string searchTerm;
  cout << "Enter the name of the painting to search for: ";
  cin.ignore();
  getline(cin, searchTerm);

  for (int i = 0; i < catalogSize; i++)
  {
    if (searchTerm == catalog[i])
    {
      return i; // Found the painting, return its index
    }
  }
  // Painting not found
  return -1;
}

void ManagerInterfaceFunctionality(int catalogSize, string catalog[], int &userCount, int Paintingsprices[], int preBookings[], string usernames[], int wishlist[], int orderHistory[], string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize, string feedbacks[], int &feedbackCount)
{
m:
  while (true)
  {
    system("cls");
    header();
    ManagerHeader();
    int option = Managermenu();
    switch (option)
    {
    case 1: // Access all items in the catalog.
      accessCatalog(catalog, Paintingsprices, catalogSize);
      break;
    case 2: // Remove item.
    {
      accessCatalog(catalog, Paintingsprices, catalogSize);
      int index;
      cout << "Enter the index of the item to remove: ";
      cin >> index;
      removeItem(index, catalog, Paintingsprices, catalogSize);
    }
    break;
    case 3: // Add item.
    {
      accessCatalog(catalog, Paintingsprices, catalogSize);
      addItem(catalog, Paintingsprices, catalogSize);
    }
    break;
    case 4: // All users data.
      displayUserData(usernames, userCount);
      break;
    case 5: // Discount applicaton.
    {
      double discountPercentage;
      cout << "Enter the discount percentage: ";
      cin >> discountPercentage;
      applyDiscount(Paintingsprices, catalogSize, discountPercentage);
    }
    break;
    case 6: // Pre-bookings Record.
      displayBookingsRecord(catalog, preBookings, catalogSize);
      break;
    case 7: // Exhibition.
      addExhibition(exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize);
      break;
    case 8: // see Exhibition.
      displayExhibition(exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize);
      break;
    case 9: // see Customer feedback.
    {
      seeCustomerFeedback(feedbacks, feedbackCount);
    }
    break;
    case 10: // search and edit a record.
    {
      int found = searchPainting(catalog, Paintingsprices, catalogSize);
      if (found != -1)
      {
        int choice;
        cout << "1. Delete this record\n";
        cout << "2. Edit this record\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
          removeItem(found + 1, catalog, Paintingsprices, catalogSize);
        }
        else if (choice == 2)
        {
          cout << "Enter the new name: ";
          cin.ignore();
          getline(cin, catalog[found]);
          cout << "Enter the new price: $";
          cin >> Paintingsprices[found];
          cout << "Record updated successfully.\n";
        }
        else
        {
          cout << "Invalid choice.\n";
        }
      }
      else
      {
        cout << "Painting not found.\n";
      }
    }
    break;
    case 11: // Exit.
      return;
      break;
    default:
      cout << "Invalid option. Please try again." << endl;
    }
    clearScreen();
    goto m;
  }
}

void holdFanMeet(string fanMeetDates[], string fanMeetVenues[], int fanMeetDurations[], int fanMeetAttendees[], int &fanMeetSize)
{
  // Checking if there is space for a new fan meet
  if (fanMeetSize < 6)
  {
    cout << "Enter fan meet details:\n";
    do
    {
      cout << "Duration (in hours, not more than 4): ";
      cin >> fanMeetDurations[fanMeetSize];
      if (fanMeetDurations[fanMeetSize] > 4)
      {
        cout << "Invalid duration! Duration should not be more than 4 hours.\n";
      }
    } while (fanMeetDurations[fanMeetSize] > 4);

    regex datePattern("^(0[1-9]|1[0-9]|2[0-9]|3[01])-(0[1-9]|1[0-2])-([2][3-5])$"); // 22-10-23
    string dateInput;
    do
    {
      cout << "Date (dd-mm-yy): ";
      cin.ignore();
      getline(cin, dateInput);
      if (!regex_match(dateInput, datePattern))
      {
        cout << "Invalid date format! Please enter in dd-mm format.\n";
      }
    } while (!regex_match(dateInput, datePattern));

    fanMeetDates[fanMeetSize] = dateInput;
    cout << "Venue: ";
    getline(cin, fanMeetVenues[fanMeetSize]);
    cout << "Number of attendees: ";
    cin >> fanMeetAttendees[fanMeetSize];
    fanMeetSize++;
    cout << "Fan meet scheduled successfully!\n";
  }
  else
  {
    cout << "Fan meet schedule is full. Cannot hold more fan meets.\n";
  }
}

void ArtistInterfaceFunctionality(int catalogSize, string catalog[], string feedbacks[], int &feedbackCount, string fanMeetDates[], string fanMeetVenues[], int fanMeetDurations[], int fanMeetAttendees[], int &fanMeetSize, string exhibitionNames[], string exhibitionDates[], string exhibitionTimes[], string specialGuests[], int exhibitionSize)
{
k:
  while (true)
  {
    system("cls");
    header();
    ArtistHeader();
    int option = Artistmenu();
    switch (option)
    {
    case 1:
      displayExhibition(exhibitionNames, exhibitionDates, exhibitionTimes, specialGuests, exhibitionSize);
      break;
    case 2: // Holding Fanmeets.
    {
      holdFanMeet(fanMeetDates, fanMeetVenues, fanMeetDurations, fanMeetAttendees, fanMeetSize);
    }
    break;
    case 3: // see Customer feedback.
    {
      seeCustomerFeedback(feedbacks, feedbackCount);
    }
    break;
    case 4: // Exit.
      return;
      break;
    default:
      cout << "Invalid option. Please try again." << endl;
    }
    clearScreen();
    goto k;
  }
}
