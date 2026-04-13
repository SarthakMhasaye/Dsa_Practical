#include<iostream>
#include<string.h>
using namespace std;

#define TABLE_SIZE 10

struct Contact {
    char name[50];
    char phone[15];
    Contact* next;
};

class HashTable {
private:
    Contact* table[TABLE_SIZE];

    int hashFunction(char* name) {
        int hash = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            hash = hash + name[i];
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    void insert(char* name, char* phone) {
        int index = hashFunction(name);
        Contact* newContact = new Contact();
        strcpy(newContact->name, name);
        strcpy(newContact->phone, phone);
        newContact->next = NULL;
        
        if (table[index] == NULL) {
            table[index] = newContact;
        } else {
            Contact* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newContact;
        }
        cout << "Contact inserted successfully!\n";
    }
  
    void search(char* name) {
        int index = hashFunction(name);
        Contact* temp = table[index];
        
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                cout << "Name: " << temp->name << ", Phone: " << temp->phone << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found!\n";
    }

    void deleteContact(char* name) {
        int index = hashFunction(name);
        Contact* temp = table[index];
        Contact* prev = NULL;
        
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                if (prev == NULL) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Contact deleted successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Contact not found!\n";
    }
    void displayAll() {
        cout << "\n--- Telephone Directory ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                Contact* temp = table[i];
                while (temp != NULL) {
                    cout << "Name: " << temp->name << ", Phone: " << temp->phone << "\n";
                    temp = temp->next;
                }
            }
        }
        cout << "----------------------------\n";
    }
};

int main() {
    HashTable ht;
    int choice;
    char name[50], phone[15];
    while (true) {
        cout << "\n--- Telephone Directory Menu ---\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin.getline(name, 50);
                cout << "Enter phone number: ";
                cin.getline(phone, 15);
                ht.insert(name, phone);
                break;
                
            case 2:
                cout << "Enter name to search: ";
                cin.getline(name, 50);
                ht.search(name);
                break;
                
            case 3:
                cout << "Enter name to delete: ";
                cin.getline(name, 50);
                ht.deleteContact(name);
                break;
                
            case 4:
                ht.displayAll();
                break;
                
            case 5:
                cout << "Exiting...\n";
                return 0;
                
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
