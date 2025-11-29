#include <iostream>

class String {
    char string[100];  

public:
    void input_string(const char str[]) { 
        int i = 0;
        while (str[i] != '\0' && i < 99) {
            string[i] = str[i];
            i++;
        }
        string[i] = '\0';  
    }
void uppercase_to_lowercase() { int num=0; 
       while(string[num]!='\0') {num++;}
       for(int i=0;i<num;i++){
           if(string[i]>=65 && string[i]<=90)
        string[i]+=32;}
              }
             
     void anagram_check(String obj2){ 
    int i=0; 
    while (string[i] != '\0' && obj2.string[i] != '\0')
    {     if(string[i] != obj2.string[i])
        {   std::cout<<" Not Anagrams"; 
            return;
        }   i++;}
      std::cout<<"Anagrams";
    }  

  
  
    void alphabetical_order() { int num=0; 
       while(string[num]!='\0') {num++;}
 for (int i=0;i<num-1;i++) {        
    for (int j=0;j<num-i-1;j++) {
        if (string[j]>string[j+1])
        {int temp=string[j];
    string[j]=string[j+1];
    string[j+1]=temp;}
             }
             }
              }
};
    int main() {
    String obj1, obj2;

    char str1[] = "Rome";
    char str2[] = "More";

    obj1.input_string(str1);  
    obj1.uppercase_to_lowercase(); 
    obj1.alphabetical_order();
    
    obj2.input_string(str2); 
    obj2.uppercase_to_lowercase(); 
    obj2.alphabetical_order();
    obj1.anagram_check(obj2)   ;
  
    return 0;
}
