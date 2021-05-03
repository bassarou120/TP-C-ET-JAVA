#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class sub_neting
{
private:
   
    string ip_classe;
    int octe_1;
    int octe_2;
    int octe_3;
    int octe_4;
    int octe_5;
    int n_bit_0;
    int nbr_sous_reseau;

public:
    sub_neting(/* args */);
    int convert_binaire_to_int(string v);
    void determineClasse(int value);
    string get_ip_classe();
    void recup_ip();
    void verifier_ip();
    void recup_nbr_sous_reseau();
    void determinen_bit_0();
    void determine_masque_perso();
    void determine_sous_reseau();
};

sub_neting::sub_neting(/* args */)
{
    cout << "*****************************************************************************************\n\n";
    cout << " Application du Subneting en fonction de nombre de machine par sous réseau \n \n";
    cout << "*****************************************************************************************\n";
}

int sub_neting::convert_binaire_to_int(string v)
{

    int j = 128;
    int r = 0;
    for (int i = 0; i < v.length(); i++)
    {

        if (v[i] == '1')
        {

            r = r + j;
        }
        j = j / 2;
    }

    return r;
}

void sub_neting::determineClasse(int v)

{

    // int v = Integer.parseInt(value);

    if (v >= 1 && v <= 127)
    {

        ip_classe = "A";
    }
    else
    {

        if (v >= 128 && v <= 191)
        {
            ip_classe = "B";
        }
        else
        {

            if (v >= 192 && v <= 223)
            {
                ip_classe = "C";
            }
        }
    }
}

string sub_neting::get_ip_classe()
{
    return ip_classe;
}

void sub_neting::recup_ip()
{

    cout << "\n Tapez votre adress ip (Ex: 192.168.8.1/24) \n";
    string ip, newIp;
    cin >> ip;

    cout << " Votre adress ip est le : \n ";
    cout << ip << "\n";
    newIp = ip;

    octe_1 = stoi(newIp.substr(0, newIp.find('.')));
 //   cout << " l'octe 1 :" << octe_1 << "\n";
    newIp = newIp.substr(newIp.find('.') + 1);
    //  cout << " le rest est  :" << ip.substr(ip.find('.') + 1) << "\n";

    octe_2 = stoi(newIp.substr(0, newIp.find('.')));
  //  cout << " l'octe 2 :" << octe_2 << "\n";
    newIp = newIp.substr(newIp.find('.') + 1);
    // cout << " le rest est  :" << newIp.substr(newIp.find('.') + 1) << "\n";

    octe_3 = stoi(newIp.substr(0, newIp.find('.')));
   // cout << " l'octe 3 :" << octe_3 << "\n";
    newIp = newIp.substr(newIp.find('.') + 1);
    // cout << " le rest est  :" << newIp.substr(newIp.find('.') + 1) << "\n";

    octe_4 = stoi(newIp.substr(0, newIp.find('.')));
   // cout << " l'octe 4 :" << octe_4 << "\n";
    newIp = newIp.substr(newIp.find('/') + 1);
    // cout << " le rest est  :" << newIp.substr(newIp.find('.') + 1) << "\n";

    octe_5 = stoi(newIp);
   // cout << " l'octe 5 :" << octe_5 << "\n";
}

void sub_neting::verifier_ip()
{

    if (!(octe_1 >= 0 && octe_1 <= 255))
    {
        cout << "Attention la valeur de l' octe n° 1 de l'adress ip n'est pas entre 0 et 255  \n \n";
    }

    if (!(octe_2 >= 0 && octe_2 <= 255))
    {
        cout << "Attention la valeur de l' octe n° 2 de l'adress ip n'est pas entre 0 et 255  \n \n";
    }

    if (!(octe_3 >= 0 && octe_3 <= 255))
    {
        cout << "Attention la valeur de l' octe n° 2 de l'adress ip n'est pas entre 0 et 255  \n \n";
    }

    if (!(octe_4 >= 0 && octe_4 <= 255))
    {
        cout << "Attention la valeur de l' octe n° 4 de l'adress ip n'est pas entre 0 et 255  \n \n";
    }

    if (octe_1 >= 1 && octe_1 <= 127)
    {

        ip_classe = "A";
        if (octe_5 != 8)
        {
            cout << "Attention il s'agit d'un adresse ip de class A donc le masque par defaut n'est pas correcte \n \n";
        }
    }
    else
    {

        if (octe_1 >= 128 && octe_1 <= 191)
        {
            ip_classe = "B";

            if (octe_5 != 16)
            {
                cout << "Attention il s'agit d'un adresse ip de class A donc le masque par defaut n'est pas correcte \n \n";
            }
        }
        else
        {

            if (octe_1 >= 192 && octe_1 <= 223)
            {
                ip_classe = "C";
                if (octe_5 != 24)
                {
                    cout << "Attention il s'agit d'un adresse ip de class A donc le masque par defaut n'est pas correcte \n \n";
                }
            }
        }
    }
}

void sub_neting::recup_nbr_sous_reseau()
{

    cout << "\n"
         << "Veuillez taper le nombre de machine par sous reseau ";

    cin >> nbr_sous_reseau;
}

void sub_neting::determinen_bit_0()
{

    n_bit_0 = 1;
    double a;
    // Math.pow(s, s)
    while (true)
    {
        a = pow(2, n_bit_0);

        if (a < nbr_sous_reseau + 2)
        {
            n_bit_0++;
        }
        else
        {

            break;
        }
    }

    cout << "le nombre de bit a zero est : " <<n_bit_0<<" \n \n";
}

void sub_neting::determine_masque_perso()
{

    int nbr_bit_un = 32 - n_bit_0;

    string ip = "";

    for (int i = 0; i < 32; i++)
    {
        if (nbr_bit_un <= 0)
        {
            ip = ip + "0";
        }
        else
        {
            ip = ip + "1";
        }

        nbr_bit_un--;
    }

    cout << ip << "\n \n";

    cout << "Le masque personnalisé est : \n";

cout<< ip.substr(1, 8) << "\n";
cout<< ip.substr(9, 8) << "\n";
cout<< ip.substr(16, 8) << "\n";
cout<< ip.substr(24, 8) << "\n";



      int o1=convert_binaire_to_int(ip.substr(1, 8)) ;
    cout << o1 << ".";
    int o2=convert_binaire_to_int(ip.substr(9,8));
    cout << o2 << ".";
   // cout << ip << "\n";
   int o3=convert_binaire_to_int(ip.substr(16, 8));
    cout << o3 << ".";
   // cout << ip << "\n";

   int o4=convert_binaire_to_int(ip.substr(24, 8));
    cout << o4 << "\n \n";
   // cout << ip << "\n";




    int plage_adress=0;
    int nbr_reseau =0;
         int v=0;

         if (ip_classe=="A")
         {
             plage_adress=256 - o2;
                nbr_reseau= pow(2,24-n_bit_0);
                
                
                v=0;
                for(int i=0; i<nbr_reseau ;i++ )
                {
                    if(i==0){
                       v=0; 
                    }else{
                      v=v+  plage_adress;
                    }

                     cout << octe_1 <<"."<< v<< ".0.0" ;
                    cout<<"------";
                 cout << octe_1 <<"."<< v << ".0.1"  ;
                 cout<<"------";
                    cout << octe_1 <<"."<< (v+(plage_adress-1)) << ".255.254"  ;

                     cout<<"------";
                    cout << octe_1 <<"."<< (v+(plage_adress-1)) << ".255.255"  ;
                cout<<"\n";

                }
             
         }
         

          if (ip_classe=="B")
         {

             plage_adress=256-o3;
                nbr_reseau= pow(2,16-n_bit_0);
                
                v=0;
                for(int i=0; i<nbr_reseau;i++ )
                {
                    if(i==0){
                       v=0; 
                    }else{
                      v=v+  plage_adress;
                    }

                     cout << octe_1 <<"."<< octe_2 << "."<< v<< ".0";
                    cout<<"------";
                 cout << octe_1 <<"."<< octe_2 << "."<< v<< ".1";
                 cout<<"------";
                    cout << octe_1 <<"."<< octe_2 << "."<< (v+(plage_adress-1))<< ".254" ;

                     cout<<"------";
                    cout << octe_1 <<"."<< octe_2 << "."<< (v+(plage_adress-1))<< ".255" ;
                cout<<"\n";

                    
                }


         }


         if (ip_classe=="C")
         {
               plage_adress=256-o4;
                 nbr_reseau=pow(2, 8-n_bit_0);
                 
                  v=0;
                for(int i=0; i<nbr_reseau ;i++ )
                {
                    if(i==0){
                       v=0; 
                    }else{
                      v=v+  plage_adress;
                    }


                cout << octe_1 <<"."<< octe_2 << "."<< octe_3<< "."<< v;
                    cout<<"------";
                 cout << octe_1 <<"."<< octe_2 << "."<< octe_3<< "."<< v+1;
                 cout<<"------";
                    cout << octe_1 <<"."<< octe_2 << "."<< octe_3<< "."<< (v+(plage_adress-2));

                     cout<<"------";
                    cout << octe_1 <<"."<< octe_2 << "."<< octe_3<< "."<< (v+(plage_adress-1));
                cout<<"\n";

                }

         }
         

 

            



}

void sub_neting::determine_sous_reseau()
{
   
           
           
           

}

