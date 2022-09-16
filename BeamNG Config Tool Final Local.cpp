#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <limits>
#include <stdio.h>

std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

using namespace std;

int main()
{
	
	//saveclear
	string clear;
	
	//directory
	
	char DIR[100];
	char DIRB[100];
	char DirV[20];

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
    
//=====================Setup====================================

cout<<"//////////////////Dex's BeamNG Custom Config Tool\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\nOfficial download only on my GitHub (https://github.com/DeXoCool)\n\n";

	cout<<"Game directory save has to be cleared after every update!\n\n";
	remakesave:
  cout<<"----------------- V -----------------\n";
  cout<<"\n";
  cout<<"\n";
  
  
  
  
  
  
  
  
  ifstream savecheck("DeX Config Tool Save.txt");
string svcheck;
getline (savecheck, svcheck);
if (svcheck=="https://www.youtube.com/c/JustDeX5"){
	cout<<"Success! Save file found. If you want to clear it, type \"clear\".\n";
	fstream readsave("DeX Config Tool Save.txt");
	GotoLine(readsave, 2);
	readsave.getline(DIR, 100);
	GotoLine(readsave, 3);
	readsave>>V;
	GotoLine(readsave, 4);
	readsave>>T;
	GotoLine(readsave, 5);
	readsave>>P;
	cout<<"Directory: ";
	cout<<DIR<<endl;
	cout<<"Velocity unit: ";
	cout<<V<<endl;
	cout<<"Torque unit: ";
	cout<<T<<endl;
	cout<<"Power unit: ";
	cout<<P<<endl<<endl;}
	else{//remake save
//1. directory
	cout<<"Save file not found!\nEnter BeamNG vechicles folder directory E.g.\"C:\\Users\\name\\BeamNG\\0.25\\vechicles\"\n";
    cout<<"> ";
	cin.getline(DIR,100);
//2. units
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

	ofstream newsave("DeX Config Tool Save.txt");
	newsave<<"https://www.youtube.com/c/JustDeX5\n";//line1
	newsave<<DIR;//line2
	newsave<<endl;
	newsave<<V;//line3
	newsave<<endl;
	newsave<<T;//line4
	newsave<<endl;
	newsave<<P;//line5
	newsave.close();
	
	cout<<"Save File Created\n\n\n";
	
	}

//Main=============================================================
    
    cout<<"Enter vechicle folder name E.g. \"etk800\" (\"clear\" to remove the save file)\n";
    cout<<"> ";
    cin.getline(DirV,50);
clear=DirV;

//save clear and remake
if (clear == "clear"){
	savecheck.close();
	if (remove("DeX Config Tool Save.txt")==0) cout<<"Save removed successfully.\n";
	else{
	 cout<<"Failed to remove save! Try again or delete \"DeX Config Tool Save.txt\" manually\n";
		system("pause");
            return 0; }

	cout<<"Starting over...\n\n\n\n";
	goto remakesave;}

//directory compiler
  char sl[5]="\\";
char ext[10]=".json";
    strcat(DIR, sl);
strcat(DIR, DirV);
strcat(DIR, sl);
    
    cout<<"Enter config file name\n";
    cout<<"> ";
cin.getline(DIRB,100);

char info[10]="info_";
strcat(DIR, info);
strcat(DIR, DIRB);
strcat(DIR, ext);

cout<<"Final Output Directory: ";
cout<<DIR;
cout<<"\n\n\n";
    
    
    
    
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



  ofstream file(DIR);
  
	file<<"{"<<endl;
	if (V=="kph"){ file<<"\"0-100 km/h\":"; file<<ak; file<<","<<endl;}
    if (V=="mph"&&bm!=0){ file<<"\"0-100 mph\":"; file<<bm; file<<","<<endl;}
    if (V=="kph"&&bk!=0){ file<<"\"0-200 km/h\":"; file<<bk; file<<","<<endl;}
    if (V=="kph"&&ck!=0){ file<<"\"0-300 km/h\":"; file<<ck; file<<","<<endl;}
    if (V=="mph"){ file<<"\"0-60 mph\":"; file<<am; file<<","<<endl;}
    if (V=="kph"){ file<<"\"100-0 km/h\":"; file<<sk; file<<","<<endl;}
    if (V=="kph"&&bk!=0){ file<<"\"100-200 km/h\":"; file<<bk-ak; file<<","<<endl;}
    if (V=="mph"){ file<<"\"60-0 mph\":"; file<<sm; file<<","<<endl;}
    if (V=="mph"&&bm!=0){ file<<"\"60-100 mph\":"; file<<bm-am; file<<","<<endl;}
    file<<"\"Braking G\":"; file<<g; file<<","<<endl;
    file<<"\"Config Type\":\""; file<<conftype; file<<"\","<<endl;
    file<<"\"Configuration\":\""; file<<name; 
		if (trans=="DCT"){file<<" (DCT)";
		}else
			if (trans=="Sequential"){file<<" (Sequential)";}
			else
				if (trans=="Manual"){file<<" (M)";}
				else
					if (trans=="Automatic"){file<<" (A)";}
					else
						if (trans=="CVT"){file<<" (CVT)";}
						else file<<" ";
		file<<"\","<<endl;
    file<<"\"Description\":\""; file<<desc; file<<"\","<<endl;
    file<<"\"Drivetrain\":\""; file<<wd; file<<"\","<<endl;
    file<<"\"Fuel Type\":\""; file<<fuel; file<<"\","<<endl;
    if (induction!="0"){ file<<"\"Induction Type\":\""; file<<induction; file<<"\","<<endl; }
    file<<"\"Off-Road Score\":"; file<<offsc; file<<","<<endl;
    file<<"\"Performance Class\":\""; file<<perf; file<<"\","<<endl;
    if (P=="hp"){
    file<<"\"Power\":"; file<<hp; file<<","<<endl; }
    else
        if (P=="bhp"){
            file<<"\"Power\":"; file<<bhp*1.0139; file<<","<<endl;}
        else{
            file<<"\"Power\":"; file<<kw*1.3596; file<<","<<endl;}
    file<<"\"PowerPeakRPM\":\""; file<<prpm; file<<"\","<<endl;
    file<<"\"Propulsion\":\""; file<<prop; file<<"\","<<endl;
    if (V=="kph") {
        file<<"\"Top Speed\":"; file<<tk*0.278; file<<","<<endl; }
        else {
            file<<"\"Top Speed\":"; file<<tm*0.447; file<<","<<endl; }
    if (T=="nm"){
        file<<"\"Torque\":"; file<<nm; file<<","<<endl; }
    else
        file<<"\"Torque\":"; file<<lbft/0.738; file<<","<<endl;
    file<<"\"TorquePeakRPM\":\""; file<<trpm; file<<"\","<<endl;
    file<<"\"Transmission\":\""; file<<trans; file<<"\","<<endl;
    file<<"\"Value\":"; file<<value; file<<","<<endl;
    file<<"\"Weight\":"; file<<weight; file<<","<<endl;
    if (P=="hp"){
        file<<"\"Weight/Power\":"; file<<weight/hp; file<<","<<endl; }
    else
        if (P=="bhp"){
            file<<"\"Weight/Power\":"; file<<weight/(bhp*1.0139); file<<","<<endl; }
        else{
            file<<"\"Weight/Power\":"; file<<weight/(kw*1.3596); file<<","<<endl; }
    file<<"}"<<endl;
    
    
    //=======================User Preview===============================================================================
    
    
    cout<<"\n";
    cout<<"\n";
    cout<<"----------------- Output Preview -----------------"<<endl;
    cout<<"\n";
    cout<<"\n";
    string preview;
    ifstream fileread(DIR);
    while (getline (fileread, preview)){
    	cout<< preview<<endl;
	}
		cout<<"\nIf you can't see a preview above, the directory is wrong. Clear and reenter it to fix this. Tip: you can right click on the file explorer address bar and copy it as text to ensure it is correct.\n\n";
    cout<<"Made by DeX\nhttps://www.youtube.com/c/JustDeX5\nhttps://github.com/DeXoCool\nhttps://twitter.com/Just_DeXbruh"<<endl;

	return 0;
}