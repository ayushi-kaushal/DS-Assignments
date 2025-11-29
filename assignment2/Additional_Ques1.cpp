
#include <iostream>
int size=0;
int Array[50];

void count();
void create();

int main() {
    create();
    count();
    
    return 0;
}

void create(){
    std::cout << "Enter number of elements\n";
    std::cin >> size;
        for(int i = 0; i < size; i++) {
        std::cout << "Enter element " << i+1<<"\n";
        std::cin >> Array[i];
    }
}

void count(){ int count_of_pairs=0; int K; 
std::cout<<"Enter K ";
std::cin>>K;
     for(int j=size-1;j>=0;j--){
         {for (int i=0;i<j;i++)
            if((Array[i]-Array[j])==K||(Array[i]-Array[j])==(-K)){count_of_pairs++;
    std::cout<<"for i,j being "<<i<<" and "<<j<<": " <<Array[i]<<" and "<<Array[j]<<"\n";
            }
        }
    } std::cout<<"Number of pairs:"<<count_of_pairs;
}
