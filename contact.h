#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void initialize(AddressBook *addressBook);
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);
int searchmenu();
void removecontact(AddressBook *addressBook, int index);
int checknamepresent(AddressBook *addressBook, char temp_name[]);
int checkphonepresent(AddressBook *addressBook, char temp_phone[]);
int checkemailpresent(AddressBook *addressBook, char temp_email[]);
int checknamevalid(char temp_name[]);
int checkphonevalid(char temp_phone[]);
int checkemailvalid(char temp_email[]);
void printsearchbyname(AddressBook *addressBook, char search_name[]);
void printsearchbyphone(AddressBook *addressBook, char phone_no[]);
void printsearchbyemail(AddressBook *addressBook, char email_id[]);
int findnameindex(AddressBook *addressBook, char search_name[], int serial_no);
int findphoneindex(AddressBook *addressBook, char phone_no[], int serial_no);
int findemailindex(AddressBook *addressBook, char email_id[], int serial_no);
void addname(AddressBook *addressBook, int i);
void addphone(AddressBook *addressBook, int i);
void addemail(AddressBook *addressBook, int i);
int editmenu();
void editmenucase(AddressBook *addressBook, int serial_edit, int index);

#endif
