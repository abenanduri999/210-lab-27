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
        cout<<e.first<<": ["<<f<<", "<<a<<", "<<c<<" ]"<<endl;
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
                    cout<<e.first<<": ["<<f<<", "<<a<<", "<<c<<" ]"<<endl;
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
                    cout<<e.first<<": ["<<f<<", "<<a<<", "<<c<<" ]"<<endl;
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
                    cout<<e.first<<": ["<<f<<", "<<a<<", "<<c<<" ]"<<endl;
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
                   f = f + i - j;
                   
                    if(f > 9)
                        cout<<e.first<<": ["<<10<<", "<<a<<", "<<c<<" ]"<<endl;
                    else
                        cout<<e.first<<": ["<<++f<<", "<<a<<", "<<c<<" ]"<<endl;
                     
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
                    f = f - j + i;
                    
                    if(f < 1)
                        cout<<e.first<<": ["<<0<<", "<<a<<", "<<c<<" ]"<<endl;
                    else
                        cout<<e.first<<": ["<<--f<<", "<<a<<", "<<c<<" ]"<<endl;
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
    
    return 0;
}