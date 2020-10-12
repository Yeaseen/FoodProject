#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define STRMAX 50
#define arraySize 50

using namespace std;

//add nothing
class Nutrition
{
public:

	char name[STRMAX];
	int numOfComponents=15;
	char components[15][STRMAX];
	double measurement[15];
	char metric[15][STRMAX];
	double dailyPercent[15]= {};

	double dailyIntake[15]={2000, 310, 56, 70, 24, 90, 30, 2.3, 4, 0.35, 25, 5000, 2, 60, 400};

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

class Recipe
{
public:
	char name[STRMAX];
	int servePeople;
	int numOfIngrad;

	char componentsR[100][STRMAX];

	char measurementR[100][STRMAX];

	char metricR[100][STRMAX];

	void print(){
		cout<<"Name of the Recipe: "<<name<<endl;
		cout<<"Number of People Served: "<<servePeople<<endl;
		cout<<"Recipe Name                Measurement            Metric"<<endl;

		for (int i = 0; i < numOfIngrad; ++i)
		{
			cout<<i+1<<". "<<componentsR[i]<<"         "<<measurementR[i]<<"             "<<metricR[i]<<endl<<endl;
		}

		cout<<endl<<endl<<"==============================================================="<<endl<<endl;
	}

};


void showMenuBar(Nutrition nutr[], int current, Recipe recip[], int currRecip);
void NutritionPage(Nutrition nutr[], int current, Recipe recip[], int currRecip);
void nutritionViewPage(Nutrition nutr[], int current, Recipe recip[], int currRecip);
void quitPage(Nutrition nutr[], int current,Recipe recip[], int currRecip);
void RecipePage(Nutrition nutr[], int current, Recipe recip[], int currRecip);
void recipeViewPage(Nutrition nutr[], int current, Recipe recip[], int currRecip);


void quitPage(Nutrition nutr[], int current,Recipe recip[], int currRecip){

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
   		save.open("NutritionDatabase.txt");

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
        cout<<endl<<"Succcessfully save all data to NutritionDatabase"<<endl;

        save.open("RecipeDatabase.txt");
		save<<currRecip<<endl;
		for (int i = 0; i < currRecip; i++)
		{
			save<<recip[i].name<<endl;
			save<<recip[i].servePeople<<endl;
			save<<recip[i].numOfIngrad<<endl;

			for (int j = 0; j < recip[i].numOfIngrad ; j++)
			{
				save<<recip[i].componentsR[j]<<endl;
				save<<recip[i].measurementR[j]<<" "<<recip[i].metricR[j]<<endl; 
			}
			
		}
		save.close();
		cout<<endl<<"Succcessfully save all data to RecipeDatabase"<<endl;

        cout<<endl<<"Application is clossing.. .. .."<<endl;
   		exit(0);	
   	} 
   	else if(option==2) {
   		cout<<endl<<"Application is clossing.. .. .."<<endl;
   		exit(0);
   	}
   	else{
   		showMenuBar(nutr,current,recip,currRecip);
   	}

}

void showMenuBar(Nutrition nutr[], int current, Recipe recip[], int currRecip){
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
   		NutritionPage(nutr,current,recip,currRecip);
        
   	}
   	else if(option==2){
   		RecipePage(nutr,current,recip,currRecip);

   	}
   	else if(option==3){
   		quitPage(nutr,current,recip,currRecip);
   	}

}

void RecipePage(Nutrition nutr[], int current, Recipe recip[], int currRecip){
    cout<<endl<<endl;
	cout<<"******* Recipe Page **********"<<endl;
	cout<<endl<<"Options"<<endl;

	cout<<"1.Add a new Recipe label."<<endl;
	cout<<"2.Edit a Recipe label"<<endl;
	cout<<"3.Delete a Recipe label"<<endl;
	cout<<"4.List of Recipes that contains up to 3 ingredients"<<endl;
	cout<<"5.Go to Recipe View page"<<endl;
	cout<<"6.Back to main menu"<<endl;
	cout<<"To choose press corresponding number: "<<endl;
    int option;
    cin>>option;

    if(option==1){
    	
		cout<<endl<<"******** Add a new Recipe label ******"<<endl;
		currRecip++;

		if(currRecip>arraySize){
        	cout<<"There is no space for Recipe labels"<<endl;
			currRecip--;
        	RecipePage(nutr,current,recip,currRecip);
        }

		char inp[20];
		cout<<"Enter the File name (filename.txt): "<<endl;
		//cin.getline(inp,sizeof(inp));
		cin>>inp;
		ifstream stage2;
		stage2.open(inp);
        
		char str[STRMAX];
		stage2.getline(recip[currRecip-1].name,STRMAX);
        
		stage2>>recip[currRecip-1].servePeople;

		stage2>>recip[currRecip-1].numOfIngrad;
		stage2.getline(str,STRMAX);
        //cout<<"Here is the recipe no: "<<currRecip-1<<endl;
		for (int j = 0; j < recip[currRecip-1].numOfIngrad; ++j){
			stage2.getline(recip[currRecip-1].componentsR[j],STRMAX);
			//cout<<"Ingradients"<<j+1<<" "<<recip[currRecip-1].componentsR[j]<<endl;
			stage2>>recip[currRecip-1].measurementR[j]>>recip[currRecip-1].metricR[j];
			//cout<<recip[currRecip-1].measurementR[j]<<recip[currRecip-1].metricR[j]<<endl;
			stage2.getline(str,STRMAX);
		}

		stage2.close();

		cout<<"Successfully adding a new Recipe done.....";

    	RecipePage(nutr,current,recip,currRecip);

    }
    else if(option==2){
    	cout<<"Not programmed this path yet"<<endl;
    	RecipePage(nutr,current,recip,currRecip);
    }
    else if(option==3){
    	
		cout<<endl<<"******** Delete a Recipe label ******"<<endl;

		cout<<"Please input the corresponding item no to delete within the range 1 to "<<currRecip<<endl;

		int itemNo;
		cin>>itemNo;

		if(itemNo>currRecip){
			cout<<"Your input is invalid"<<endl;
			RecipePage(nutr,current,recip,currRecip);

		}
		else{
			itemNo-=1;
			for (int i = itemNo; i < currRecip-1; ++i){
				recip[i]=recip[i+1];
			}
			currRecip-=1;
			cout<<"Recipe label deleted sucessfully........"<<endl;
			RecipePage(nutr,current,recip,currRecip);
		}
    	
    }
    else if(option==4){
    	cout<<"Not programmed this path yet"<<endl;
    	RecipePage(nutr,current,recip,currRecip);
    }
    else if(option==5){
    	
    	recipeViewPage(nutr,current,recip,currRecip);
    }
    else if(option==6){
    	cout<<endl<<"******** Back to main menu from Recipe Page ******"<<endl;
		showMenuBar(nutr,current,recip,currRecip);
    	
    }
    
}

void recipeViewPage(Nutrition nutr[], int current, Recipe recip[], int currRecip){

	cout<<endl<<"******** Recipe View Page ******"<<endl;
    cout<<"There are "<<currRecip<<" Recipe labels now"<<endl;
	

	cout<<endl<<"Options"<<endl;

	cout<<"1. View all Recipe Label's name"<<endl;
	cout<<"2. View specific Recipe label's components"<<endl;
	cout<<"3. Print all Recipe label's details to a output file"<<endl;
	cout<<"4. Go to Recipe Page"<<endl;
    cout<<"5. Go to Main Menu View"<<endl;
	cout<<"To choose press corresponding number: "<<endl;

	int option;
	cin>>option;

	if(option==1){

		cout<<endl<<endl;
		cout<<"Item No     Names"<<endl;
		for (int i = 0; i < currRecip; ++i){
        	cout<<i+1<<".     "<<recip[i].name<<endl;
        }
        recipeViewPage(nutr,current,recip,currRecip);

	}
	else if(option==2){

		cout<<"Please input the corresponding integer number within the range 1 to "<<currRecip<<endl;
		int itemNo;
		cin>>itemNo;
		if(itemNo>currRecip){
			cout<<"Your input is invalid"<<endl;
			recipeViewPage(nutr,current,recip,currRecip);
		}
		else{
			cout<<endl<<"Output of Query"<<endl;
			//recip[itemNo-1].print();

			cout<<"Name of the label: "<<recip[itemNo-1].name<<endl<<endl;
			cout<<"Number of People Served: "<<recip[itemNo-1].servePeople<<endl<<endl;
			cout<<"Recipe Name                Measurement            Metric"<<endl<<endl;
            
			for (int j = 0; j < recip[itemNo-1].numOfIngrad; ++j){
				cout<<j+1<<". "<<recip[itemNo-1].componentsR[j]<<endl;
				cout<<recip[itemNo-1].measurementR[j]<<"             "<<recip[itemNo-1].metricR[j]<<endl<<endl;
			}


			recipeViewPage(nutr,current,recip,currRecip);
		}

	}
	else if(option==3){
		ofstream fout;
		fout.open ("OutputRecipe.txt");

		for (int i = 0; i < currRecip; ++i){

			fout<<"Name of the label: "<<recip[i].name<<endl<<endl;
			fout<<"Number of People Served: "<<recip[i].servePeople<<endl<<endl;
			fout<<"Recipe Name                Measurement            Metric"<<endl<<endl;

			for (int j = 0; j < recip[i].numOfIngrad; ++j){
				fout<<recip[i].componentsR[j]<<"         "<<recip[i].measurementR[j]<<"             "<<recip[i].metricR[j]<<endl<<endl;
			}

		

		fout<<endl<<endl<<"==============================================================="<<endl<<endl;

			
		}

        fout.close();

        cout<<"Print all labels's compoments to OutputRecipe.txt file"<<endl;
        recipeViewPage(nutr,current,recip,currRecip);
	}
	else if(option==4){
		RecipePage(nutr,current,recip,currRecip);
	}
	else if(option==5){
		showMenuBar(nutr,current,recip,currRecip);
	}

}



void NutritionPage(Nutrition nutr[], int current, Recipe recip[], int currRecip){

	cout<<endl<<endl;
	cout<<"******* Nutrion Page **********"<<endl;
	cout<<endl<<"Options"<<endl;

	cout<<"1.Add a new Nutrion label."<<endl;
	cout<<"2.Edit a Nutrion label"<<endl;
	cout<<"3.Delete a Nutrion label"<<endl;
	cout<<"4.Go to Nutrition View page"<<endl;
	cout<<"5.Back to main menu"<<endl;
	cout<<"To choose press corresponding number: "<<endl;
    int option;
    cin>>option;
	if(option==1){
		cout<<endl<<"******** Add a new Nutrition label ******"<<endl;
		current++;
        if(current>arraySize){
        	cout<<"There is no space for Nutrition labels"<<endl;
			current--;
        	NutritionPage(nutr,current,recip,currRecip);
        }
		char inp[20];
		cout<<"Enter the File name (filename.txt): "<<endl;
		//cin.getline(inp,sizeof(inp));
		cin>>inp;
		ifstream stage2;
		stage2.open (inp);
		stage2>>nutr[current-1].name;


		int i=0;

		while(i<nutr[current-1].numOfComponents){
			stage2>>nutr[current-1].components[i]>>nutr[current-1].measurement[i]>>nutr[current-1].metric[i];
			i++;

		}

		stage2.close();

    cout<<"Adding a new Nutrition part done. "<<endl;
	NutritionPage(nutr,current,recip,currRecip);
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

		NutritionPage(nutr,current,recip,currRecip);
	}
	else if(option==3){
		cout<<endl<<"******** Delete a Nutrition label ******"<<endl;

		cout<<"Please input the corresponding item no to delete within the range 1 to "<<current<<endl;

		int itemNo;
		cin>>itemNo;

		if(itemNo>current){
			cout<<"Your input is invalid"<<endl;
			NutritionPage(nutr,current,recip,currRecip);

		}
		else{
			itemNo-=1;
			for (int i = itemNo; i < current-1; ++i){
				nutr[i]=nutr[i+1];
			}
			current-=1;
			cout<<"Nutrition label deleted sucessfully!"<<endl;
			NutritionPage(nutr,current,recip,currRecip);
		}

	}
	else if(option==4){

       	nutritionViewPage(nutr,current,recip,currRecip);
	}
	else if(option==5){
		cout<<endl<<"******** Back to main menu from Nutrition Page ******"<<endl;
		showMenuBar(nutr,current,recip,currRecip);
	}

}

void nutritionViewPage(Nutrition nutr[], int current, Recipe recip[], int currRecip){
	cout<<endl<<"******** Nutrition View Page ******"<<endl;
    cout<<"There are "<<current<<" nutrition labels now"<<endl;
	

	cout<<endl<<"Options"<<endl;

	cout<<"1. View all Nutrition Label's name"<<endl;
	cout<<"2. View specific label's components"<<endl;
	cout<<"3. Print all Nutrition label's details to a output file"<<endl;
	cout<<"4. Go to Nutrition Page"<<endl;
    cout<<"5. Go to Main Menu View"<<endl;
	cout<<"To choose press corresponding number: "<<endl;

	int option;
	cin>>option;
	if(option==1){

		cout<<endl<<endl;
		cout<<"Item No     Names"<<endl;
		for (int i = 0; i < current; ++i){
        	cout<<i+1<<".     "<<nutr[i].name<<endl;
        }
        nutritionViewPage(nutr,current,recip,currRecip);

	}
	else if(option==2){

		cout<<"Please input the corresponding integer number within the range 1 to "<<current<<endl;
		int itemNo;
		cin>>itemNo;
		if(itemNo>current){
			cout<<"Your input is invalid"<<endl;
			nutritionViewPage(nutr,current,recip,currRecip);
		}
		else{
			cout<<endl<<"Output of Query"<<endl;
			nutr[itemNo-1].print();
			nutritionViewPage(nutr,current,recip,currRecip);
		}

	}
	else if(option==3){
		ofstream fout;
		fout.open ("OutputNutrition.txt");

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
        NutritionPage(nutr,current,recip,currRecip);


	}
	else if(option==4){
		NutritionPage(nutr,current,recip,currRecip);
	}
	else if(option==5){
		showMenuBar(nutr,current,recip,currRecip);
	}


}

int main(){
   	
	Nutrition lists[arraySize];
	ifstream stage1;
	stage1.open("NutritionDatabase.txt");
	int currNutr;
	stage1>>currNutr;

    for (int j = 0; j < currNutr; ++j){

    	stage1>>lists[j].name;
    	int i=0;

		while(i<lists[j].numOfComponents){
			stage1>>lists[j].components[i]>>lists[j].measurement[i]>>lists[j].metric[i];
			i++;	

		}
    	
    }
    stage1.close();
    cout<<"Succcessfully fetched data from NutritionDatabase file"<<endl;

	Recipe recipeList[arraySize];

	//ifstream stage1;
	stage1.open("RecipeDatabase.txt");

	int currRecip;
	stage1>>currRecip;
	
    char str[STRMAX];
    
	for (int i = 0; i < currRecip; ++i)
	{
	    stage1.getline(str,STRMAX);
		stage1.getline(recipeList[i].name,STRMAX);
        
		stage1>>recipeList[i].servePeople;

		stage1>>recipeList[i].numOfIngrad;
		stage1.getline(str,STRMAX);

		for (int j = 0; j < recipeList[i].numOfIngrad; ++j){

		stage1.getline(recipeList[i].componentsR[j],STRMAX);
		stage1>>recipeList[i].measurementR[j]>>recipeList[i].metricR[j];
		if(j<recipeList[i].numOfIngrad-1) stage1.getline(str,STRMAX);
		}
	}
	stage1.close();

	cout<<"Succcessfully fetched data from RecipeDatabase file"<<endl;

   	showMenuBar(lists,currNutr,recipeList,currRecip);
}









	




   	
