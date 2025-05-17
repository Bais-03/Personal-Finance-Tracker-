/* Write backend code here */
#include<iostream>
#include <fstream>          // for file writing
#include "json.hpp"         // the library you just added

using json = nlohmann::json;

int main() {
    /* ---- demo data to plot ---- */
    json chart;
    chart["labels"] = {"Food", "Transport", "Salary"};
    chart["data"]   = {500, 150, 5000};
    chart["type"]   = {"Expense", "Expense", "Income"};

    /* ---- write file ---- */
    std::ofstream("data.json") << chart.dump(4);   // pretty-print with indent=4
    return 0;
}
 using namespace std;

class User {
  private:
    string username;
    string password;
    string email;
    string date;

  public:
    void login() {
        cout << "Username: ";
        getline(cin, username);
        cout << "Email: ";
        cin >> email;
        cout << "Password: ";
        cin >> password;
        cout << "Date (dd-mm-yy): ";
        cin >> date;
        cin.ignore();  // Clear input buffer before using getline

    }

    void updateProfile() {
        string passcheck;
        int choice;

        cout << "\nVerification Required: ";
        cout << "\nEnter your password: ";
        cin >> passcheck;

        if (passcheck != password) {
            cout << "Wrong Password! Cannot update profile.\n";
            return;
        }

        cout << "\nWhat do you want to update?\n";
        cout << "1. Update Username\n";
        cout << "2. Update Email\n";
        cout << "3. Update Password\n";
        cout << "4. Update Date\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore();  // To flush leftover newline

        switch (choice) {
            case 1:
                cout << "Enter new username: ";
                getline(cin, username);
                cout << "Updated Username: " << username << endl;
                break;
            case 2:
                cout << "Enter new email: ";
                cin >> email;
                cout << "Updated Email: " << email << endl;
                break;
            case 3:
                cout << "Enter new password: ";
                cin >> password;
                cout << "Updated Password.\n";
                break;
            case 4:
                cout << "Enter new date (dd-mm-yy): ";
                cin >> date;
                cout << "Updated Date: " << date << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    }

    void displayProfile() {
        cout << "\n--- User Profile ---\n";
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Email: " << email << endl;
        cout << "Date (dd-mm-yy): " << date << endl;
    }
};

class Transaction {
  private:
  double amount;
  string date;
  string category;

  public:
  void recordTransaction() {
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter date (dd-mm-yy): ";
    cin >> date;
    cout << "Enter category: ";
    cin >> category;
  }

  void editTransaction() {
    int choice;
    cout << "What do you want to edit?" << endl;
    cout << "1. Amount" << endl;
    cout << "2. Date" << endl;
    cout << "3. Category" << endl;
  }

  void displayTransaction() {
    cout << "---Transcation---" << endl;
    cout << "Amount: " << amount << endl;
    cout << "Date: " << date << endl;
    cout << "Category: " << category << endl;
  }

};

class Income : public Transaction {
    private: 
    string income_source;
    bool isRecurring;

    public:

    void record_income_source() {
      cout << "Enter income source: ";
      cin >> income_source;
    }

    void recurring_flag() {

    string input;
    cout << "Is the income recurring? (yes/no): ";
    cin >> input;

    if (input == "yes" || input == "Yes")
        isRecurring = true;
    else if (input == "no" || input == "No")
        isRecurring = false;
    else {
        cout << "Invalid input. Assuming not recurring.\n";
        isRecurring = false;
    }

        }
};


class Expense : public Transaction{
    private:
    string payment_method;
    bool isTaxDeductible;

    public:

    void paymentMode () {
        cout << "Payment method: ";
        cin >> payment_method;
    }

    void taxdeductible_flag() {
        string input;
        cout << "Is tax deductible? (yes/no): ";
        cin >> input;

        if(input == "yes" || input == "Yes") {
            isTaxDeductible = true;
        } else if(input == "no" || input == "No") {
            isTaxDeductible = false;
        } else {
            cout << "Invalid input! Assuming not tax deductible." << endl;
            isTaxDeductible = false;
        }
    }
};




int main() {
    // User u1;
    // cout << "\n--- Login User 1 ---\n";
    // u1.login();
    // u1.displayProfile();

    // cout << "\n--- Login User 2 ---\n";
    // User u2;
    // u2.login();
    // u2.displayProfile();

    // cout << "\n--- Update Profile of User 2 ---\n";
    // u2.updateProfile();
    // u2.displayProfile();

    return 0;
}
