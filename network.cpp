#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Device
{
public:
    string device_id;
    string device_name;
    string device_type;
    string ip_address;
    string mac_address;
    string status;
    Device(string device_id, string device_name,
           string device_type, string ip_address, string mac_address, string status)
    {

        this->device_id = device_id;
        this->device_name = device_name;
        this->device_type = device_type;
        this->ip_address = ip_address;
        this->mac_address = mac_address;
        this->status = status;
    }
    virtual void display()
    {
        cout << "Loading device details\n";
        cout << "Device id = " << device_id << endl;
        cout << "Device name is = " << device_name << endl;
        cout << "Device Type is " << device_type << endl;
        cout << "IP address is " << ip_address << endl;
        cout << "MAC Address is " << mac_address << endl;
        cout << "STATUS" << status << endl;
    }
};

class Computer : public Device
{
public:
    string OS;
    string processor;
    int ram;
    int storage;
    string username;
    Computer(string OS, string device_id, string device_name,
             string device_type, string ip_address, string mac_address, string status, string processor, int ram, int storage, string username) : Device(device_id, device_name,
                                                                                                                                                         device_type, ip_address, mac_address, status)
    {

        this->processor = processor;
        this->ram = ram;
        this->storage = storage;
        this->username = username;
        this->OS = OS;
    }
    void display()
    {
        cout << "Device id = " << device_id << endl;
        cout << "Device name is = " << device_name << endl;
        cout << "Device Type is " << device_type << endl;
        cout << "IP address is " << ip_address << endl;
        cout << "MAC Address is " << mac_address << endl;
        cout << "STATUS = " << status << endl;
        cout << "Processor = " << processor << endl;
        cout << "RAM = " << ram << endl;
        cout << "STORAGE = " << storage << endl;
        cout << "USERNME = " << username << endl;
        cout << "OS = " << OS << endl;
    }
    void createfile()
    {
        ofstream file;
        file.open("network.txt");
        file << "NETWORK TRANSFER REPORT.\n";
        file << "Source Device: PC1.\n";
        file << "Destination Device: PC1.\n";
        file << "File Type: TEXT.\n";
        file << "Priority: NORMAL.\n";

        file << "This file contains network simulation data.\n";
        file << "The file will be divided into packets and transmitted.\n";
        file << "from PC1 to PC2 through the configured network path.\n";

        file << "Transfer Status: PENDING.\n";
        file.close();
    }
    void viewfile()
    {
        ifstream file;
        file.open("network.txt");
        string data;
        while (getline(file, data))
        {
            cout << data << endl;
        }
    }
    void append()
    {
        ofstream file("network.txt", ios::app);
        string data;
        cout << "Enter data to append\n";
        cin >> data;
        file << data << endl;
        file.close();
    }
    void removefile()
    {
        if (remove("network.txt") == 0)
        {
            cout << "File removed successfully\n";
        }
        else
        {
            cout << "Not removed\n";
        }
    }
};
class Switch
{
public:
    string switch_id;
    string switch_name;
    string switch_type;
    string Description;
    int Portnumber;
    int Connected_Device;
    string destinationMAC;
    string MAC_address;
    Switch(string switch_id,
           string switch_name,
           string switch_type,
           string Description,
           int Portnumber,
           int Connected_Device,
           string destinationMAC,
           string MAC_address)
    {
        cout << "Switch : A network device that connects devices in a LAN and forwards data using their MAC addresses\n ";
        this->switch_id = switch_id;
        this->switch_name = switch_name;
        this->switch_type = switch_type;
        this->Description = Description;
        this->Portnumber = Portnumber;
        this->Connected_Device = Connected_Device;
        this->destinationMAC = destinationMAC;
        this->MAC_address = MAC_address;
    }
    void getinfo()
    {
        cout << "Switch_id is : " << switch_id << endl;
        cout << "Switch_name : " << switch_name << endl;
        cout << "Switch_type : " << switch_type << endl;
        cout << "Other related info : " << Description << endl;
        cout << "Portnumber : " << Portnumber << endl;
        cout << "Connected_device : " << Connected_Device << endl;
        cout << "Destiation MAC ADDRESS : " << destinationMAC << endl;
    }
    void forwardframe(string destinationMAC)
    {
        if (destinationMAC == "AA:BB:CC:11:22:93")
        {
            cout << "Fowarded thorugh port number : " << Portnumber << endl;
        }
        else
        {
            cout << "DO NOT FORWRAD THE FRAME\n";
        }
    }
};
class Router
{
private:
    string router_id;
    string router_name;
    string router_type;
    string description;
    int portnumber;
    int connected_device;
    string ip_address;
    string status;

public:
    Router(string router_id,
           string router_name,
           string router_type,
           string description,
           int portnumber,
           int connected_device,
           string ip_address,
           string status)
    {
        this->router_id = router_id;
        this->router_name = router_name;
        this->router_type = router_type;
        this->description = description;
        this->portnumber = portnumber;
        this->connected_device = connected_device;
        this->ip_address = ip_address;
        this->status = status;
    }
    void showDeviceinfo()
    {
        cout << "router_id : " << router_id << endl;
        cout << "router_name : " << router_name << endl;
        cout << "router_type : " << router_type << endl;
        cout << "description : " << description << endl;
        cout << "portnumber  : " << portnumber << endl;
        cout << "connected_device : " << connected_device << endl;
        cout << "ip_address : " << ip_address << endl;
        cout << "Status : " << status << endl;
    }
    void findroute(Computer Pc2 , string  destination_ip)
    {
        if (destination_ip ==Pc2.ip_address) {
 cout << "ROUTE FOUND\n" ; 
        }
        else {
            cout << "ROUTE NOT FOUND\n" ;
        }
    
}
} ; 

int main()
{
    string Uservalue;
    cout << "Displaying user data\n";

    // CREATING THE FIRST PC DEVICE //
    Computer Pc1("linux", "PC01", "Office-PC-01", "Computer",
                 "192.168.1.10", "AA:BB:CC:11:22:33", "Online",
                 "Intel Core i5", 16, 512, "ridham");

    Pc1.display();
    Computer Pc2("Windows", "PC02", "Office-PC-02", "Computer",
                 "192.168.1.13", "AA:BB:CC:11:22:93", "Online",
                 "Intel Core i7", 16, 512, "rahul");
    int choice;
    cout << "Entering LINUX BASED SERVER\n";
    cout << "YES/NO : ";
    cin >> Uservalue;
    if (Uservalue == "Y")
    {
        cout << "Congratulations linux server enabled\n";
        cout << "1 : Create a file\n";
        cout << "2 : Add content in the file\n";
        cout << "3 : View a file\n";
        cout << "4 : Remove a file\n";
        cout << "Enter user choice : ";
        cin >> choice;
    }
    // cases for the file //
    switch (choice)
    {
    case 1:
        Pc1.createfile();
        cout << "File created\n";
        break;
        // case 2
    case 2:
        cout << "ENTER THE CORRECT COMMAND TO APPEND DATA\n";
        cin >> Uservalue;
        if (Uservalue == "nano")
        {
            Pc1.append();
        }
    case 3:
        cout << "View the file\n";
        Pc1.viewfile();
        break;
    case 4:
        cout << "Enter command to remove a file\n";
        cin >> Uservalue;
        if (Uservalue == "rm")
        {
            Pc1.removefile();
        }

        break;

    default:
        cout << "Invalid option\n";
    }
    Switch sw1(
        "SW1",
        "Switch-1",
        "Layer 2 Switch",
        "Connects devices in a LAN and forwards frames using MAC addresses",
        4,
        2,
        "AA:BB:CC:DD:EE:02",
        "AA:BB:CC:DD:EE:01");
    sw1.getinfo();
    Router r1("R1",
              "Router-1",
              "Network Router",
              "Connects different networks and forwards packets",
              4,
              2,
              "192.168.1.1",
              "ONLINE");  
            r1.findroute(Pc2 , "192.168.1.13") ; 
}
