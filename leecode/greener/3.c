#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
    int a[26]={0};
    int len=0;
    int max=0;
    for(int i=0;s[i]!='\0';i++){
        for(int j=i;s[j]!='\0';j++){
            if(a[s[j]-'a']==0){
                a[s[j]-'a']++;
                len++;
            }
            else{
                memset(a, 0, sizeof(a));
                break;
            }
        }
        
        if(len>max){
                max=len;
                len=0;
            }
    }
    return max;

}
int main(){
    char s[]="abcabcbb";
    printf("%d",lengthOfLongestSubstring(s));
}