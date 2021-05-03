//
//  main.cpp
//  TP C++ SUBNETING
//
//  Created by yacoubou bassarou on 30/04/2021.
//  Copyright © 2021 toptic-solutions. All rights reserved.
//

#include <iostream>
using namespace std;

 #include  "sub_neting.cpp"
 


int main(int argc, const char * argv[]) {
    
    sub_neting sub_neting_objet= sub_neting();
    sub_neting_objet.recup_ip();
    sub_neting_objet.verifier_ip();
    sub_neting_objet.recup_nbr_sous_reseau();
    sub_neting_objet.determinen_bit_0();
    sub_neting_objet.determine_masque_perso();




 

    return 0;
}
