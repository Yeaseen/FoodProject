#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define STRMAX 50
#define arraySize 50

using namespace std;


class Nutrition
{
public:

	char name[STRMAX];
	int numOfComponents=15;
	char components[15][STRMAX];
	double measurement[15];
	char metric[15][STRMAX];
	double dailyPercent[15]= {};

	double dailyIntake[15]={2000, 310, 50, 70,24,90,30,2.3,4000,380,18,5000,2,60,400};

	void print(){
		cout<<"Name of the label: "<<name<<endl;
		cout<<"Component Name	   measurement		Metric		Daily Percentage"<<endl;
		for (int i = 0; i < numOfComponents; ++i)
		{
			if(i==3 || i==10){
				cout<<i+1<<"."<<components[i]<<"   		"<<measurement[i]<<"		"<<metric[i]<<"			"<<(measurement[i]/dailyIntake[i])*100<<"%"<<endl;
			}
			else{
				cout<<i+1<<"."<<components[i]<<"		"<<measurement[i]<<"		"<<metric[i]<<"			"<<(measurement[i]/dailyIntake[i])*100<<"%"<<endl;
			}  
		}
		cout<<endl<<endl<<"==============================================================="<<endl<<endl;
	}



};
void showMenuBar(Nutrition nutr[],int current);
void NutritionPage(Nutrition nutr[], int current);
void nutritionViewPage(Nutrition nutr[], int current);
void quitPage(Nutrition nutr[], int current);


void quitPage(Nutrition nutr[], int current){

	cout<<endl<<"******** Quit Page ******"<<endl;
    cout<<endl<<"Options"<<endl;
	cout<<"1.Save and exit"<<endl;
	cout<<"2.Don't Save and exit"<<endl;
	cout<<"3.Go to main menu"<<endl;
	cout<<"To choose press corresponding number: "<<endl;


	int option;

   	cin>>option;
   	if(option==1){
   		//save to file and exit part

   		ofstream save;
   		save.open("Database.txt");

   		save<<current<<endl<<endl;

   		for (int i = 0; i < current; ++i)
   		{
   			save<<nutr[i].name<<endl<<endl;
   			for (int j = 0; j < nutr[i].numOfComponents ; ++j)
   			{
   				save<<nutr[i].components[j]<<" "<<nutr[i].measurement[j]<<" "<<nutr[i].metric[j]<<endl<<endl;
   			}
   		}
         
        save.close();
        cout<<endl<<"Succcessfully save all data to database"<<endl;
        cout<<endl<<"Application is clossing.. .. .."<<endl;
   		exit(0);	
   	} 
   	else if(option==2) {
   		cout<<endl<<"Application is clossing.. .. .."<<endl;
   		exit(0);
   	}
   	else{
   		showMenuBar(nutr,current);
   	}

}

void showMenuBar(Nutrition nutr[], int current){
	cout<<endl<<endl;
	cout<<"********* Main Menu Page *********"<<endl;
	cout<<endl<<"Options"<<endl;
	cout<<"1.Nutrition Labels"<<endl;
	cout<<"2.Recipes"<<endl;
	cout<<"3.Quit"<<endl<<endl;
	cout<<"To choose press corresponding number: "<<endl;
	int option;
   	cin>>option;

   	
   	if(option==1) {
   		NutritionPage(nutr,current);
        
   	}
   	else if(option==2){
   		cout<<endl<<"******** Recipes label ******"<<endl;
   		cout<<endl<<"Not programmed this path"<<endl;
   		showMenuBar(nutr,current);
   	}
   	else if(option==3){
   		
   		
   		quitPage(nutr,current);
   	}

}

void NutritionPage(Nutrition nutr[], int current){

	cout<<endl<<endl;
	cout<<"******* Nutrion Page **********"<<endl;
	cout<<endl<<"Options"<<endl;

	cout<<"1.Add a new label."<<endl;
	cout<<"2.Edit a label"<<endl;
	cout<<"3.Delete a label"<<endl;
	cout<<"4.Go to Nutrition View page"<<endl;
	cout<<"5.Back to main menu"<<endl;
	cout<<"To choose press corresponding number: "<<endl;
    int option;
    cin>>option;
	if(option==1){
		cout<<endl<<"******** New label ******"<<endl;
		current++;
        if(current>50){
        	cout<<"There is no space for Nutrition labels"<<endl;
        	NutritionPage(nutr,current);
        }
		char inp[20];
		cout<<"Enter the File name (filename.txt): "<<endl;
		//cin.getline(inp,sizeof(inp));
		cin>>inp;
		ifstream stage2;
		stage2.open ("banana.txt");
		stage2>>nutr[current-1].name;


		int i=0;

		while(i<nutr[current-1].numOfComponents){
			stage2>>nutr[current-1].components[i]>>nutr[current-1].measurement[i]>>nutr[current-1].metric[i];
			i++;

		}

		stage2.close();

    cout<<"Adding part done. "<<endl;
	NutritionPage(nutr,current);
	
	}
	else if(option==2){
		cout<<"******** Edit a Label's component"<<endl;
        int itemNo,componentNo;

        cout<<"Please input the Nutrition label No."<<endl;
        cin>>itemNo;
        cout<<"Please input the Component No"<<endl;
        cin>>componentNo;

        cout<<"Please Give the changed value "<<endl;
        double measure;
        cin>>measure;

        nutr[itemNo-1].measurement[componentNo-1]=measure;

		cout<<"sucessfully Edited the value"<<endl;

		NutritionPage(nutr,current);
	}
	else if(option==3){
		cout<<endl<<"******** Delete label ******"<<endl;

		cout<<"Please input the corresponding item no to delete within the range 1 to "<<current<<endl;

		int itemNo;
		cin>>itemNo;

		if(itemNo>current){
			cout<<"Your input is invalid"<<endl;
			nutritionViewPage(nutr,current);

		}
		else{
			itemNo-=1;
			for (int i = itemNo; i < current-1; ++i){
				nutr[i]=nutr[i+1];
			}
			current-=1;
			cout<<"Nutrition label deleted sucessfully!"<<endl;
			NutritionPage(nutr,current);
		}

	}
	else if(option==4){

       	nutritionViewPage(nutr,current);
	}
	else if(option==5){
		cout<<endl<<"******** Back to main menu from Nutrition Page ******"<<endl;
		showMenuBar(nutr,current);
	}

}

void nutritionViewPage(Nutrition nutr[], int current){
	cout<<endl<<"******** Nutrition View Page ******"<<endl;
    cout<<"There are "<<current<<" nutrition labels now"<<endl;
	

	cout<<endl<<"Options"<<endl;

	cout<<"1. View all Nutrition Label's name"<<endl;
	cout<<"2. View specific label's components"<<endl;
	cout<<"3. Print all Nutrition label's details to a output file"<<endl;
	cout<<"4. Go to Nutrition Page"<<endl;
	cout<<"5. Go to Main Menu Bar"<<endl;

	cout<<"To choose press corresponding number: "<<endl;

	int option;
	cin>>option;
	if(option==1){

		cout<<endl<<endl;
		cout<<"Item No     Names"<<endl;
		for (int i = 0; i < current; ++i){
        	cout<<i+1<<".     "<<nutr[i].name<<endl;
        }
        nutritionViewPage(nutr,current);

	}
	else if(option==2){

		cout<<"Please input the corresponding integer number within the range 1 to "<<current<<endl;
		int itemNo;
		cin>>itemNo;
		if(itemNo>current){
			cout<<"Your input is invalid"<<endl;
			nutritionViewPage(nutr,current);
		}
		else{
			cout<<endl<<"Output of Query"<<endl;
			nutr[itemNo-1].print();
			nutritionViewPage(nutr,current);
		}

	}
	else if(option==3){
		ofstream fout;
		fout.open ("Output.txt");

		for (int i = 0; i < current; ++i){

			fout<<"Name of the label: "<<nutr[i].name<<endl<<endl;
			fout<<"Component Name 	 measurement 	 Metric 	 Daily Percentage"<<endl<<endl;
			for (int j = 0; j < nutr[i].numOfComponents; ++j)
			{
				
				fout<<j+1<<"."<<nutr[i].components[j]<<" --	-- 	"<<nutr[i].measurement[j]<<" --	 --	"<<nutr[i].metric[j]<<" --	 --	"<<(nutr[i].measurement[j]/nutr[i].dailyIntake[j])*100<<"%"<<endl<<endl;
		    
		}

		fout<<endl<<endl<<"==============================================================="<<endl<<endl;

			
		}

        fout.close();

        cout<<"Print all labels's compoments to Output.txt file"<<endl;
        NutritionPage(nutr,current);


	}
	else if(option==4){
		NutritionPage(nutr,current);
	}
	else if(option==5){
		showMenuBar(nutr,current);

	}


}

int main(){
   	
	Nutrition lists[50];
    
	

  
	
	ifstream stage1;
	stage1.open ("Database.txt");
	int items;
	stage1>>items;

    for (int j = 0; j < items; ++j){

    	stage1>>lists[j].name;
    	int i=0;

		while(i<lists[j].numOfComponents){
			stage1>>lists[j].components[i]>>lists[j].measurement[i]>>lists[j].metric[i];
			i++;	

		}
    	
    }
    stage1.close();
    cout<<"Succcessfully fetxhed data from database file"<<endl;
	showMenuBar(lists,items);
   	return 0;
}