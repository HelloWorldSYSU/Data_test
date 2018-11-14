#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>

#define SleepTime 1500
using namespace std;

stack<int> key;
int Index_record = 0;
int Finalsort = 0;
int Length;

int compute_Least_DapatchStation(int k){
	int i = 0;
	for (i = 1; (i * i + i + 2) / 2 < k; i ++){}
	return i;
}

void print(vector<stack<int> > b, int m, stack<int> key){
	cout << endl;
	int i;
	for(int k = 0; k < m; k ++) {
		for(i = 0; i < b.size(); i ++){
			if((b[i].empty())) {
				cout << "     |";
			}
			else {
			cout << setw(4) <<b[i].top() << " |";
			}
			
			if(!b[i].empty()) b[i].pop();
		}
		if((key.empty())) {
			cout << "     |";
		}
		else {
			cout << setw(4) << key.top() << " |";
		}
			
		if(!key.empty()) key.pop();
		cout << endl;
	}
	/*if(kbhit()){
        system("pause"); 
    }*/
}

void stackToStack(vector<stack<int> > &b, vector<int> c, int k){
	int y = Index_record + 2;
	int k_record = k;
	
	while(!b[Index_record].empty()){
		int record = b[Index_record].top();
		b[Index_record].pop();
		
		if(record >= c[Finalsort] && record <= c[Finalsort + k_record - 1]) {
			if(record == c[Finalsort]) {
				Finalsort ++;
				key.push(record);
				cout << "NO." << record << " train compartment is moving to assemble." << endl;
				print(b , Length, key);
				Sleep(SleepTime);
				if(kbhit()){
        			system("pause"); 
    			}
				system("cls");
			}
			else {
				b[y ++].push(record);
				cout << "NO." << record << " train compartment is moving to " << y - 1 << " depatch station." <<endl;
				print(b , Length, key);
				Sleep(SleepTime);
				if(kbhit()){
        			system("pause"); 
    			}
				system("cls");	
				k_record --;
			}
		}
		
		else {
			b[Index_record + 1].push(record);
			cout << "No." << record << " train compartment is moving to " << Index_record + 1 << " depatch station." << endl;
			print(b , Length, key);
			Sleep(SleepTime);
			if(kbhit()){
        		system("pause"); 
    		}
			system("cls");
			
		}	
	
	}
	
	Index_record ++;
}

int main() {
	vector<int> FinalSort;
	vector<stack<int> > All;
	stack<int> start;
	stack<int> Temp;
	int number;
		
	while(cin >> number) {
		start.push(number);
		FinalSort.push_back(number);
		if(getchar() == '\n') break;
	}
	
	All.push_back(start);
	sort(FinalSort.begin(), FinalSort.end());
	int length = start.size();
	//cout << length << " " << endl;
	int min = compute_Least_DapatchStation(length);
	cout << "To realize the goal, wo need " << min << " depatch stations" << endl;
	//cout << min << endl;
	int min_record = min;
	Length = length;
	
	while(min_record --) All.push_back(Temp);
	
	print(All , Length, key);
	Sleep(SleepTime);
	if(kbhit()){
        system("pause"); 
   	}
	system("cls");
	
	min_record = min;
	int min_record2 = min;
	
	while(min_record2 --) {
		if(key.size() == length) {
			cout << "Finished!" << endl;
			break;
		}
		stackToStack(All, FinalSort, min_record);
		min_record --;
	
		for(int i = 0; i <= min; i ++) {
			if(Finalsort >= length) break;
			for(int k = 0; k <= min; k ++) {
				if((!All[k].empty()) && All[k].top() == FinalSort[Finalsort]) {
					Finalsort ++;
					key.push(All[k].top());
					cout << "NO." << All[k].top() << " train compartment is moving to assemble from "<< k << " depatch station." << endl;
					if (!All[k].empty()) All[k].pop();
					print(All , Length, key);
					Sleep(SleepTime);
					if(kbhit()){
        				system("pause"); 
    				}
					system("cls");
				}
			}
		}
	}
}
	
