#include <stdio.h>
#include <string.h>
//define maxlength
#define MAX_USERNAME_LENGTH 12
#define MAX_PASSWORD_LENGTH 12
#define MAX_ADMINS 55
// Structure taht we use to store admin username and password
struct Admin {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};
// Function that we use to  to check if the entered username and password are correct.
int isAdmin(struct Admin *admins, int numAdmins, const char *username, const char *password) {
    for (int i = 0; i < numAdmins; ++i) {
        if (strcmp(username, admins[i].username) == 0 && strcmp(password, admins[i].password) == 0) {
            return 1; // User is an admin
        }
    }
    return 0; // User is not an admin
}
// Function that the admin can do
//it will runafter the system confirm that the Admin has log in
void adminFunctionality(struct Admin *admins, int *numAdmins) {
    printf("The function Admin can do.\n");
     // Choice depend on Admin they will add another admin or not
    char choice;
    printf("Do you want to add another admin? (y/n): ");
    scanf(" %c", &choice);
    //Type y = yes n = no
    if (choice == 'y' || choice == 'Y') {
        if (*numAdmins < MAX_ADMINS) {
            printf("Enter new admin username: ");
            //scan the username and password to the array admin(the number which store in the numAdmins address)
            scanf("%s", admins[*numAdmins].username);

            printf("Enter new admin password: ");
            scanf("%s", admins[*numAdmins].password);
            //The number store in the numAdmins will increase by one
            (*numAdmins)++;
            printf("New admin added successfully.\n");
            printf("%s", admins[*numAdmins].password);
        } else {
            //the numer of admin already max
            printf("Maximum number of admins reached.\n");
        }
    }
}

int main() {
    struct Admin admins[MAX_ADMINS];
    int numAdmins = 0;
    // copy the username and password to the admin array 
    strcpy(admins[numAdmins].username, "admin");
    strcpy(admins[numAdmins].password, "Icecream");
    numAdmins++;

    char enteredUsername[MAX_USERNAME_LENGTH];
    char enteredPassword[MAX_PASSWORD_LENGTH];
    // Prompt that use for login
    printf("Enter username: ");
    scanf("%s", enteredUsername);

    printf("Enter password: ");
    scanf("%s", enteredPassword);

    if (isAdmin(admins, numAdmins, enteredUsername, enteredPassword)) { // Call the admin functionality
        printf("Login successful. Welcome, admin!\n");
        adminFunctionality(admins, &numAdmins);
    } else {
        printf("Invalid username or password. Access denied.\n");
    }

    return 0;
}
