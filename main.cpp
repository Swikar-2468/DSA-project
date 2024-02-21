#include <iostream>
#include <string>
using namespace std;
int no_of_node=0;
class Node{
public:
    string foodItem;
    double price;
    int quantity;
    Node* next;
};

class Restro_Order_Management{
    Node* head;
public:
    Restro_Order_Management(){
        head = nullptr;
    }

    void food_menu() {
        cout<<"1. Pizza - Rs 400"<<endl;
        cout<<"2. Burger - Rs 150"<<endl;
        cout<<"3. Momo - Rs 130"<<endl;
        cout<<"4. Chowmin - Rs 100"<<endl;
        cout<<"5. Water - Rs 25"<<endl;
    }

    void addOrder(string foodItem, double price, int quantity) {
        Node* new_node= new Node;
        new_node->foodItem = foodItem;
        new_node->price = price;
        new_node->quantity = quantity;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
            no_of_node++;
        }
        else {
            Node* current = head;
            do{
                if (current->foodItem == foodItem)
                {
                    current->quantity += quantity;
                    delete new_node;
                    return;
                }
                if(current->next==NULL)
                {
                    current->next=new_node;
                    current=new_node->next;
                    no_of_node++;
                }
                else
                {
                    current = current->next;
                }
            }while (current != nullptr);
        }
    }

    void cancelOrder(int index, int quantity)
    {
        if (head == nullptr)
        {
            cout<<endl<<"No orders to cancel."<<endl;
            return;
        }

        if (index < 1)
        {
            cout<<endl<<"Invalid order index."<< endl;
            return;
        }

        Node* current = head;

        for(int i=1; i<index; i++)
        {
              current = current->next;
        }
        if (quantity > current->quantity)
        {
            cout<<endl<<"Invalid quantity to cancel."<<endl;
            return;
        }

        current->quantity -= quantity;
        if (current->quantity == 0)
        {
            if (current == head)
            {
                head = head->next;
                no_of_node--;
            }
            else
            {
                Node* temp = head;
                while (temp->next != current)
                {
                    temp = temp->next;
                }
                temp->next = current->next;
            }
            delete current;
            cout <<endl<<"Order at index "<<index<<" canceled successfully."<<endl;
            no_of_node--;
        }
        else
        {
            cout<<endl<<"Cancelled "<<quantity<<" "<<current->foodItem<<" successfully."<<endl;
        }
    }

    void displayOrders() {
        if (head == nullptr)
        {
            cout << endl << "No orders available." << endl;
            return;
        }
        Node* current = head;
        cout<<endl<<"Current orders:"<<endl;
        int index = 1;
        while (current != nullptr)
        {
            cout<<index<<". "<<current->foodItem<<" -   Rs "<<current->price<<" (Quantity: "<<current->quantity<<")"<< endl;
            current = current->next;
            index++;
        }
    }

    void displayTotal() {
        double total = 0;
        cout<<no_of_node<<endl;
        Node* current = head;
        while (current != nullptr) {
            total += current->price * current->quantity;
            current = current->next;
        }
        cout<<"Total: Rs " << total << endl;
    }
};

int main() {
    Restro_Order_Management restro_obj;
    int choice1, choice2, quantity, cancelQuantity;
    string foodItem;
    double price;
    cout <<"----Welcome to Khwopa Vegetarian Restaurant Ordering System!!!----"<<endl<< endl;
    do {
        cout <<"Choices: "<< endl;
        cout <<"1. Add order"<< endl;
        cout <<"2. Cancel order"<< endl;
        cout <<"3. Display Order"<< endl;
        cout <<"4. Display Total"<< endl;
        cout <<"5. Exit"<< endl;

        cout <<"\nEnter your choice: ";
        cin >> choice1;

        switch (choice1)
        {
            case 1:
                cout << endl;
                restro_obj.food_menu();
                cout << endl;
                cout <<"Which food would you like to order: ";
                cin >> choice2;
                if(choice2 >= 6 || choice2 <=0)
                {
                    cout<<"Invalid order" <<endl;
                    break;
                }
                cout << "Enter the quantity: ";
                cin >> quantity;
                switch (choice2)
                {
                    cout << endl;
                    case 1:
                        restro_obj.addOrder("Pizza", 400, quantity);
                        break;
                    case 2:
                        restro_obj.addOrder("Burger", 150, quantity);
                        break;
                    case 3:
                        restro_obj.addOrder("Momo", 130, quantity);
                        break;
                    case 4:
                        restro_obj.addOrder("Chowmin", 100, quantity);
                        break;
                    case 5:
                        restro_obj.addOrder("Water", 25, quantity);
                        break;
                    default:
                        cout <<"Invalid order!!"<<endl;
                }
                break;

            case 2:
                int index;
                restro_obj.displayOrders();
                if (no_of_node > 0) {
                    cout <<endl<<"Enter the index of the order you want to cancel: ";
                    cin>>index;
                    if(no_of_node >= index)
                    {
                        cout <<"Enter the quantity to cancel: ";
                        cin>>cancelQuantity;
                        restro_obj.cancelOrder(index, cancelQuantity);
                    }

                    else
                    {
                        cout<<index<<" index not available."<<endl;
                    }

                }
                break;

            case 3:
                restro_obj.displayOrders();
                break;

            case 4:
                if(no_of_node > 0)
                {
                    restro_obj.displayTotal();
                }
                else
                {
                    cout<<endl<<"No orders for displaying total."<<endl;
                }
                break;

            case 5:
                cout << endl << "Exiting...";
                break;

            default:
                cout << endl << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice1 != 5);
    if (no_of_node > 0)
    {
        restro_obj.displayOrders();
        restro_obj.displayTotal();
    }
    cout<<endl<<"Thank you!!!"<<endl;
    return 0;
}
