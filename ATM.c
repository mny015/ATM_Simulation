#include<stdio.h>
#include<string.h>

//Function Declaration
void checkBalance(float balance); //void returns function
float deposit(float balance);
float withdraw(float balance);

int main(){
    const char correctPassword[] = "secure123"; // Password
    char inputPassword[20];
    int attempts = 3; // Maximum attempts for entering the password
    int authenticated = 0;

     // Password authentication system
     while (attempts > 0) {
        printf("Enter password to access the ATM: ");
        scanf("%s", inputPassword);

        if (strcmp(inputPassword, correctPassword) == 0) {
            printf("Authentication successful!\n");
            authenticated = 1;
            break;
        } else {
            attempts--;
            printf("Incorrect password. You have %d attempt(s) remaining.\n", attempts);
        }
    }

    if (!authenticated) {
        printf("Access denied. Exiting program.\n");
        return 1; // Exit the program if authentication fails
    }

    // Main ATM program
    int choice;
    float balance = 1000.0; // Initial balance

    do {
        printf("\n===== ATM Simulation =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

//function define
void checkBalance(float balance){
    printf("\nYour current balance is: $%.2f\n",balance);
}
float deposit(float balance){
    float amount;
printf("\n Enter the amount to deposit: ");
scanf("%f", &amount);
if(amount > 0) {
    balance += amount;
    printf("$%.2f deposited successfully!\n",amount);
}  else{
    printf("Invalid deposit amount!\n");
}
return balance;
}
float withdraw(float balance) {
    float amount;
    printf("\nEnter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("$%.2f withdrawn successfully!\n", amount);
    } else if (amount > balance) {
        printf("Insufficient funds!\n");
    } else {
        printf("Invalid withdrawal amount!\n");
    }
    return balance;
}