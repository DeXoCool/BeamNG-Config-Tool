#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <limits>
#include <stdio.h>



using namespace std;

int main()
{
	

	//units
	
    string V;
    string T;
    string P;
    
    //speeds metric
    
   	float ak;
    float bk;
    float ck;
    int sk;
    float abk;
    int tk;
    
    //speeds imperial
    
    float am;
    float bm;
    float cm;
    int sm;
    float abm;
    int tm;
    
    float g; //braking g
    
    //torque
    
    int lbft;
    int nm;
    char trpm[20];
    
    //power
    
    int bhp;
    int hp;
    int kw; 
    char prpm[20];
    
    //misc
    
    string conftype;
    char name[50];
    char desc[200];
    string wd;
    string fuel;
    string induction;
    int offsc;
    int perf;
    string prop;
    string trans;
    int value;
    int weight;
    

cout<<"//////////////////Dex's BeamNG Custom Config Tool\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\nOfficial download only on my GitHub (https://github.com/DeXoCool)\n\n";
  cout<<"----------------- V -----------------\n";
  cout<<"\n";
  cout<<"\n";


        cout<<"Choose velocity units (kph, mph)" << endl;
    cout<<"> ";
    getline(cin, V);
    cout<<"Choose torque units (lbft, Nm)" << endl;
    cout<<"> ";
    getline(cin, T);
    cout<<"Choose power units (hp, bhp, kw)"<< endl;
    cout<<"> ";
    getline(cin, P);
    if (V!="kph"&&V!="mph"){
    	cout<<"Incorrect velocity unit!"<<endl;
            system("pause");
            return 0; }
    if (P!="bhp"&&P!="hp"&&P!="kw"){
    	cout<<"Incorrect power unit!"<<endl;
            system("pause");
            return 0; }
    if (T!="lbft"&&T!="nm"){
    	cout<<"Incorrect torque unit!"<<endl;
            system("pause");
            return 0; }
  cout<<"\n";
    
    
    
    
//=================Speed Kph=====================================
    
    if (V=="kph"){
        cout<<"Enter 0-100 Km/h time E.g. \"5.1\""<< endl;
    	cout<<"> ";
        cin>>ak;
        cout<<"Enter 0-200 Km/h time (0 if not applicable)"<< endl;
    	cout<<"> ";
        cin>>bk;
        if (bk!=0){ 
        	cout<<"Enter 0-300 Km/h time (0 if not applicable)"<< endl;
    		cout<<"> ";
        	cin>>ck;}
        else{
        	abk=0;
        	ck=0;}
        cout<<"Enter Top speed (Km/h)"<< endl;
    	cout<<"> ";
        cin>>tk;
        cout<<"Enter braking distance from 100 Km/h in meters E.g. \"37\""<< endl;
    	cout<<"> ";
        cin>>sk; 
      cout<<"\n";}
        
//================Speed Mph=========================
        
    else
        if (V=="mph"){
            cout<<"Enter 0-60 Mph time E.g. \"5.1\""<< endl;
    		cout<<"> ";
            cin>>am;
            cout<<"Enter 0-100 Mph time (0 if not applicable)"<< endl;
    		cout<<"> ";
            cin>>bm;
            if (bm!=0){
            	cout<<"Enter 0-200 Mph time (0 if not applicable)"<< endl;
    			cout<<"> ";
            	cin>>cm;}
            else{
            	abm=0;
            	cm=0;}
            cout<<"Enter Top speed (Mph)"<<endl;
    		cout<<"> ";
            cin>>tm;
            cout<<"Enter braking distance from 60 Mph in meters E.g. \"37\""<< endl;
		    cout<<"> ";
            cin>>sm;
  cout<<"\n";}
            
//=================Braking G======================
          
    cout<<"Enter Braking G E.g. \"1.12\""<< endl;
    cout<<"> ";
    cin>>g;
    
//=================Torque===============================

    if (T=="lbft"){
        cout<<"Enter torque (lb-ft)"<< endl;
	    cout<<"> ";
        cin>>lbft; }
    else{
            cout<<"Enter torque (N-m)"<< endl;
		    cout<<"> ";
            cin>>nm; }
        
//================Peak Torque RPM=====================

    cout<<"Enter peak torque RPM (X - Y)"<< endl;
    cin.ignore();
    cout<<"> ";
    cin.getline(trpm,20);
    
//==================Power================================

    if (P=="bhp"){
        cout<<"Enter power (bhp)"<< endl;
   		 cout<<"> ";
        cin>>bhp; }
    else
        if (P=="hp"){
            cout<<"Enter power (hp)"<< endl;
   			 cout<<"> ";
            cin>>hp; }
        else{
                cout<<"Enter power (kW)"<< endl;
 			   cout<<"> ";
                cin>>kw; }
                
//=================Peak Power RPM======================
    
    cout<<"Enter peak power RPM (X - Y)"<<endl;
    cin.ignore();
    cout<<"> ";
    cin.getline(prpm,20);
  cout<<"\n";
    
//================Other Stuff===========================
    
    cout<<"\n";
    cout<<"* - can be anything | # - has to be a whole number | ! - anything without spaces"<<endl;
    cout<<"\n";
    cout<<"* Enter name (max 50 char.)"<<endl;
    cout<<"> ";
    cin.getline(name,50);
    cout<<"* Enter description (max 200 char.)"<<endl;
    cout<<"> ";
    cin.getline(desc,200);
    cout<<"! Enter drivetrain type (RWD, FWD, AWD)"<<endl;
    cout<<"> ";
    cin>>wd;
    cout<<"! Enter fuel type (Gasoline, Diesel, Battery)"<<endl;
    cout<<"> ";
    cin>>fuel;
    if (fuel!="Battery"){
    cout<<"! Enter forced induction type (NA, Turbo, SC)"<<endl;
    cout<<"> ";
    cin>>induction;
	prop="ICE";}
    else{
    induction="0";
    prop="Electric";}
    cout<<"# Enter offroad score"<<endl;
    cout<<"> ";
    cin>>offsc;
    cout<<"# Enter performance class"<<endl;
    cout<<"> ";
    cin>>perf;
    if (prop!="Electric"){
    cout<<"! Enter transmission type (DCT, Sequential, Manual, Automatic, CVT, Other)"<<endl;
    cout<<"> ";
    cin>>trans;}
    else
    trans="Other";
    cout<<"# Enter configuration's value"<<endl;
    cout<<"> ";
    cin>>value;
    cout<<"# Enter configuration's weight (kg)"<<endl;
    cout<<"> ";
    cin>>weight;

    
//===================Result=================================================================================

cout<<"---------------------------------Copy text below---------------------------------\n\n\n\n";
  
	cout<<"{"<<endl;
	if (V=="kph"){ cout<<"\"0-100 km/h\":"; cout<<ak; cout<<","<<endl;}
    if (V=="mph"&&bm!=0){ cout<<"\"0-100 mph\":"; cout<<bm; cout<<","<<endl;}
    if (V=="kph"&&bk!=0){ cout<<"\"0-200 km/h\":"; cout<<bk; cout<<","<<endl;}
    if (V=="kph"&&ck!=0){ cout<<"\"0-300 km/h\":"; cout<<ck; cout<<","<<endl;}
    if (V=="mph"){ cout<<"\"0-60 mph\":"; cout<<am; cout<<","<<endl;}
    if (V=="kph"){ cout<<"\"100-0 km/h\":"; cout<<sk; cout<<","<<endl;}
    if (V=="kph"&&bk!=0){ cout<<"\"100-200 km/h\":"; cout<<bk-ak; cout<<","<<endl;}
    if (V=="mph"){ cout<<"\"60-0 mph\":"; cout<<sm; cout<<","<<endl;}
    if (V=="mph"&&bm!=0){ cout<<"\"60-100 mph\":"; cout<<bm-am; cout<<","<<endl;}
    cout<<"\"Braking G\":"; cout<<g; cout<<","<<endl;
    cout<<"\"Config Type\":\""; cout<<conftype; cout<<"\","<<endl;
    cout<<"\"Configuration\":\""; cout<<name; 
		if (trans=="DCT"){cout<<" (DCT)";
		}else
			if (trans=="Sequential"){cout<<" (Sequential)";}
			else
				if (trans=="Manual"){cout<<" (M)";}
				else
					if (trans=="Automatic"){cout<<" (A)";}
					else
						if (trans=="CVT"){cout<<" (CVT)";}
						else cout<<" ";
		cout<<"\","<<endl;
    cout<<"\"Description\":\""; cout<<desc; cout<<"\","<<endl;
    cout<<"\"Drivetrain\":\""; cout<<wd; cout<<"\","<<endl;
    cout<<"\"Fuel Type\":\""; cout<<fuel; cout<<"\","<<endl;
    if (induction!="0"){ cout<<"\"Induction Type\":\""; cout<<induction; cout<<"\","<<endl; }
    cout<<"\"Off-Road Score\":"; cout<<offsc; cout<<","<<endl;
    cout<<"\"Performance Class\":\""; cout<<perf; cout<<"\","<<endl;
    if (P=="hp"){
    cout<<"\"Power\":"; cout<<hp; cout<<","<<endl; }
    else
        if (P=="bhp"){
            cout<<"\"Power\":"; cout<<bhp*1.0139; cout<<","<<endl;}
        else{
            cout<<"\"Power\":"; cout<<kw*1.3596; cout<<","<<endl;}
    cout<<"\"PowerPeakRPM\":\""; cout<<prpm; cout<<"\","<<endl;
    cout<<"\"Propulsion\":\""; cout<<prop; cout<<"\","<<endl;
    if (V=="kph") {
        cout<<"\"Top Speed\":"; cout<<tk*0.278; cout<<","<<endl; }
        else {
            cout<<"\"Top Speed\":"; cout<<tm*0.447; cout<<","<<endl; }
    if (T=="nm"){
        cout<<"\"Torque\":"; cout<<nm; cout<<","<<endl; }
    else
        cout<<"\"Torque\":"; cout<<lbft/0.738; cout<<","<<endl;
    cout<<"\"TorquePeakRPM\":\""; cout<<trpm; cout<<"\","<<endl;
    cout<<"\"Transmission\":\""; cout<<trans; cout<<"\","<<endl;
    cout<<"\"Value\":"; cout<<value; cout<<","<<endl;
    cout<<"\"Weight\":"; cout<<weight; cout<<","<<endl;
    if (P=="hp"){
        cout<<"\"Weight/Power\":"; cout<<weight/hp; cout<<","<<endl; }
    else
        if (P=="bhp"){
            cout<<"\"Weight/Power\":"; cout<<weight/(bhp*1.0139); cout<<","<<endl; }
        else{
            cout<<"\"Weight/Power\":"; cout<<weight/(kw*1.3596); cout<<","<<endl; }
    cout<<"}"<<endl;
    
    cout<<"\n\n\n---------------------------------Copy text above---------------------------------";
    
    cout<<"\n\nMade by DeX\nhttps://www.youtube.com/c/JustDeX5\nhttps://github.com/DeXoCool\nhttps://twitter.com/Just_DeXbruh"<<endl;

	return 0;
}