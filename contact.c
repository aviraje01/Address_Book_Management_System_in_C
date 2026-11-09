#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

char str[] = "-------------------------------------------------------------------------------";

void initialize(AddressBook *addressBook)
{
    FILE *fp;
    int i = 0;
    addressBook->contactCount = 0;
    fp = fopen("contacts.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        return;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%[^,], %[^,], %[^\n] ", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        addressBook->contactCount++;
        i++;
    }

    fclose(fp);
    return;
}

void listContacts(AddressBook *addressBook)
{
    printf("\n%s\n", str);
    printf("| %-10s|  %-18s|  %-15s|  %-25s|\n", "Sr.no", "Name", "Phone No.", "Email ID");
    printf("%s\n", str);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        printf("%s\n", str);
    }
}

void saveAndExit(AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("contacts.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s, %s, %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fp);

    exit(0);
}

int checknamepresent(AddressBook *addressBook, char temp_name[])
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].name, temp_name) && strlen(addressBook->contacts[i].name) == strlen(temp_name))
        {
            return 0;
        }
    }

    return 1;
}

int checkphonepresent(AddressBook *addressBook, char temp_phone[])
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, temp_phone) == 0)
        {
            return 0;
        }
    }

    return 1;
}

int checkemailpresent(AddressBook *addressBook, char temp_email[])
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, temp_email) == 0)
        {
            return 0;
        }
    }

    return 1;
}

int checknamevalid(char temp_name[])
{
    if (temp_name == NULL)
        return 0;

    for (int i = 0; temp_name[i] != '\0'; i++)
    {
        if (!isalpha(temp_name[i]) && temp_name[i] != ' ')
        {
            return 0;
        }
    }

    return 1;
}

int checkphonevalid(char temp_phone[])
{
    if (temp_phone == NULL)
        return 0;

    for (int i = 0; temp_phone[i] != '\0'; i++)
    {
        if (!isdigit(temp_phone[i]))
        {
            return 0;
        }
    }

    if (strlen(temp_phone) > 10)
        return 0;

    return 1;
}

int checkemailvalid(char temp_email[])
{
    if (temp_email == NULL)
        return 0;

    for (int i = 0; temp_email[i] != '\0'; i++)
    {
        if (isupper(temp_email[i]))
            return 0;

        if (temp_email[i] == '@')
        {
            if (i == 0)
                return 0;

            if (!isalnum(temp_email[i - 1]))
                return 0;

            if (strcmp(temp_email + i + 1, "gmail.com") != 0)
                return 0;

            return 1;
        }
    }

    return 0;
}

void addname(AddressBook *addressBook, int i)
{
    char temp_name[50];
    int name_count = 0, valid = 0, present = 0;

    while (name_count < 3)
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", temp_name);
        present = checknamepresent(addressBook, temp_name);
        if (present == 0)
        {
            printf("\nName is Already Present.\nPlease try again.\nYou have %d Chance\n\n", 2 - name_count);
            name_count++;
            continue;
        }
        else
        {

            valid = checknamevalid(temp_name);
            if (valid == 0)
            {
                printf("\nName is Not Valid.\nPlease try again.\nYou have %d Chance\n\n", 2 - name_count);
                name_count++;
                continue;
            }
            else
            {
                strcpy(addressBook->contacts[i].name, temp_name);
                break;
            }
        }
    }
}

void addphone(AddressBook *addressBook, int i)
{
    char temp_phone[20];
    int phone_count = 0, valid = 0, present = 0;

    while (phone_count < 3)
    {
        printf("Enter Phone No: ");
        scanf(" %[^\n]", temp_phone);
        present = checkphonepresent(addressBook, temp_phone);
        if (present == 0)
        {
            printf("\nPhone No. is Already Present.\nPlease try again.\nYou have %d Chance\n\n", 2 - phone_count);
            phone_count++;
            continue;
        }
        else
        {

            valid = checkphonevalid(temp_phone);
            if (valid == 0)
            {
                printf("\nPhone no. is Not Valid.\nPlease try again.\nYou have %d Chance\n\n", 2 - phone_count);
                phone_count++;
                continue;
            }
            else
            {
                strcpy(addressBook->contacts[i].phone, temp_phone);
                break;
            }
        }
    }
}

void addemail(AddressBook *addressBook, int i)
{
    char temp_email[50];
    int email_count = 0, valid = 0, present = 0;

    while (email_count < 3)
    {
        printf("Enter Email ID: ");
        scanf(" %[^\n]", temp_email);
        present = checkemailpresent(addressBook, temp_email);
        if (present == 0)
        {
            printf("\nEmail is Already Present.\nPlease try again.\nYou have %d Chance\n\n", 2 - email_count);
            email_count++;
            continue;
        }
        else
        {

            valid = checkemailvalid(temp_email);
            if (valid == 0)
            {
                printf("\nEmail is Not Valid.\nPlease try again.\nYou have %d Chance\n\n", 2 - email_count);
                email_count++;
                continue;
            }
            else
            {
                strcpy(addressBook->contacts[i].email, temp_email);
                break;
            }
        }
    }
}

void createContact(AddressBook *addressBook)
{
    int i = addressBook->contactCount;

    addname(addressBook, i);
    addphone(addressBook, i);
    addemail(addressBook, i);

    addressBook->contactCount++;

    printf("\n%s\n", str);
    printf("|%24s%s%24s|\n", "", "Successfully Contact Added..!!", "");
    printf("%s\n", str);
}

int searchmenu()
{
    int num;
    printf("\nSearch Contact Menu:\n");
    printf("1. Search By Name\n");
    printf("2. Search By Phone No.\n");
    printf("3. Search By Email ID\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &num);

    return num;
}

void printsearchbyname(AddressBook *addressBook, char search_name[])
{
    int found = 0, j = 1;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].name, search_name) != NULL)
        {
            if (found == 0)
            {
                printf("\n%s\n", str);
                printf("| %-10s|  %-18s|  %-15s|  %-25s|\n", "Sr.no", "Name", "Phone No.", "Email ID");
                printf("%s\n", str);
            }

            printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", j++, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            printf("%s\n", str);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNot Found\n");
    }
}

void printsearchbyphone(AddressBook *addressBook, char phone_no[])
{
    int found = 0, j = 1;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].phone, phone_no) != NULL)
        {
            if (found == 0)
            {
                printf("\n%s\n", str);
                printf("| %-10s|  %-18s|  %-15s|  %-25s|\n", "Sr.no", "Name", "Phone No.", "Email ID");
                printf("%s\n", str);
            }

            printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", j++, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            printf("%s\n", str);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNot Found\n");
    }
}

void printsearchbyemail(AddressBook *addressBook, char email_id[])
{
    int found = 0, j = 1;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].email, email_id) != NULL)
        {
            if (found == 0)
            {
                printf("\n%s\n", str);
                printf("| %-10s|  %-18s|  %-15s|  %-25s|\n", "Sr.no", "Name", "Phone No.", "Email ID");
                printf("%s\n", str);
            }

            printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", j++, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            printf("%s\n", str);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNot Found\n");
    }
}

void searchContact(AddressBook *addressBook)
{
    int var, serial_no;
    char search_name[50], phone_no[20], email_id[50];

    var = searchmenu();

    switch (var)
    {
    case 1:
        printf("Enter a Name: ");
        scanf(" %[^\n]", search_name);

        printsearchbyname(addressBook, search_name);

        break;
    case 2:
        printf("Enter a Phone number: ");
        scanf(" %[^\n]", phone_no);

        printsearchbyphone(addressBook, phone_no);

        break;
    case 3:
        printf("Enter a Email ID: ");
        scanf(" %[^\n]", email_id);

        printsearchbyemail(addressBook, email_id);

        break;
    case 4:
        return;
    default:
        printf("\nInvalid choice. Please try again.\n");
    }
}

int findnameindex(AddressBook *addressBook, char search_name[], int serial_no)
{
    int count = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].name, search_name) != NULL)
        {
            count++;

            if (count == serial_no)
            {
                return i;
            }
        }
    }
}

int findphoneindex(AddressBook *addressBook, char phone_no[], int serial_no)
{
    int count = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].phone, phone_no) != NULL)
        {
            count++;

            if (count == serial_no)
            {
                return i;
            }
        }
    }
}

int findemailindex(AddressBook *addressBook, char email_id[], int serial_no)
{
    int count = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].email, email_id) != NULL)
        {
            count++;

            if (count == serial_no)
            {
                return i;
            }
        }
    }
}

int editmenu()
{
    int num;
    printf("\nEdit Contact Menu:\n");
    printf("1. Edit Name\n");
    printf("2. Edit Phone No.\n");
    printf("3. Edit Email ID\n");
    printf("4. Edit ALL\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &num);

    return num;
}

void editmenucase(AddressBook *addressBook, int serial_edit, int index)
{
    switch (serial_edit)
    {
    case 1:
        addname(addressBook, index);
        printf("\n%s\n", str);
        printf("|%26s%s%26s|\n", "", "Edit Name Successfully..!!", "");
        printf("%s\n", str);
        break;
    case 2:
        addphone(addressBook, index);
        printf("\n%s\n", str);
        printf("|%23s%s%24s|\n", "", "Edit Phone No. Successfully..!!", "");
        printf("%s\n", str);
        break;
    case 3:
        addemail(addressBook, index);
        printf("\n%s\n", str);
        printf("|%24s%s%24s|\n", "", "Edit Email ID Successfully..!!", "");
        printf("%s\n", str);
        break;
    case 4:
        addname(addressBook, index);
        addphone(addressBook, index);
        addemail(addressBook, index);
        printf("\n%s\n", str);
        printf("|%24s%s%25s|\n", "", "Edit Contact Successfully..!!", "");
        printf("%s\n", str);
        break;
    case 5:
        return;
    default:
        printf("\nInvalid choice. Please try again.\n");
    }
}

void editContact(AddressBook *addressBook)
{
    int var, serial_no, found = 0, index, serial_edit;
    char search_name[50], phone_no[20], email_id[50];

    var = searchmenu();

    switch (var)
    {
    case 1:
        printf("Enter a Name: ");
        scanf(" %[^\n]", search_name);

        printsearchbyname(addressBook, search_name);

        printf("\nEnter the serial number which want to edit: ");
        scanf("%d", &serial_no);

        index = findnameindex(addressBook, search_name, serial_no);
        serial_edit = editmenu();
        editmenucase(addressBook, serial_edit, index);

        break;
    case 2:
        printf("Enter a Phone number: ");
        scanf(" %[^\n]", phone_no);

        printsearchbyphone(addressBook, phone_no);

        printf("\nEnter the serial number which want to edit: ");
        scanf("%d", &serial_no);

        index = findphoneindex(addressBook, phone_no, serial_no);
        serial_edit = editmenu();
        editmenucase(addressBook, serial_edit, index);

        break;
    case 3:
        printf("Enter a Email ID: ");
        scanf(" %[^\n]", email_id);

        printsearchbyemail(addressBook, email_id);

        printf("\nEnter the serial number which want to edit: ");
        scanf("%d", &serial_no);

        index = findemailindex(addressBook, email_id, serial_no);
        serial_edit = editmenu();
        editmenucase(addressBook, serial_edit, index);

        break;
    case 4:
        return;
    default:
        printf("\nInvalid choice. Please try again.\n");
    }
}

void removecontact(AddressBook *addressBook, int index)
{
    for (int i = index; i < addressBook->contactCount; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("\n%s\n", str);
    printf("|%23s%s%23s|\n", "", "Successfully Removed Contact..!!", "");
    printf("%s\n", str);
}

void deleteContact(AddressBook *addressBook)
{
    int var, serial_no, index;
    char search_name[50], phone_no[20], email_id[50], option;

    var = searchmenu();

    switch (var)
    {
    case 1:
        printf("Enter a Name: ");
        scanf(" %[^\n]", search_name);

        printsearchbyname(addressBook, search_name);

        printf("\nEnter the serial number which want to delete: ");
        scanf("%d", &serial_no);

        index = findnameindex(addressBook, search_name, serial_no);

        printf("\n%s\n", str);
        printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", 1, addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);
        printf("%s\n", str);

        printf("\nDo you Want to delete contact Y/N: ");
        scanf(" %c", &option);

        if (option == 'Y' || option == 'y')
        {
            removecontact(addressBook, index);
        }

        break;
    case 2:
        printf("Enter a Phone number: ");
        scanf(" %[^\n]", phone_no);

        printsearchbyphone(addressBook, phone_no);

        printf("\nEnter the serial number which want to delete: ");
        scanf("%d", &serial_no);

        index = findphoneindex(addressBook, phone_no, serial_no);

        printf("\n%s\n", str);
        printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", 1, addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);
        printf("%s\n", str);

        printf("\nDo you Want to delete contact Y/N: ");
        scanf(" %c", &option);

        if (option == 'Y' || option == 'y')
        {
            removecontact(addressBook, index);
        }
        break;
    case 3:
        printf("Enter a Email ID: ");
        scanf(" %[^\n]", email_id);

        printsearchbyemail(addressBook, email_id);

        printf("\nEnter the serial number which want to delete: ");
        scanf("%d", &serial_no);

        index = findemailindex(addressBook, email_id, serial_no);

        printf("\n%s\n", str);
        printf("| %-10d|  %-18s|  %-15s|  %-25s|\n", 1, addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);
        printf("%s\n", str);

        printf("\nDo you Want to delete contact Y/N: ");
        scanf(" %c", &option);

        if (option == 'Y' || option == 'y')
        {
            removecontact(addressBook, index);
        }

        break;
    case 4:
        return;
    default:
        printf("\nInvalid choice. Please try again.\n");
    }
}
