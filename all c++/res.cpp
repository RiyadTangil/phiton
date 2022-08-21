#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
};
class Menu
{
public:
    int code;
    int qtn;
    int price;
    string foodName;
};
void spaceHandler(int no)
{
    for (int i = 0; i < no; i++)
    {
        cout << " ";
    }
}
int main()
{

    int noOfItems;
    cin >> noOfItems;
    Restaurant bangla;

    for (int i = 0; i < noOfItems; i++)
    {
        int food_item_codes, food_item_prices;
        string food_item_names;
        cin >> food_item_codes;
        getchar();
        getline(cin, food_item_names);
        cin >> food_item_prices;
        bangla.food_item_codes[i] = food_item_codes;
        bangla.food_item_names[i] = food_item_names;
        bangla.food_item_prices[i] = food_item_prices;
    }
    for (int i = 0; i < noOfItems; i++)
    {
        if (i == 0)
        {
            cout << "Item Code"
                 << "                       "
                 << "Item name"
                 << "                       "
                 << "Item Price"
                 << endl;
        }
        cout << bangla.food_item_codes[i]
             << setw(20) << left
             << bangla.food_item_names[i]
             << setw(50) << left
             << bangla.food_item_prices[i]
             << endl;
    }
    int tabNo, noOfItem;
    cout << "Enter Table No:";
    cin >> tabNo;
    cout << "Enter The No of Items:";
    cin >> noOfItem;
    Menu myMenu[noOfItem];

    for (int j = 0; j < noOfItem; j++)
    {
    Flag:
        int selectedCode, selectedQnt;
        cout << "Enter Item " << j + 1 << " Code : ";
        cin >> selectedCode;
        cout << "Enter Item " << j + 1 << " Quantity : ";
        cin >> selectedQnt;
        bool found = false;
        for (int s = 0; s < noOfItems; s++)
        {
            if (bangla.food_item_codes[s] == selectedCode)
            {
                found = true;

                myMenu[j].price = bangla.food_item_prices[s];
                myMenu[j].code = selectedCode;
                myMenu[j].qtn = selectedQnt;
                myMenu[j].foodName = bangla.food_item_names[s];
                break;
            }
        }
        if (!found)
        {
            cout << "Code not found try again!" << endl;
            goto Flag;
        }
    };
    int total = 0;

    for (int k = 0; k < noOfItem; k++)
    {
        if (k == 0)
        {
            cout << "                                          Bill Summary                                  " << endl;
            cout << "                                       -----------------                                " << endl;
            cout << "Table No" << tabNo << endl;
            cout << "Item Code"
                 << "          "
                 << "Item Name"
                 << "          "
                 << "Item Price"
                 << "          "
                 << "Item Quantity"
                 << "          "
                 << "Total Price"
                 << "          " << endl;
        }
        total += myMenu[k].price * myMenu[k].qtn;
        cout << myMenu[k].code
             << "                 " << myMenu[k].foodName
             << "                  " << myMenu[k].qtn
             << "                  " << myMenu[k].price
             << "                  " << myMenu[k].price * myMenu[k].qtn
             << "                  " << endl;
    }

    cout << "Tax                                                                                    " << total * .05 << endl;
    total += total * .05;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Net Balance                                                                            " << total << " taka" << endl;

    return 0;
}
