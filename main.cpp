#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails;

    villagerDetails["Drago"] = make_tuple(5, "Alligator", "Snap to it!");
    villagerDetails["Kyle"] = make_tuple(10, "Wolf", "Hubba Hubba!");
    villagerDetails["Raymond"] = make_tuple(8, "Cat", "Nice Fit"); 

    for(auto e: villagerDetails)
    {
        int f = get<0>(e.second);
        string a = get<1>(e.second);
        string c = get<2>(e.second);
        cout<<e.first<<": "<<f<<" "<<a<<" "<<c<<" "<<endl;
    }
    cout<<endl; 
    //menu
     
    int choice; 
    string n, a, c;
    int f; 
    int i = 0; 
    int j = 0;
    auto it = villagerDetails.find(n);

    do{
        
        cout<<"1. Add Villager"<<endl; 
        cout<<"2. Delete Villager"<<endl; 
        cout<<"3. Increase Friendship"<<endl; 
        cout<<"4. Decrease Friendship"<<endl; 
        cout<<"5. Search for Villager"<<endl; 
        cout<<"6. Exit"<<endl;
        cin>>choice; 
        cin.ignore();  
        cout<<endl; 

    switch(choice)
    {
        case 1: 
            
            cout<<"Villagers Name: ";
            getline(cin, n);  
            cout<<"Friendship Level: "; 
            cin>>f; 
            cin.ignore(); 
            cout<<"Species: "; 
            getline(cin, a); 
            cout<<"Catchphrase: "; 
            getline(cin, c); 
            villagerDetails.insert({n, {f, a, c}});
            cout<<n<<" added."<<endl<<endl;

            for(auto e: villagerDetails)
                {
                    int f = get<0>(e.second);
                    string a = get<1>(e.second);
                    string c = get<2>(e.second);
                    cout<<e.first<<": "<<f<<" "<<a<<" "<<c<<" "<<endl;
                }
            break; 

        case 2:
            if(villagerDetails.empty())
                cout<<"The village is empty"<<endl;
            else
            {

            for(auto e: villagerDetails)
                {
                    int f = get<0>(e.second);
                    string a = get<1>(e.second);
                    string c = get<2>(e.second);
                    cout<<e.first<<": "<<f<<" "<<a<<" "<<c<<" "<<endl;
                }
            cout<<endl; 
            cout<<"Enter the name of the villager you would like to delete(case sensitive): "; 
            getline(cin, n); 
            villagerDetails.erase(n); 

            cout<<endl; 

            for(auto e: villagerDetails)
                {
                    int f = get<0>(e.second);
                    string a = get<1>(e.second);
                    string c = get<2>(e.second);
                    cout<<e.first<<": "<<f<<" "<<a<<" "<<c<<" "<<endl;
                }
            }
            break; 

            case 3: 
                
                cout<<"Friendship has been increased"<<" "<<endl<<endl; 
                for(auto e: villagerDetails)
                {
                   int f = get<0>(e.second);   
                   string a = get<1>(e.second);
                   string c = get<2>(e.second);
                   f = f + i;
                   
                    if(f > 9)
                        cout<<e.first<<": "<<10<<" "<<a<<" "<<c<<" "<<endl;
                    else
                        cout<<e.first<<": "<<++f<<" "<<a<<" "<<c<<" "<<endl;
                     
                }
                i++;
            break;

            case 4: 

                cout<<"Friendship has been decreased"<<endl<<endl; 
                for(auto e: villagerDetails)
                {
                    int f = get<0>(e.second);
                    string a = get<1>(e.second);
                    string c = get<2>(e.second);
                    f = f - j;
                    
                    if(f < 1)
                        cout<<e.first<<": "<<0<<" "<<a<<" "<<c<<" "<<endl;
                    else
                        cout<<e.first<<": "<<--f<<" "<<a<<" "<<c<<" "<<endl;
                }
                j++; 
            break;

            case 5: 

                for(auto e: villagerDetails)
                {
                    cout<<e.first<<", "; 
                }
                cout<<endl;
                cout<<"Which villager's details would you like to search for?"<<endl; 
                getline(cin, n); 
                it = villagerDetails.find(n);
                if(it != villagerDetails.end())
                {
                    cout<<"Villager Found! "<<n<<" details: "<<endl;
                    cout<<get<0>(villagerDetails[n])<<" "<<get<1>(villagerDetails[n])<<" "
                    <<get<2>(villagerDetails[n])<<endl; 
                    
                }
                else 
                    cout<<n<<" not found."<<endl; 

            break;

            case 6: 
                break;

        } 
         
        }while(choice != 6);
    

    

    // access the map using a range-based for loop
   /* cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerDetails) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerDetails.begin(); 
                                               it != villagerDetails.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerDetails.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerDetails.find(searchKey);
    if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl; */

    return 0;
}